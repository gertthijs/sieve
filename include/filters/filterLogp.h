/**********************************************************************
filterLogp.h - Sieve
 
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



#ifndef __FILTERLOGP_H__
#define __FILTERLOGP_H__

#include <filters/filterRealProperty.h>

#include <filters/filterFormalCharges.h>
#include <filters/filterHbondAcceptors.h>
#include <filters/filterHbondDonors.h>
#include <filters/filterHeteroAtoms.h>
#include <filters/filterRigidBonds.h>
#include <filters/filterRingsystems.h>
#include <filters/filterTotalFormalCharge.h>
#include <filters/filterHeteroCarbonRatio.h>
#include <filters/filterRingFraction.h>
#include <filters/filterTpsa.h>



class FilterLogp: public FilterRealProperty 
{
   protected:
   
      std::vector<OpenBabel::OBSmartsPattern*>   _p;
      std::vector<double>                 _v;
      std::vector<std::string>            _s;
      
      FilterFormalCharges                 _formalCharges;
      FilterHbondAcceptors                _hbondAcceptors;
      FilterHbondDonors                   _hbondDonors;
      FilterHeteroAtoms                   _heteroAtoms;
      FilterRigidBonds                    _rigidBonds;
      FilterRingsystems                   _ringsystems;
      FilterTotalFormalCharge             _totalFormalCharge;
      FilterHeteroCarbonRatio             _heteroCarbonRatio;
      FilterRingFraction                  _ringFraction;
      FilterTpsa                          _tpsa;

         
   public:
   
      FilterLogp(void);
      virtual ~FilterLogp(void);
      FilterLogp(const FilterLogp&);
      FilterLogp& operator=(const FilterLogp&);

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
