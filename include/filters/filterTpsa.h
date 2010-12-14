/**********************************************************************
filterTpsa.h - Sieve
 
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



#ifndef __FILTERTPSA_H__
#define __FILTERTPSA_H__

#include <filters/filterRealProperty.h>



class FilterTpsa: public FilterRealProperty 
{
   protected:
   
      std::vector<OpenBabel::OBSmartsPattern*>   _p;
      std::vector<double>                 _v;
      std::vector<std::string>            _s;

         
   public:
   
      FilterTpsa(void);
      virtual ~FilterTpsa(void);
      FilterTpsa(const FilterTpsa&);
      FilterTpsa& operator=(const FilterTpsa&);

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
