#ifndef CURRENTSENSOR
#define CURRENTSENSOR

#include <vector>
#include <cmath>
#include <bits/stdc++.h>

#define INVALID -1

class CurrentSensor
{
    int lowerCurrentSensorRange;
    int totalCurrentRange;
    int maximumA2DConverterReading;
    int minimumA2DConverterReading;
    
    public:
    CurrentSensor(int lowerRange, int upperRange, int numberOfBits);
    int convertA2DReadingToCurrent(int A2DConverterReading);
    std::vector<int> calculateCurrentFromA2DConverterReadings(std::vector<int> A2DConverterReadings);
};

#endif