import FWCore.ParameterSet.Config as cms

process = cms.Process("WWreweight")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:/hadoop/cms/store/user/rcoelhol/006CB26C-44F9-E411-862A-9CB654ADA584.root'
    )
)

process.load('ReweightModule.WWreweightProducer.WWreweightGenSimProducer_cfi')

process.TFileService = cms.Service("TFileService", 
      fileName = cms.string("histo.root"),
      closeFileFast = cms.untracked.bool(True)
)

process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('test.root'),
    outputCommands = cms.untracked.vstring( 'drop *' )
)

process.p = cms.Path(process.WWreweight)
process.e = cms.EndPath(process.out)
