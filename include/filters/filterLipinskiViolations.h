/**********************************************************************
filterLipinskiViolations.h - Sieve
 
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



#ifndef __FILTERLIPINSKIVIOLATIONS_H__
#define __FILTERLIPINSKIVIOLATIONS_H__

#include <filters/filterIntegerProperty.h>
#include <filters/filterLipinskiAcceptors.h>
#include <filters/filterLipinskiDonors.h>
#include <filters/filterLogp.h>




class FilterLipinskiViolations: public FilterIntegerProperty 
{
   protected:
   
      FilterLipinskiAcceptors       _lpa;
      FilterLipinskiDonors          _lpd;
      FilterLogp                    _logp;
      
      
   public:
   
      FilterLipinskiViolations(void);
      virtual ~FilterLipinskiViolations(void);
      FilterLipinskiViolations(const FilterLipinskiViolations&);
      FilterLipinskiViolations& operator=(const FilterLipinskiViolations&);

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
