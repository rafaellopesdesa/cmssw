#ifndef __WWREWEIGHT_PRODUCER__
#define __WWREWEIGHT_PRODUCER__

// system include files
#define _USE_MATH_DEFINES
#include <cmath> 
#include <memory>
#include <iostream>
#include <string>
#include <algorithm>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "PhysicsTools/HepMCCandAlgos/interface/MCTruthHelper.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "Math/VectorUtil.h"

typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

template < typename T, typename U >
class WWreweightProducer : public edm::EDProducer {
   public:
      WWreweightProducer(const edm::ParameterSet&);
      ~WWreweightProducer();

   private:

      virtual void produce(edm::Event&, const edm::EventSetup&) override;
      edm::EDGetTokenT<T> genParticlesToken;
      edm::EDGetTokenT<U> genJetsToken;
      bool makeHistograms;
      std::string reweightingSample;
      std::vector<double> reweightingFactors_central;
      std::vector<double> reweightingFactors_Qup;
      std::vector<double> reweightingFactors_Qdown;
      std::vector<double> reweightingFactors_Rup;
      std::vector<double> reweightingFactors_Rdown;

      TH1D* h_WWpT;
      TH1D* h_WWpT_genweightsup;
      TH1D* h_WWpT_genweightsdown;
      TH1D* h_WWpT_central;
      TH1D* h_WWpT_Qup;
      TH1D* h_WWpT_Qdown;
      TH1D* h_WWpT_Rup;
      TH1D* h_WWpT_Rdown;
      TH1D* h_WWpT_0jet;
      TH1D* h_WWpT_genweightsup_0jet;
      TH1D* h_WWpT_genweightsdown_0jet;
      TH1D* h_WWpT_central_0jet;
      TH1D* h_WWpT_Qup_0jet;
      TH1D* h_WWpT_Qdown_0jet;
      TH1D* h_WWpT_Rup_0jet;
      TH1D* h_WWpT_Rdown_0jet;
      TH1D* h_WWpT_1jet;
      TH1D* h_WWpT_genweightsup_1jet;
      TH1D* h_WWpT_genweightsdown_1jet;
      TH1D* h_WWpT_central_1jet;
      TH1D* h_WWpT_Qup_1jet;
      TH1D* h_WWpT_Qdown_1jet;
      TH1D* h_WWpT_Rup_1jet;
      TH1D* h_WWpT_Rdown_1jet;
      TH1D* h_WWpT_2jet;
      TH1D* h_WWpT_genweightsup_2jet;
      TH1D* h_WWpT_genweightsdown_2jet;
      TH1D* h_WWpT_central_2jet;
      TH1D* h_WWpT_Qup_2jet;
      TH1D* h_WWpT_Qdown_2jet;
      TH1D* h_WWpT_Rup_2jet;
      TH1D* h_WWpT_Rdown_2jet;
      TH1D* h_LeadingLeptonpT;
      TH1D* h_LeadingLeptonpT_genweightsup;
      TH1D* h_LeadingLeptonpT_genweightsdown;
      TH1D* h_LeadingLeptonpT_central;
      TH1D* h_LeadingLeptonpT_Qup;
      TH1D* h_LeadingLeptonpT_Qdown;
      TH1D* h_LeadingLeptonpT_Rup;
      TH1D* h_LeadingLeptonpT_Rdown;
      TH1D* h_LeadingLeptonpT_0jet;
      TH1D* h_LeadingLeptonpT_genweightsup_0jet;
      TH1D* h_LeadingLeptonpT_genweightsdown_0jet;
      TH1D* h_LeadingLeptonpT_central_0jet;
      TH1D* h_LeadingLeptonpT_Qup_0jet;
      TH1D* h_LeadingLeptonpT_Qdown_0jet;
      TH1D* h_LeadingLeptonpT_Rup_0jet;
      TH1D* h_LeadingLeptonpT_Rdown_0jet;
      TH1D* h_LeadingLeptonpT_1jet;
      TH1D* h_LeadingLeptonpT_genweightsup_1jet;
      TH1D* h_LeadingLeptonpT_genweightsdown_1jet;
      TH1D* h_LeadingLeptonpT_central_1jet;
      TH1D* h_LeadingLeptonpT_Qup_1jet;
      TH1D* h_LeadingLeptonpT_Qdown_1jet;
      TH1D* h_LeadingLeptonpT_Rup_1jet;
      TH1D* h_LeadingLeptonpT_Rdown_1jet;
      TH1D* h_LeadingLeptonpT_2jet;
      TH1D* h_LeadingLeptonpT_genweightsup_2jet;
      TH1D* h_LeadingLeptonpT_genweightsdown_2jet;
      TH1D* h_LeadingLeptonpT_central_2jet;
      TH1D* h_LeadingLeptonpT_Qup_2jet;
      TH1D* h_LeadingLeptonpT_Qdown_2jet;
      TH1D* h_LeadingLeptonpT_Rup_2jet;
      TH1D* h_LeadingLeptonpT_Rdown_2jet;
      TH1D* h_AK04jets30;
      TH1D* h_AK04jets30_genweightsup;
      TH1D* h_AK04jets30_genweightsdown;
      TH1D* h_AK04jets30_central;
      TH1D* h_AK04jets30_Qup;
      TH1D* h_AK04jets30_Qdown;
      TH1D* h_AK04jets30_Rup;
      TH1D* h_AK04jets30_Rdown;
      TH1D* h_AK04jets30_0jet;
      TH1D* h_AK04jets30_genweightsup_0jet;
      TH1D* h_AK04jets30_genweightsdown_0jet;
      TH1D* h_AK04jets30_central_0jet;
      TH1D* h_AK04jets30_Qup_0jet;
      TH1D* h_AK04jets30_Qdown_0jet;
      TH1D* h_AK04jets30_Rup_0jet;
      TH1D* h_AK04jets30_Rdown_0jet;
      TH1D* h_AK04jets30_1jet;
      TH1D* h_AK04jets30_genweightsup_1jet;
      TH1D* h_AK04jets30_genweightsdown_1jet;
      TH1D* h_AK04jets30_central_1jet;
      TH1D* h_AK04jets30_Qup_1jet;
      TH1D* h_AK04jets30_Qdown_1jet;
      TH1D* h_AK04jets30_Rup_1jet;
      TH1D* h_AK04jets30_Rdown_1jet;
      TH1D* h_AK04jets30_2jet;
      TH1D* h_AK04jets30_genweightsup_2jet;
      TH1D* h_AK04jets30_genweightsdown_2jet;
      TH1D* h_AK04jets30_central_2jet;
      TH1D* h_AK04jets30_Qup_2jet;
      TH1D* h_AK04jets30_Qdown_2jet;
      TH1D* h_AK04jets30_Rup_2jet;
      TH1D* h_AK04jets30_Rdown_2jet;

};

