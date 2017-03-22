# EGM skimmer
# Author: Rafael Lopes de Sa

import FWCore.ParameterSet.Config as cms

# Run with the 2017 detector
from Configuration.StandardSequences.Eras import eras
process = cms.Process('SKIM',eras.Run2_2017)

# Import the standard packages for reconstruction and digitization
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.Digi_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.RawToDigi_cff')
process.load('Configuration.StandardSequences.L1Reco_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load('CommonTools.RecoAlgos.pfClusterMatchedToPhotonsSelector_cfi')

# Global Tag configuration ... just using the same as in the RelVal
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '90X_upgrade2017_realistic_v15', '')

# This is where users have some control.
# Define which collections to save and which dataformat we are using
savedCollections = cms.untracked.vstring('drop *',
                                         'keep EcalRecHitsSorted_*_*_*',
                                         'keep recoPFClusters_*_*_*',
                                         'keep recoCaloClusters_*_*_*',
                                         'keep recoSuperClusters_*_*_*', 
                                         'keep recoGsfElectron*_*_*_*',
                                         'keep recoPhoton*_*_*_*',
                                         'keep double_fixedGridRho*_*_*',
                                         'keep recoGenParticles_*_*_*',
                                         'keep GenEventInfoProduct_*_*_*',
                                         'keep PileupSummaryInfos_*_*_*',
                                         'keep *_ecalDigis_*_*',
                                         'keep *_mix_MergedTrackTruth_*')

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

process.source = cms.Source("PoolSource",                 
                            fileNames = cms.untracked.vstring(
        'file:/eos/cms/store/relval/CMSSW_9_0_0_pre6/RelValSingleGammaPt35/GEN-SIM-RECO/90X_upgrade2017_realistic_v15-v1/00000/8C4BE10C-5001-E711-9B47-0025905A6122.root',
        'file:/eos/cms/store/relval/CMSSW_9_0_0_pre6/RelValSingleGammaPt35/GEN-SIM-RECO/90X_upgrade2017_realistic_v15-v1/00000/C80E4D0B-5001-E711-B528-0025905B858C.root'
),
                            secondaryFileNames = cms.untracked.vstring(
        'file:/eos/cms/store/relval/CMSSW_9_0_0_pre6/RelValSingleGammaPt35/GEN-SIM-DIGI-RAW/90X_upgrade2017_realistic_v15-v1/00000/48495C2C-4701-E711-BEED-0025905A60E4.root',
        'file:/eos/cms/store/relval/CMSSW_9_0_0_pre6/RelValSingleGammaPt35/GEN-SIM-DIGI-RAW/90X_upgrade2017_realistic_v15-v1/00000/B80BA312-4701-E711-BE8F-0025905A48EC.root'
)
                            )
process.PFCLUSTERoutput = cms.OutputModule("PoolOutputModule",
                                           dataset = cms.untracked.PSet(dataTier = cms.untracked.string('RECO'),
                                                                        filterName = cms.untracked.string('')
                                                                        ),
                                           eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
                                           fileName = cms.untracked.string('skimEGMobjects_fromRECO.root'),
                                           outputCommands = savedCollections,
                                           splitLevel = cms.untracked.int32(0)
                                           )

# Run the digitizer to make the trackingparticles
process.mix.digitizers = cms.PSet(process.theDigitizersValid)
process.trackingtruth_step = cms.Path(process.pdigi_valid)

# Remake the PFClusters
process.particleFlowClusterECAL.energyCorrector.autoDetectBunchSpacing = cms.bool(False)
process.particleFlowClusterECAL.energyCorrector.bunchSpacing = cms.int32(25)
process.pfclusters_step = cms.Path(process.ecalDigis * 
                                   process.particleFlowRecHitPS * 
                                   process.particleFlowRecHitECAL * 
                                   process.particleFlowClusterECALUncorrected * 
                                   process.particleFlowClusterPS *
                                   process.particleFlowClusterECAL)

# Select the PFClusters we want to calibrate
process.selection_step = cms.Path(process.particleFlowClusterECALMatchedToPhotons)

# Ends job and writes our output
process.endjob_step = cms.EndPath(process.endOfProcess)
process.output_step = cms.EndPath(process.PFCLUSTERoutput)

# Schedule definition, rebuilding rechits
process.schedule = cms.Schedule(process.trackingtruth_step,process.pfclusters_step,process.selection_step,process.endjob_step,process.output_step)


