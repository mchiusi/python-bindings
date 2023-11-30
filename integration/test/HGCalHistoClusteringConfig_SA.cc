#include "HGCalHistoClusteringConfig_SA.h"
#include <iostream>
#include <fstream>

using namespace std;
// using namespace l1thgcfirmware;
ClusterAlgoConfig::ClusterAlgoConfig() :
  // clusterizerOffset_(0),
  TriggerCellDistributionLUT_( OpenMif("S2.CombinedTD.Balanced60.MixedTypes.NoSplit.mif") ),
  TriggerCellAddressLUT_( OpenMif("S2.TCaddr.CombinedTD.Balanced60.MixedTypes.NoSplit.mif") ),  
  cClocks_(0),
  cInputs_(0),
  cInputs2_(0),
  cInt_(0),
  cColumns_(124),
  cRows_(54),
  rOverZHistOffset_(440),
  rOverZBinSize_(64),
  kernelWidths_(),
  areaNormalizations_(),
  thresholdMaximaParam_a_(400000),
  thresholdMaximaParam_b_(2000),
  thresholdMaximaParam_c_(-80),   
  thresholdMaximaConstants_(),
  maximaWidths_{ 6 , 5 , 5 , 5 , 4 , 4 , 4 , 4 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
  fanoutWidths_{ 6 , 5 , 5 , 5 , 4 , 4 , 4 , 4 , 3 , 3 , 3 , 3 , 3 , 3 , 3 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
  cosLUT_(),
  clusterizerMagicTime_(0),
  stepLatency_({
    { UnpackLinks , 3 },        
    { TriggerCellDistribution , 2 },
    { UnpackTriggerCells , 4 },
    { TcToHc , 2 },
    { Hist   , 231 },
    { Smearing1D , 6 },
    { Interleaving , 1 },
    { NormArea   , 3 },
    { Smearing2D , 5 },
    { Deinterleaved , 4 },    
    { Maxima1D   , 5 },
    { Interleaving2 , 0 },  // Unused
    { Maxima2D   , 6 },
    { ThresholdMaxima , 3 },  // Unused?
    { CalcAverage , 4 },
    { Deinterleaving2, 0 }, // Unused
    { MaximaFanout , 9 },
    { Clusterizer , 0 },
    { TriggerCellToCluster , 8 }
    // { ClusterSum , 0 }
  }),
  depths_{ (unsigned)(-1) , 0 , 30 , 59 , 89 , 118 , 148 , 178 , 208 , 237 , 267 , 297 , 327 , 356 , 386 , 415 , 445 , 475 , 505 , 534 , 564 , 594 , 624 , 653 , 683 , 712 , 742 , 772 , 802 , 911 , 1020 , 1129 , 1238 , 1347 , 1456 , 1565 , 1674 , 1783 , 1892 , 2001 , 2110 , 2281 , 2452 , 2623 , 2794 , 2965 , 3136 , 3307 , 3478 , 3649 , 3820 },
  triggerLayers_{ (unsigned)(-1) , 1 , 0 , 2 , 0 , 3 , 0 , 4 , 0 , 5 , 0 , 6 , 0 , 7 , 0 , 8 , 0 , 9 , 0 , 10 , 0 , 11 , 0 , 12 , 0 , 13 , 0 , 14 , 0 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 , 23 , 24 , 25 , 26 , 27 , 28 , 29 , 30 , 31 , 32 , 33 , 34 , 35 , 36 },
  layerWeights_E_{ (unsigned)(-1) , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 },
  layerWeights_E_EM_{ (unsigned)(-1) , 252969 , 0 , 254280 , 0 , 255590 , 0 , 256901 , 0 , 258212 , 0 , 259523 , 0 , 260833 , 0 , 262144 , 0 , 263455 , 0 , 264765 , 0 , 266076 , 0 , 267387 , 0 , 268698 , 0 , 270008 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
  layerWeights_E_EM_core_{ (unsigned)(-1) , 0 , 0 , 0 , 0 , 0 , 0 , 256901 , 0 , 258212 , 0 , 259523 , 0 , 260833 , 0 , 262144 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0},
  layerWeights_E_H_early_{ (unsigned)(-1) , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },
  correction_( 131071 ), // 0b011111111111111111
  saturation_( (2<<19) - 1 )
{}

void ClusterAlgoConfig::printConfiguration() const {
  cout << "Config params" << endl;
  // cout << "Clusterizer offset : " << clusterizerOffset() << endl;
  cout << "Latencies : ";
  for ( const auto& latency : stepLatency_ ) cout << latency.first << ":" << latency.second << ", ";
  cout << endl;
  cout << "cClocks : " << cClocks() << endl;
  cout << "cInputs : " << cInputs() << endl;
  cout << "cInputs2 : " << cInputs2() << endl;
  cout << "cColumns : " << cColumns() << endl;
  cout << "cRows : " << cRows() << endl;
  cout << "rOverZHistOffset : " << rOverZHistOffset() << endl;
  cout << "rOverZBinSize : " << rOverZBinSize() << endl;
  cout << "nBinsCosLUT : " << nBinsCosLUT() << endl;
  cout << "CosLUT : ";
  for ( const auto& value : cosLUT_ ) cout << value << ", ";
  cout << endl;
  
  cout << "clusterizerMagicTime : " << clusterizerMagicTime() << endl;
  cout << "depths : ";
  for ( const auto& depth : depths() ) cout << depth << " ";
  cout << endl;
  cout << "triggerLayers : ";
  for ( const auto& triggerLayer : triggerLayers() ) cout << triggerLayer << " ";
  cout << endl;
  cout << "layerWeights_E : ";
  for ( const auto& weight : layerWeights_E() ) cout << weight << " ";
  cout << endl;
  cout << "layerWeights_E_EM : ";
  for ( const auto& weight : layerWeights_E_EM() ) cout << weight << " ";
  cout << endl;
  cout << "layerWeights_E_EM_core : ";
  for ( const auto& weight : layerWeights_E_EM_core() ) cout << weight << " ";
  cout << endl;
  cout << "layerWeights_E_H_early : ";
  for ( const auto& weight : layerWeights_E_H_early() ) cout << weight << " ";
  cout << endl;
  cout << "correction : " << correction() << endl;
  cout << "saturation : " << saturation() << endl;

  cout << "Trigger cell LUT size : " << TriggerCellDistributionLUT_.size() << endl;
}


