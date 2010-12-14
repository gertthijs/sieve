#ifndef __FINGERPRINT_H__
#define __FINGERPRINT_H__

#include <openbabel/fingerprint.h> 
#include <openbabel/mol.h>

class Fingerprint
{
public:
  Fingerprint(const char* id = NULL)
  {
    //When id is empty or NULL the default fingerprint, currently FP2, is used.
    _obfpt = OpenBabel::OBFingerprint::FindType(id);
  }

  virtual void CalculateFP(OpenBabel::OBMol* mol, std::vector<unsigned int> & fp)
  {
    _obfpt->GetFingerprint(mol, fp);
  }

  static double Tanimoto(const std::vector<unsigned int>& fp1, const std::vector<unsigned int>& fp2)
  {
    return OpenBabel::OBFingerprint::Tanimoto(fp1, fp2);
  }

private:
   OpenBabel::OBFingerprint* _obfpt;
};


#endif
