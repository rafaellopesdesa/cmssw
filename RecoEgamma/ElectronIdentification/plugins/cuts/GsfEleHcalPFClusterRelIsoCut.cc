#include "PhysicsTools/SelectorUtils/interface/CutApplicatorBase.h"

#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/PatCandidates/interface/Electron.h"

#include "RecoEgamma/ElectronIdentification/interface/EBEECutValues.h"

class GsfEleHcalPFClusterRelIsoCut : public CutApplicatorBase {
public:
  GsfEleHcalPFClusterRelIsoCut(const edm::ParameterSet& c);
  
  result_type operator()(const reco::GsfElectronPtr&) const override final;

  double value(const reco::CandidatePtr& cand) const override final;

  CandidateType candidateType() const override final { 
    return ELECTRON; 
  }

private:
  
  const double _hcalPFClusterRelIsoCutValueEB,_hcalPFClusterRelIsoCutValueEE,_barrelCutOff;   
  edm::Handle<edm::ValueMap<float> > hcalPFClusterIsoMapH;
};

DEFINE_EDM_PLUGIN(CutApplicatorFactory,
		  GsfEleHcalPFClusterRelIsoCut,
		  "GsfEleHcalPFClusterRelIsoCut");

GsfEleHcalPFClusterRelIsoCut::GsfEleHcalPFClusterRelIsoCut(const edm::ParameterSet& params) :
  CutApplicatorBase(params),
  _hcalPFClusterRelIsoCutValueEB(params.getParameter<double>("hcalPFClusterRelIsoCutValueEB")),
  _hcalPFClusterRelIsoCutValueEE(params.getParameter<double>("hcalPFClusterRelIsoCutValueEE")),
  _barrelCutOff(params.getParameter<double>("barrelCutOff"))
{

}


CutApplicatorBase::result_type 
GsfEleHcalPFClusterRelIsoCut::
operator()(const reco::GsfElectronPtr& cand) const{  
  
  edm::Ptr<pat::Electron> pat(cand);

  const float isolHcalPFCluster = pat->hcalPFClusterIso();  
  const float pt = pat->pt();

  const float cutValue =
    ( std::abs(pat->superCluster()->position().eta()) < _barrelCutOff ?
      _hcalPFClusterRelIsoCutValueEB : _hcalPFClusterRelIsoCutValueEE );

  return isolHcalPFCluster/pt < cutValue;
}

double GsfEleHcalPFClusterRelIsoCut::
value(const reco::CandidatePtr& cand) const {
  reco::GsfElectronPtr ele(cand);  
  edm::Ptr<pat::Electron> pat(ele);
  return pat->hcalPFClusterIso()/pat->pt();
}
