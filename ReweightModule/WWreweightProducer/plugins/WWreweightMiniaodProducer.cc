#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/PatCandidates/interface/Jet.h"

#include "ReweightModule/WWreweightProducer/interface/WWreweightProducer.h"

typedef WWreweightProducer<reco::GenParticleCollection,pat::JetCollection> WWreweightMiniaodProducer;

DEFINE_FWK_MODULE( WWreweightMiniaodProducer );
