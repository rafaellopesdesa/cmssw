#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"

#include "ReweightModule/WWreweightProducer/interface/WWreweightProducer.h"

typedef WWreweightProducer<reco::GenParticleCollection,reco::GenJetCollection> WWreweightGenSimProducer;

DEFINE_FWK_MODULE( WWreweightGenSimProducer );
