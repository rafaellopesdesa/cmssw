from CRABClient.UserUtilities import config
config = config()

config.General.requestName              = 'DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_trackingNtuple_90X'

config.General.workArea                 = './'
config.General.transferOutputs          = True
config.General.transferLogs             = True

config.JobType.pluginName               = 'Analysis'
config.JobType.psetName                 = 'trackingNtupleExample_electronGsfTracks90.py'
config.JobType.allowUndistributedCMSSW  = True
config.Data.inputDataset                = '/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/rcoelhol-crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_DIGI_L1_DIGI2RAW_90X-39d841ebac27abefb983bf6b6e2df636/USER'

config.Data.inputDBS                    = 'phys03'
config.Data.splitting                   = 'FileBased'
config.Data.unitsPerJob                 = 1
config.Data.publication                 = True

config.Site.storageSite                 = 'T3_US_FNALLPC'
