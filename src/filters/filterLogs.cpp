/**********************************************************************
filterLogs.h - Sieve
 
Copyright (C) 2005-2010 by Silicos NV
 
This file is part of the Open Babel project.
For more information, see <http://openbabel.sourceforge.net/>
 
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
***********************************************************************/



#include <filters/filterLogs.h>



FilterLogs::FilterLogs(void)
{
   _keyword = "LOGS";
   
   _s.push_back("[NH0;X3;v3]");
   _v.push_back(+0.71535);
   
   _s.push_back("[NH2;X3;v3]");
   _v.push_back(+0.41056);

   _s.push_back("[nH0;X3]");
   _v.push_back(+0.82535);

   _s.push_back("[OH0;X2;v2]");
   _v.push_back(+0.31464);

   _s.push_back("[OH0;X1;v2]");
   _v.push_back(+0.14787);

   _s.push_back("[OH1;X2;v2]");
   _v.push_back(+0.62998);

   _s.push_back("[CH2;!R]");
   _v.push_back(-0.35634);

   _s.push_back("[CH3;!R]");
   _v.push_back(-0.33888);

   _s.push_back("[CH0;R]");
   _v.push_back(-0.21912);

   _s.push_back("[CH2;R]");
   _v.push_back(-0.23057);

   _s.push_back("[ch0]");
   _v.push_back(-0.37570);

   _s.push_back("[ch1]");
   _v.push_back(-0.22435);

   _s.push_back("F");
   _v.push_back(-0.21728);

   _s.push_back("Cl");
   _v.push_back(-0.49721);

   _s.push_back("Br");
   _v.push_back(-0.57982);

   _s.push_back("I");
   _v.push_back(-0.51547);
   
   for (unsigned int i = 0; i < _s.size(); ++i)
   {
      _p.push_back(new OpenBabel::OBSmartsPattern());
      _p[i]->Init(_s[i]);
   }
}



FilterLogs::~FilterLogs(void)
{
   for (unsigned int i = 0; i < _p.size(); ++i)
   {
      delete _p[i];
      _p[i] = NULL;
   }
}



FilterLogs::FilterLogs(const FilterLogs& f)
{
   // Filter class members
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
   
   // FilterRealProperty class members
   _min = f._min;
   _max = f._max;
   _minLimit = f._minLimit;
   _maxLimit = f._maxLimit;
   _result = f._result;
   
   // Own class members
   _s = f._s;
   _v = f._v;
   for (unsigned int i = 0; i < _s.size(); ++i)
   {
      _p.push_back(new OpenBabel::OBSmartsPattern());
      _p[i]->Init(_s[i]);
   }
}



FilterLogs&
FilterLogs::operator=(const FilterLogs& f)
{
   // Filter class members
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
   
   // FilterRealProperty class members
   _min = f._min;
   _max = f._max;
   _minLimit = f._minLimit;
   _maxLimit = f._maxLimit;
   _result = f._result;
   
   // Own class members
   _s = f._s;
   _v = f._v;
   for (unsigned int i = 0; i < _s.size(); ++i)
   {
      _p.push_back(new OpenBabel::OBSmartsPattern());
      _p[i]->Init(_s[i]);
   }

   // Return
   return *this;
}



void
FilterLogs::Calculate(OpenBabel::OBMol* mol)
{
   // Molweight
   _result = -0.10369 * sqrt(mol->GetMolWt(true));
   
   // Fragments
   std::vector< std::vector< int > > matches;
   for (unsigned int i(0); i < _p.size(); ++i)
   {
      _p[i]->Match(*mol, false);
      matches = _p[i]->GetUMapList();
      _result += (_v[i] * matches.size());
   }
   
   // Intercept
   _result += 0.89823;
   
   if ((_minLimit && (_result < _min)) || (_maxLimit && (_result > _max)))
   {
      _passed = false;
   }
   else
   {
      _passed = true;
   }
}




