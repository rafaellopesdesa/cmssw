import FWCore.ParameterSet.Config as cms

process = cms.Process('ConversionAnalysis')

process.load('FWCore/MessageService/MessageLogger_cfi')
process.maxEvents = cms.untracked.PSet(
        input = cms.untracked.int32(-1)
)

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
readFiles.extend( ['/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-RECO/PU25ns_MCRUN2_75_V1-v1/00000/860F1835-0CF8-E411-9872-0025905B8562.root'])
secFiles.extend([
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/9C077315-EBF7-E411-ADC9-0025905A6110.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/2C358BDE-ECF7-E411-B354-0025905938AA.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/4636FB5B-E4F7-E411-B6B1-0025905B8606.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/48EA5F9F-EFF7-E411-B9FC-0025905A6092.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/5215513E-E4F7-E411-BA2E-002618943865.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/7C29797A-E7F7-E411-A3AB-0025905A611E.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/92399962-E6F7-E411-8776-002590593876.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/924EE261-D9F7-E411-A915-0025905A6138.root'
])

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
  outputFile    = cms.untracked.string('SingleLegConversionBaby_5.root'),
)

process.p = cms.EndPath(process.tpClusterProducer * process.quickTrackAssociatorByHits * process.myOutputTest)
