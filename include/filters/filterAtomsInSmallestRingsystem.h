/**********************************************************************
filterAtomsInSmallestRingsystem.h - Sieve
 
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



#ifndef __FILTERATOMSINSMALLESTRINGSYSTEM_H__
#define __FILTERATOMSINSMALLESTRINGSYSTEM_H__

#include <filters/filterIntegerProperty.h>



class FilterAtomsInSmallestRingsystem: public FilterIntegerProperty 
{
   protected:
      
   public:
   
      FilterAtomsInSmallestRingsystem(void);
      virtual ~FilterAtomsInSmallestRingsystem(void);
      FilterAtomsInSmallestRingsystem(const FilterAtomsInSmallestRingsystem&);
      FilterAtomsInSmallestRingsystem& operator=(const FilterAtomsInSmallestRingsystem&);

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
