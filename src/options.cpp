/**********************************************************************
options.h - Sieve
 
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



#include <options.h>



Options::Options(void)
{
   _ifile.clear();
   _pfile.clear();
   _ffile.clear();
   _filterFileName.clear();
   _tabulate = false;
   _salts = false;
   _noLog = false;
   _rename = false;
}



Options::~Options(void)
{
}



Options::Options(const Options& f)
{
   // Class members
   _ifile = f._ifile;
   _iconv = f._iconv;
   _pfile = f._pfile;
   _pconv = f._pconv;
   _ffile = f._ffile;
   _fconv = f._fconv;
   _filterFileName = f._filterFileName;
   _tabulate = f._tabulate;
   _salts = f._salts;
   _noLog = f._noLog;
   _rename - f._rename;
}



Options&
Options::operator=(const Options& f)
{
   // Class members
   _ifile = f._ifile;
   _iconv = f._iconv;
   _pfile = f._pfile;
   _pconv = f._pconv;
   _ffile = f._ffile;
   _fconv = f._fconv;
   _filterFileName = f._filterFileName;
   _tabulate = f._tabulate;
   _salts = f._salts;
   _noLog = f._noLog;
   _rename - f._rename;

   return *this;
}



bool
Options::InputFilename(std::string f)
{
   _ifile = f;
   if (_ifile.empty()) return false;
   return true;
}



std::string
Options::InputFilename(void) const
{
   return _ifile;
}


std::string
Options::InputFormat(void) const
{
   return std::string(_iconv.GetInFormat()->GetID());
}


std::ifstream*
Options::InputStream(void)
{
   return &_ifs;
}



OpenBabel::OBConversion*
Options::InputConverter(void)
{
   return &_iconv;
}



bool
Options::FailFilename(const std::string& f)
{
   _ffile = f;
   if (_ffile.empty()) return false;
   return true;
}



std::string
Options::FailFilename(void) const
{
   return _ffile;
}


std::string
Options::FailFormat(void) const
{
   return std::string(_fconv.GetOutFormat()->GetID());
}


std::ofstream*
Options::FailStream(void)
{
   return &_ffs;
}



OpenBabel::OBConversion*
Options::FailConverter(void)
{
   return &_fconv;
}



bool
Options::PassFilename(const std::string& f)
{
   _pfile = f;
   if (_pfile.empty()) return false;
   return true;
}



std::string
Options::PassFilename(void) const
{
   return _pfile;
}


std::string
Options::PassFormat(void) const
{
   return std::string(_pconv.GetOutFormat()->GetID());
}



std::ofstream*
Options::PassStream(void)
{
   return &_pfs;
}



OpenBabel::OBConversion*
Options::PassConverter(void)
{
   return &_pconv;
}



bool
Options::FilterFilename(const std::string& f)
{
   _filterFileName = f;
   if (_filterFileName.empty()) return false;
   return true;
}



std::string
Options::FilterFilename(void) const
{
   return _filterFileName;
}



void
Options::Tabulate(const bool& f)
{
   _tabulate = f;
}



bool
Options::Tabulate(void) const
{
   return _tabulate;
}



void
Options::Salts(const bool& f)
{
   _salts = f;
}



bool
Options::Salts(void) const
{
   return _salts;
}



void
Options::Rename(const bool& f)
{
   _rename = f;
}



bool
Options::Rename(void) const
{
   return _rename;
}



void
Options::NoLog(const bool& f)
{
   _noLog = f;
}



bool
Options::NoLog(void) const
{
   return _noLog;
}



void
Options::Log(const bool& f)
{
   _noLog = !f;
}



bool
Options::Log(void) const
{
   return !_noLog;
}



std::string
Options::Print(void) const
{
   std::ostringstream os;
   os << std::endl;
   os << "COMMAND_LINE OPTIONS:" << std::endl;
   os << std::endl;
   os << "  -> Strip salts:       " << (_salts ? "no" : "yes") << std::endl;
   os << "  -> Rename titles:     " << (_rename ? "yes" : "no") << std::endl;
   os << "  -> Tabulate mode:     " << (_tabulate ? "yes" : "no") << std::endl;
   os << "  -> Write log file:    " << (_noLog ? "no" : "yes") << std::endl;
   os << "  -> Filter file:       " << _filterFileName << std::endl;
   os << "  -> Input file:        " << _ifile << " (";
   os << Options::InputFormat() << ") -> ";
   if (_ifs.good())
   {
      os << "ok";
   }
   else
   {
      os << "error";
   }
   os << std::endl;
   if (!_tabulate)
   {
      os << "  -> Pass file:         " << _pfile << " (";
      os << Options::PassFormat() << ") -> ";
      if (_pfs.good())
      {
         os << "ok";
      }
      else
      {
         os << "error";
      }
      os << std::endl;
   }
   if (!_tabulate && !_ffile.empty())
   {
      os << "  -> Fail file:         " << _ffile << " (";
      os << Options::FailFormat() << ") -> ";
      if (_ffs.good())
      {
         os << "ok";
      }
      else
      {
         os << "error";
      }
      os << std::endl;
   }
   os << std::endl;
   
   std::string r = os.str();
   return r;
}
