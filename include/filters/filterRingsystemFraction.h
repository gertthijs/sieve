/**********************************************************************
filterRingsystemFraction.h - Sieve
 
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



#ifndef __FILTERRINGSYSTEMFRACTION_H__
#define __FILTERRINGSYSTEMFRACTION_H__

#include <filters/filterRealProperty.h>



class FilterRingsystemFraction: public FilterRealProperty 
{
   protected:
      
   public:
   
      FilterRingsystemFraction(void);
      virtual ~FilterRingsystemFraction(void);
      FilterRingsystemFraction(const FilterRingsystemFraction&);
      FilterRingsystemFraction& operator=(const FilterRingsystemFraction&);

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
