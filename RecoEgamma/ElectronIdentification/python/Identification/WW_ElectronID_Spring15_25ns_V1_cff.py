from PhysicsTools.SelectorUtils.centralIDRegistry import central_id_registry

# Common functions and classes for ID definition are imported here.
# It is a copy of the standard one with the extra things for the WW ID.
from RecoEgamma.ElectronIdentification.Identification.WW_ElectronID_tools import *

# Fakable working point Barrel and Endcap
idName = "WW-ElectronID-Spring15-25ns-V1-triggerpresel"
WP_Fakable_EB = WW_WorkingPoint_V1(
    idName,   # idName
    0.01  ,   # dEtaInCut
    0.04  ,   # dPhiInCut
    0.011 ,   # full5x5_sigmaIEtaIEtaCut
    0.08  ,   # hOverECut
    0.1   ,   # dxyCut
    0.373 ,   # dzCut
    0.01  ,   # absEInverseMinusPInverseCut
    10000.0   ,   # relCombIsolationWithEALowPtCut
    10000.0   ,   # relCombIsolationWithEAHighPtCut
              # conversion veto cut needs no parameters, so not mentioned
    2     ,   # missingHitsCut
    0.45  ,   # EcalPFClusterIso/pt
    0.25  ,   # HcalPFClusterIso/pt
    0.2       # TrackIso/pt 
    )

WP_Fakable_EE = WW_WorkingPoint_V1(
    idName,   # idName
    0.01  ,   # dEtaInCut
    0.08  ,   # dPhiInCut
    0.031 ,   # full5x5_sigmaIEtaIEtaCut
    0.08  ,   # hOverECut
    0.2   ,   # dxyCut
    0.602 ,   # dzCut
    0.01  ,   # absEInverseMinusPInverseCut
    10000.0   ,   # relCombIsolationWithEALowPtCut
    10000.0   ,   # relCombIsolationWithEAHighPtCut
              # conversion veto cut needs no parameters, so not mentioned
    1     ,   # missingHitsCut
    0.45  ,   # EcalPFClusterIso/pt
    0.25  ,   # HcalPFClusterIso/pt
    0.2       # TrackIso/pt 
    )

# Medium working point Barrel and Endcap
idName = "WW-ElectronID-Spring15-25ns-V1-triggerpresel-medium"
WP_Medium_EB = WW_WorkingPoint_V1(
    idName , # idName
    0.01, # dEtaInCut
    0.0336 , # dPhiInCut
    0.0101 , # full5x5_sigmaIEtaIEtaCut
    0.08   , # hOverECut
    0.0118 , # dxyCut
    0.373  , # dzCut
    0.01   , # absEInverseMinusPInverseCut
    0.0766 , # relCombIsolationWithEALowPtCut
    0.0766 , # relCombIsolationWithEAHighPtCut
    # conversion veto cut needs no parameters, so not mentioned
    2      ,  # missingHitsCut
    0.45   ,  # EcalPFClusterIso/pt
    0.25   ,  # HcalPFClusterIso/pt
    0.2       # TrackIso/pt 
    )

WP_Medium_EE = WW_WorkingPoint_V1(
    idName  , # idName
    0.00733 , # dEtaInCut
    0.08    , # dPhiInCut
    0.0283  , # full5x5_sigmaIEtaIEtaCut
    0.0678  , # hOverECut
    0.0739  , # dxyCut
    0.602   , # dzCut
    0.01    , # absEInverseMinusPInverseCut
    0.0678  , # relCombIsolationWithEALowPtCut
    0.0678  , # relCombIsolationWithEAHighPtCut
    # conversion veto cut needs no parameters, so not mentioned
    1       , # missingHitsCut
    0.45    , # EcalPFClusterIso/pt
    0.25    , # HcalPFClusterIso/pt
    0.2       # TrackIso/pt 
    )

# Tight working point Barrel and Endcap
idName = "WW-BasedElectronID-Spring15-25ns-V1-triggerpresel-tight"
WP_Tight_EB = WW_WorkingPoint_V1(
    idName   , # idName
    0.00926  , # dEtaInCut
    0.0336   , # dPhiInCut
    0.0101   , # full5x5_sigmaIEtaIEtaCut
    0.0597   , # hOverECut
    0.0111   , # dxyCut
    0.0466   , # dzCut
    0.01     , # absEInverseMinusPInverseCut
    0.0354   , # relCombIsolationWithEALowPtCut
    0.0354   , # relCombIsolationWithEAHighPtCut
    # conversion veto cut needs no parameters, so not mentioned
    2        , # missingHitsCut
    0.45     , # EcalPFClusterIso/pt
    0.25     , # HcalPFClusterIso/pt
    0.2        # TrackIso/pt 
    )

WP_Tight_EE = WW_WorkingPoint_V1(
    idName  , # idName
    0.00724 , # dEtaInCut
    0.08    , # dPhiInCut
    0.0279  , # full5x5_sigmaIEtaIEtaCut
    0.0615  , # hOverECut
    0.0351  , # dxyCut
    0.417   , # dzCut
    0.00999 , # absEInverseMinusPInverseCut
    0.0646  , # relCombIsolationWithEALowPtCut
    0.0646  , # relCombIsolationWithEAHighPtCut
    # conversion veto cut needs no parameters, so not mentioned
    1       , # missingHitsCut
    0.45    , # EcalPFClusterIso/pt
    0.25    , # HcalPFClusterIso/pt
    0.2       # TrackIso/pt 
    )

# Second, define what effective areas to use for pile-up correction
isoInputs = IsolationCutInputs_V1(
    # phoIsolationEffAreas
    "RecoEgamma/ElectronIdentification/data/Spring15/effAreaElectrons_cone03_pfNeuHadronsAndPhotons_25ns.txt"
)


#
# Set up VID configuration for all cuts and working points
#

WW_ElectronID_Spring15_25ns_V1_triggerpresel = WW_configureVIDCutBasedEleID_V1(WP_Fakable_EB, WP_Fakable_EE, isoInputs)
WW_ElectronID_Spring15_25ns_V1_triggerpresel_medium = WW_configureVIDCutBasedEleID_V1(WP_Medium_EB, WP_Medium_EE, isoInputs)
WW_ElectronID_Spring15_25ns_V1_triggerpresel_tight = WW_configureVIDCutBasedEleID_V1(WP_Tight_EB, WP_Tight_EE, isoInputs)


# The MD5 sum numbers below reflect the exact set of cut variables
# and values above. If anything changes, one has to 
# 1) comment out the lines below about the registry, 
# 2) run "calculateMD5 <this file name> <one of the VID config names just above>
# 3) update the MD5 sum strings below and uncomment the lines again.
#

central_id_registry.register(WW_ElectronID_Spring15_25ns_V1_triggerpresel.idName,
                             '4d6ee9540ef03826aa6b21bd0f203301')
central_id_registry.register(WW_ElectronID_Spring15_25ns_V1_triggerpresel_medium.idName,
                             'f7a6ba796c303d23b6a52e9825297e00')
central_id_registry.register(WW_ElectronID_Spring15_25ns_V1_triggerpresel_tight.idName,
                             '6b0b868e1896a72fc96f65cd51c460be')


### for now until we have a database...
WW_ElectronID_Spring15_25ns_V1_triggerpresel.isPOGApproved        = cms.untracked.bool(False)
WW_ElectronID_Spring15_25ns_V1_triggerpresel_medium.isPOGApproved = cms.untracked.bool(False)
WW_ElectronID_Spring15_25ns_V1_triggerpresel_tight.isPOGApproved  = cms.untracked.bool(False)
