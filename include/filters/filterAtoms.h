/**********************************************************************
filterAtoms.h - Sieve
 
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



#ifndef __FILTERATOMS_H__
#define __FILTERATOMS_H__

#include <filters/filterIntegerProperty.h>



class FilterAtoms: public FilterIntegerProperty 
{
   protected:
      
   public:
   
      FilterAtoms(void);
      virtual ~FilterAtoms(void);
      FilterAtoms(const FilterAtoms&);
      FilterAtoms& operator=(const FilterAtoms&);

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
