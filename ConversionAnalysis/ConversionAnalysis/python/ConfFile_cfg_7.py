import FWCore.ParameterSet.Config as cms

process = cms.Process('ConversionAnalysis')

process.load('FWCore/MessageService/MessageLogger_cfi')
process.maxEvents = cms.untracked.PSet(
        input = cms.untracked.int32(-1)
)

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
readFiles.extend( ['/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-RECO/PU25ns_MCRUN2_75_V1-v1/00000/E6DCBCBE-ECF7-E411-A7E0-0025905B861C.root'])
secFiles.extend([
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/1E08246C-D4F7-E411-A69A-002354EF3BE2.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/2EF73658-D1F7-E411-A625-0025905A48C0.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/3449E2A9-BDF7-E411-A9FD-003048FFCBA8.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/3897B80E-C2F7-E411-A7F7-00259059649C.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/3EA61E5A-BFF7-E411-8E09-0025905A6088.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/688A473A-D0F7-E411-8D08-00261894384F.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/7626FCC4-BEF7-E411-9897-0025905A612C.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/D0B24A06-D0F7-E411-BB25-0025905A60BE.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/EC71720A-BFF7-E411-B003-0025905AA9CC.root'
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
  outputFile    = cms.untracked.string('SingleLegConversionBaby_7.root'),
)

process.p = cms.EndPath(process.tpClusterProducer * process.quickTrackAssociatorByHits * process.myOutputTest)