template<typename T, typename U> WWreweightProducer<T,U>::WWreweightProducer(const edm::ParameterSet& iConfig) : 
  genParticlesToken( consumes<T>( iConfig.template getParameter<edm::InputTag>( "src" ) ) ),
  genJetsToken( consumes<U>( iConfig.template getParameter<edm::InputTag>( "jets" ) ) ),
  makeHistograms( iConfig.getParameter<bool>( "makeHistograms" ) ),
  reweightingSample( iConfig.getParameter<std::string>( "reweightingSample" ) )
{ 
  
  produces<double>( "central" );
  produces<double>( "Rup" );
  produces<double>( "Rdown" );
  produces<double>( "Qup" );
  produces<double>( "Qdown" );

  std::vector<std::string> knownDatasets;
  knownDatasets.push_back("/WWTo2L2Nu_13TeV-powheg/RunIIWinter15GS-MCRUN2_71_V1-v1/GEN-SIM");

  if (find(knownDatasets.begin(), knownDatasets.end(), reweightingSample) == knownDatasets.end()) {
    throw cms::Exception("UnknownDataset") <<
      "I don't know the dataset " << reweightingSample.c_str() << std::endl;
  } else if (reweightingSample.compare("/WWTo2L2Nu_13TeV-powheg/RunIIWinter15GS-MCRUN2_71_V1-v1/GEN-SIM") == 0) {
    
    reweightingFactors_central = {1.6018, 1.5692, 1.4683, 1.3578, 1.2935, 1.2204, 1.1765, 1.1453, 1.1223, 1.1076, 1.088, 1.0848, 1.0723, 1.082, 1.0695, 1.0711, 1.0622, 1.0573, 1.0691, 1.0576, 1.0479, 1.0455, 1.0521, 1.0346, 1.0368, 1.0352, 1.0346, 1.037, 1.0268, 1.0091, 1.0186, 1.0317, 1.0151, 1.016, 1.0204, 1.0076, 0.99879, 1.0064, 1.0024, 0.99581, 0.99513, 0.97461, 1.0027, 0.9822, 0.99182, 0.99743, 0.98574, 0.9731, 0.99286, 1.0071, 0.98165, 0.98392, 0.96506, 0.99376, 0.96922, 0.99215, 0.9914, 0.96924, 0.9754, 0.97314, 0.97763, 0.97235, 0.96582, 0.94414, 0.97247, 0.94307, 0.94992, 0.94385, 0.96833, 0.96201, 0.93631, 0.95368, 0.9536, 0.94646, 0.95281, 0.97027, 0.96519, 0.94486, 0.9596, 0.96567, 0.93849, 0.93747, 0.95691, 0.96031, 0.95319, 0.94265, 0.93108, 0.93787, 0.94038, 0.91762, 0.91956, 0.91745, 0.92686, 0.9261, 0.92902, 0.9378, 0.92011, 0.94456, 0.93044, 0.97319, 0.94622, 0.95677, 0.95706, 0.94578, 0.93348, 0.94926, 0.96996, 0.9417, 0.9238, 0.91127, 0.94604, 0.91139, 0.92831, 0.91082, 0.91245, 0.91407, 0.92611, 0.89288, 0.88529, 0.92231, 0.91535, 0.93047, 0.90041, 0.91621, 0.91155, 0.94182, 0.89825, 0.94243, 0.9256, 0.93202, 0.93618, 0.91556, 0.90254, 0.90905, 0.91636, 0.92049, 0.92298, 0.8966, 0.90114, 0.87081, 0.8928, 0.90602, 0.85697, 0.89365, 0.8504, 0.87063, 0.93021, 0.87253, 0.8934, 0.88879, 0.90026, 0.90887, 0.91499, 0.93284, 0.89736, 0.91112, 0.91731, 0.88695, 0.89915, 0.92728, 0.87641, 0.87929, 0.85045, 0.87912, 0.87133, 0.86116, 0.85001, 0.8802, 0.85594, 0.85153, 0.88399, 0.86906, 0.90885, 0.91293, 0.91098, 0.88676, 0.87178, 0.90087, 0.89948, 0.85897, 0.89649, 0.91167, 0.93598, 0.87681, 0.87504, 0.88057, 0.90631, 0.85273, 0.84743, 0.86231, 0.82545, 0.80748, 0.84084, 0.80682, 0.85624, 0.86844, 0.85708, 0.89498, 0.90907, 0.89802, 0.89351, 0.91955, 0.91142, 0.92476, 0.87112, 0.90917, 0.87374, 0.9088, 0.83579, 0.86386, 0.8037, 0.86674, 0.83939, 0.79942, 0.8253, 0.81832, 0.7863, 0.8683, 0.87781, 0.78433, 0.80807, 0.86437, 0.86158, 0.88932, 0.9062, 0.88668, 0.97225, 0.8794, 0.87213, 0.91322, 0.85788, 0.82148, 0.84422, 0.83283, 0.82661, 0.83241, 0.85783, 0.83516, 0.81569, 0.79605, 0.81657, 0.82265, 0.78156, 0.78877, 0.79505, 0.84843, 0.8363, 0.85652, 0.8344, 0.87409, 0.85466, 0.88205, 0.86433, 0.86107, 0.89657, 0.89174, 0.84295, 0.83775, 0.86319, 0.83772, 0.90711, 0.85245, 0.83536, 0.81482, 0.82318, 0.77786, 0.76606, 0.76635, 0.77896, 0.85912, 0.78718, 0.84345, 0.84783, 0.86884, 0.84687, 0.85111, 0.84417, 0.85374, 0.84326, 0.84471, 0.82675, 0.88029, 0.83821, 0.77781, 0.82009, 0.82749, 0.84119, 0.88502, 0.81755, 0.79166, 0.76548, 0.78936, 0.8496, 0.83229, 0.84183, 0.81172, 0.81736, 0.836, 0.80565, 0.81729, 0.82577, 0.81668, 0.74897, 0.81659, 0.82242, 0.82023, 0.84431, 0.81567, 0.86091, 0.8738, 0.81685, 0.81783, 0.88669, 0.80085, 0.78163, 0.86337, 0.81927, 0.82554, 0.83791, 0.83384};

    reweightingFactors_Qup = {1.0674, 1.1848, 1.1838, 1.1269, 1.097, 1.0545, 1.0352, 1.0256, 1.0206, 1.0191, 1.0093, 1.0134, 1.0093, 1.027, 1.0233, 1.031, 1.0261, 1.024, 1.0392, 1.0332, 1.0293, 1.0312, 1.0396, 1.0231, 1.027, 1.0288, 1.0328, 1.0388, 1.0301, 1.0122, 1.0223, 1.038, 1.0253, 1.03, 1.0362, 1.0228, 1.0136, 1.023, 1.0225, 1.0196, 1.0209, 0.99931, 1.0269, 1.0064, 1.019, 1.0284, 1.0184, 1.0048, 1.0233, 1.0373, 1.0131, 1.019, 1.0022, 1.0322, 1.0049, 1.0275, 1.0284, 1.0093, 1.0196, 1.0185, 1.0218, 1.0147, 1.0088, 0.98961, 1.0235, 0.99447, 1.0002, 0.99117, 1.0162, 1.0119, 0.98852, 1.009, 1.0075, 0.99646, 1.0011, 1.0208, 1.0193, 1.001, 1.0166, 1.02, 0.98907, 0.98922, 1.0142, 1.0228, 1.0171, 1.0039, 0.98907, 0.99667, 1.0034, 0.98415, 0.98872, 0.98444, 0.9904, 0.98761, 0.99268, 1.0062, 0.98975, 1.014, 0.99376, 1.0356, 1.0076, 1.0231, 1.0276, 1.0155, 0.9985, 1.0118, 1.0347, 1.0098, 0.99683, 0.98614, 1.0216, 0.98058, 0.99853, 0.98415, 0.99234, 0.99768, 1.0085, 0.96676, 0.95512, 0.99651, 0.99365, 1.0133, 0.97825, 0.98864, 0.97805, 1.0102, 0.96795, 1.0207, 1.0031, 1.0054, 1.0049, 0.98289, 0.97475, 0.98969, 1.002, 1.0044, 1.0023, 0.9725, 0.9822, 0.95676, 0.98587, 0.99815, 0.93712, 0.97181, 0.92539, 0.95243, 1.0219, 0.9563, 0.9709, 0.95824, 0.96915, 0.98331, 0.99634, 1.0174, 0.9735, 0.98185, 0.98755, 0.96119, 0.98417, 1.0213, 0.96363, 0.96085, 0.92697, 0.96307, 0.96383, 0.95923, 0.94498, 0.96959, 0.93538, 0.9301, 0.97124, 0.96016, 1.0022, 0.9966, 0.98434, 0.95544, 0.94427, 0.98375, 0.98509, 0.93535, 0.96774, 0.9816, 1.0148, 0.96211, 0.96834, 0.97326, 0.9939, 0.93086, 0.92943, 0.95652, 0.92416, 0.90307, 0.93021, 0.88301, 0.93528, 0.95491, 0.94953, 0.99073, 0.99501, 0.96977, 0.95991, 0.99335, 0.9946, 1.0141, 0.94982, 0.98059, 0.93796, 0.98234, 0.91635, 0.95781, 0.89083, 0.95147, 0.91474, 0.87444, 0.91442, 0.91754, 0.88186, 0.96176, 0.95876, 0.85332, 0.88569, 0.95704, 0.95517, 0.97422, 0.97655, 0.94822, 1.0456, 0.95768, 0.95688, 0.99645, 0.92349, 0.87741, 0.90718, 0.90947, 0.91552, 0.92271, 0.93975, 0.905, 0.88565, 0.87669, 0.91291, 0.92186, 0.8639, 0.85665, 0.85798, 0.92312, 0.92218, 0.9486, 0.91317, 0.93819, 0.90763, 0.94197, 0.93734, 0.94403, 0.97843, 0.95737, 0.89431, 0.89266, 0.9362, 0.92433, 1.0031, 0.92935, 0.89659, 0.87364, 0.89601, 0.86258, 0.85409, 0.84236, 0.83817, 0.91584, 0.8468, 0.92347, 0.93647, 0.94936, 0.90472, 0.89621, 0.89341, 0.92043, 0.92295, 0.92158, 0.88446, 0.92569, 0.88276, 0.83481, 0.89852, 0.91031, 0.90996, 0.93718, 0.86123, 0.84682, 0.8373, 0.87137, 0.92475, 0.8834, 0.88196, 0.85868, 0.88439, 0.91804, 0.87745, 0.86794, 0.86057, 0.85458, 0.80132, 0.89167, 0.89726, 0.87445, 0.87878, 0.84638, 0.9108, 0.94696, 0.8909, 0.87498, 0.92266, 0.82449, 0.81685, 0.92654, 0.89182, 0.88736, 0.87509, 0.85565};

    reweightingFactors_Qdown = {2.9408, 2.3845, 1.9755, 1.7309, 1.5868, 1.4529, 1.368, 1.307, 1.2605, 1.2274, 1.1925, 1.1773, 1.1536, 1.1556, 1.1345, 1.1292, 1.1142, 1.1037, 1.1108, 1.0946, 1.0805, 1.0738, 1.077, 1.0555, 1.0537, 1.0484, 1.0444, 1.0428, 1.0289, 1.0078, 1.0136, 1.0233, 1.0043, 1.0024, 1.0044, 0.99035, 0.98023, 0.98647, 0.98223, 0.97532, 0.97397, 0.95381, 0.98068, 0.95936, 0.96764, 0.97135, 0.95706, 0.94197, 0.95781, 0.96709, 0.93863, 0.93701, 0.91477, 0.93832, 0.91265, 0.93167, 0.92944, 0.90873, 0.91478, 0.91368, 0.92036, 0.91767, 0.91364, 0.89588, 0.92473, 0.89744, 0.90452, 0.89798, 0.91852, 0.90939, 0.88106, 0.89156, 0.88575, 0.87355, 0.87302, 0.88356, 0.87503, 0.85303, 0.86438, 0.87027, 0.84681, 0.8483, 0.87053, 0.87839, 0.87669, 0.87283, 0.86683, 0.87631, 0.88156, 0.86116, 0.86125, 0.85675, 0.86135, 0.85396, 0.8498, 0.85078, 0.82662, 0.84146, 0.82359, 0.85613, 0.82936, 0.83847, 0.83939, 0.83196, 0.82631, 0.84576, 0.87014, 0.85214, 0.84214, 0.8353, 0.87202, 0.84279, 0.85822, 0.84119, 0.83999, 0.83581, 0.84088, 0.80464, 0.79007, 0.81615, 0.80473, 0.81235, 0.78254, 0.79554, 0.79104, 0.8185, 0.78456, 0.82711, 0.81645, 0.82819, 0.83693, 0.82199, 0.81456, 0.82313, 0.8299, 0.83409, 0.83555, 0.80825, 0.80945, 0.77946, 0.79435, 0.80246, 0.75699, 0.7861, 0.74624, 0.76432, 0.81598, 0.76545, 0.78601, 0.78293, 0.79355, 0.80341, 0.80966, 0.8248, 0.79431, 0.80636, 0.80982, 0.78278, 0.79326, 0.81603, 0.77133, 0.77504, 0.74931, 0.77618, 0.77263, 0.76513, 0.75763, 0.78862, 0.76835, 0.76526, 0.79646, 0.78207, 0.81509, 0.81718, 0.81095, 0.78313, 0.76622, 0.78709, 0.77981, 0.74183, 0.77227, 0.78254, 0.80437, 0.75677, 0.75768, 0.76799, 0.79876, 0.75753, 0.75987, 0.78193, 0.75345, 0.74058, 0.77536, 0.74381, 0.78629, 0.79498, 0.77865, 0.80408, 0.80974, 0.79176, 0.77809, 0.79467, 0.78296, 0.78892, 0.74242, 0.77705, 0.74818, 0.78362, 0.72867, 0.75957, 0.71431, 0.78088, 0.76293, 0.73207, 0.76259, 0.7584, 0.72824, 0.8048, 0.81009, 0.71779, 0.7355, 0.7806, 0.76949, 0.78914, 0.79938, 0.77553, 0.84766, 0.76623, 0.7573, 0.79385, 0.74928, 0.71834, 0.7411, 0.7369, 0.73411, 0.7425, 0.77181, 0.75464, 0.73922, 0.72682, 0.74827, 0.75435, 0.72038, 0.72872, 0.73298, 0.78373, 0.77277, 0.7873, 0.76533, 0.7998, 0.77529, 0.79513, 0.77554, 0.76446, 0.78923, 0.78172, 0.73276, 0.72394, 0.74719, 0.72494, 0.78664, 0.74786, 0.74084, 0.73044, 0.75183, 0.72237, 0.71994, 0.73172, 0.75274, 0.83276, 0.76569, 0.82004, 0.81528, 0.82582, 0.79466, 0.78126, 0.75866, 0.75433, 0.72886, 0.7171, 0.69683, 0.73661, 0.70036, 0.65827, 0.70425, 0.72283, 0.75583, 0.8169, 0.77144, 0.76697, 0.75748, 0.78902, 0.85703, 0.84198, 0.8425, 0.80168, 0.79411, 0.78959, 0.73972, 0.73253, 0.71815, 0.69275, 0.62818, 0.67789, 0.6813, 0.69022, 0.72337, 0.71363, 0.77876, 0.81516, 0.78088, 0.80431, 0.89091, 0.81144, 0.79765, 0.8811, 0.8237, 0.81607, 0.8122, 0.78268};

    reweightingFactors_Rup = {2.109, 2.0133, 1.8163, 1.6218, 1.5001, 1.3807, 1.3044, 1.2495, 1.2075, 1.1779, 1.1459, 1.1327, 1.1112, 1.1142, 1.0949, 1.0907, 1.077, 1.0676, 1.0754, 1.0605, 1.0478, 1.0424, 1.0466, 1.0271, 1.0269, 1.0234, 1.0212, 1.0214, 1.0097, 0.99075, 0.99809, 1.0091, 0.99151, 0.99045, 0.99291, 0.97908, 0.96887, 0.97455, 0.96967, 0.96212, 0.96018, 0.93988, 0.96633, 0.94582, 0.95503, 0.96041, 0.94867, 0.93663, 0.95584, 0.96901, 0.9444, 0.94656, 0.92754, 0.95434, 0.93027, 0.95084, 0.94867, 0.92651, 0.93072, 0.92682, 0.9301, 0.92367, 0.91598, 0.89495, 0.92123, 0.89264, 0.89947, 0.89416, 0.91738, 0.91235, 0.8891, 0.90595, 0.9068, 0.90109, 0.90713, 0.92391, 0.91943, 0.89919, 0.91217, 0.9173, 0.88974, 0.88676, 0.90385, 0.90499, 0.89594, 0.88488, 0.87262, 0.87732, 0.87944, 0.85812, 0.85955, 0.85857, 0.86881, 0.86884, 0.87333, 0.88378, 0.8681, 0.89258, 0.88096, 0.92163, 0.89609, 0.90645, 0.90546, 0.89299, 0.88025, 0.89271, 0.90907, 0.8807, 0.8615, 0.8469, 0.87783, 0.84448, 0.8585, 0.84251, 0.84487, 0.84661, 0.85958, 0.8313, 0.8257, 0.8626, 0.85913, 0.87472, 0.8478, 0.86459, 0.86017, 0.888, 0.84688, 0.8867, 0.86805, 0.87231, 0.87329, 0.85021, 0.83591, 0.83945, 0.8429, 0.84542, 0.84711, 0.82161, 0.82651, 0.80063, 0.82184, 0.8365, 0.7948, 0.83097, 0.79319, 0.81552, 0.8728, 0.81944, 0.84064, 0.83569, 0.8446, 0.8518, 0.85498, 0.86757, 0.83214, 0.84177, 0.84306, 0.81289, 0.82224, 0.84498, 0.79807, 0.80149, 0.77492, 0.80272, 0.79901, 0.79151, 0.78399, 0.81627, 0.79594, 0.79365, 0.82706, 0.81374, 0.85026, 0.85461, 0.85119, 0.82517, 0.80944, 0.83344, 0.82733, 0.7875, 0.81933, 0.82896, 0.84931, 0.79531, 0.79196, 0.79756, 0.82369, 0.77608, 0.77377, 0.79215, 0.76077, 0.74663, 0.78182, 0.75175, 0.798, 0.81112, 0.79968, 0.83185, 0.84355, 0.83028, 0.82078, 0.84167, 0.83114, 0.83805, 0.78723, 0.82075, 0.78619, 0.81785, 0.75455, 0.78055, 0.72856, 0.79102, 0.76886, 0.7352, 0.76437, 0.7603, 0.73147, 0.81071, 0.81934, 0.72937, 0.75053, 0.79965, 0.79094, 0.8127, 0.82392, 0.79946, 0.87279, 0.78743, 0.77686, 0.81266, 0.76552, 0.73324, 0.75623, 0.75207, 0.75023, 0.76016, 0.79137, 0.77506, 0.76005, 0.74687, 0.76761, 0.77141, 0.73274, 0.7363, 0.73504, 0.77923, 0.76188, 0.77049, 0.74447, 0.77503, 0.75068, 0.77165, 0.7568, 0.75272, 0.78622, 0.78925, 0.7509, 0.75281, 0.7868, 0.77128, 0.84239, 0.8015, 0.79085, 0.77283, 0.78392, 0.73962, 0.72211, 0.7177, 0.72234, 0.78338, 0.70842, 0.74975, 0.74071, 0.75047, 0.72723, 0.7246, 0.7173, 0.73025, 0.72462, 0.73266, 0.72994, 0.78854, 0.76187, 0.72157, 0.77233, 0.78719, 0.81061, 0.85814, 0.79073, 0.76461, 0.7341, 0.74429, 0.78898, 0.75982, 0.74926, 0.70751, 0.70081, 0.70187, 0.66736, 0.67514, 0.67922, 0.67405, 0.62833, 0.69523, 0.71279, 0.73088, 0.77008, 0.75864, 0.82059, 0.84771, 0.79917, 0.80797, 0.87822, 0.78568, 0.75962, 0.8273, 0.76476, 0.7517, 0.74491, 0.71712};

    reweightingFactors_Rdown = {1.3002, 1.267, 1.2023, 1.1403, 1.1102, 1.0676, 1.0499, 1.0383, 1.0294, 1.0292, 1.0222, 1.0264, 1.0232, 1.0413, 1.0338, 1.0411, 1.0397, 1.0381, 1.0533, 1.0482, 1.0413, 1.0407, 1.0526, 1.0375, 1.0402, 1.0429, 1.0451, 1.047, 1.0401, 1.0252, 1.034, 1.0498, 1.0368, 1.0368, 1.0431, 1.0343, 1.0248, 1.0335, 1.0341, 1.0275, 1.0267, 1.0101, 1.0399, 1.0174, 1.0314, 1.0384, 1.0237, 1.0135, 1.0357, 1.047, 1.0223, 1.0269, 1.0036, 1.0342, 1.0119, 1.0327, 1.0321, 1.0136, 1.0183, 1.0157, 1.0262, 1.0206, 1.013, 0.99638, 1.0276, 0.99487, 1.0076, 1.0032, 1.0258, 1.0228, 0.99756, 1.011, 1.0121, 1.0065, 1.0071, 1.0246, 1.0218, 0.99449, 1.0079, 1.0184, 0.98594, 0.98284, 1.0095, 1.0125, 1.0035, 1.0005, 0.99078, 0.99671, 1.0078, 0.98782, 0.98742, 0.99144, 1.0061, 1.0002, 1.0057, 1.0184, 0.9915, 1.0158, 1.0027, 1.0394, 1.0056, 1.0193, 1.012, 0.99436, 0.98628, 0.99963, 1.0171, 0.99583, 0.97918, 0.96399, 1.0119, 0.98177, 0.99897, 0.99058, 1.0012, 1.0002, 1.0198, 0.99027, 0.97525, 1.0155, 1.0116, 1.0174, 0.9777, 0.99614, 0.9796, 1.0017, 0.95716, 0.99593, 0.9688, 0.98117, 0.98442, 0.9573, 0.95405, 0.96783, 0.97429, 0.99247, 1.0081, 0.97937, 0.9963, 0.97589, 0.99758, 1.0172, 0.97114, 1.0038, 0.9504, 0.97638, 1.029, 0.95253, 0.97539, 0.95704, 0.95384, 0.96442, 0.96344, 0.96935, 0.93921, 0.95635, 0.95661, 0.9377, 0.96365, 0.99344, 0.95441, 0.97652, 0.94547, 0.98912, 0.99828, 0.98318, 0.9716, 1.017, 0.97821, 0.96202, 1.0014, 0.96889, 0.99276, 0.99616, 0.9802, 0.93335, 0.91906, 0.94542, 0.92894, 0.89489, 0.94261, 0.95228, 0.99289, 0.94996, 0.94872, 0.97051, 1.025, 0.96593, 0.96865, 1.0071, 0.96008, 0.93478, 0.98465, 0.93343, 0.97201, 0.98779, 0.95955, 0.97502, 0.9887, 0.96587, 0.93606, 0.96506, 0.95788, 0.95497, 0.90786, 0.96348, 0.92015, 0.97116, 0.9185, 0.95068, 0.89612, 0.99617, 0.96642, 0.9232, 0.97563, 0.96333, 0.91437, 1.0215, 1.0215, 0.88918, 0.91763, 0.96986, 0.9361, 0.9647, 0.97868, 0.9307, 1.0222, 0.93337, 0.90927, 0.95902, 0.92262, 0.87806, 0.9113, 0.92872, 0.92295, 0.9348, 0.99486, 0.97043, 0.94279, 0.94214, 0.96421, 0.95245, 0.91552, 0.91841, 0.89754, 0.95995, 0.94237, 0.9329, 0.90764, 0.95561, 0.90827, 0.93738, 0.93503, 0.91527, 0.95505, 0.9777, 0.91788, 0.91321, 0.97342, 0.94479, 1.018, 0.9874, 0.97007, 0.93208, 0.9639, 0.9131, 0.87641, 0.88811, 0.90581, 0.96695, 0.88947, 0.9608, 0.93451, 0.95605, 0.94707, 0.92644, 0.91447, 0.94827, 0.92022, 0.91472, 0.92369, 0.97559, 0.91782, 0.88008, 0.92784, 0.91937, 0.96245, 1.0188, 0.91827, 0.90931, 0.88949, 0.89067, 0.97174, 0.96838, 0.94967, 0.91975, 0.94733, 0.94126, 0.90281, 0.94115, 0.92823, 0.90563, 0.8559, 0.9173, 0.90394, 0.92959, 0.94907, 0.89143, 0.9687, 0.98559, 0.89265, 0.91699, 1.0082, 0.88201, 0.87848, 0.99457, 0.91615, 0.93458, 0.9801, 0.94967};

  }
  if (makeHistograms) {
    edm::Service<TFileService> fs;

    h_WWpT = fs->make<TH1D>( "h_WWpT", "WW p_{T}", 1000, 0., 500. );
    h_WWpT_genweightsup = fs->make<TH1D>( "h_WWpT_genweightsup", "WW p_{T} genweights up", 1000, 0., 500. );
    h_WWpT_genweightsdown = fs->make<TH1D>( "h_WWpT_genweightsdown", "WW p_{T} genweights down", 1000, 0., 500. );
    h_WWpT_central = fs->make<TH1D>( "h_WWpT_central", "WW p_{T} central", 1000, 0., 500. );
    h_WWpT_Qup = fs->make<TH1D>( "h_WWpT_Qup", "WW p_{T} Qup", 1000, 0., 500. );
    h_WWpT_Qdown = fs->make<TH1D>( "h_WWpT_Qdown", "WW p_{T} Qdown", 1000, 0., 500. );
    h_WWpT_Rup = fs->make<TH1D>( "h_WWpT_Rup", "WW p_{T} Rup", 1000, 0., 500. );
    h_WWpT_Rdown = fs->make<TH1D>( "h_WWpT_Rdown", "WW p_{T} Rdown", 1000, 0., 500. );
    h_WWpT_0jet = fs->make<TH1D>( "h_WWpT_0jet", "WW p_{T} 0jet", 1000, 0., 500. );
    h_WWpT_central_0jet = fs->make<TH1D>( "h_WWpT_central_0jet", "WW p_{T} central 0jet", 1000, 0., 500. );
    h_WWpT_genweightsup_0jet = fs->make<TH1D>( "h_WWpT_genweightsup_0jet", "WW p_{T} genweights up 0jet", 1000, 0., 500. );
    h_WWpT_genweightsdown_0jet = fs->make<TH1D>( "h_WWpT_genweightsdown_0jet", "WW p_{T} genweights down 0jet", 1000, 0., 500. );
    h_WWpT_Qup_0jet = fs->make<TH1D>( "h_WWpT_Qup_0jet", "WW p_{T} Qup 0jet", 1000, 0., 500. );
    h_WWpT_Qdown_0jet = fs->make<TH1D>( "h_WWpT_Qdown_0jet", "WW p_{T} Qdown 0jet", 1000, 0., 500. );
    h_WWpT_Rup_0jet = fs->make<TH1D>( "h_WWpT_Rup_0jet", "WW p_{T} Rup 0jet", 1000, 0., 500. );
    h_WWpT_Rdown_0jet = fs->make<TH1D>( "h_WWpT_Rdown_0jet", "WW p_{T} Rdown 0jet", 1000, 0., 500. );
    h_WWpT_1jet = fs->make<TH1D>( "h_WWpT_1jet", "WW p_{T} 1jet", 1000, 0., 500. );
    h_WWpT_genweightsup_1jet = fs->make<TH1D>( "h_WWpT_genweightsup_1jet", "WW p_{T} genweights up 1jet", 1000, 0., 500. );
    h_WWpT_genweightsdown_1jet = fs->make<TH1D>( "h_WWpT_genweightsdown_1jet", "WW p_{T} genweights down 1jet", 1000, 0., 500. );
    h_WWpT_central_1jet = fs->make<TH1D>( "h_WWpT_central_1jet", "WW p_{T} central 1jet", 1000, 0., 500. );
    h_WWpT_Qup_1jet = fs->make<TH1D>( "h_WWpT_Qup_1jet", "WW p_{T} Qup 1jet", 1000, 0., 500. );
    h_WWpT_Qdown_1jet = fs->make<TH1D>( "h_WWpT_Qdown_1jet", "WW p_{T} Qdown 1jet", 1000, 0., 500. );
    h_WWpT_Rup_1jet = fs->make<TH1D>( "h_WWpT_Rup_1jet", "WW p_{T} Rup 1jet", 1000, 0., 500. );
    h_WWpT_Rdown_1jet = fs->make<TH1D>( "h_WWpT_Rdown_1jet", "WW p_{T} Rdown 1jet", 1000, 0., 500. );
    h_WWpT_2jet = fs->make<TH1D>( "h_WWpT_2jet", "WW p_{T} 2jet", 1000, 0., 500. );
    h_WWpT_genweightsup_2jet = fs->make<TH1D>( "h_WWpT_genweightsup_2jet", "WW p_{T} genweights up 2jet", 1000, 0., 500. );
    h_WWpT_genweightsdown_2jet = fs->make<TH1D>( "h_WWpT_genweightsdown_2jet", "WW p_{T} genweights down 2jet", 1000, 0., 500. );
    h_WWpT_central_2jet = fs->make<TH1D>( "h_WWpT_central_2jet", "WW p_{T} central 2jet", 1000, 0., 500. );
    h_WWpT_Qup_2jet = fs->make<TH1D>( "h_WWpT_Qup_2jet", "WW p_{T} Qup 2jet", 1000, 0., 500. );
    h_WWpT_Qdown_2jet = fs->make<TH1D>( "h_WWpT_Qdown_2jet", "WW p_{T} Qdown 2jet", 1000, 0., 500. );
    h_WWpT_Rup_2jet = fs->make<TH1D>( "h_WWpT_Rup_2jet", "WW p_{T} Rup 2jet", 1000, 0., 500. );
    h_WWpT_Rdown_2jet = fs->make<TH1D>( "h_WWpT_Rdown_2jet", "WW p_{T} Rdown 2jet", 1000, 0., 500. );

    h_LeadingLeptonpT = fs->make<TH1D>( "h_LeadingLeptonpT", "Leading lepton p_{T}", 1000, 0., 500. );
    h_LeadingLeptonpT_genweightsup = fs->make<TH1D>( "h_LeadingLeptonpT_genweightsup", "Leading lepton p_{T} genweights up", 1000, 0., 500.);
    h_LeadingLeptonpT_genweightsdown = fs->make<TH1D>( "h_LeadingLeptonpT_genweightsdown", "Leading lepton p_{T} genweights down", 1000, 0., 500.);
    h_LeadingLeptonpT_central = fs->make<TH1D>( "h_LeadingLeptonpT_central", "Leading lepton p_{T} central", 1000, 0., 500. );
    h_LeadingLeptonpT_Qup = fs->make<TH1D>( "h_LeadingLeptonpT_Qup", "Leading lepton p_{T} Qup", 1000, 0., 500. );
    h_LeadingLeptonpT_Qdown = fs->make<TH1D>( "h_LeadingLeptonpT_Qdown", "Leading lepton p_{T} Qdown", 1000, 0., 500. );
    h_LeadingLeptonpT_Rup = fs->make<TH1D>( "h_LeadingLeptonpT_Rup", "Leading lepton p_{T} Rup", 1000, 0., 500. );
    h_LeadingLeptonpT_Rdown = fs->make<TH1D>( "h_LeadingLeptonpT_Rdown", "Leading lepton p_{T} Rdown", 1000, 0., 500. );
    h_LeadingLeptonpT_0jet = fs->make<TH1D>( "h_LeadingLeptonpT_0jet", "Leading lepton p_{T} 0jet", 1000, 0., 500. );
    h_LeadingLeptonpT_genweightsup_0jet = fs->make<TH1D>( "h_LeadingLeptonpT_genweightsup_0jet", "Leading lepton p_{T} genweights up 0jet", 1000, 0., 500. );
    h_LeadingLeptonpT_genweightsdown_0jet = fs->make<TH1D>( "h_LeadingLeptonpT_genweightsdown_0jet", "Leading lepton p_{T} genweights down 0jet", 1000, 0., 500. );
    h_LeadingLeptonpT_central_0jet = fs->make<TH1D>( "h_LeadingLeptonpT_central_0jet", "Leading lepton p_{T} central 0jet", 1000, 0., 500. );
    h_LeadingLeptonpT_Qup_0jet = fs->make<TH1D>( "h_LeadingLeptonpT_Qup_0jet", "Leading lepton p_{T} Qup 0jet", 1000, 0., 500. );
    h_LeadingLeptonpT_Qdown_0jet = fs->make<TH1D>( "h_LeadingLeptonpT_Qdown_0jet", "Leading lepton p_{T} Qdown 0jet", 1000, 0., 500. );
    h_LeadingLeptonpT_Rup_0jet = fs->make<TH1D>( "h_LeadingLeptonpT_Rup_0jet", "Leading lepton p_{T} Rup 0jet", 1000, 0., 500. );
    h_LeadingLeptonpT_Rdown_0jet = fs->make<TH1D>( "h_LeadingLeptonpT_Rdown_0jet", "Leading lepton p_{T} Rdown 0jet", 1000, 0., 500. );
    h_LeadingLeptonpT_1jet = fs->make<TH1D>( "h_LeadingLeptonpT_1jet", "Leading lepton p_{T} 1jet", 1000, 0., 500. );
    h_LeadingLeptonpT_genweightsup_1jet = fs->make<TH1D>( "h_LeadingLeptonpT_genweightsup_1jet", "Leading lepton p_{T} genweights up 1jet", 1000, 0., 500. );
    h_LeadingLeptonpT_genweightsdown_1jet = fs->make<TH1D>( "h_LeadingLeptonpT_genweightsdown_1jet", "Leading lepton p_{T} genweights down 1jet", 1000, 0., 500. );
    h_LeadingLeptonpT_central_1jet = fs->make<TH1D>( "h_LeadingLeptonpT_central_1jet", "Leading lepton p_{T} central 1jet", 1000, 0., 500. );
    h_LeadingLeptonpT_Qup_1jet = fs->make<TH1D>( "h_LeadingLeptonpT_Qup_1jet", "Leading lepton p_{T} Qup 1jet", 1000, 0., 500. );
    h_LeadingLeptonpT_Qdown_1jet = fs->make<TH1D>( "h_LeadingLeptonpT_Qdown_1jet", "Leading lepton p_{T} Qdown 1jet", 1000, 0., 500. );
    h_LeadingLeptonpT_Rup_1jet = fs->make<TH1D>( "h_LeadingLeptonpT_Rup_1jet", "Leading lepton p_{T} Rup 1jet", 1000, 0., 500. );
    h_LeadingLeptonpT_Rdown_1jet = fs->make<TH1D>( "h_LeadingLeptonpT_Rdown_1jet", "Leading lepton p_{T} Rdown 1jet", 1000, 0., 500. );
    h_LeadingLeptonpT_2jet = fs->make<TH1D>( "h_LeadingLeptonpT_2jet", "Leading lepton p_{T} 2jet", 1000, 0., 500. );
    h_LeadingLeptonpT_genweightsup_2jet = fs->make<TH1D>( "h_LeadingLeptonpT_genweightsup_2jet", "Leading lepton p_{T} genweights up 2jet", 1000, 0., 500. );
    h_LeadingLeptonpT_genweightsdown_2jet = fs->make<TH1D>( "h_LeadingLeptonpT_genweightsdown_2jet", "Leading lepton p_{T} genweights down 2jet", 1000, 0., 500. );
    h_LeadingLeptonpT_central_2jet = fs->make<TH1D>( "h_LeadingLeptonpT_central_2jet", "Leading lepton p_{T} central 2jet", 1000, 0., 500. );
    h_LeadingLeptonpT_Qup_2jet = fs->make<TH1D>( "h_LeadingLeptonpT_Qup_2jet", "Leading lepton p_{T} Qup 2jet", 1000, 0., 500. );
    h_LeadingLeptonpT_Qdown_2jet = fs->make<TH1D>( "h_LeadingLeptonpT_Qdown_2jet", "Leading lepton p_{T} Qdown 2jet", 1000, 0., 500. );
    h_LeadingLeptonpT_Rup_2jet = fs->make<TH1D>( "h_LeadingLeptonpT_Rup_2jet", "Leading lepton p_{T} Rup 2jet", 1000, 0., 500. );
    h_LeadingLeptonpT_Rdown_2jet = fs->make<TH1D>( "h_LeadingLeptonpT_Rdown_2jet", "Leading lepton p_{T} Rdown 2jet", 1000, 0., 500. );

    h_AK04jets30 = fs->make<TH1D>( "h_AK04jets30", "AK 0.4 jets (30 GeV)", 10, 0., 10. );
    h_AK04jets30_genweightsup = fs->make<TH1D>( "h_AK04jets30_genweightsup", "AK 0.4 jets (30 GeV) genweights up", 10, 0., 10. );
    h_AK04jets30_genweightsdown = fs->make<TH1D>( "h_AK04jets30_genweightsdown", "AK 0.4 jets (30 GeV) genweights down", 10, 0., 10. );
    h_AK04jets30_central = fs->make<TH1D>( "h_AK04jets30_central", "AK 0.4 jets (30 GeV) central", 10, 0., 10. );
    h_AK04jets30_Qup = fs->make<TH1D>( "h_AK04jets30_Qup", "AK 0.4 jets (30 GeV) Qup", 10, 0., 10. );
    h_AK04jets30_Qdown = fs->make<TH1D>( "h_AK04jets30_Qdown", "AK 0.4 jets (30 GeV) Qdown", 10, 0., 10. );
    h_AK04jets30_Rup = fs->make<TH1D>( "h_AK04jets30_Rup", "AK 0.4 jets (30 GeV) Rup", 10, 0., 10. );
    h_AK04jets30_Rdown = fs->make<TH1D>( "h_AK04jets30_Rdown", "AK 0.4 jets (30 GeV) Rdown", 10, 0., 10. );
    h_AK04jets30_0jet = fs->make<TH1D>( "h_AK04jets30_0jet", "AK 0.4 jets (30 GeV) 0jet", 10, 0., 10. );
    h_AK04jets30_genweightsup_0jet = fs->make<TH1D>( "h_AK04jets30_genweightsup_0jet", "AK 0.4 jets (30) genweights up 0jet", 10, 0., 10. );
    h_AK04jets30_genweightsdown_0jet = fs->make<TH1D>( "h_AK04jets30_genweightsdown_0jet", "AK 0.4 jets (30) genweights down 0jet", 10, 0., 10. );
    h_AK04jets30_central_0jet = fs->make<TH1D>( "h_AK04jets30_central_0jet", "AK 0.4 jets (30) central 0jet", 10, 0., 10. );
    h_AK04jets30_Qup_0jet = fs->make<TH1D>( "h_AK04jets30_Qup_0jet", "AK 0.4 jets (30 GeV) Qup 0jet", 10, 0., 10. );
    h_AK04jets30_Qdown_0jet = fs->make<TH1D>( "h_AK04jets3_Qdown_0jet", "AK 0.4 jets (30 GeV) Qdown 0jet", 10, 0., 10. );
    h_AK04jets30_Rup_0jet = fs->make<TH1D>( "h_AK04jets30_Rup_0jet", "AK 0.4 jets (30 GeV) Rup 0jet", 10, 0., 10. );
    h_AK04jets30_Rdown_0jet = fs->make<TH1D>( "h_AK04jets30_Rdown_0jet", "AK 0.4 jets (30 GeV) Rdown 0jet", 10, 0., 10. );
    h_AK04jets30_1jet = fs->make<TH1D>( "h_AK04jets30_1jet", "AK 0.4 jets (30 GeV) 1jet", 10, 0., 10. );
    h_AK04jets30_genweightsup_1jet = fs->make<TH1D>( "h_AK04jets30_genweightsup_1jet", "AK 0.4 jets (30 GeV) genweights up 1jet", 10, 0., 10. );
    h_AK04jets30_genweightsdown_1jet = fs->make<TH1D>( "h_AK04jets30_genweightsdown_1jet", "AK 0.4 jets (30 GeV) genweights down 1jet", 10, 0., 10. );
    h_AK04jets30_central_1jet = fs->make<TH1D>( "h_AK04jets30_central_1jet", "AK 0.4 jets (30 GeV) central 1jet", 10, 0., 10. );
    h_AK04jets30_Qup_1jet = fs->make<TH1D>( "h_AK04jets30_Qup_1jet", "AK 0.4 jets (30 GeV) Qup 1jet", 10, 0., 10. );
    h_AK04jets30_Qdown_1jet = fs->make<TH1D>( "h_AK04jets30_Qdown_1jet", "AK 0.4 jets (30 GeV) Qdown 1jet", 10, 0., 10. );
    h_AK04jets30_Rup_1jet = fs->make<TH1D>( "h_AK04jets30_Rup_1jet", "AK 0.4 jets (30 GeV) Rup 1jet", 10, 0., 10. );
    h_AK04jets30_Rdown_1jet = fs->make<TH1D>( "h_AK04jets30_Rdown_1jet", "AK 0.4 jets (30 GeV) Rdown 1jet", 10, 0., 10. );
    h_AK04jets30_2jet = fs->make<TH1D>( "h_AK04jets30_2jet", "AK 0.4 jets (30 GeV) 2jet", 10, 0., 10. );
    h_AK04jets30_genweightsup_2jet = fs->make<TH1D>( "h_AK04jets30_genweightsup_2jet", "AK 0.4 jets (30 GeV) genweights up 2jet", 10, 0., 10. );
    h_AK04jets30_genweightsdown_2jet = fs->make<TH1D>( "h_AK04jets30_genweightsdown_2jet", "AK 0.4 jets (30 GeV) genweights down 2jet", 10, 0., 10. );
    h_AK04jets30_central_2jet = fs->make<TH1D>( "h_AK04jets30_central_2jet", "AK 0.4 jets (30 GeV) central 2jet", 10, 0., 10. );
    h_AK04jets30_Qup_2jet = fs->make<TH1D>( "h_AK04jets30_Qup_2jet", "AK 0.4 jets (30 GeV) Qup 2jet", 10, 0., 10. );
    h_AK04jets30_Qdown_2jet = fs->make<TH1D>( "h_AK04jets30_Qdown_2jet", "AK 0.4 jets (30 GeV) Qdown 2jet", 10, 0., 10. );
    h_AK04jets30_Rup_2jet = fs->make<TH1D>( "h_AK04jets30_Rup_2jet", "AK 0.4 jets (30 GeV) Rup 2jet", 10, 0., 10. );
    h_AK04jets30_Rdown_2jet = fs->make<TH1D>( "h_AK04jets30_Rdown_2jet", "AK 0.4 jets (30 GeV) Rdown 2jet", 10, 0., 10. );
    
  }

}


