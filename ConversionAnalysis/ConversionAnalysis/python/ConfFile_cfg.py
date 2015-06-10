import FWCore.ParameterSet.Config as cms

process = cms.Process('ConversionAnalysis')

process.load('FWCore/MessageService/MessageLogger_cfi')
process.maxEvents = cms.untracked.PSet(
        input = cms.untracked.int32(-1)
)

readFiles = cms.untracked.vstring()
secFiles = cms.untracked.vstring() 
storagePath = 'root://xrootd.t2.ucsd.edu//store/user/rclsa/hgg/gen-sim-reco/10A17242-15F8-E411-8BC3-0025905A611E_gen-sim-digi-raw-hltdebug/'
readFiles.extend( ['root://xrootd.t2.ucsd.edu//store/user/rclsa/hgg/gen-sim-reco/10A17242-15F8-E411-8BC3-0025905A611E.root']) 
secFiles.extend(map(lambda x: storagePath+x, ['1202ECBB-F6F7-E411-939F-0025905B85F6.root',
                                              '2808488F-F6F7-E411-B15B-0025905A60E0.root',
                                              '30058F8B-EFF7-E411-9816-0025905A607E.root',
                                              '44127FCE-E1F7-E411-AF31-0025905A60A6.root',
                                              '48EA5F9F-EFF7-E411-B9FC-0025905A6092.root',
                                              '5215513E-E4F7-E411-BA2E-002618943865.root',
                                              '7C29797A-E7F7-E411-A3AB-0025905A611E.root',
                                              'B0B49475-DFF7-E411-87F7-0025905A60A6.root',
                                              'C2D12D87-F1F7-E411-BAB6-0025905A607E.root',
                                              'DEA22DD2-DCF7-E411-A822-002618943875.root']))

process.source = cms.Source ("PoolSource",fileNames = readFiles, secondaryFileNames = secFiles)

process.load('SimTracker.TrackerHitAssociation.clusterTpAssociationProducer_cfi')
process.load('SimTracker.TrackAssociatorProducers.quickTrackAssociatorByHits_cfi')

process.myOutputTest = cms.EDAnalyzer(
  'ConversionAnalysis',
  trackingTruth = cms.untracked.InputTag('mix', 'MergedTrackTruth'),
  trackingReco  = cms.untracked.InputTag('generalTracks'),
  photonReco    = cms.untracked.InputTag('gedPhotons'),
  outputFile    = cms.untracked.string('SingleLegConversionBaby.root'),
)

process.p = cms.EndPath(process.tpClusterProducer * process.quickTrackAssociatorByHits * process.myOutputTest)
