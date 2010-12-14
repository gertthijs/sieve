/**********************************************************************
filterAbsorption.cpp - Sieve
 
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



#include <filters/filterAbsorption.h>



FilterAbsorption::FilterAbsorption(void)
{
   _keyword = "ABSORPTION";
}



FilterAbsorption::~FilterAbsorption(void)
{
}



FilterAbsorption::FilterAbsorption(const FilterAbsorption& f)
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
   
   // Own members
   _logp = f._logp;
   _tpsa = f._tpsa;
}



FilterAbsorption&
FilterAbsorption::operator=(const FilterAbsorption& f)
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
   
   // Own members
   _logp = f._logp;
   _tpsa = f._tpsa;

   // Return
   return *this;
}



void
FilterAbsorption::Calculate(OpenBabel::OBMol* mol)
{
   // Step 1
   _tpsa.Calculate(mol);
   _logp.Calculate(mol);
   double x(_tpsa.Result() * 4.05);
   double y(_logp.Result() * 116.5);
   
   // Step 2
   double f1(sqrt((x - 109.0)*(x - 109.0) + (y - 580.0)*(y - 580.0)));
   double f2(sqrt((x - 422.0)*(x - 422.0) + (y + 28.0)*(y + 28.0)));
   double f(f1 + f2);
   
   _result = (f <= 834.0) ? 1 : 0;
   
   if ((_minLimit && (_result < _min)) || (_maxLimit && (_result > _max)))
   {
      _passed = false;
   }
   else
   {
      _passed = true;
   }
}







