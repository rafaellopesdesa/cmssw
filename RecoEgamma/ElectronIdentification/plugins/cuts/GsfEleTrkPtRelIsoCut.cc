#include "PhysicsTools/SelectorUtils/interface/CutApplicatorBase.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/ConversionFwd.h"
#include "DataFormats/EgammaCandidates/interface/Conversion.h"
#include "RecoEgamma/EgammaTools/interface/ConversionTools.h"

#include "RecoEgamma/ElectronIdentification/interface/EBEECutValues.h"

class GsfEleTrkPtRelIsoCut : public CutApplicatorBase {
public:
  GsfEleTrkPtRelIsoCut(const edm::ParameterSet& c);
  
  result_type operator()(const reco::GsfElectronPtr&) const override final;

  double value(const reco::CandidatePtr& cand) const override final;

  CandidateType candidateType() const override final { 
    return ELECTRON; 
  }

private:

  const double _trkPtRelIsoCutValueEB,_trkPtRelIsoCutValueEE,_barrelCutOff;   
};

DEFINE_EDM_PLUGIN(CutApplicatorFactory,
		  GsfEleTrkPtRelIsoCut,
		  "GsfEleTrkPtRelIsoCut");

GsfEleTrkPtRelIsoCut::GsfEleTrkPtRelIsoCut(const edm::ParameterSet& params) :
  CutApplicatorBase(params),
  _trkPtRelIsoCutValueEB(params.getParameter<double>("trkPtRelIsoCutValueEB")),
  _trkPtRelIsoCutValueEE(params.getParameter<double>("trkPtRelIsoCutValueEE")),
  _barrelCutOff(params.getParameter<double>("barrelCutOff"))
{

}


CutApplicatorBase::result_type 
GsfEleTrkPtRelIsoCut::
operator()(const reco::GsfElectronPtr& cand) const{  

  const float isolTrkPt = cand->dr03TkSumPt()/cand->pt();  

  const float cutValue =
    ( std::abs(cand->superCluster()->position().eta()) < _barrelCutOff ?
      _trkPtRelIsoCutValueEB : _trkPtRelIsoCutValueEE );

  return isolTrkPt < cutValue;
}

double GsfEleTrkPtRelIsoCut::
value(const reco::CandidatePtr& cand) const {
  reco::GsfElectronPtr ele(cand);  
  return ele->dr03TkSumPt()/ele->pt();
}
