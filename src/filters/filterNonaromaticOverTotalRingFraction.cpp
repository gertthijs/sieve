/**********************************************************************
filterNonaromaticOverTotalRingFraction.cpp - Sieve
 
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



#include <filters/filterNonaromaticOverTotalRingFraction.h>



FilterNonaromaticOverTotalRingFraction::FilterNonaromaticOverTotalRingFraction(void)
{
   _keyword = "NONAROMATIC_OVER_TOTAL_RING_FRACTION";
}



FilterNonaromaticOverTotalRingFraction::~FilterNonaromaticOverTotalRingFraction(void)
{
}



FilterNonaromaticOverTotalRingFraction::FilterNonaromaticOverTotalRingFraction(const FilterNonaromaticOverTotalRingFraction& f)
{
   // Filter class members
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
   
   // FilterIntegerProperty class members
   _min = f._min;
   _max = f._max;
   _minLimit = f._minLimit;
   _maxLimit = f._maxLimit;
   _result = f._result;
}



FilterNonaromaticOverTotalRingFraction&
FilterNonaromaticOverTotalRingFraction::operator=(const FilterNonaromaticOverTotalRingFraction& f)
{
   // Filter class members
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
   
   // FilterIntegerProperty class members
   _min = f._min;
   _max = f._max;
   _minLimit = f._minLimit;
   _maxLimit = f._maxLimit;
   _result = f._result;

   // Return
   return *this;
}



void
FilterNonaromaticOverTotalRingFraction::Calculate(OpenBabel::OBMol* mol)
{
   // Are there atoms and rings?
   unsigned int rings(0);
   unsigned int natoms(0);
   OpenBabel::OBAtom* atom;
   std::vector<OpenBabel::OBAtom*>::iterator i;
   for (atom = mol->BeginAtom(i); atom; atom = mol->NextAtom(i))
   {
      if (atom->IsHydrogen()) continue;
      if (atom->IsInRing()) ++rings;
      ++natoms;
   }
   if (!natoms)
   {
      _result = 0.0;
      _passed = false;
      return;
   }
   
   unsigned int ar(0);
   unsigned int to(0);
   if (rings)
   {
      std::vector<OpenBabel::OBRing*> nrings = mol->GetSSSR();
      std::vector<OpenBabel::OBRing*>::iterator ri;
      for (ri = nrings.begin(); ri != nrings.end(); ++ri)
      {
         if (!(*ri)->IsAromatic())
         {
            ++ar;
         }
         ++to;
      }
   }
   if (!to)
   {
      _result = 0.0;
      _passed = false;
      return;
   }
   else
   {
      _result = (double) ar / (double) to;
   }
   
   if ((_minLimit && (_result < _min)) || (_maxLimit && (_result > _max)))
   {
      _passed = false;
   }
   else
   {
      _passed = true;
   }
}




