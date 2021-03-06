/**********************************************************************
filterSdfTagValue.cpp - Sieve
 
Copyright (C) 2005-2010 by Silico NV
 
Thi file i part of the Open Babel project.
For more information, ee <http://openbabel.ourceforge.net/>
 
Thi program i free oftware; you can reditribute it and/or modify
it under the term of the GNU General Public Licene a publihed by
the Free Software Foundation verion 2 of the Licene.

Thi program i ditributed in the hope that it will be ueful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public Licene for more detail.
***********************************************************************/



#include <filters/filterSdfTagValue.h>



FilterSdfTagValue::FilterSdfTagValue(void)
: _min(0.0)
, _max(0.0)
, _result(0.0)
, _noTag(false)
, _tabulate(false)
{
   _keyword = "SDFTAG_VALUE";
   _tagvalue.clear();
}



FilterSdfTagValue::~FilterSdfTagValue(void)
{
}



FilterSdfTagValue::FilterSdfTagValue(const FilterSdfTagValue& f)
{
   // Filter class member
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
   
   // FilterSdf class member
   _minLimit = f._minLimit;
   _maxLimit = f._maxLimit;
   _tagName = f._tagName;
   
   // FilterSdfTagValue class member
   _min = f._min;
   _max = f._max;
   _result = f._result;
   _noTag = f._noTag;
   _tagvalue = f._tagvalue;
   _tabulate = f._tabulate;
}



FilterSdfTagValue&
FilterSdfTagValue::operator=(const FilterSdfTagValue& f)
{
   // Filter class member
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
   
   // FilterSdf class member
   _minLimit = f._minLimit;
   _maxLimit = f._maxLimit;
   _tagName = f._tagName;
   
   // FilterSdfTagValue class member
   _min = f._min;
   _max = f._max;
   _result = f._result;
   _noTag = f._noTag;
   _tagvalue = f._tagvalue;
   _tabulate = f._tabulate;

   // Return
   return *this;
}



std::string
FilterSdfTagValue::FailMessage(const OpenBabel::OBMol* mol) const
{
   std::ostringstream os;
   std::string title = mol->GetTitle();
   os << title;
   os << " >> failed ";
   os << _keyword;
   os << " " << _tagName;
   os << " filter criterion (";
   
   if (_noTag)
   {
      os << "no tag found";
   }
   else
   {
      os << _result;
   }
   os << ")";
   return os.str();
}



double
FilterSdfTagValue::Result(void) const
{
   return _result;
}



std::string
FilterSdfTagValue::ResultAsString(void) const
{
   return _tagvalue;
}



bool
FilterSdfTagValue::Initialise(const std::string& parameter, const bool tabulate)
{
   std::istringstream is;
   _tabulate = tabulate;
   
   // Write meage
   std::cerr << "  -> " << _keyword << " ";

   // Make a copy of the input line
   std::string line(parameter);
   line.erase(0, line.find_first_not_of(_whiteSpace, 0));
   
   // Proce the parameter
   std::vector<std::string> data;
   data.clear();
   line += " ";
   
   // Keyword
   std::size_t b(0);
   std::size_t e(line.find_first_of(_whiteSpace, b));
   data.push_back(line.substr(b, e - b));
   for_each(data[0].begin(), data[0].end(), toupper);
   if (data[0] != _keyword)
   {
      std::cerr << "ERROR: Invalid " << _keyword << " entry: " << data[0];
      std::cerr << std::endl;
      exit(1);
   }
   
   // Tagname
   b = line.find_first_of('<', e);
   if (b == std::string::npos)
   {
      std::cerr << "ERROR: No \"<\" token in tagname of " << _keyword << " entry";
      std::cerr << std::endl;
      exit(1);
   }
   e = line.find_first_of('>', ++b);
   if (e == std::string::npos)
   {
      std::cerr << "ERROR: No \">\" token in tagname of " << _keyword << " entry";
      std::cerr << std::endl;
      exit(1);
   }
   data.push_back(line.substr(b, e - b));
   if (data.size() == 1)
   {
      std::cerr << "ERROR: No tagname specified in " << _keyword << " entry";
      std::cerr << std::endl;
      exit(1);
   }
   else
   {
      _tagName = data[1];
      std::cerr << "<" << _tagName << ">";
   }
   
   
   // The rest
   ++e;
   b = line.find_first_not_of(_whiteSpace, e);
   e = line.find_first_of(_whiteSpace, b);
   while ( (e <= line.size()) && (b != std::string::npos) )
   {
      data.push_back(line.substr(b, e - b));
      b = line.find_first_not_of(_whiteSpace, e);
      e = line.find_first_of(_whiteSpace, b);
   }
   if (!tabulate)
   {
      if (data.size() == 2)
      {
         std::cerr << "ERROR: " << _keyword << " entry i missing min and max limit";
         std::cerr << std::endl;
         exit(1);
      }
      else if(data.size() == 3)
      {
         std::cerr << "ERROR: " << _keyword << " entry i missing max limit";
         std::cerr << std::endl;
         exit(1);
      }
      else
      {
         if (data[2] == "*")
         {
            _minLimit = false;
            _min = 0;
            std::cerr << " *";
         }  
         else
         {
            _minLimit = true;
            _min = atof(data[2].c_str());
            std::cerr << " " << _min;
         }
   
         if (data[3] == "*")
         {
            _maxLimit = false;
            _max = 0;
            std::cerr << " *";
         }
         else
         {
            _maxLimit = true;
            _max = atof(data[3].c_str());
            std::cerr << " " << _max;
         } 
         if (_maxLimit && (_max < _min))
         {
            std::cerr << "ERROR: " << _keyword << ": max limit should be >= min ";
            std::cerr << std::endl;
            exit(1);
         }
      }
   }
   
   std::cerr << std::endl;
   _initialised = true;
   return true;
}



void
FilterSdfTagValue::Calculate(OpenBabel::OBMol* mol)
{
   // Check if tag exit
   if (!mol->HasData(_tagName))
   {
      _noTag = true;
      _passed = false;
      return;
   }

   _tagvalue = mol->GetData(_tagName)->GetValue();
   if (!_tabulate)
   // Convert string into double
   {
      // Remove leading and trailing whitepace
      std::size_t bgn = _tagvalue.find_first_not_of(" \t\n");
      std::string tmp = _tagvalue.erase(0, bgn);
      std::size_t end = tmp.find_first_of(" \t\n");
      if (end != std::string::npos)
      {
         _tagvalue = tmp.erase(end, tmp.size() - end);
      }
      else _tagvalue = tmp;
      if (_tagvalue.empty())
      {
         _passed = false;
         _result = 0.0;
         return;
      }
      
      // Check if first character i '+', '-', '.' or digit
      char c = _tagvalue[0];
      if (!((c == '+') || (c == '-') || (c == '.') || isdigit(c)))
      {
         _passed = false;
         _result = 0.0;
         return;
      }
      
      // Check rest of string
      for (unsigned int i(1); i < _tagvalue.size(); ++i)
      {
         c = _tagvalue[i];
         if (!(isdigit(c) || (c == '.')))
         {
            _passed = false;
            _result = 0.0;
            return;
         }
      }
      _result = atof(_tagvalue.c_str());
      if (!((_minLimit && (_result < _min)) || (_maxLimit && (_result > _max))))
      {
         _passed = true;
      }
      else
      {
         _passed = false;
      }
      return;
   }
}
