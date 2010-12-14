/**********************************************************************
filterSdfTagValue.h - Sieve
 
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



#ifndef __FILTERSDFTAGVALUE_H__
#define __FILTERSDFTAGVALUE_H__

#include <filters/filterSdf.h>



class FilterSdfTagValue: public FilterSdf
{
   protected:
      
      double                  _min;
      double                  _max;
      double                  _result;
      bool                    _noTag;
      
      bool                    _tabulate;
      std::string             _tagvalue;
   
   public:
   
      FilterSdfTagValue(void);
      virtual ~FilterSdfTagValue(void);
      FilterSdfTagValue(const FilterSdfTagValue&);
      FilterSdfTagValue& operator=(const FilterSdfTagValue&);

      virtual bool            Initialise(const std::string&, const bool);
      
      virtual std::string     FailMessage(const OpenBabel::OBMol*) const;
      virtual double          Result(void) const;
      virtual std::string     ResultAsString(void) const;

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
