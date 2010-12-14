/**********************************************************************
filterHbondAcceptors.cpp - Sieve
 
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



#include <filters/filterHbondAcceptors.h>



FilterHbondAcceptors::FilterHbondAcceptors(void)
{
   _keyword = "HBOND_ACCEPTORS";
}



FilterHbondAcceptors::~FilterHbondAcceptors(void)
{
}



FilterHbondAcceptors::FilterHbondAcceptors(const FilterHbondAcceptors& f)
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



FilterHbondAcceptors&
FilterHbondAcceptors::operator=(const FilterHbondAcceptors& f)
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
FilterHbondAcceptors::Calculate(OpenBabel::OBMol* mol)
{
   _result = 0;
   for(OpenBabel::OBMolAtomIter atom(mol); atom; ++atom)
   {
      if (atom->IsNitrogen() &&              // Nitrogen
         !atom->IsAromatic() &&              // Aliphatic
         !atom->IsAmideNitrogen() &&         // No amide N
         ((atom->GetImplicitValence() - atom->GetHvyValence()) == 0) &&    // No H
         (atom->GetFormalCharge() <= 0))     // No + charge
      {
         ++_result;
         continue;
      }
      if (atom->IsNitrogen() &&              // Nitrogen
          atom->IsAromatic() &&              // Aromatic
         ((atom->GetImplicitValence() - atom->GetHvyValence()) == 0) &&    // No H
         (atom->GetHvyValence() <= 2) &&     // Maximal two non-H atoms connected
         (atom->GetFormalCharge() <= 0))     // No + charge
      {
         ++_result;
         continue;
      }
      if (atom->IsOxygen() &&                // Oxygen
         (atom->GetFormalCharge() <= 0))     // No + charge
      {
         ++_result;
         continue;
      }
      if (atom->IsSulfur() &&                // Sulfur
         (atom->GetFormalCharge() <= 0) &&   // No + charge
         (atom->GetHyb() == 2))  // sp2
      {
         ++_result;
         continue;
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