template<typename T, typename U> WWreweightProducer<T,U>::~WWreweightProducer()
{

}

template<typename T, typename U> void
WWreweightProducer<T,U>::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;

   unique_ptr<double> reweightingCentral (new double(1.0));
   unique_ptr<double> reweightingQup (new double(1.0));
   unique_ptr<double> reweightingQdown (new double(1.0));
   unique_ptr<double> reweightingRup (new double(1.0));
   unique_ptr<double> reweightingRdown (new double(1.0));

   if(!iEvent.isRealData()) {
     
     Handle<T> genParticles;
     iEvent.getByToken( genParticlesToken, genParticles );
     Handle<U> genJets;
     iEvent.getByToken( genJetsToken, genJets );
     
     Handle<LHEEventProduct> LHEEventInfo;
     iEvent.getByLabel("externalLHEProducer", LHEEventInfo); 

     LorentzVector WW(0,0,0,0);   
     LorentzVector lepton1(0,0,0,0);   
     LorentzVector lepton2(0,0,0,0);   
     LorentzVector neutrino1(0,0,0,0);   
     LorentzVector neutrino2(0,0,0,0); 
     bool f_lepton1 = false, f_lepton2 = false, f_neutrino1 = false, f_neutrino2 = false;
     int nAK04jets30 = 0.;
     vector<double> genweights = {1.};

     for ( typename T::const_iterator iGenPart = genParticles->begin(); iGenPart != genParticles->end(); iGenPart++ ) {
       
       if (MCTruthHelper::fromHardProcessBeforeFSR(*iGenPart) && abs(iGenPart->pdgId()) == 24) {
	 WW += iGenPart->p4();
       }

       if (makeHistograms) {

	 if ((MCTruthHelper::isHardProcess(*iGenPart)) && 
	     (abs(iGenPart->pdgId()) == 11 || abs(iGenPart->pdgId()) == 13)) {
	   if (iGenPart->pdgId() < 0) {
	     f_lepton1 = true;
	     lepton1 = iGenPart->p4();
	   } else {
	     f_lepton2 = true;
	     lepton2 = iGenPart->p4();
	   }
	 }
	 
	 if ((MCTruthHelper::isHardProcess(*iGenPart)) && 
	     (abs(iGenPart->pdgId()) == 12 || abs(iGenPart->pdgId()) == 14)) {
	   if (iGenPart->pdgId() > 0) {
	     f_neutrino1 = true;
	     neutrino1 = iGenPart->p4();
	   } else {
	     f_neutrino2 = true;
	     neutrino2 = iGenPart->p4();
	   }
	 }
	 
       }

     }

     if (makeHistograms) {
       if (f_lepton1 && f_lepton2 && f_neutrino1 && f_neutrino2) {
	 for ( typename U::const_iterator iGenJet = genJets->begin(); iGenJet != genJets->end(); iGenJet++ ) {
	   if (iGenJet->p4().Pt() > 30. && fabs(iGenJet->p4().Eta()) < 4.7) {
	     if ((ROOT::Math::VectorUtil::DeltaR(iGenJet->p4(), lepton1) < 0.05) || 
		 (ROOT::Math::VectorUtil::DeltaR(iGenJet->p4(), lepton2) < 0.05) || 
		 (ROOT::Math::VectorUtil::DeltaR(iGenJet->p4(), neutrino1) < 0.05) || 
		 (ROOT::Math::VectorUtil::DeltaR(iGenJet->p4(), neutrino2) < 0.05)) continue;
	     nAK04jets30++;
	   }
	 }
       }
     }
     /*
       <weight id='1001'> muR=0.10000E+01 muF=0.10000E+01 </weight>
       <weight id='1002'> muR=0.10000E+01 muF=0.20000E+01 </weight>
       <weight id='1003'> muR=0.10000E+01 muF=0.50000E+00 </weight>
       <weight id='1004'> muR=0.20000E+01 muF=0.10000E+01 </weight>
       <weight id='1005'> muR=0.20000E+01 muF=0.20000E+01 </weight>
       <weight id='1006'> muR=0.20000E+01 muF=0.50000E+00 </weight>
       <weight id='1007'> muR=0.50000E+00 muF=0.10000E+01 </weight>
       <weight id='1008'> muR=0.50000E+00 muF=0.20000E+01 </weight>
       <weight id='1009'> muR=0.50000E+00 muF=0.50000E+00 </weight>
     */

     if (LHEEventInfo.isValid()){
       for (auto& weight : LHEEventInfo->weights()) {
	 if (atoi(weight.id.c_str()) >= 1001 && atoi(weight.id.c_str()) <= 1009)
	   genweights.push_back(weight.wgt);
       }
     }

     int bin = int (320*WW.Pt()/160.);
     if (!(bin < 0 || bin >= 320)) {
       *reweightingCentral = reweightingFactors_central[bin];
       *reweightingQup = reweightingFactors_Qup[bin];
       *reweightingQdown = reweightingFactors_Qdown[bin];
       *reweightingRup = reweightingFactors_Rup[bin];
       *reweightingRdown = reweightingFactors_Rdown[bin];
     }
     
     if (makeHistograms) {

       h_WWpT->Fill(WW.Pt());
       h_WWpT_genweightsup->Fill(WW.Pt(), *max_element(genweights.begin(), genweights.end()));
       h_WWpT_genweightsdown->Fill(WW.Pt(), *min_element(genweights.begin(), genweights.end()));
       h_WWpT_central->Fill(WW.Pt(), *reweightingCentral);
       h_WWpT_Qup->Fill(WW.Pt(), *reweightingQup);
       h_WWpT_Qdown->Fill(WW.Pt(), *reweightingQdown);
       h_WWpT_Rup->Fill(WW.Pt(), *reweightingRup);
       h_WWpT_Rdown->Fill(WW.Pt(), *reweightingRdown);       

       if (f_lepton1 && f_lepton2 && f_neutrino1 && f_neutrino2) {
		
       if (nAK04jets30 == 0) {
	 h_WWpT_0jet->Fill(WW.Pt());
	 h_WWpT_genweightsup_0jet->Fill(WW.Pt(), *max_element(genweights.begin(), genweights.end()));
	 h_WWpT_genweightsdown_0jet->Fill(WW.Pt(), *min_element(genweights.begin(), genweights.end()));
	 h_WWpT_central_0jet->Fill(WW.Pt(), *reweightingCentral);
	 h_WWpT_Qup_0jet->Fill(WW.Pt(), *reweightingQup);
	 h_WWpT_Qdown_0jet->Fill(WW.Pt(), *reweightingQdown);
	 h_WWpT_Rup_0jet->Fill(WW.Pt(), *reweightingRup);
	 h_WWpT_Rdown_0jet->Fill(WW.Pt(), *reweightingRdown);       	 
       } else if (nAK04jets30 == 1) {
	 h_WWpT_1jet->Fill(WW.Pt());
	 h_WWpT_genweightsup_1jet->Fill(WW.Pt(), *max_element(genweights.begin(), genweights.end()));
	 h_WWpT_genweightsdown_1jet->Fill(WW.Pt(), *min_element(genweights.begin(), genweights.end()));
	 h_WWpT_central_1jet->Fill(WW.Pt(), *reweightingCentral);
	 h_WWpT_Qup_1jet->Fill(WW.Pt(), *reweightingQup);
	 h_WWpT_Qdown_1jet->Fill(WW.Pt(), *reweightingQdown);
	 h_WWpT_Rup_1jet->Fill(WW.Pt(), *reweightingRup);
	 h_WWpT_Rdown_1jet->Fill(WW.Pt(), *reweightingRdown);       	 
       } else if (nAK04jets30 == 2) {
	 h_WWpT_2jet->Fill(WW.Pt());
	 h_WWpT_genweightsup_2jet->Fill(WW.Pt(), *max_element(genweights.begin(), genweights.end()));
	 h_WWpT_genweightsdown_2jet->Fill(WW.Pt(), *min_element(genweights.begin(), genweights.end()));
	 h_WWpT_central_2jet->Fill(WW.Pt(), *reweightingCentral);
	 h_WWpT_Qup_2jet->Fill(WW.Pt(), *reweightingQup);
	 h_WWpT_Qdown_2jet->Fill(WW.Pt(), *reweightingQdown);
	 h_WWpT_Rup_2jet->Fill(WW.Pt(), *reweightingRup);
	 h_WWpT_Rdown_2jet->Fill(WW.Pt(), *reweightingRdown);       	 
       }

       h_LeadingLeptonpT->Fill(max(lepton1.Pt(), lepton2.Pt()));
       h_LeadingLeptonpT_genweightsup->Fill(max(lepton1.Pt(), lepton2.Pt()), *max_element(genweights.begin(), genweights.end()));
       h_LeadingLeptonpT_genweightsdown->Fill(max(lepton1.Pt(), lepton2.Pt()), *min_element(genweights.begin(), genweights.end()));
       h_LeadingLeptonpT_central->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingCentral);
       h_LeadingLeptonpT_Qup->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingQup);
       h_LeadingLeptonpT_Qdown->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingQdown);
       h_LeadingLeptonpT_Rup->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingRup);
       h_LeadingLeptonpT_Rdown->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingRdown);       
       if (nAK04jets30 == 0) {
	 h_LeadingLeptonpT_0jet->Fill(max(lepton1.Pt(), lepton2.Pt()));
	 h_LeadingLeptonpT_genweightsup_0jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *max_element(genweights.begin(), genweights.end()));
	 h_LeadingLeptonpT_genweightsdown_0jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *min_element(genweights.begin(), genweights.end()));
	 h_LeadingLeptonpT_central_0jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingCentral);
	 h_LeadingLeptonpT_Qup_0jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingQup);
	 h_LeadingLeptonpT_Qdown_0jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingQdown);
	 h_LeadingLeptonpT_Rup_0jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingRup);
	 h_LeadingLeptonpT_Rdown_0jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingRdown);       	 
       } else if (nAK04jets30 == 1) {
	 h_LeadingLeptonpT_1jet->Fill(max(lepton1.Pt(), lepton2.Pt()));
	 h_LeadingLeptonpT_genweightsup_1jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *max_element(genweights.begin(), genweights.end()));
	 h_LeadingLeptonpT_genweightsdown_1jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *min_element(genweights.begin(), genweights.end()));
	 h_LeadingLeptonpT_central_1jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingCentral);
	 h_LeadingLeptonpT_Qup_1jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingQup);
	 h_LeadingLeptonpT_Qdown_1jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingQdown);
	 h_LeadingLeptonpT_Rup_1jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingRup);
	 h_LeadingLeptonpT_Rdown_1jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingRdown);       	 
       } else if (nAK04jets30 == 2) {
	 h_LeadingLeptonpT_2jet->Fill(max(lepton1.Pt(), lepton2.Pt()));
	 h_LeadingLeptonpT_genweightsup_2jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *max_element(genweights.begin(), genweights.end()));
	 h_LeadingLeptonpT_genweightsdown_2jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *min_element(genweights.begin(), genweights.end()));
	 h_LeadingLeptonpT_central_2jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingCentral);
	 h_LeadingLeptonpT_Qup_2jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingQup);
	 h_LeadingLeptonpT_Qdown_2jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingQdown);
	 h_LeadingLeptonpT_Rup_2jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingRup);
	 h_LeadingLeptonpT_Rdown_2jet->Fill(max(lepton1.Pt(), lepton2.Pt()), *reweightingRdown);       	 
       }

       h_AK04jets30->Fill(nAK04jets30);
       h_AK04jets30_genweightsup->Fill(nAK04jets30, *max_element(genweights.begin(), genweights.end()));
       h_AK04jets30_genweightsdown->Fill(nAK04jets30, *min_element(genweights.begin(), genweights.end()));
       h_AK04jets30_central->Fill(nAK04jets30, *reweightingCentral);
       h_AK04jets30_Qup->Fill(nAK04jets30, *reweightingQup);
       h_AK04jets30_Qdown->Fill(nAK04jets30, *reweightingQdown);
       h_AK04jets30_Rup->Fill(nAK04jets30, *reweightingRup);
       h_AK04jets30_Rdown->Fill(nAK04jets30, *reweightingRdown);       
       if (nAK04jets30 == 0) {
	 h_AK04jets30_0jet->Fill(nAK04jets30);
	 h_AK04jets30_genweightsup_0jet->Fill(nAK04jets30, *max_element(genweights.begin(), genweights.end()));
	 h_AK04jets30_genweightsdown_0jet->Fill(nAK04jets30, *min_element(genweights.begin(), genweights.end()));
	 h_AK04jets30_central_0jet->Fill(nAK04jets30, *reweightingCentral);
	 h_AK04jets30_Qup_0jet->Fill(nAK04jets30, *reweightingQup);
	 h_AK04jets30_Qdown_0jet->Fill(nAK04jets30, *reweightingQdown);
	 h_AK04jets30_Rup_0jet->Fill(nAK04jets30, *reweightingRup);
	 h_AK04jets30_Rdown_0jet->Fill(nAK04jets30, *reweightingRdown);       	 
       } else if (nAK04jets30 == 1) {
	 h_AK04jets30_1jet->Fill(nAK04jets30);
	 h_AK04jets30_genweightsup_1jet->Fill(nAK04jets30, *max_element(genweights.begin(), genweights.end()));
	 h_AK04jets30_genweightsdown_1jet->Fill(nAK04jets30, *min_element(genweights.begin(), genweights.end()));
	 h_AK04jets30_central_1jet->Fill(nAK04jets30, *reweightingCentral);
	 h_AK04jets30_Qup_1jet->Fill(nAK04jets30, *reweightingQup);
	 h_AK04jets30_Qdown_1jet->Fill(nAK04jets30, *reweightingQdown);
	 h_AK04jets30_Rup_1jet->Fill(nAK04jets30, *reweightingRup);
	 h_AK04jets30_Rdown_1jet->Fill(nAK04jets30, *reweightingRdown);       	 
       } else if (nAK04jets30 == 2) {
	 h_AK04jets30_2jet->Fill(nAK04jets30);
	 h_AK04jets30_genweightsup_2jet->Fill(nAK04jets30, *max_element(genweights.begin(), genweights.end()));
	 h_AK04jets30_genweightsdown_2jet->Fill(nAK04jets30, *min_element(genweights.begin(), genweights.end()));
	 h_AK04jets30_central_2jet->Fill(nAK04jets30, *reweightingCentral);
	 h_AK04jets30_Qup_2jet->Fill(nAK04jets30, *reweightingQup);
	 h_AK04jets30_Qdown_2jet->Fill(nAK04jets30, *reweightingQdown);
	 h_AK04jets30_Rup_2jet->Fill(nAK04jets30, *reweightingRup);
	 h_AK04jets30_Rdown_2jet->Fill(nAK04jets30, *reweightingRdown);       	 
       }
       }
     }
     
   }

   iEvent.put(move(reweightingCentral), "central");
   iEvent.put(move(reweightingQup), "Qup");
   iEvent.put(move(reweightingQdown), "Qdown");
   iEvent.put(move(reweightingRup), "Rup");
   iEvent.put(move(reweightingRdown), "Rdown");

 
}

#endif
