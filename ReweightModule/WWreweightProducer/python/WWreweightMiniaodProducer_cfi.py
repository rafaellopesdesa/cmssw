import FWCore.ParameterSet.Config as cms
 
WWreweight = cms.EDProducer(
    "WWreweightMiniaodProducer",
    src               = cms.InputTag("prunedGenParticles"),
    jets              = cms.InputTag("slimmedJets"),
#    makeHistograms    = cms.bool(True),
    makeHistograms    = cms.bool(False),
    reweightingSample = cms.string("/WWTo2L2Nu_13TeV-powheg/RunIIWinter15GS-MCRUN2_71_V1-v1/GEN-SIM")
)
