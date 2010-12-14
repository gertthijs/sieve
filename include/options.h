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

      OpenBabel::OBConversion _iconv;
      std::ifstream           _ifs;
      std::string             _ifile;           // --in

      OpenBabel::OBConversion _pconv;
      std::ofstream           _pfs;
      std::string             _pfile;           // --pass

      OpenBabel::OBConversion _fconv;
      std::ofstream           _ffs;
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

      virtual bool                  InputFilename(std::string);
      virtual std::string           InputFilename(void) const;
      virtual std::string           InputFormat(void) const;
      virtual OpenBabel::OBConversion* InputConverter(void);
      virtual std::ifstream*        InputStream(void);

      virtual bool                  FailFilename(const std::string&);
      virtual std::string           FailFilename(void) const;
      virtual std::string           FailFormat(void) const;
      virtual OpenBabel::OBConversion* FailConverter(void);
      virtual std::ofstream*        FailStream(void);

      virtual bool                  PassFilename(const std::string&);
      virtual std::string           PassFilename(void) const;
      virtual std::string           PassFormat(void) const;
      virtual OpenBabel::OBConversion* PassConverter(void);
      virtual std::ofstream*        PassStream(void);

      virtual bool                  FilterFilename(const std::string&);
      virtual std::string           FilterFilename(void) const;

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
