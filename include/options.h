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



#ifndef __OPTIONS_H__
#define __OPTIONS_H__


#include <string>
#include <sstream>

#include <openbabel/obconversion.h>



class Options
{
   protected:

      std::string             _ifile;           // --in
      std::string             _pfile;           // --pass
      std::string             _ffile;           // --fail

      std::string             _filterFileName;  // --filter

      bool                    _tabulate;        // --tab
      bool                    _salts;           // --salts
      bool                    _noLog;           // --noLog
      bool                    _rename;          // --rename

   public:
      
      Options(void);
      virtual ~Options(void);
      Options(const Options&);
      Options& operator=(const Options&);

      virtual bool                  SetInputFilename(const std::string&);
      virtual std::string           GetInputFilename(void);

      virtual bool                  SetFailFilename(const std::string&);
      virtual std::string           GetFailFilename(void);

      virtual bool                  SetPassFilename(const std::string&);
      virtual std::string           GetPassFilename(void);

      virtual bool                  SetFilterFilename(const std::string&);
      virtual std::string           GetFilterFilename(void);

      virtual void                  Tabulate(const bool&);
      virtual bool                  Tabulate(void) const;

      virtual void                  Salts(const bool&);
      virtual bool                  Salts(void) const;

      virtual void                  NoLog(const bool&);
      virtual bool                  NoLog(void) const;
      virtual void                  Log(const bool&);
      virtual bool                  Log(void) const;

      virtual void                  Rename(const bool&);
      virtual bool                  Rename(void) const;

      virtual std::string           Print(void) const;     
};




#endif
