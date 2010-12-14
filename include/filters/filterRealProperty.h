/**********************************************************************
filterRealProperty.h - Sieve
 
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



#ifndef __FILTERREALPROPERTY_H__
#define __FILTERREALPROPERTY_H__

#include <filters/filter.h>



class FilterRealProperty: public Filter 
{
   protected:
      
      double                  _min;
      double                  _max;
      bool                    _minLimit;
      bool                    _maxLimit;
      double                  _result;
   
   public:
   
      FilterRealProperty(void);
      virtual ~FilterRealProperty(void);
      FilterRealProperty(const FilterRealProperty&);
      FilterRealProperty& operator=(const FilterRealProperty&);

      virtual bool            Initialise(const std::string&, const bool);
      
      virtual std::string     FailMessage(const OpenBabel::OBMol*) const;
      virtual double          Result(void) const;

      virtual void            Calculate(OpenBabel::OBMol*) = 0;
};



#endif
