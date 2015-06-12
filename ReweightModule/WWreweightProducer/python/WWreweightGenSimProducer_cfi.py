import FWCore.ParameterSet.Config as cms
 
WWreweight = cms.EDProducer(
    "WWreweightGenSimProducer",
    src               = cms.InputTag("genParticles"),
    jets              = cms.InputTag("ak4GenJets"),
    makeHistograms    = cms.bool(True),
    reweightingSample = cms.string("/WWTo2L2Nu_13TeV-powheg/RunIIWinter15GS-MCRUN2_71_V1-v1/GEN-SIM")
)
