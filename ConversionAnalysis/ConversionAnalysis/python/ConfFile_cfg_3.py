import FWCore.ParameterSet.Config as cms

process = cms.Process('ConversionAnalysis')

process.load('FWCore/MessageService/MessageLogger_cfi')
process.maxEvents = cms.untracked.PSet(
        input = cms.untracked.int32(-1)
)

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
readFiles.extend( ['/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-RECO/PU25ns_MCRUN2_75_V1-v1/00000/52081B71-2BF8-E411-B12C-0025905A613C.root'])
secFiles.extend([
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/1202ECBB-F6F7-E411-939F-0025905B85F6.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/28B50129-FBF7-E411-A010-0025905B861C.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/2EE3C454-19F8-E411-9A5C-0025905A6090.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/8895CA57-FFF7-E411-804A-0025905A607E.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/DC7DAF81-0EF8-E411-9064-0025905B85D6.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/E84A3CCD-02F8-E411-BA84-0025905A606A.root',
'/store/relval/CMSSW_7_5_0_pre4/RelValH130GGgluonfusion_13/GEN-SIM-DIGI-RAW-HLTDEBUG/PU25ns_MCRUN2_75_V1-v1/00000/F8B38DC3-05F8-E411-AB22-0025905B8610.root'
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
  outputFile    = cms.untracked.string('SingleLegConversionBaby_3.root'),
)

process.p = cms.EndPath(process.tpClusterProducer * process.quickTrackAssociatorByHits * process.myOutputTest)
