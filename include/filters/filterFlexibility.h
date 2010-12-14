/**********************************************************************
filterFlexibility.h - Sieve
 
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



#ifndef __FILTERFLEXIBILITY_H__
#define __FILTERFLEXIBILITY_H__

#include <filters/filterRealProperty.h>
#include <filters/filterRigidBonds.h>
#include <filters/filterRotatableBonds.h>



class FilterFlexibility: public FilterRealProperty 
{
   protected:
   
      FilterRigidBonds     _rigid;
      FilterRotatableBonds _rotor;
      
   public:
   
      FilterFlexibility(void);
      virtual ~FilterFlexibility(void);
      FilterFlexibility(const FilterFlexibility&);
      FilterFlexibility& operator=(const FilterFlexibility&);

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
