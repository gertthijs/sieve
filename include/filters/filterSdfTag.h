/**********************************************************************
filterSdfTag.h - Sieve
 
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



#ifndef __FILTERSDFTAG_H__
#define __FILTERSDFTAG_H__

#include <filters/filterSdf.h>



class FilterSdfTag: public FilterSdf
{
   protected:
      
      unsigned int            _min;
      unsigned int            _max;
      unsigned int            _result;
   
   public:
   
      FilterSdfTag(void);
      virtual ~FilterSdfTag(void);
      FilterSdfTag(const FilterSdfTag&);
      FilterSdfTag& operator=(const FilterSdfTag&);

      virtual bool            Initialise(const std::string&, const bool);
      
      virtual std::string     FailMessage(const OpenBabel::OBMol*) const;
      virtual unsigned int    Result(void) const;

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
