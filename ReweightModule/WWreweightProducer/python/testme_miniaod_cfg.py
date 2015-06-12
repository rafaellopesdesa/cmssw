import FWCore.ParameterSet.Config as cms

process = cms.Process("WWreweight")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:/hadoop/cms/store/user/rcoelhol/1EF48EA6-DE0B-E511-99EF-0002C92A1024.root'
    )
)

process.load('ReweightModule.WWreweightProducer.WWreweightMiniaodProducer_cfi')

process.TFileService = cms.Service("TFileService", 
      fileName = cms.string("histo.root"),
      closeFileFast = cms.untracked.bool(True)
)

process.out = cms.OutputModule("PoolOutputModule",
    fileName = cms.untracked.string('test.root'),
)

process.p = cms.Path(process.WWreweight)
process.e = cms.EndPath(process.out)
