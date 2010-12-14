/**********************************************************************
filterRigidBonds.h - Sieve
 
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



#include <filters/filterRigidBonds.h>



FilterRigidBonds::FilterRigidBonds(void)
{
   _keyword = "RIGID_BONDS";
}



FilterRigidBonds::~FilterRigidBonds(void)
{
}



FilterRigidBonds::FilterRigidBonds(const FilterRigidBonds& f)
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



FilterRigidBonds&
FilterRigidBonds::operator=(const FilterRigidBonds& f)
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
FilterRigidBonds::Calculate(OpenBabel::OBMol* mol)
{
   _result = 0;
   for(OpenBabel::OBMolBondIter bond(mol); bond; ++bond)
   {
      if ( bond->IsInRing() ) continue;
      
      if ( (bond->IsDouble()) || // double; or
           
           (bond->IsTriple()) || // triple; or
           
           (bond->IsSecondaryAmide() ) // secondary amide
         )
      {
         // Not endstanding or bond to H
         if ((bond->GetBeginAtom()->GetHvyValence() > 1) &&
             (bond->GetEndAtom()->GetHvyValence() > 1) &&
             (bond->GetBeginAtom()->GetAtomicNum() > 1) &&
             (bond->GetEndAtom()->GetAtomicNum() > 1))
         {
            ++_result;
         }
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



