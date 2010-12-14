/**********************************************************************
filterAtomsInLargestNonaromaticRing.h - Sieve
 
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



#ifndef __FILTERATOMSINLARGESTNONAROMATICRING_H__
#define __FILTERATOMSINLARGESTNONAROMATICRING_H__

#include <filters/filterIntegerProperty.h>



class FilterAtomsInLargestNonaromaticRing: public FilterIntegerProperty 
{
   protected:
      
   public:
   
      FilterAtomsInLargestNonaromaticRing(void);
      virtual ~FilterAtomsInLargestNonaromaticRing(void);
      FilterAtomsInLargestNonaromaticRing(const FilterAtomsInLargestNonaromaticRing&);
      FilterAtomsInLargestNonaromaticRing& operator=(const FilterAtomsInLargestNonaromaticRing&);

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
