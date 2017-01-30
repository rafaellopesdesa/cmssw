import FWCore.ParameterSet.Config as cms

# Generic jetTag configuration
cTagGenericAnalysisBlock = cms.PSet(
    parameters = cms.PSet(
        discriminatorStart = cms.double(-1.011),
        nBinEffPur = cms.int32(200),
        # the constant b-efficiency for the differential plots versus pt and eta
        effBConst = cms.double(0.5),
        endEffPur = cms.double(1.005),
        discriminatorEnd = cms.double(1.011),
        startEffPur = cms.double(0.005)
    )
)

