/**********************************************************************
filterElements.h - Sieve
 
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



#ifndef __FILTERELEMENTS_H__
#define __FILTERELEMENTS_H__

#include <filters/filter.h>



class FilterElements: public Filter 
{
   
   protected:
      
      std::set<std::string>      _elements;
      std::set<std::string>      _validElements;
      std::string                _result;
      std::vector<std::string>   _number2symbol;
   
   public:
   
      FilterElements(void);
      virtual ~FilterElements(void);
      FilterElements(const FilterElements&);
      FilterElements& operator=(const FilterElements&);

      virtual bool            Initialise(const std::string&, const bool);
      
      virtual std::string     FailMessage(const OpenBabel::OBMol*) const;
      virtual std::string     Result(void) const;

      virtual void            Calculate(OpenBabel::OBMol*) = 0;
};



#endif
