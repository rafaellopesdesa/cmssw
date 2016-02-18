import FWCore.ParameterSet.Config as cms

# Barrel/endcap division in eta
ebCutOff = 1.479

# -----------------------------
# Version V1 WW definitions
# -----------------------------

class WW_WorkingPoint_V1:
    """
    This is a container class to hold numerical cut values for either
    the barrel or endcap set of cuts for electron cut-based ID
    """
    def __init__(self, 
                 idName,
                 dEtaInCut,
                 dPhiInCut,
                 full5x5_sigmaIEtaIEtaCut,
                 hOverECut,
                 dxyCut,
                 dzCut,
                 absEInverseMinusPInverseCut,
                 relCombIsolationWithEALowPtCut,
                 relCombIsolationWithEAHighPtCut,
                 # conversion veto cut needs no parameters, so not mentioned
                 missingHitsCut,
                 EcalPFClusterRelIso,
                 HcalPFClusterRelIso,
                 TrackRelIso
                 ):
        self.idName                       = idName                       
        self.dEtaInCut                    = dEtaInCut                   
        self.dPhiInCut                    = dPhiInCut                   
        self.full5x5_sigmaIEtaIEtaCut     = full5x5_sigmaIEtaIEtaCut    
        self.hOverECut                    = hOverECut                   
        self.dxyCut                       = dxyCut                      
        self.dzCut                        = dzCut                       
        self.absEInverseMinusPInverseCut  = absEInverseMinusPInverseCut 
        self.relCombIsolationWithEALowPtCut  = relCombIsolationWithEALowPtCut
        self.relCombIsolationWithEAHighPtCut = relCombIsolationWithEAHighPtCut
        # conversion veto cut needs no parameters, so not mentioned
        self.missingHitsCut               = missingHitsCut
        self.EcalPFClusterRelIso     = EcalPFClusterRelIso
        self.HcalPFClusterRelIso     = HcalPFClusterRelIso
        self.TrackRelIso             = TrackRelIso
        
class IsolationCutInputs_V1:
    """
    A container class that holds the name of the file with the effective 
    area constants for pile-up corrections
    """
    def __init__(self, 
                 neuHadAndPhoIsolationEffAreas
                 ):
                 self.neuHadAndPhoIsolationEffAreas    = neuHadAndPhoIsolationEffAreas


