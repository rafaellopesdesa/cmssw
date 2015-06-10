// -*- C++ -*-
//
// Package:    ConversionAnalysis/ConversionAnalysis
// Class:      ConversionAnalysis
// 
/**\class ConversionAnalysis ConversionAnalysis.cc ConversionAnalysis/ConversionAnalysis/plugins/ConversionAnalysis.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  
//         Created:  Tue, 02 Jun 2015 13:33:47 GMT
//
//


// system include files
#include <memory>
#include <string>
#include <vector>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/PluginManager/interface/ModuleDef.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/Association.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/EgammaCandidates/interface/Conversion.h"
#include "DataFormats/EgammaCandidates/interface/ConversionFwd.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"
#include "DataFormats/EgammaCandidates/interface/PhotonCore.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/VertexReco/interface/Vertex.h"

#include "SimDataFormats/CrossingFrame/interface/CrossingFrame.h"
#include "SimDataFormats/CrossingFrame/interface/MixCollection.h"
#include "SimDataFormats/TrackingAnalysis/interface/TrackingParticle.h"
#include "SimDataFormats/TrackingAnalysis/interface/TrackingVertex.h"
#include "SimDataFormats/TrackingAnalysis/interface/TrackingParticleFwd.h"
#include "SimDataFormats/TrackingAnalysis/interface/TrackingVertexContainer.h"
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include "SimDataFormats/Associations/interface/TrackToTrackingParticleAssociator.h"

#include <Math/VectorUtil.h>
#include <Math/Boost.h>
#include <Math/GenVector/LorentzVector.h>
#include <TFile.h>
#include <TTree.h>

//
// class declaration
//

typedef edm::RefVector< std::vector<TrackingParticle> > TrackingParticleContainer;
typedef std::vector<TrackingParticle>                   TrackingParticleCollection;

typedef TrackingParticleRefVector::iterator             tp_iterator;
typedef TrackingVertex::genv_iterator                   genv_iterator;
typedef TrackingVertex::g4v_iterator                    g4v_iterator;

class ConversionAnalysis : public edm::EDAnalyzer {
   public:
      explicit ConversionAnalysis(const edm::ParameterSet&);
      ~ConversionAnalysis();

   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      edm::ParameterSet conf_;

      // Baby tree stuff
      TFile* babyFile;
      TTree* babyTree;

      bool isTruthConversion;
      bool isTruthSingleLegConversion;
      bool isMatchedConversion1;
      bool isMatchedConversion2;
      bool isRecoConversion;
      bool isRecoSingleLegConversion;
      bool hasRecoPhoton;
    
      double GenPhotonPx;
      double GenPhotonPy;
      double GenPhotonPz;
      double GenPhotonE;
    
      double SimConversionVertexX;
      double SimConversionVertexY;
      double SimConversionVertexZ;
      double SimConversionVertexT;
    
      double ElectronTrackingParticle1Px;
      double ElectronTrackingParticle1Py;
      double ElectronTrackingParticle1Pz;
      double ElectronTrackingParticle1E;
      int ElectronTrackingParticle1Charge;
    
      double ElectronTrackingParticle2Px;
      double ElectronTrackingParticle2Py;
      double ElectronTrackingParticle2Pz;
      double ElectronTrackingParticle2E;
      int ElectronTrackingParticle2Charge;
    
      double MatchedElectronTrack1Px;
      double MatchedElectronTrack1Py;
      double MatchedElectronTrack1Pz;
      int MatchedElectronTrack1Charge;
      int MatchedElectronTrack1NumberOfValidPixelHits;
      int MatchedElectronTrack1Algo;
      int MatchedElectronTrack1NumberOfMissingInnerHits;
 
      double MatchedElectronTrack2Px;
      double MatchedElectronTrack2Py;
      double MatchedElectronTrack2Pz;
      int MatchedElectronTrack2Charge;
      int MatchedElectronTrack2NumberOfValidPixelHits;
      int MatchedElectronTrack2Algo;
      int MatchedElectronTrack2NumberOfMissingInnerHits;
    
      double RecoPhotonPx;
      double RecoPhotonPy;
      double RecoPhotonPz;
      double RecoPhotonE;

      int nDoubleLegConversions;
    
      std::vector<double> RecoConversionVertexX;
      std::vector<double>* RecoConversionVertexX_ = &RecoConversionVertexX;
      std::vector<double> RecoConversionVertexY;
      std::vector<double>* RecoConversionVertexY_ = &RecoConversionVertexY;
      std::vector<double> RecoConversionVertexZ;
      std::vector<double>* RecoConversionVertexZ_ = &RecoConversionVertexZ;
    
      std::vector<double> RecoElectronTrack1Px;
      std::vector<double>* RecoElectronTrack1Px_ = &RecoElectronTrack1Px;
      std::vector<double> RecoElectronTrack1Py;
      std::vector<double>* RecoElectronTrack1Py_ = &RecoElectronTrack1Py;
      std::vector<double> RecoElectronTrack1Pz;
      std::vector<double>* RecoElectronTrack1Pz_ = &RecoElectronTrack1Pz;
      std::vector<int> RecoElectronTrack1Charge;
      std::vector<int>* RecoElectronTrack1Charge_ = &RecoElectronTrack1Charge;
      std::vector<int> RecoElectronTrack1NumberOfValidPixelHits;
      std::vector<int>* RecoElectronTrack1NumberOfValidPixelHits_ = &RecoElectronTrack1NumberOfValidPixelHits;
      std::vector<int> RecoElectronTrack1Algo;
      std::vector<int>* RecoElectronTrack1Algo_ = &RecoElectronTrack1Algo;
      std::vector<int> RecoElectronTrack1NumberOfMissingInnerHits;
      std::vector<int>* RecoElectronTrack1NumberOfMissingInnerHits_ = &RecoElectronTrack1NumberOfMissingInnerHits;
    
      std::vector<double> RecoElectronTrack2Px;
      std::vector<double>* RecoElectronTrack2Px_ = &RecoElectronTrack2Px;
      std::vector<double> RecoElectronTrack2Py;
      std::vector<double>* RecoElectronTrack2Py_ = &RecoElectronTrack2Py;
      std::vector<double> RecoElectronTrack2Pz;
      std::vector<double>* RecoElectronTrack2Pz_ = &RecoElectronTrack2Pz;
      std::vector<int> RecoElectronTrack2Charge;
      std::vector<int>* RecoElectronTrack2Charge_ = &RecoElectronTrack2Charge;
      std::vector<int> RecoElectronTrack2NumberOfValidPixelHits;
      std::vector<int>* RecoElectronTrack2NumberOfValidPixelHits_ = &RecoElectronTrack2NumberOfValidPixelHits;
      std::vector<int> RecoElectronTrack2Algo;
      std::vector<int>* RecoElectronTrack2Algo_ = &RecoElectronTrack2Algo;
      std::vector<int> RecoElectronTrack2NumberOfMissingInnerHits;
      std::vector<int>* RecoElectronTrack2NumberOfMissingInnerHits_ = &RecoElectronTrack2NumberOfMissingInnerHits;

      int nSingleLegConversions;

      std::vector<double> SingleLegMVA;
      std::vector<double>* SingleLegMVA_ = &SingleLegMVA;
      std::vector<double> RecoSingleLegConversionVertexX;
      std::vector<double>* RecoSingleLegConversionVertexX_ = &RecoSingleLegConversionVertexX;
      std::vector<double> RecoSingleLegConversionVertexY;
      std::vector<double>* RecoSingleLegConversionVertexY_ = &RecoSingleLegConversionVertexY;
      std::vector<double> RecoSingleLegConversionVertexZ;
      std::vector<double>* RecoSingleLegConversionVertexZ_ = &RecoSingleLegConversionVertexZ;

      std::vector<double> RecoSingleLegElectronTrackPx;
      std::vector<double>* RecoSingleLegElectronTrackPx_ = &RecoSingleLegElectronTrackPx;
      std::vector<double> RecoSingleLegElectronTrackPy;
      std::vector<double>* RecoSingleLegElectronTrackPy_ = &RecoSingleLegElectronTrackPy;
      std::vector<double> RecoSingleLegElectronTrackPz;
      std::vector<double>* RecoSingleLegElectronTrackPz_ = &RecoSingleLegElectronTrackPz;
      std::vector<int> RecoSingleLegElectronTrackCharge;
      std::vector<int>* RecoSingleLegElectronTrackCharge_ = &RecoSingleLegElectronTrackCharge;
      std::vector<int> RecoSingleLegElectronTrackNumberOfValidPixelHits;
      std::vector<int>* RecoSingleLegElectronTrackNumberOfValidPixelHits_ = &RecoSingleLegElectronTrackNumberOfValidPixelHits;
      std::vector<int> RecoSingleLegElectronTrackAlgo;
      std::vector<int>* RecoSingleLegElectronTrackAlgo_ = &RecoSingleLegElectronTrackAlgo;
      std::vector<int> RecoSingleLegElectronTrackNumberOfMissingInnerHits;
      std::vector<int>* RecoSingleLegElectronTrackNumberOfMissingInnerHits_ = &RecoSingleLegElectronTrackNumberOfMissingInnerHits;


      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

      // ----------member data ---------------------------
};

//
// constructors and destructor
//
ConversionAnalysis::ConversionAnalysis(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
  conf_ = iConfig;
}


ConversionAnalysis::~ConversionAnalysis()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
ConversionAnalysis::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace reco;

  Handle<TrackingParticleCollection> TrackingParticles;
  Handle<PhotonCollection> Photons;

  // To do the matching
  Handle< View<Track > > Tracks;
  Handle<TrackToTrackingParticleAssociator> assoc;  

  // Gets the event
  edm::InputTag trackingTruth = conf_.getUntrackedParameter<edm::InputTag>("trackingTruth");
  edm::InputTag trackingReco  = conf_.getUntrackedParameter<edm::InputTag>("trackingReco");
  edm::InputTag photonReco    = conf_.getUntrackedParameter<edm::InputTag>("photonReco");
  iEvent.getByLabel(trackingTruth, TrackingParticles);
  iEvent.getByLabel(trackingReco, Tracks);   
  iEvent.getByLabel(photonReco, Photons);  

  iEvent.getByLabel("quickTrackAssociatorByHits", assoc);
  SimToRecoCollection SimToGsfRecoAssociations = assoc->associateSimToReco(Tracks, TrackingParticles);

  for ( auto PhotonTrackingParticle : *TrackingParticles ) {

    // Gen information
    GenParticle GenPhoton;

    // Sim information
    TrackingVertexRef ConversionVertex;
    TrackingParticleRef ElectronTrackingParticle1;
    TrackingParticleRef ElectronTrackingParticle2;

    // Reco information
    Track MatchedElectronTrack1;
    Track MatchedElectronTrack2;
    Photon RecoPhoton;
    ConversionRefVector PhotonConversions;
    ConversionRefVector PhotonSingleLegConversions;

    vector<Vertex> RecoConversionVertex;
    vector<Track> RecoElectronTrack1;
    vector<Track> RecoElectronTrack2;

    // Store up to 2 single leg conversions... does this really happen?
    vector<vector<float> > OneLegMVA;
    vector<Vertex> RecoSingleLegConversionVertex;
    vector<Track> RecoSingleLegElectronTrack;
    
    isTruthConversion = false;
    isMatchedConversion1 = false;
    isMatchedConversion2 = false;
    isTruthSingleLegConversion = false;
    isRecoConversion = false;
    isRecoSingleLegConversion = false;
    hasRecoPhoton = false;

    if (PhotonTrackingParticle.pdgId() != 22) continue; // We have to analyze photons...
    if (PhotonTrackingParticle.genParticles().size() == 0) continue; // is it matched to a gen particle?...
    if (!PhotonTrackingParticle.genParticles()[0]->isPromptFinalState()) continue; // not prompt, don't care...
    if (PhotonTrackingParticle.genParticles()[0]->mother()[0].pdgId() != 25) continue; // and from a Higgs.
    GenPhoton = *PhotonTrackingParticle.genParticles()[0];

    //    if (PhotonTrackingParticle.parentVertex()->g4Vertices().size() == 0) continue; // is it matched to a simvertex?...
    //    if (PhotonTrackingParticle.parentVertex()->g4Vertices()[0].vertexId() != 0) continue; // from the PV.

    if (Photons->size() > 0) {

      auto RecoPhotonPtr = min_element(Photons->begin(), Photons->end(), [&](auto v1, auto v2) {
	  return ROOT::Math::VectorUtil::DeltaR(PhotonTrackingParticle.p4(), v1.p4()) < ROOT::Math::VectorUtil::DeltaR(PhotonTrackingParticle.p4(), v2.p4()); 
	});      

      if (ROOT::Math::VectorUtil::DeltaR(PhotonTrackingParticle.p4(), RecoPhotonPtr->p4()) < 0.1) {

	hasRecoPhoton = true;

	// Save it for later
	RecoPhoton = *RecoPhotonPtr;
	PhotonConversions = RecoPhotonPtr->conversions();
	PhotonSingleLegConversions = RecoPhotonPtr->photonCore()->conversionsOneLeg();
	nDoubleLegConversions = 0;
	nSingleLegConversions = 0;

	if (PhotonConversions.size() > 0) {
	  isRecoConversion = true;
	  for (auto& PhotonConversion : PhotonConversions ) {
	    if (PhotonConversion->isConverted() && PhotonConversion->nTracks() == 2) {
	      nDoubleLegConversions++;
	      
	      RecoConversionVertex.push_back(PhotonConversion->conversionVertex());
	      RecoElectronTrack1.push_back(*(PhotonConversion->tracks()[0]));
	      RecoElectronTrack2.push_back(*(PhotonConversion->tracks()[1]));	    
	    }
	  }
	}

	if (PhotonSingleLegConversions.size() > 0) {
	  isRecoSingleLegConversion = true;
	  for (auto& PhotonSingleLegConversion : PhotonSingleLegConversions ) {
	    if (PhotonSingleLegConversions[0]->nTracks() == 1) {
	      nSingleLegConversions++;
	      RecoSingleLegConversionVertex.push_back(PhotonSingleLegConversion->conversionVertex());
	      RecoSingleLegElectronTrack.push_back(*(PhotonSingleLegConversion->tracks()[0]));
	      OneLegMVA.push_back(const_cast<Conversion&>(*PhotonSingleLegConversion).oneLegMVA());
	    }
	  }
	}

      }
    }
    for (tv_iterator decayVertex = PhotonTrackingParticle.decayVertices_begin(); decayVertex != PhotonTrackingParticle.decayVertices_end(); decayVertex++) {
      if ((*decayVertex)->nDaughterTracks() != 2) continue; // Two decay products..
      if ((*decayVertex)->daughterTracks()[0]->pdgId() * (*decayVertex)->daughterTracks()[1]->pdgId() != -121)	
	continue; // to electron and positron
      ConversionVertex = *decayVertex;
      isTruthConversion = true;

    }
    
    if (isTruthConversion) {
      
      if (ConversionVertex->position().Rho() > 60.) continue;  // rho < 60cm
      if (fabs(ConversionVertex->position().z()) > 150.) continue; // |z| < 150cm

      ElectronTrackingParticle1 = (ConversionVertex->daughterTracks()[0]);
      ElectronTrackingParticle2 = (ConversionVertex->daughterTracks()[1]);
	
      if(SimToGsfRecoAssociations.find(ElectronTrackingParticle1) != SimToGsfRecoAssociations.end()) {

	isMatchedConversion1 = true;
	auto ElectronTracks1 = SimToGsfRecoAssociations[ElectronTrackingParticle1];
	MatchedElectronTrack1 = *ElectronTracks1.begin()->first;

      }
      
      if (SimToGsfRecoAssociations.find(ElectronTrackingParticle2) != SimToGsfRecoAssociations.end()) {
	
	isMatchedConversion2 = true;
	auto ElectronTracks2 = SimToGsfRecoAssociations[ElectronTrackingParticle2];	
	MatchedElectronTrack2 = *ElectronTracks2.begin()->first;

      }

      if(SimToGsfRecoAssociations.find(ElectronTrackingParticle1) != SimToGsfRecoAssociations.end() && 
	 SimToGsfRecoAssociations.find(ElectronTrackingParticle2) != SimToGsfRecoAssociations.end()) {
	auto ElectronTracks1 = SimToGsfRecoAssociations[ElectronTrackingParticle1];
	auto ElectronTracks2 = SimToGsfRecoAssociations[ElectronTrackingParticle2];
	if (ROOT::Math::VectorUtil::DeltaR(ElectronTracks1.begin()->first->momentum(), ElectronTracks2.begin()->first->momentum()) == 0) {
	  isTruthSingleLegConversion = true;	  
	}
      }
    
    }
  
    // Fill the baby    
    GenPhotonPx = -999.;
    GenPhotonPy = -999.;
    GenPhotonPz = -999.;
    GenPhotonE = -999.;
    
    SimConversionVertexX = -999.;
    SimConversionVertexY = -999.;
    SimConversionVertexZ = -999.;
    SimConversionVertexT = -999.;
    
    ElectronTrackingParticle1Px = -999.;
    ElectronTrackingParticle1Py = -999.;
    ElectronTrackingParticle1Pz = -999.;
    ElectronTrackingParticle1E = -999.;
    ElectronTrackingParticle1Charge = -999;
    
    ElectronTrackingParticle2Px = -999.;
    ElectronTrackingParticle2Py = -999.;
    ElectronTrackingParticle2Pz = -999.;
    ElectronTrackingParticle2E = -999.;
    ElectronTrackingParticle2Charge = -999;
    
    MatchedElectronTrack1Px = -999.;
    MatchedElectronTrack1Py = -999.;
    MatchedElectronTrack1Pz = -999.;
    MatchedElectronTrack1Charge = -999;
    MatchedElectronTrack1NumberOfValidPixelHits = -999;
    MatchedElectronTrack1Algo = -999;
    MatchedElectronTrack1NumberOfMissingInnerHits = -999;

    MatchedElectronTrack2Px = -999.;
    MatchedElectronTrack2Py = -999.;
    MatchedElectronTrack2Pz = -999.;
    MatchedElectronTrack2Charge = -999;
    MatchedElectronTrack2NumberOfValidPixelHits = -999;
    MatchedElectronTrack2Algo = -999;
    MatchedElectronTrack2NumberOfMissingInnerHits = -999;
    
    RecoPhotonPx = -999.;
    RecoPhotonPy = -999.;
    RecoPhotonPz = -999.;
    RecoPhotonE = -999.;
    
    RecoConversionVertexX_->clear();
    RecoConversionVertexY_->clear();
    RecoConversionVertexZ_->clear();
        
    RecoElectronTrack1Px_->clear();
    RecoElectronTrack1Py_->clear();
    RecoElectronTrack1Pz_->clear();
    RecoElectronTrack1Charge_->clear();
    RecoElectronTrack1NumberOfValidPixelHits_->clear();
    RecoElectronTrack1Algo_->clear();
    RecoElectronTrack1NumberOfMissingInnerHits_->clear();

    RecoElectronTrack2Px_->clear();
    RecoElectronTrack2Py_->clear();
    RecoElectronTrack2Pz_->clear();
    RecoElectronTrack2Charge_->clear();
    RecoElectronTrack2NumberOfValidPixelHits_->clear();
    RecoElectronTrack2Algo_->clear();
    RecoElectronTrack2NumberOfMissingInnerHits_->clear();

    SingleLegMVA_->clear();
    RecoSingleLegConversionVertexX_->clear();
    RecoSingleLegConversionVertexY_->clear();
    RecoSingleLegConversionVertexZ_->clear();

    RecoSingleLegElectronTrackPx_->clear();
    RecoSingleLegElectronTrackPy_->clear();
    RecoSingleLegElectronTrackPz_->clear();
    RecoSingleLegElectronTrackCharge_->clear();
    RecoSingleLegElectronTrackNumberOfValidPixelHits_->clear();
    RecoSingleLegElectronTrackAlgo_->clear();
    RecoSingleLegElectronTrackNumberOfMissingInnerHits_->clear();

    GenPhotonPx = GenPhoton.p4().px();
    GenPhotonPy = GenPhoton.p4().py();
    GenPhotonPz = GenPhoton.p4().pz();
    GenPhotonE = GenPhoton.p4().e();

    if (isTruthConversion) {
      SimConversionVertexX = ConversionVertex->position().x();
      SimConversionVertexY = ConversionVertex->position().y();
      SimConversionVertexZ = ConversionVertex->position().z();
      SimConversionVertexT = ConversionVertex->position().t();
      
      ElectronTrackingParticle1Px = ElectronTrackingParticle1->p4().px();
      ElectronTrackingParticle1Py = ElectronTrackingParticle1->p4().py();
      ElectronTrackingParticle1Pz = ElectronTrackingParticle1->p4().pz();
      ElectronTrackingParticle1E = ElectronTrackingParticle1->p4().e();
      ElectronTrackingParticle1Charge = ElectronTrackingParticle1->charge();
      
      ElectronTrackingParticle2Px = ElectronTrackingParticle2->p4().px();
      ElectronTrackingParticle2Py = ElectronTrackingParticle2->p4().py();
      ElectronTrackingParticle2Pz = ElectronTrackingParticle2->p4().pz();
      ElectronTrackingParticle2E = ElectronTrackingParticle2->p4().e();
      ElectronTrackingParticle2Charge = ElectronTrackingParticle2->charge();

      if (isMatchedConversion1) {

	MatchedElectronTrack1Px = MatchedElectronTrack1.px();
	MatchedElectronTrack1Py = MatchedElectronTrack1.py();
	MatchedElectronTrack1Pz = MatchedElectronTrack1.pz();
	MatchedElectronTrack1Charge = MatchedElectronTrack1.charge();
	MatchedElectronTrack1NumberOfValidPixelHits = MatchedElectronTrack1.hitPattern().numberOfValidPixelHits();
      	MatchedElectronTrack1Algo = MatchedElectronTrack1.algo();
	MatchedElectronTrack1NumberOfMissingInnerHits = MatchedElectronTrack1.hitPattern().numberOfLostHits(reco::HitPattern::MISSING_INNER_HITS);
	
      }

      if (isMatchedConversion2) {

	MatchedElectronTrack2Px = MatchedElectronTrack2.px();
	MatchedElectronTrack2Py = MatchedElectronTrack2.py();
	MatchedElectronTrack2Pz = MatchedElectronTrack2.pz();
	MatchedElectronTrack2Charge = MatchedElectronTrack2.charge();
	MatchedElectronTrack2NumberOfValidPixelHits = MatchedElectronTrack2.hitPattern().numberOfValidPixelHits();
	MatchedElectronTrack2Algo = MatchedElectronTrack2.algo();
	MatchedElectronTrack2NumberOfMissingInnerHits = MatchedElectronTrack1.hitPattern().numberOfLostHits(reco::HitPattern::MISSING_INNER_HITS);

      }
    }

    if (hasRecoPhoton) {
      RecoPhotonPx = RecoPhoton.p4().px();
      RecoPhotonPy = RecoPhoton.p4().py();
      RecoPhotonPz = RecoPhoton.p4().pz();
      RecoPhotonE = RecoPhoton.p4().e();

      if (isRecoConversion) {

	RecoConversionVertexX_->reserve(RecoConversionVertex.size());
	RecoConversionVertexY_->reserve(RecoConversionVertex.size());
	RecoConversionVertexZ_->reserve(RecoConversionVertex.size());
	for (auto& RecoConversionVtx : RecoConversionVertex) {
	  RecoConversionVertexX_->push_back(RecoConversionVtx.x());
	  RecoConversionVertexY_->push_back(RecoConversionVtx.y());
	  RecoConversionVertexZ_->push_back(RecoConversionVtx.z());
	}

	RecoElectronTrack1Px_->reserve(RecoElectronTrack1.size());
	RecoElectronTrack1Py_->reserve(RecoElectronTrack1.size());
	RecoElectronTrack1Pz_->reserve(RecoElectronTrack1.size());
	RecoElectronTrack1Charge_->reserve(RecoElectronTrack1.size());
	RecoElectronTrack1NumberOfValidPixelHits_->reserve(RecoElectronTrack1.size());
	RecoElectronTrack1Algo_->reserve(RecoElectronTrack1.size());
	RecoElectronTrack1NumberOfMissingInnerHits_->reserve(RecoElectronTrack1.size());
	for (auto& RecoElectronTrk1 : RecoElectronTrack1) {
	  RecoElectronTrack1Px_->push_back(RecoElectronTrk1.px());
	  RecoElectronTrack1Py_->push_back(RecoElectronTrk1.py());
	  RecoElectronTrack1Pz_->push_back(RecoElectronTrk1.pz());
	  RecoElectronTrack1Charge_->push_back(RecoElectronTrk1.charge());
	  RecoElectronTrack1NumberOfValidPixelHits_->push_back(RecoElectronTrk1.hitPattern().numberOfValidPixelHits());
	  RecoElectronTrack1Algo_->push_back(RecoElectronTrk1.algo());
	  RecoElectronTrack1NumberOfMissingInnerHits_->push_back(RecoElectronTrk1.hitPattern().numberOfLostHits(reco::HitPattern::MISSING_INNER_HITS));
	}

	RecoElectronTrack2Px_->reserve(RecoElectronTrack2.size());
	RecoElectronTrack2Py_->reserve(RecoElectronTrack2.size());
	RecoElectronTrack2Pz_->reserve(RecoElectronTrack2.size());
	RecoElectronTrack2Charge_->reserve(RecoElectronTrack2.size());
	RecoElectronTrack2NumberOfValidPixelHits_->reserve(RecoElectronTrack2.size());
	RecoElectronTrack2Algo_->reserve(RecoElectronTrack2.size());
	RecoElectronTrack2NumberOfMissingInnerHits_->reserve(RecoElectronTrack1.size());
	for (auto& RecoElectronTrk2 : RecoElectronTrack2) {
	  RecoElectronTrack2Px_->push_back(RecoElectronTrk2.px());
	  RecoElectronTrack2Py_->push_back(RecoElectronTrk2.py());
	  RecoElectronTrack2Pz_->push_back(RecoElectronTrk2.pz());
	  RecoElectronTrack2Charge_->push_back(RecoElectronTrk2.charge());
	  RecoElectronTrack2NumberOfValidPixelHits_->push_back(RecoElectronTrk2.hitPattern().numberOfValidPixelHits());
	  RecoElectronTrack2Algo_->push_back(RecoElectronTrk2.algo());
	  RecoElectronTrack2NumberOfMissingInnerHits_->push_back(RecoElectronTrk2.hitPattern().numberOfLostHits(reco::HitPattern::MISSING_INNER_HITS));
	}
      }
      
      if (isRecoSingleLegConversion) {
	RecoSingleLegConversionVertexX_->reserve(RecoSingleLegConversionVertex.size());
	for (auto& RecoSingleLegConversionVtx : RecoSingleLegConversionVertex) {
	  RecoSingleLegConversionVertexX_->push_back(RecoSingleLegConversionVtx.x());
	  RecoSingleLegConversionVertexY_->push_back(RecoSingleLegConversionVtx.y());
	  RecoSingleLegConversionVertexZ_->push_back(RecoSingleLegConversionVtx.z());      
	}
	  
	RecoSingleLegElectronTrackPx_->reserve(RecoSingleLegElectronTrack.size());
	RecoSingleLegElectronTrackPy_->reserve(RecoSingleLegElectronTrack.size());
	RecoSingleLegElectronTrackPz_->reserve(RecoSingleLegElectronTrack.size());
	RecoSingleLegElectronTrackCharge_->reserve(RecoSingleLegElectronTrack.size());
	RecoSingleLegElectronTrackNumberOfValidPixelHits_->reserve(RecoSingleLegElectronTrack.size());
	RecoSingleLegElectronTrackAlgo_->reserve(RecoSingleLegElectronTrack.size());
	for (auto& RecoSingleLegElectronTrk : RecoSingleLegElectronTrack) {
	  RecoSingleLegElectronTrackPx_->push_back(RecoSingleLegElectronTrk.px());
	  RecoSingleLegElectronTrackPy_->push_back(RecoSingleLegElectronTrk.py());
	  RecoSingleLegElectronTrackPz_->push_back(RecoSingleLegElectronTrk.pz());
	  RecoSingleLegElectronTrackCharge_->push_back(RecoSingleLegElectronTrk.charge());	
	  RecoSingleLegElectronTrackNumberOfValidPixelHits_->push_back(RecoSingleLegElectronTrk.hitPattern().numberOfValidPixelHits());
	  RecoSingleLegElectronTrackAlgo_->push_back(RecoSingleLegElectronTrk.algo());
	  RecoSingleLegElectronTrackNumberOfMissingInnerHits_->push_back(RecoSingleLegElectronTrk.hitPattern().numberOfLostHits(reco::HitPattern::MISSING_INNER_HITS));
	}	

	SingleLegMVA_->reserve(OneLegMVA.size());
	for (auto& OneLeg : OneLegMVA)
	  SingleLegMVA_->push_back(OneLeg[0]);
      }       
    }
  
    babyTree->Fill();
  }
  
}


// ------------ method called once each job just before starting event loop  ------------
void 
ConversionAnalysis::beginJob()
{

  babyFile = TFile::Open(conf_.getUntrackedParameter<std::string>("outputFile").c_str(), "RECREATE");
  babyTree = new TTree("conversion", "Single Leg Conversion Baby");

  babyTree->Branch("isTruthConversion", &isTruthConversion, "isTruthConversion/O");
  babyTree->Branch("isRecoConversion", &isRecoConversion, "isRecoConversion/O");
  babyTree->Branch("isMatchedConversion1", &isMatchedConversion1, "isMatchedConversion1/O");
  babyTree->Branch("isMatchedConversion2", &isMatchedConversion2, "isMatchedConversion2/O");
  babyTree->Branch("isTruthSingleLegConversion", &isTruthSingleLegConversion, "isTruthSingleLegConversion/O");
  babyTree->Branch("isRecoSingleLegConversion", &isRecoSingleLegConversion, "isRecoSingleLegConversion/O");
  babyTree->Branch("hasRecoPhoton", &hasRecoPhoton, "hasRecoPhoton/O");
    
  babyTree->Branch("GenPhotonPx", &GenPhotonPx, "GenPhotonPx/D");
  babyTree->Branch("GenPhotonPy", &GenPhotonPy, "GenPhotonPy/D");
  babyTree->Branch("GenPhotonPz", &GenPhotonPz, "GenPhotonPz/D");
  babyTree->Branch("GenPhotonE", &GenPhotonE, "GenPhotonE/D");
    
  babyTree->Branch("SimConversionVertexX", &SimConversionVertexX, "SimConversionVertexX/D");
  babyTree->Branch("SimConversionVertexY", &SimConversionVertexY, "SimConversionVertexY/D");
  babyTree->Branch("SimConversionVertexZ", &SimConversionVertexZ, "SimConversionVertexZ/D");
  babyTree->Branch("SimConversionVertexT", &SimConversionVertexT, "SimConversionVertexT/D");
    
  babyTree->Branch("ElectronTrackingParticle1Px", &ElectronTrackingParticle1Px, "ElectronTrackingParticle1Px/D");
  babyTree->Branch("ElectronTrackingParticle1Py", &ElectronTrackingParticle1Py, "ElectronTrackingParticle1Py/D");
  babyTree->Branch("ElectronTrackingParticle1Pz", &ElectronTrackingParticle1Pz, "ElectronTrackingParticle1Pz/D");
  babyTree->Branch("ElectronTrackingParticle1E", &ElectronTrackingParticle1E, "ElectronTrackingParticle1E/D");
  babyTree->Branch("ElectronTrackingParticle1Charge", &ElectronTrackingParticle1Charge, "ElectronTrackingParticle1Charge/I");
    
  babyTree->Branch("ElectronTrackingParticle2Px", &ElectronTrackingParticle2Px, "ElectronTrackingParticle2Px/D");
  babyTree->Branch("ElectronTrackingParticle2Py", &ElectronTrackingParticle2Py, "ElectronTrackingParticle2Py/D");
  babyTree->Branch("ElectronTrackingParticle2Pz", &ElectronTrackingParticle2Pz, "ElectronTrackingParticle2Pz/D");
  babyTree->Branch("ElectronTrackingParticle2E", &ElectronTrackingParticle2E, "ElectronTrackingParticle2E/D");
  babyTree->Branch("ElectronTrackingParticle2Charge", &ElectronTrackingParticle2Charge, "ElectronTrackingParticle2Charge/I");
    
  babyTree->Branch("MatchedElectronTrack1Px", &MatchedElectronTrack1Px, "MatchedElectronTrack1Px/D");
  babyTree->Branch("MatchedElectronTrack1Py", &MatchedElectronTrack1Py, "MatchedElectronTrack1Py/D");
  babyTree->Branch("MatchedElectronTrack1Pz", &MatchedElectronTrack1Pz, "MatchedElectronTrack1Pz/D");
  babyTree->Branch("MatchedElectronTrack1Charge", &MatchedElectronTrack1Charge, "MatchedElectronTrack1Charge/I");
  babyTree->Branch("MatchedElectronTrack1NumberOfValidPixelHits", &MatchedElectronTrack1NumberOfValidPixelHits, "MatchedElectronTrack1NumberOfValidPixelHits/I");
  babyTree->Branch("MatchedElectronTrack1Algo", &MatchedElectronTrack1Algo, "MatchedElectronTrack1Algo/I");
  babyTree->Branch("MatchedElectronTrack1NumberOfMissingInnerHits", &MatchedElectronTrack1NumberOfMissingInnerHits, "MatchedElectronTrack1NumberOfMissingInnerHits/I");

  babyTree->Branch("MatchedElectronTrack2Px", &MatchedElectronTrack2Px, "MatchedElectronTrack2Px/D");
  babyTree->Branch("MatchedElectronTrack2Py", &MatchedElectronTrack2Py, "MatchedElectronTrack2Py/D");
  babyTree->Branch("MatchedElectronTrack2Pz", &MatchedElectronTrack2Pz, "MatchedElectronTrack2Pz/D");
  babyTree->Branch("MatchedElectronTrack2Charge", &MatchedElectronTrack2Charge, "MatchedElectronTrack2Charge/I");
  babyTree->Branch("MatchedElectronTrack2NumberOfValidPixelHits", &MatchedElectronTrack2NumberOfValidPixelHits, "MatchedElectronTrack2NumberOfValidPixelHits/I");
  babyTree->Branch("MatchedElectronTrack2Algo", &MatchedElectronTrack2Algo, "MatchedElectronTrack2Algo/I");
  babyTree->Branch("MatchedElectronTrack2NumberOfMissingInnerHits", &MatchedElectronTrack1NumberOfMissingInnerHits, "MatchedElectronTrack1NumberOfMissingInnerHits/I");
    
  babyTree->Branch("RecoPhotonPx", &RecoPhotonPx, "RecoPhotonPx/D");
  babyTree->Branch("RecoPhotonPy", &RecoPhotonPy, "RecoPhotonPy/D");
  babyTree->Branch("RecoPhotonPz", &RecoPhotonPz, "RecoPhotonPz/D");
  babyTree->Branch("RecoPhotonE", &RecoPhotonE, "RecoPhotonE/D");

  babyTree->Branch("nSingleLegConversions", &nSingleLegConversions, "nSingleLegConversions/I");
  babyTree->Branch("nDoubleLegConversions", &nDoubleLegConversions, "nDoubleLegConversions/I");
    
  babyTree->Branch("RecoConversionVertexX", "std::vector<double >", &RecoConversionVertexX_);
  babyTree->Branch("RecoConversionVertexY", "std::vector<double >", &RecoConversionVertexY_);
  babyTree->Branch("RecoConversionVertexZ", "std::vector<double >", &RecoConversionVertexZ_);
        
  babyTree->Branch("RecoElectronTrack1Px", "std::vector<double >", &RecoElectronTrack1Px_);
  babyTree->Branch("RecoElectronTrack1Py", "std::vector<double >", &RecoElectronTrack1Py_);
  babyTree->Branch("RecoElectronTrack1Pz", "std::vector<double >", &RecoElectronTrack1Pz_);
  babyTree->Branch("RecoElectronTrack1Charge", "std::vector<int >", &RecoElectronTrack1Charge_);
  babyTree->Branch("RecoElectronTrack1NumberOfValidPixelHits", "std::vector<int >", &RecoElectronTrack1NumberOfValidPixelHits_);
  babyTree->Branch("RecoElectronTrack1Algo", "std::vector<int >", &RecoElectronTrack1Algo_);
  babyTree->Branch("RecoElectronTrack1NumberOfMissingInnerHits", "std::vector<int >", &RecoElectronTrack1NumberOfMissingInnerHits_);

  babyTree->Branch("RecoElectronTrack2Px", "std::vector<double >", &RecoElectronTrack2Px_);
  babyTree->Branch("RecoElectronTrack2Py", "std::vector<double >", &RecoElectronTrack2Py_);
  babyTree->Branch("RecoElectronTrack2Pz", "std::vector<double >", &RecoElectronTrack2Pz_);
  babyTree->Branch("RecoElectronTrack2Charge", "std::vector<int >", &RecoElectronTrack2Charge_);
  babyTree->Branch("RecoElectronTrack2NumberOfValidPixelHits", "std::vector<int >", &RecoElectronTrack2NumberOfValidPixelHits_);
  babyTree->Branch("RecoElectronTrack2Algo", "std::vector<int >", &RecoElectronTrack2Algo_);
  babyTree->Branch("RecoElectronTrack2NumberOfMissingInnerHits", "std::vector<int >", &RecoElectronTrack2NumberOfMissingInnerHits_);

  babyTree->Branch("SingleLegMVA", "std::vector<double >", &SingleLegMVA_);
  babyTree->Branch("RecoSingleLegConversionVertexX", "std::vector<double >", &RecoSingleLegConversionVertexX_);
  babyTree->Branch("RecoSingleLegConversionVertexY", "std::vector<double >", &RecoSingleLegConversionVertexY_);
  babyTree->Branch("RecoSingleLegConversionVertexZ", "std::vector<double >", &RecoSingleLegConversionVertexZ_);
        
  babyTree->Branch("RecoSingleLegElectronTrackPx", "std::vector<double >", &RecoSingleLegElectronTrackPx_);
  babyTree->Branch("RecoSingleLegElectronTrackPy", "std::vector<double >", &RecoSingleLegElectronTrackPy_);
  babyTree->Branch("RecoSingleLegElectronTrackPz", "std::vector<double >", &RecoSingleLegElectronTrackPz_);
  babyTree->Branch("RecoSingleLegElectronTrackCharge", "std::vector<int >", &RecoSingleLegElectronTrackCharge_);
  babyTree->Branch("RecoSingleLegElectronTrackNumberOfValidPixelHits", "std::vector<int >", &RecoSingleLegElectronTrackNumberOfValidPixelHits_);
  babyTree->Branch("RecoSingleLegElectronTrackAlgo", "std::vector<int >", &RecoSingleLegElectronTrackAlgo_);
  babyTree->Branch("RecoSingleLegElectronTrackNumberOfMissingInnerHits", "std::vector<int >", &RecoSingleLegElectronTrackNumberOfMissingInnerHits_);
}

// ------------ method called once each job just after ending the event loop  ------------
void 
ConversionAnalysis::endJob() 
{
  babyFile->Write();
  babyFile->Close();
}


//define this as a plug-in
DEFINE_FWK_MODULE(ConversionAnalysis);
