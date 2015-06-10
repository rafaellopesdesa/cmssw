import FWCore.ParameterSet.Config as cms

process = cms.Process('ConversionAnalysis')

process.load('FWCore/MessageService/MessageLogger_cfi')
process.maxEvents = cms.untracked.PSet(
        input = cms.untracked.int32(-1)
)

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
readFiles.extend( ['/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-RECO/PU25ns_MCRUN2_75_V1-v1/00000/FA32EFC7-32F8-E411-A459-0025905B8610.root'])
secFiles.extend(['/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/606B0163-19F8-E411-86CD-0025905B8562.root'])

process.source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)

process.load('SimTracker.TrackerHitAssociation.clusterTpAssociationProducer_cfi')
process.load('SimTracker.TrackAssociatorProducers.quickTrackAssociatorByHits_cfi')

#process.quickTrackAssociatorByHits.ThreeHitTracksAreSpecial = cms.bool(False)
#process.quickTrackAssociatorByHits.Purity_SimToReco = cms.double(0.3)
#process.quickTrackAssociatorByHits.Quality_SimToReco = cms.double(0.3)

process.myOutputTest = cms.EDAnalyzer(
  'ConversionAnalysis',
  trackingTruth = cms.untracked.InputTag('mix', 'MergedTrackTruth'),
  trackingReco  = cms.untracked.InputTag('generalTracks'),
  photonReco    = cms.untracked.InputTag('gedPhotons'),
  outputFile    = cms.untracked.string('SingleLegConversionBaby_9.root'),
)

process.p = cms.EndPath(process.tpClusterProducer * process.quickTrackAssociatorByHits * process.myOutputTest)
