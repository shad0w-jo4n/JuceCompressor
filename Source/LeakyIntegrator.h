//
//  LeakyIntegrator.h
//  BU-P05-Compressor
//
//  Created by Brian Uosseph on 4/7/15.
//
//

#ifndef __BU_P05_Compressor__LeakyIntegrator__
#define __BU_P05_Compressor__LeakyIntegrator__

#include <math.h>

class GainDynamics {
public:
    GainDynamics(float sampleRate, float attackTime, float releaseTime);
    ~GainDynamics();
    
    float tick(float inputSample);
    void setDetector(float sampleRate);
    void setAttack(float attackTime);
    void setRelease(float releaseTime);
    
private:
    float fs, outputGain;
    float b0Attack, b0Release, b0,
          a1Attack, a1Release, a1;
    float attackTime, releaseTime;     // seconds
};

#endif /* defined(__BU_P05_Compressor__LeakyIntegrator__) */
