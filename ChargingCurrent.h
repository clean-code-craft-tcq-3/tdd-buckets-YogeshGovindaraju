#ifndef CHARGINGCURRENT
#define CHARGINGCURRENT

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <bits/stdc++.h>

struct ChargingCurrentReadings
{
    std::vector<int> startingValue;
    std::vector<int> endingValue;
    std::vector<int> numberOfReadings;
};

class ChargingCurrent
{
    ChargingCurrentReadings chargingCurrentReadings;
    std::stringstream result;
    int incrementValue;
    int presentValue;
    size_t samplesIndex;
    int readingsIndex;
    size_t rangeIndex;
    void clearAllValues();
    void updateCurrentRangeValues(std::vector<int> currentSamples);
    void updateCurrentReadingsRange(std::vector<int> currentSamples);
    bool isValueWithinRange(std::vector<int> currentSamples);
    void updateResult();
    
    public:
    ChargingCurrent()
    {
        clearAllValues();
    }
    
    std::string classifyChargingCurrentRange(std::vector<int> currentSamples);
};

#endif