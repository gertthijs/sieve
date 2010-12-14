/**********************************************************************
filterAtomsInLargestRing.h - Sieve
 
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



#include <filters/filterAtomsInLargestRing.h>



FilterAtomsInLargestRing::FilterAtomsInLargestRing(void)
{
   _keyword = "ATOMS_IN_LARGEST_RING";
}



FilterAtomsInLargestRing::~FilterAtomsInLargestRing(void)
{
}



FilterAtomsInLargestRing::FilterAtomsInLargestRing(const FilterAtomsInLargestRing& f)
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



FilterAtomsInLargestRing&
FilterAtomsInLargestRing::operator=(const FilterAtomsInLargestRing& f)
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
FilterAtomsInLargestRing::Calculate(OpenBabel::OBMol* mol)
{
   // Get the number of atoms in the smallest rings
   _result = 0;
   bool rings(false);
   for(OpenBabel::OBMolAtomIter atom(mol); atom; ++atom)
   {
      if (atom->IsInRing())
      {
         rings = true;
         if (atom->MemberOfRingSize() > _result) _result = atom->MemberOfRingSize();
      }
   }

   if (rings)
   {
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
      _passed = true;
   }
}



