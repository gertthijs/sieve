/**********************************************************************
filterAtmetScore.h - Sieve
 
Copyright (C) 2005-2011 by Silicos NV
 
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



#ifndef __FILTERATMETSCORE_H__
#define __FILTERATMETSCORE_H__

#include <filters/filterRealProperty.h>
#include <filters/filterMolwt.h>
#include <filters/filterLogp.h>




class FilterAdmetScore: public FilterRealProperty 
{
   protected:
   
      FilterLogp                    _logp;
      
      
   public:
   
      FilterAdmetScore(void);
      virtual ~FilterAdmetScore(void);
      FilterAdmetScore(const FilterAdmetScore&);
      FilterAdmetScore& operator=(const FilterAdmetScore&);

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