def WW_configureVIDCutBasedEleID_V1( wpEB, wpEE, isoInputs ):
    """
    This function configures the full cms.PSet for a VID ID and returns it.
    The inputs: two objects of the type WW_WorkingPoint_V1, one
    containing the cuts for the Barrel (EB) and the other one for the Endcap (EE).
    The third argument is an object that contains information necessary
    for isolation calculations.
    """
    # print "VID: Configuring cut set %s" % wpEB.idName
    parameterSet =  cms.PSet(
        #
        idName = cms.string( wpEB.idName ), # same name stored in the _EB and _EE objects
        cutFlow = cms.VPSet(
            cms.PSet( cutName = cms.string("MinPtCut"),
                      minPt = cms.double(5.0),
                      needsAdditionalProducts = cms.bool(False),
                      isIgnored = cms.bool(False)                ),
            cms.PSet( cutName = cms.string("GsfEleSCEtaMultiRangeCut"),
                      useAbsEta = cms.bool(True),
                      allowedEtaRanges = cms.VPSet( 
                    cms.PSet( minEta = cms.double(0.0), 
                              maxEta = cms.double(ebCutOff) ),
                    cms.PSet( minEta = cms.double(ebCutOff), 
                              maxEta = cms.double(2.5) )
                    ),
                      needsAdditionalProducts = cms.bool(False),
                      isIgnored = cms.bool(False)),
            cms.PSet( cutName = cms.string('GsfEleDEtaInCut'),
                      dEtaInCutValueEB = cms.double( wpEB.dEtaInCut ),
                      dEtaInCutValueEE = cms.double( wpEE.dEtaInCut ),
                      barrelCutOff = cms.double(ebCutOff),
                      needsAdditionalProducts = cms.bool(False),
                      isIgnored = cms.bool(False)),
            cms.PSet( cutName = cms.string('GsfEleDPhiInCut'),
                      dPhiInCutValueEB = cms.double( wpEB.dPhiInCut ),
                      dPhiInCutValueEE = cms.double( wpEE.dPhiInCut ),
                      barrelCutOff = cms.double(ebCutOff),
                      needsAdditionalProducts = cms.bool(False),
                      isIgnored = cms.bool(False)),
            cms.PSet( cutName = cms.string('GsfEleFull5x5SigmaIEtaIEtaCut'),
                      full5x5SigmaIEtaIEtaCutValueEB = cms.double( wpEB.full5x5_sigmaIEtaIEtaCut ),
                      full5x5SigmaIEtaIEtaCutValueEE = cms.double( wpEE.full5x5_sigmaIEtaIEtaCut ),
                      barrelCutOff = cms.double(ebCutOff),
                      needsAdditionalProducts = cms.bool(False),
                      isIgnored = cms.bool(False)),
            cms.PSet( cutName = cms.string('GsfEleHadronicOverEMCut'),
                      hadronicOverEMCutValueEB = cms.double( wpEB.hOverECut ),
                      hadronicOverEMCutValueEE = cms.double( wpEE.hOverECut ),
                      barrelCutOff = cms.double(ebCutOff),
                      needsAdditionalProducts = cms.bool(False),
                      isIgnored = cms.bool(False)),
            cms.PSet( cutName = cms.string('GsfEleDxyCut'),
                      dxyCutValueEB = cms.double( wpEB.dxyCut ),
                      dxyCutValueEE = cms.double( wpEE.dxyCut ),
                      vertexSrc        = cms.InputTag("offlinePrimaryVertices"),
                      vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices"),
                      barrelCutOff = cms.double(ebCutOff),
                      needsAdditionalProducts = cms.bool(True),
                      isIgnored = cms.bool(False)),
            cms.PSet( cutName = cms.string('GsfEleDzCut'),
                      dzCutValueEB = cms.double( wpEB.dzCut ),
                      dzCutValueEE = cms.double( wpEE.dzCut ),
                      vertexSrc        = cms.InputTag("offlinePrimaryVertices"),
                      vertexSrcMiniAOD = cms.InputTag("offlineSlimmedPrimaryVertices"),
                      barrelCutOff = cms.double(ebCutOff),
                      needsAdditionalProducts = cms.bool(True),
                      isIgnored = cms.bool(False)),
            cms.PSet( cutName = cms.string('GsfEleEInverseMinusPInverseCut'),
                      eInverseMinusPInverseCutValueEB = cms.double( wpEB.absEInverseMinusPInverseCut ),
                      eInverseMinusPInverseCutValueEE = cms.double( wpEE.absEInverseMinusPInverseCut ),
                      barrelCutOff = cms.double(ebCutOff),
                      needsAdditionalProducts = cms.bool(False),
                      isIgnored = cms.bool(False)),
            cms.PSet( cutName = cms.string('GsfEleEffAreaPFIsoCut'),
                      isoCutEBLowPt  = cms.double( wpEB.relCombIsolationWithEALowPtCut  ),
                      isoCutEBHighPt = cms.double( wpEB.relCombIsolationWithEAHighPtCut ),
                      isoCutEELowPt  = cms.double( wpEE.relCombIsolationWithEALowPtCut  ),
                      isoCutEEHighPt = cms.double( wpEE.relCombIsolationWithEAHighPtCut ),
                      isRelativeIso = cms.bool(True),
                      ptCutOff = cms.double(20.0),          # high pT above this value, low pT below
                      barrelCutOff = cms.double(ebCutOff),
                      rho = cms.InputTag("fixedGridRhoFastjetAll"),
                      effAreasConfigFile = cms.FileInPath( isoInputs.neuHadAndPhoIsolationEffAreas ),
                      needsAdditionalProducts = cms.bool(True),
                      isIgnored = cms.bool(False) ),
            cms.PSet( cutName = cms.string('GsfEleConversionVetoCut'),
                      conversionSrc        = cms.InputTag('allConversions'),
                      conversionSrcMiniAOD = cms.InputTag('reducedEgamma:reducedConversions'),
                      beamspotSrc = cms.InputTag('offlineBeamSpot'),
                      needsAdditionalProducts = cms.bool(True),
                      isIgnored = cms.bool(False)),
            cms.PSet( cutName = cms.string('GsfEleMissingHitsCut'),
                      maxMissingHitsEB = cms.uint32( wpEB.missingHitsCut ),
                      maxMissingHitsEE = cms.uint32( wpEE.missingHitsCut ),
                      barrelCutOff = cms.double(ebCutOff),
                      needsAdditionalProducts = cms.bool(False),
                      isIgnored = cms.bool(False) ),
            cms.PSet( cutName = cms.string('GsfEleEcalPFClusterRelIsoCut'),
                      ecalPFClusterRelIsoCutValueEB = cms.double( wpEB.EcalPFClusterRelIso ),
                      ecalPFClusterRelIsoCutValueEE = cms.double( wpEE.EcalPFClusterRelIso ),
                      barrelCutOff = cms.double(ebCutOff),
                      needsAdditionalProducts = cms.bool(False),
                      isIgnored = cms.bool(False)),
            cms.PSet( cutName = cms.string('GsfEleHcalPFClusterRelIsoCut'),
                      hcalPFClusterRelIsoCutValueEB = cms.double( wpEB.HcalPFClusterRelIso ),
                      hcalPFClusterRelIsoCutValueEE = cms.double( wpEE.HcalPFClusterRelIso ),
                      barrelCutOff = cms.double(ebCutOff),
                      needsAdditionalProducts = cms.bool(False),
                      isIgnored = cms.bool(False)),
            cms.PSet( cutName = cms.string('GsfEleTrkPtRelIsoCut'),
                      trkPtRelIsoCutValueEB = cms.double( wpEB.TrackRelIso ), 
                      trkPtRelIsoCutValueEE = cms.double( wpEE.TrackRelIso ), 
                      barrelCutOff = cms.double(ebCutOff),
                      needsAdditionalProducts = cms.bool(False),
                      isIgnored = cms.bool(False)),

            )
        )
    #
    return parameterSet

