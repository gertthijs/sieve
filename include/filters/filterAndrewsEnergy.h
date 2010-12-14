/**********************************************************************
filterAndrewsEnergy.h - Sieve
 
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



#ifndef __FILTERANDREWSENERGY_H__
#define __FILTERANDREWSENERGY_H__

#include <filters/filterRealProperty.h>
#include <filters/filterRotatableBonds.h>



struct AndrewsParameters
{
   double                     v;
   unsigned int               n;
};



class FilterAndrewsEnergy: public FilterRealProperty 
{
   protected:
   
      FilterRotatableBonds                _rotor;
      std::vector<OpenBabel::OBSmartsPattern>    _s;
      std::vector<AndrewsParameters>      _p;

         
   public:
   
      FilterAndrewsEnergy(void);
      virtual ~FilterAndrewsEnergy(void);
      FilterAndrewsEnergy(const FilterAndrewsEnergy&);
      FilterAndrewsEnergy& operator=(const FilterAndrewsEnergy&);

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
