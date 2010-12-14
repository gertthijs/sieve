/**********************************************************************
filterHeteroCarbonRatio.cpp - Sieve
 
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



#include <filters/filterHeteroCarbonRatio.h>



FilterHeteroCarbonRatio::FilterHeteroCarbonRatio(void)
{
   _keyword = "HETERO_CARBON_RATIO";
}



FilterHeteroCarbonRatio::~FilterHeteroCarbonRatio(void)
{
}



FilterHeteroCarbonRatio::FilterHeteroCarbonRatio(const FilterHeteroCarbonRatio& f)
{
   // Filter class members
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
   
   // FilterRealProperty class members
   _min = f._min;
   _max = f._max;
   _minLimit = f._minLimit;
   _maxLimit = f._maxLimit;
   _result = f._result;
}



FilterHeteroCarbonRatio&
FilterHeteroCarbonRatio::operator=(const FilterHeteroCarbonRatio& f)
{
   // Filter class members
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
   
   // FilterRealProperty class members
   _min = f._min;
   _max = f._max;
   _minLimit = f._minLimit;
   _maxLimit = f._maxLimit;
   _result = f._result;

   // Return
   return *this;
}



void
FilterHeteroCarbonRatio::Calculate(OpenBabel::OBMol* mol)
{
   unsigned int hetero(0);
   unsigned int carbon(0);
   for(OpenBabel::OBMolAtomIter atom(mol); atom; ++atom)
   {
      if (!atom->IsHydrogen() && !atom->IsCarbon())
      {
         ++hetero;
      }
      else if (atom->IsCarbon())
      {
         ++carbon;
      }
   }

   if (carbon)
   {
      _result = (double) hetero / (double) carbon;
      if ((_minLimit && (_result < _min)) || (_maxLimit && (_result > _max)))
      {
         _passed = false;
      }
      else
      {
         _passed = true;
      }
   }
   else
   {
      _result = 0;
      _passed = false;
   }
}

