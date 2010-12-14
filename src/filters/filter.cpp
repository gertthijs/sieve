/**********************************************************************
filter.cpp - Sieve
 
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



#include <filters/filter.h>



Filter::Filter(void)
: _initialised(false)
, _whiteSpace("\n\t \r")
, _passed(false)
, _keyword("")
{
}



Filter::~Filter(void)
{
}



Filter::Filter(const Filter& f)
{
   // Filter class members
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
}



Filter&
Filter::operator=(const Filter& f)
{
   // Filter class members
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;

   return *this;
}



std::string
Filter::Keyword(void) const
{
   return _keyword;
}



bool
Filter::IsInitialised(void) const
{
   return _initialised;
}



bool
Filter::HasPassed(void) const
{
   return _passed;
}



bool
Filter::HasFailed(void) const
{
   return !_passed;
}

