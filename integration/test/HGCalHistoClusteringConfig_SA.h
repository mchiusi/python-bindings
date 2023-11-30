#ifndef __L1Trigger_L1THGCal_HGCalHistoCluteringConfig_SA_h__
#define __L1Trigger_L1THGCal_HGCalHistoCluteringConfig_SA_h__

#include <map>
#include <vector>
#include <cstdint>
#include <string>
#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

// namespace l1thgcfirmware {

  class ClusterAlgoConfig {
  public:
    ClusterAlgoConfig();
    ~ClusterAlgoConfig() {};

    void setSector( const unsigned int sector ) { sector_ = sector; }
    unsigned int sector() const { return sector_; }

    void printConfiguration() const; // For debugging
  private:
    unsigned int sector_;

  };

// }  // namespace l1thgcfirmware

#endif
