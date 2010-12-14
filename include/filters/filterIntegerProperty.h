/**********************************************************************
filterIntegerProperty.h - Sieve
 
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



#ifndef __FILTERINTEGERPROPERTY_H__
#define __FILTERINTEGERPROPERTY_H__

#include <filters/filter.h>



class FilterIntegerProperty: public Filter 
{
   protected:
      
      int                     _min;
      int                     _max;
      bool                    _minLimit;
      bool                    _maxLimit;
      int                     _result;
         
   public:
   
      FilterIntegerProperty(void);
      virtual ~FilterIntegerProperty(void);
      FilterIntegerProperty(const FilterIntegerProperty&);
      FilterIntegerProperty& operator=(const FilterIntegerProperty&);

      virtual bool            Initialise(const std::string&, const bool);
      
      virtual std::string     FailMessage(const OpenBabel::OBMol*) const;
      virtual int             Result(void) const;

      virtual void            Calculate(OpenBabel::OBMol*) = 0;
};



#endif
