/**********************************************************************
filterSidechains.cpp - Sieve
 
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



#include <filters/filterSidechains.h>



FilterSidechains::FilterSidechains(void)
{
   _keyword = "SIDECHAINS";
}



FilterSidechains::~FilterSidechains(void)
{
}



FilterSidechains::FilterSidechains(const FilterSidechains& f)
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



FilterSidechains&
FilterSidechains::operator=(const FilterSidechains& f)
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
FilterSidechains::Calculate(OpenBabel::OBMol* mol)
{
   // Rings?
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
      // Make working copies of mol
      OpenBabel::OBMol m1 = *mol; m1.DeleteHydrogens();
      OpenBabel::OBMol m2 = *mol; m2.DeleteHydrogens();
   
      // Create a mapping of the atoms between m1 and m2
      std::map<OpenBabel::OBAtom*, OpenBabel::OBAtom*> m1_2_m2;
      OpenBabel::OBAtom* a1;
      OpenBabel::OBAtom* a2;
      std::vector<OpenBabel::OBAtom*>::iterator i1;
      std::vector<OpenBabel::OBAtom*>::iterator i2;
      a1 = m1.BeginAtom(i1);
      a2 = m2.BeginAtom(i2);
      while (a1 && a2)
      {
         m1_2_m2[a1] = a2;
         a1 = m1.NextAtom(i1);
         a2 = m2.NextAtom(i2);
      }
      
      // Remove all endstanding atoms in m1
      std::set<OpenBabel::OBAtom*> sidechainAtoms;
      sidechainAtoms.clear();
      bool endstanding(true);
      while (endstanding)
      {
         endstanding = false;
         for (a1 = m1.BeginAtom(i1); a1; a1 = m1.NextAtom(i1))
         {
            if (a1->GetValence() < 2)
            {
               endstanding = true;
               sidechainAtoms.insert(m1_2_m2[a1]);
               m1.DeleteAtom(a1);
               break;
            }
         }
      }

      // Now remove the non-sidechain atoms of m2
      std::set<OpenBabel::OBAtom*> nonSidechainAtoms;
      nonSidechainAtoms.clear();
      for (a2 = m2.BeginAtom(i2); a2; a2 = m2.NextAtom(i2))
      {
         if (!sidechainAtoms.count(a2)) nonSidechainAtoms.insert(a2);
      }
      std::set<OpenBabel::OBAtom*>::iterator i;
      for (i = nonSidechainAtoms.begin(); i != nonSidechainAtoms.end(); ++i)
      {
         m2.DeleteAtom(*i);
      }
      
      // Separate
      if (!m2.NumAtoms())
      {
         _result = 0;
         return;
      }
      else
      {
         std::vector<std::vector<int > > sidechains;
         m2.ContigFragList(sidechains);
         _result = sidechains.size();
      }
   }
   else
   {
      _result = 0;
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





