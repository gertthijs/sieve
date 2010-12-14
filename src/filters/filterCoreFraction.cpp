/**********************************************************************
filterCoreFraction.cpp - Sieve
 
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



#include <filters/filterCoreFraction.h>



FilterCoreFraction::FilterCoreFraction(void)
{
   _keyword = "CORE_FRACTION";
}



FilterCoreFraction::~FilterCoreFraction(void)
{
}



FilterCoreFraction::FilterCoreFraction(const FilterCoreFraction& f)
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



FilterCoreFraction&
FilterCoreFraction::operator=(const FilterCoreFraction& f)
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
FilterCoreFraction::Calculate(OpenBabel::OBMol* mol)
{
   OpenBabel::OBAtom* atom;
   std::vector<OpenBabel::OBAtom*>::iterator i;
   bool rings(false);
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
      // Make workcopy of original mol
      OpenBabel::OBMol m = *mol; m.DeleteHydrogens();
      unsigned int natoms(m.NumAtoms());
      if (!natoms)
      {
         _result = 0.0;
         _passed = false;
         return;
      }
   
      // Iteratively remove all endstanding atoms until none are left
      OpenBabel::OBAtom* atom;
      std::vector<OpenBabel::OBAtom*>::iterator i;
      bool endstanding(true);
      while (endstanding && m.NumAtoms())
      {
         endstanding = false;
         for (atom = m.BeginAtom(i); atom; atom = m.NextAtom(i))
         {
            if (atom->GetValence() < 2)
            {
               if (m.DeleteAtom(atom))
               {
                  endstanding = true;
                  break;
               }
            }
         }
      }

      _result = (double) m.NumAtoms() / (double) natoms;
   }
   else
   {
      _result = 0.0;
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






