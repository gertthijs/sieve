/**********************************************************************
filterDistance.h - Sieve
 
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



#ifndef __FILTERDISTANCE_H__
#define __FILTERDISTANCE_H__

#include <filters/filter.h>



struct Pattern
{
   // Initialised at reading of filter file
   std::string                name;
   std::string                smartsName;
   OpenBabel::OBSmartsPattern smarts;
   std::vector<unsigned int>  indices;
   
   // Updated by PostProcess() method
   unsigned int               maxConnections;
   
   // Updated by Calculate() method
   unsigned int               nMatches;
   std::vector<double>        x;                // size = nMatches
   std::vector<double>        y;                // size = nMatches
   std::vector<double>        z;                // size = nMatches
   std::vector<unsigned int>  foundConnections; // size = nMatches
};



struct Distance
{
   // Initialised at reading of filter file
   std::string                bPatternName;
   std::string                ePatternName;
   double                     min;
   double                     max;
   bool                       minLimit;
   bool                       maxLimit;
   
   // Updated by PostProcess() method
   Pattern*                   bPattern;
   Pattern*                   ePattern;
};



class FilterDistance: public Filter 
{
   protected:
      
      bool                    _result;
      std::set<Pattern*>      _patterns;
      std::vector<Distance*>  _distances;
      OpenBabel::OBMol        _molFailed;
      std::string             _msg;
      
      virtual bool            DistanceWithinLimits(Distance*, unsigned int, unsigned int);
      
   public:

      FilterDistance(void);
      virtual ~FilterDistance(void);
      FilterDistance(const FilterDistance&);
      FilterDistance& operator=(const FilterDistance&);

      virtual bool            Initialise(const std::string&, const bool);
      virtual void            PostProcess(void);

      virtual std::string     FailMessage(const OpenBabel::OBMol*) const;
      virtual bool            Result(void) const;

      virtual void            Calculate(OpenBabel::OBMol*);
};



#endif
