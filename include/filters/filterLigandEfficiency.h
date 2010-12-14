/**********************************************************************
filterLigandEfficiency.h - Sieve
 
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



#ifndef __FILTERLIGANDEFFICIENCY_H__
#define __FILTERLIGANDEFFICIENCY_H__

#include <filters/filterRealProperty.h>
#include <filters/filterHbondAcceptors.h>
#include <filters/filterHeteroCarbonRatio.h>
#include <filters/filterTpsa.h>




class FilterLigandEfficiency: public FilterRealProperty 
{
   protected:
      
      FilterHbondAcceptors       _hba;
      FilterHeteroCarbonRatio    _hcr;
      FilterTpsa                 _tpsa;
      
   public:
   
      FilterLigandEfficiency(void);
      virtual ~FilterLigandEfficiency(void);
      FilterLigandEfficiency(const FilterLigandEfficiency&);
      FilterLigandEfficiency& operator=(const FilterLigandEfficiency&);

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
