/**********************************************************************
filterSimilarityStack.h - Sieve
 
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



#ifndef __FILTERSIMILARITYSTACK_H__
#define __FILTERSIMILARITYSTACK_H__

#include <filters/filterSimilarity.h>



class FilterSimilarityStack: public FilterSimilarity 
{
   protected:
      
   public:
   
      FilterSimilarityStack(void);
      virtual ~FilterSimilarityStack(void);
      FilterSimilarityStack(const FilterSimilarityStack&);
      FilterSimilarityStack& operator=(const FilterSimilarityStack&);

      virtual bool            Initialise(const std::string&, const bool);

      virtual double          GetMin(void) const;
      virtual double          GetMax(void) const;
      virtual bool            GetMinLimit(void) const;
      virtual bool            GetMaxLimit(void) const;
      
      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
