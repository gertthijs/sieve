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
   _pfile = f._pfile;
   _ffile = f._ffile;
   _filterFileName = f._filterFileName;
   _tabulate = f._tabulate;
   _salts = f._salts;
   _noLog = f._noLog;
   _rename = f._rename;
}



Options&
Options::operator=(const Options& f)
{
   // Class members
   _ifile = f._ifile;
   _pfile = f._pfile;
   _ffile = f._ffile;
   _filterFileName = f._filterFileName;
   _tabulate = f._tabulate;
   _salts = f._salts;
   _noLog = f._noLog;
   _rename = f._rename;

   return *this;
}



bool
Options::SetInputFilename(const std::string& f)
{
   _ifile = f;
   if (_ifile.empty()) return false;
   return true;
}



std::string
Options::GetInputFilename(void)
{
   return _ifile;
}



bool
Options::SetFailFilename(const std::string& f)
{
   _ffile = f;
   if (_ffile.empty()) return false;
   return true;
}



std::string
Options::GetFailFilename(void)
{
   return _ffile;
}



bool
Options::SetPassFilename(const std::string& f)
{
   _pfile = f;
   if (_pfile.empty()) return false;
   return true;
}



std::string
Options::GetPassFilename(void)
{
   return _pfile;
}



bool
Options::SetFilterFilename(const std::string& f)
{
   _filterFileName = f;
   if (_filterFileName.empty()) return false;
   return true;
}



std::string
Options::GetFilterFilename(void)
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
   os << "  -> Input file:        " << _ifile << std::endl;
   if (!_tabulate)
   {
      os << "  -> Pass file:         " << _pfile << std::endl;
   }
   if (!_tabulate && !_ffile.empty())
   {
      os << "  -> Fail file:         " << _ffile << std::endl;
   }
   os << std::endl;
   
   std::string r = os.str();
   return r;
}
