#ifndef CURRENTSENSOR
#define CURRENTSENSOR

#include <vector>
#include <cmath>

class CurrentSensor
{
    int totalCurrentRange;
    int maximumA2DConverterReading;
    int minimumA2DConverterReading;
    
    public:
    CurrentSensor(int lowerRange, int upperRange, int numberOfBits);
    std::vector<int> calculateCurrentFromA2DConverterReadings(std::vector<int> A2DConverterReadings);
};

#endif