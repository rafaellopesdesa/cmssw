#include "PhysicsTools/SelectorUtils/interface/CutApplicatorBase.h"

#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/PatCandidates/interface/Electron.h"

#include "RecoEgamma/ElectronIdentification/interface/EBEECutValues.h"

class GsfEleEcalPFClusterRelIsoCut : public CutApplicatorBase {
public:
  GsfEleEcalPFClusterRelIsoCut(const edm::ParameterSet& c);
  
  result_type operator()(const reco::GsfElectronPtr&) const override final;

  double value(const reco::CandidatePtr& cand) const override final;

  CandidateType candidateType() const override final { 
    return ELECTRON; 
  }

private:
  
  const double _ecalPFClusterRelIsoCutValueEB,_ecalPFClusterRelIsoCutValueEE,_barrelCutOff;   
  edm::Handle<edm::ValueMap<float> > ecalPFClusterIsoMapH;
};

DEFINE_EDM_PLUGIN(CutApplicatorFactory,
		  GsfEleEcalPFClusterRelIsoCut,
		  "GsfEleEcalPFClusterRelIsoCut");

GsfEleEcalPFClusterRelIsoCut::GsfEleEcalPFClusterRelIsoCut(const edm::ParameterSet& params) :
  CutApplicatorBase(params),
  _ecalPFClusterRelIsoCutValueEB(params.getParameter<double>("ecalPFClusterRelIsoCutValueEB")),
  _ecalPFClusterRelIsoCutValueEE(params.getParameter<double>("ecalPFClusterRelIsoCutValueEE")),
  _barrelCutOff(params.getParameter<double>("barrelCutOff"))
{

}


CutApplicatorBase::result_type 
GsfEleEcalPFClusterRelIsoCut::
operator()(const reco::GsfElectronPtr& cand) const{  
  
  edm::Ptr<pat::Electron> pat(cand);

  const float isolEcalPFCluster = pat->ecalPFClusterIso();  
  const float pt = pat->pt();

  const float cutValue =
    ( std::abs(pat->superCluster()->position().eta()) < _barrelCutOff ?
      _ecalPFClusterRelIsoCutValueEB : _ecalPFClusterRelIsoCutValueEE );

  return isolEcalPFCluster/pt < cutValue;
}

double GsfEleEcalPFClusterRelIsoCut::
value(const reco::CandidatePtr& cand) const {
  reco::GsfElectronPtr ele(cand);  
  edm::Ptr<pat::Electron> pat(ele);
  return pat->ecalPFClusterIso()/pat->pt();
}
