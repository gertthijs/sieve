/**********************************************************************
filterElementsOnly.cpp - Sieve
 
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



#include <filters/filterElementsOnly.h>



FilterElementsOnly::FilterElementsOnly(void)
{
   _keyword = "ONLY_ELEMENTS";
}



FilterElementsOnly::~FilterElementsOnly(void)
{
}



FilterElementsOnly::FilterElementsOnly(const FilterElementsOnly& f)
{
   // Filter class members
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
   
   // FilterElements class members
   _elements = f._elements;
   _validElements = f._validElements;
   _result = f._result;
   _number2symbol = f._number2symbol;
   
   // FilterElementsOnly class members
}



FilterElementsOnly&
FilterElementsOnly::operator=(const FilterElementsOnly& f)
{
   // Filter class members
   _initialised = f._initialised;
   _whiteSpace = f._whiteSpace;
   _passed = f._passed;
   _keyword = f._keyword;
   
   // FilterElements class members
   _elements = f._elements;
   _validElements = f._validElements;
   _result = f._result;
   _number2symbol = f._number2symbol;
   
   // FilterElementsOnly class members

   // Return
   return *this;
}



void
FilterElementsOnly::Calculate(OpenBabel::OBMol* mol)
{
   // Store the molecular formula as result
   _result = mol->GetFormula();
   
   // Molecule is empty -> fails
   if (!mol->NumAtoms())
   {
      _result = "NA";
      _passed = false;
      return;
   }
   else
   {
      unsigned int number;
      for(OpenBabel::OBMolAtomIter atom(mol); atom; ++atom)
      {
         number = atom->GetAtomicNum();
         if (!_elements.count(_number2symbol[number]))
         {
            _passed = false;
            return;
         }
      }
            
      // Take care of implicit hydrogens
      if (!_elements.count("H"))
      {
         for(OpenBabel::OBMolAtomIter atom(mol); atom; ++atom)
         {
            if (atom->ImplicitHydrogenCount())
            {
               _passed = false;
               return;
            }
         }
      }

   }
   
   // Molecule passes
   _passed = true;
}
