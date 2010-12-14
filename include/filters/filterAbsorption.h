/**********************************************************************
filterAbsorption.h - Sieve
 
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



#ifndef __FILTERABSORPTION_H__
#define __FILTERABSORPTION_H__

#include <filters/filterIntegerProperty.h>
#include <filters/filterLogp.h>
#include <filters/filterTpsa.h>



class FilterAbsorption: public FilterIntegerProperty 
{
   protected:
   
      FilterLogp           _logp;
      FilterTpsa           _tpsa;
      
   public:
   
      FilterAbsorption(void);
      virtual ~FilterAbsorption(void);
      FilterAbsorption(const FilterAbsorption&);
      FilterAbsorption& operator=(const FilterAbsorption&);

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
