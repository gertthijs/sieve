/**********************************************************************
filterSdf.cpp - Sieve
 
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



#include <filters/filterSdf.h>



FilterSdf::FilterSdf(void)
: _minLimit(true)
, _maxLimit(true)
{
   _keyword = "TAG";
   _tagName.clear();
}



FilterSdf::~FilterSdf(void)
{
}



FilterSdf::FilterSdf(const FilterSdf& f)
{
   // Filter class members
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
   
   // FilterSdf class members
   _minLimit = f._minLimit;
   _maxLimit = f._maxLimit;
   _tagName = f._tagName;
}



FilterSdf&
FilterSdf::operator=(const FilterSdf& f)
{
   // Filter class members
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
   
   // FilterSdf class members
   _minLimit = f._minLimit;
   _maxLimit = f._maxLimit;
   _tagName = f._tagName;

   return *this;
}



std::string
FilterSdf::TagName(void) const
{
   return _tagName;
}
