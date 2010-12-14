/**********************************************************************
filterLigandEfficiency.cpp - Sieve
 
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



#include <filters/filterLigandEfficiency.h>



FilterLigandEfficiency::FilterLigandEfficiency(void)
{
   _keyword = "LIGAND_EFFICIENCY";
}



FilterLigandEfficiency::~FilterLigandEfficiency(void)
{
}



FilterLigandEfficiency::FilterLigandEfficiency(const FilterLigandEfficiency& f)
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
   
   // Own class
   _tpsa = f._tpsa;
   _hba = f._hba;
   _hcr = f._hcr;
}



FilterLigandEfficiency&
FilterLigandEfficiency::operator=(const FilterLigandEfficiency& f)
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
   
   // Own class
   _tpsa = f._tpsa;
   _hba = f._hba;
   _hcr = f._hcr;

   // Return
   return *this;
}



void
FilterLigandEfficiency::Calculate(OpenBabel::OBMol* mol)
{
   // HeteroCarbonRatio
   unsigned int carbon(0);
   for(OpenBabel::OBMolAtomIter atom(mol); atom; ++atom)
   {
      if (atom->IsCarbon()) ++carbon;
   }
   _hcr.Calculate(mol);
   double HeteroCarbonRatio(0.0);
   if (carbon)
   {
      HeteroCarbonRatio = _hcr.Result();
   }
   
   // HbondAcceptors
   _hba.Calculate(mol);
   double HbondAcceptors = (double) _hba.Result();
   
   // Tpsa
   _tpsa.Calculate(mol);
   double Tpsa = _tpsa.Result();
   
   // Ln(NumAtoms)
   double lnAtoms = (double) mol->NumHvyAtoms();
   lnAtoms = log(lnAtoms);
   
   // Ligand efficiency
   _result =  +1.4903096;
   _result += -0.0130163 * HbondAcceptors;
   _result += +0.0848970 * HeteroCarbonRatio;
   _result += +0.0036336 * Tpsa;
   _result += -0.3155732 * lnAtoms;
   _result += -0.0140382 * (Tpsa / lnAtoms);
   
   if ((_minLimit && (_result < _min)) || (_maxLimit && (_result > _max)))
   {
      _passed = false;
   }
   else
   {
      _passed = true;
   }
}



