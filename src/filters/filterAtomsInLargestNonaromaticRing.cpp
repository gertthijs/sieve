/**********************************************************************
filterAtomsInLargestNonaromaticRing.h - Sieve
 
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



#include <filters/filterAtomsInLargestNonaromaticRing.h>



FilterAtomsInLargestNonaromaticRing::FilterAtomsInLargestNonaromaticRing(void)
{
   _keyword = "ATOMS_IN_LARGEST_NONAROMATIC_RING";
}



FilterAtomsInLargestNonaromaticRing::~FilterAtomsInLargestNonaromaticRing(void)
{
}



FilterAtomsInLargestNonaromaticRing::FilterAtomsInLargestNonaromaticRing(const FilterAtomsInLargestNonaromaticRing& f)
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



FilterAtomsInLargestNonaromaticRing&
FilterAtomsInLargestNonaromaticRing::operator=(const FilterAtomsInLargestNonaromaticRing& f)
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
FilterAtomsInLargestNonaromaticRing::Calculate(OpenBabel::OBMol* mol)
{
   // Are there rings?
   bool rings(false);
   OpenBabel::OBAtom* atom;
   std::vector<OpenBabel::OBAtom*>::iterator i;
   for (atom = mol->BeginAtom(i); atom; atom = mol->NextAtom(i))
   {
      if (atom->IsInRing())
      {
         rings = true;
         break;
      }
   }

   if (rings)
   {
      std::vector<OpenBabel::OBRing*> nrings = mol->GetSSSR();
      _result = 0;
      std::vector<OpenBabel::OBRing*>::iterator ri;
      for (ri = nrings.begin(); ri != nrings.end(); ++ri)
      {
         if ( !(*ri)->IsAromatic() && ((*ri)->Size() > _result))
         {
            _result = (*ri)->Size();
         }
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
   else
   {
      _result = 0;
      _passed = true;
   }
}



