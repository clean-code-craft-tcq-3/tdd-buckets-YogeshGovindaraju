#ifndef TESTCHARGINGCURRENT
#define TESTCHARGINGCURRENT

#include <assert.h>

void testChargingCurrent()
{
    std::vector<int> currentSamples{4,5};
    std::stringstream expectedOutput;
    expectedOutput << "\nRange, Readings\n4-5, 2";
    ChargingCurrent chargingCurrent;
    assert(chargingCurrent.classifyChargingCurrentRange(currentSamples) == expectedOutput.str());
    
    currentSamples = {};
    expectedOutput.str("");
    expectedOutput << "\nNo Current Samples are given!!!";
    assert(chargingCurrent.classifyChargingCurrentRange(currentSamples) == expectedOutput.str());
    
    currentSamples = {10,12,9,11,1,3,3,1,4,2};
    expectedOutput.str("");
    expectedOutput << "\nRange, Readings\n1-4, 6\n9-12, 4";
    assert(chargingCurrent.classifyChargingCurrentRange(currentSamples) == expectedOutput.str());
    
    currentSamples = {5,8,-3,-1,-3,-2,6,6,7,15,15,15,16,6};
    expectedOutput.str("");
    expectedOutput << "\nRange, Readings\n-3--1, 4\n5-8, 6\n15-16, 4";
    assert(chargingCurrent.classifyChargingCurrentRange(currentSamples) == expectedOutput.str());
}

#endif