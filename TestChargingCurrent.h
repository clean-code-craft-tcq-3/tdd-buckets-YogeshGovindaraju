#ifndef TESTCHARGINGCURRENT
#define TESTCHARGINGCURRENT

#include <assert.h>

void testChargingCurrent()
{
    std::vector<int> currentSamples{4,5};
    std::stringstream expectedOutput;
    expectedOutput << "Range, Readings\n4-5, 2";
    ChargingCurrent chargingCurrent;
    assert(chargingCurrent.classifyChargingCurrentRange(currentSamples) == expectedOutput.str());
}

#endif