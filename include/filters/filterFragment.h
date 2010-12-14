/**********************************************************************
filterFragment.h - Sieve
 
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



#ifndef __FILTERFRAGMENT_H__
#define __FILTERFRAGMENT_H__

#include <filters/filter.h>



class FilterFragment: public Filter 
{
   protected:

      std::string             _smarts;
      OpenBabel::OBSmartsPattern     _ss;
      std::string             _name;
      int                     _min;
      int                     _max;
      bool                    _minLimit;
      bool                    _maxLimit;
      unsigned int            _result;

   public:

      FilterFragment(void);
      virtual ~FilterFragment(void);
      FilterFragment(const FilterFragment&);
      FilterFragment& operator=(const FilterFragment&);

      virtual bool            Initialise(const std::string&, const bool);

      virtual std::string     Name(void) const;

      virtual std::string     FailMessage(const OpenBabel::OBMol*) const;
      virtual unsigned int    Result(void) const;

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
