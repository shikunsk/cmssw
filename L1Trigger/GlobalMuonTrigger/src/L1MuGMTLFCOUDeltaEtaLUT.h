//-------------------------------------------------
//
/** \class L1MuGMTLFCOUDeltaEtaLUT
 *
 *   LFCOUDeltaEta look-up table
 *          
 *   this class was automatically generated by 
 *     L1MuGMTLUT::MakeSubClass()  
*/ 
//
//   Author :
//   H. Sakulin            HEPHY Vienna
//
//   Migrated to CMSSW:
//   I. Mikulec
//
//--------------------------------------------------
#ifndef L1TriggerGlobalMuonTrigger_L1MuGMTLFCOUDeltaEtaLUT_h
#define L1TriggerGlobalMuonTrigger_L1MuGMTLFCOUDeltaEtaLUT_h

//---------------
// C++ Headers --
//---------------


//----------------------
// Base Class Headers --
//----------------------
#include "L1Trigger/GlobalMuonTrigger/src/L1MuGMTLUT.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//              ---------------------
//              -- Class Interface --
//              ---------------------


class L1MuGMTLFCOUDeltaEtaLUT : public L1MuGMTLUT {
  
 public:
  enum {DTCSC, CSCDT, CSCbRPC, DTfRPC};

  /// constuctor using function-lookup
  L1MuGMTLFCOUDeltaEtaLUT() : L1MuGMTLUT("LFCOUDeltaEta", 
				       "DTCSC CSCDT CSCbRPC DTfRPC",
				       "eta1(4) eta2(4)",
				       "delta_eta(4)", 8, true) {
    InitParameters();
  } ;

  /// destructor
  virtual ~L1MuGMTLFCOUDeltaEtaLUT() {};

  /// specific lookup function for delta_eta
  unsigned SpecificLookup_delta_eta (int idx, unsigned eta1, unsigned eta2) const {
    std::vector<unsigned> addr(2);
    addr[0] = eta1;
    addr[1] = eta2;
    return Lookup(idx, addr) [0];
  };

  /// specific lookup function for entire output field
  unsigned SpecificLookup (int idx, unsigned eta1, unsigned eta2) const {
    std::vector<unsigned> addr(2);
    addr[0] = eta1;
    addr[1] = eta2;
    return LookupPacked(idx, addr);
  };



  /// access to lookup function with packed input and output

  virtual unsigned LookupFunctionPacked (int idx, unsigned address) const {
    std::vector<unsigned> addr = u2vec(address, m_Inputs);
    return TheLookupFunction(idx ,addr[0] ,addr[1]);

  };

 private:
  /// Initialize scales, configuration parameters, alignment constants, ...
  void InitParameters();

  /// The lookup function - here the functionality of the LUT is implemented
  unsigned TheLookupFunction (int idx, unsigned eta1, unsigned eta2) const;

};
#endif



















