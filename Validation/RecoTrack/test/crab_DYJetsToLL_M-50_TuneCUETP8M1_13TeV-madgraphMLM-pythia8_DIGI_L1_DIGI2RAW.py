from CRABClient.UserUtilities import config
config = config()

config.General.requestName              = 'DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_DIGI_L1_DIGI2RAW_90X'

config.General.workArea                 = './'
config.General.transferOutputs          = True
config.General.transferLogs             = True

config.JobType.pluginName               = 'Analysis'
config.JobType.psetName                 = 'trackingNtupleExample_DIGI_L1_DIGI2RAW.py'
config.JobType.allowUndistributedCMSSW  = True
config.Data.inputDataset                = '/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/PhaseIFall16DR-FlatPU28to62HcalNZSRAW_90X_upgrade2017_realistic_v6_C1-v1/AODSIM'

config.Data.inputDBS                    = 'global'
config.Data.splitting                   = 'FileBased'
config.Data.unitsPerJob                 = 1
config.Data.totalUnits                  = 800
config.Data.publication                 = True

config.Site.storageSite                 = 'T3_US_FNALLPC'
