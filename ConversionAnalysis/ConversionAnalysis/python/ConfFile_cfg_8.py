import FWCore.ParameterSet.Config as cms

process = cms.Process('ConversionAnalysis')

process.load('FWCore/MessageService/MessageLogger_cfi')
process.maxEvents = cms.untracked.PSet(
        input = cms.untracked.int32(-1)
)

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
readFiles.extend( ['/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-RECO/PU25ns_MCRUN2_75_V1-v1/00000/EEC9FD12-FEF7-E411-8E35-002618943800.root'])
secFiles.extend([
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/4636FB5B-E4F7-E411-B6B1-0025905B8606.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/72F0D5B3-DFF7-E411-BCF3-0025905A48FC.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/88084DB7-DCF7-E411-9725-002618943910.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/92399962-E6F7-E411-8776-002590593876.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/924EE261-D9F7-E411-A915-0025905A6138.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/B00B9E98-E3F7-E411-92A5-0025905A60CA.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/B0812339-E8F7-E411-A38A-0025905A6138.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/B0B49475-DFF7-E411-87F7-0025905A60A6.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/FA3D5DE4-D9F7-E411-BAC3-0025905A6132.root'
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
  outputFile    = cms.untracked.string('SingleLegConversionBaby_8.root'),
)

process.p = cms.EndPath(process.tpClusterProducer * process.quickTrackAssociatorByHits * process.myOutputTest)
