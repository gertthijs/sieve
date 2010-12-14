/**********************************************************************
filterSdf.h - Sieve
 
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



#ifndef __FILTERSDF_H__
#define __FILTERSDF_H__

#include <filters/filter.h>



class FilterSdf: public Filter 
{
   protected:
      
      std::string             _tagName;
      bool                    _minLimit;
      bool                    _maxLimit;
      
   public:

      FilterSdf(void);
      virtual ~FilterSdf(void);
      FilterSdf(const FilterSdf&);
      FilterSdf& operator=(const FilterSdf&);

      virtual bool            Initialise(const std::string&, const bool) = 0;

      virtual std::string     FailMessage(const OpenBabel::OBMol*) const = 0;
      
      virtual std::string     TagName(void) const;

      virtual void            Calculate(OpenBabel::OBMol*) = 0;
};



#endif
