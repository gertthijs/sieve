/**********************************************************************
fingerprint.h - Sieve
 
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



#ifndef __FINGERPRINT_H__
#define __FINGERPRINT_H__


#include <set>
#include <vector>
#include <algorithm>

#include <openbabel/atom.h>
#include <openbabel/bond.h>
#include <openbabel/mol.h>



class Fingerprint
{
	protected:
   
      	unsigned int                        _bitsPerInt;
      	std::set<std::vector<int> >         _fragset;
      	std::set<std::vector<int> >         _ringset;
      
      	void  _getFragments(std::vector<int>, std::vector<int>, int,
                          OpenBabel::OBAtom*, OpenBabel::OBBond*);
      	void  _doRings(void);
      	void  _doReverses(void);
      	unsigned int _calcHash(const std::vector<int>&);
      	void  _setBit(std::vector<unsigned int>&, const unsigned int);

	public:
   
      	Fingerprint(void);
      	virtual ~Fingerprint(void);
      	Fingerprint(const Fingerprint&);
      	Fingerprint& operator=(const Fingerprint&);

      	virtual void CalculateFP(OpenBabel::OBMol* mol, std::vector<unsigned int> &);
		double Tanimoto(const std::vector<unsigned int>&, const std::vector<unsigned int>&);
};







#endif
