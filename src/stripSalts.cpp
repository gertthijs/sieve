/**********************************************************************
stripSalts.h - Sieve
 
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


November 3, 2010:

This is a temporary replacement function to replace the OBMol::StripSalts()
method that contains a bug in OB 2.3.0 release. In this 2.3.0 release, calling
the OBSmartsPattern::Match() method after that a OBMol::StripSalts() method
was called caused in some cases a crash. This was the case when molecules
containing salts were processed.

As soon as an updated OB 2.3.x release comes out, this function can be removed
and the original code can be restored.


***********************************************************************/



#include "stripSalts.h"

#include <vector>
#include <set>
#include <list>
#include <openbabel/obconversion.h>
#include <openbabel/mol.h>
#include <openbabel/bitvec.h>


bool StripSalts(OpenBabel::OBMol* mol)
{
   // Initiate bit vector and vector of atom pointers
   std::vector<OpenBabel::OBAtom*> atoms;
   OpenBabel::OBAtom* atom;
   std::vector<OpenBabel::OBAtom*>::iterator avi;
   for (atom = mol->BeginAtom(avi); atom; atom = mol->NextAtom(avi))
   {
      atoms.push_back(atom);
   }
   std::vector<OpenBabel::OBBitVec*> ct;
   for (unsigned int i(0); i < atoms.size(); ++i)
   {
      ct.push_back(new OpenBabel::OBBitVec(atoms.size()));
   }
   
   // Set the bits of connected atoms to on
   for (unsigned int i(0); i < atoms.size(); ++i)
   {
      for (unsigned int j(i+1); j < atoms.size(); ++j)
      {
         if (atoms[i]->IsConnected(atoms[j]))
         {
            ct[i]->SetBitOn(i);
            ct[i]->SetBitOn(j);
            ct[j]->SetBitOn(i);
            ct[j]->SetBitOn(j);
         }
      }
   }
   
   // Fill in the remaining connections
   OpenBabel::OBBitVec result(atoms.size());
   for (unsigned int i(0); i < atoms.size(); ++i)
   {
      for (unsigned int j(0); j < atoms.size(); ++j)
      {
         result = *(ct[i]) & *(ct[j]);
         if (!result.IsEmpty())
         {
            *(ct[i]) |= *(ct[j]);
            *(ct[j]) |= *(ct[i]);
         }
      }
   }
   
   // Keep only the unique bit vectors
   std::set<OpenBabel::OBBitVec> connectedGroups;
   for (unsigned int i(0); i < ct.size(); ++i)
   {
      connectedGroups.insert(*(ct[i]));
   }
   
   // Make a list of the atoms that should be deleted
   bool returnValue = false;
   if (connectedGroups.size() > 1)
   {
      std::list<OpenBabel::OBAtom*> toBeDeleted;
      toBeDeleted.clear();
      std::set<OpenBabel::OBBitVec>::iterator si;
      unsigned int max(0);
      for (si = connectedGroups.begin(); si != connectedGroups.end(); ++si)
      {
         if (si->CountBits() > max)
         {
            max = si->CountBits();
         }
      }
      for (si = connectedGroups.begin(); si != connectedGroups.end(); ++si)
      {
         if (si->CountBits() == max)
         {
            max = 0;    // In case there are more than one equal-sized largest
                        // fragments, take the first one
            continue;
         }
         else
         {
            for (int i(si->FirstBit()); i != -1; i = si->NextBit(i))
            {
               toBeDeleted.push_back(atoms[i]);
            }
         }
      }
   
      // Remove the atoms
      mol->BeginModify();
      std::list<OpenBabel::OBAtom*>::iterator li;
      for (li = toBeDeleted.begin(); li != toBeDeleted.end(); ++li)
      {
         mol->DeleteAtom(*li);
      }
      mol->EndModify();
      
      // Set return value
      returnValue = true;
   }

   // Return
   for (unsigned int i(0); i < atoms.size(); ++i)
   {
      delete ct[i];
      ct[i] = NULL;
   }
   return returnValue;
}
