#include "CurrentSensor.h"

CurrentSensor::CurrentSensor(int lowerRange, int upperRange, int numberOfBits)
{
    totalCurrentRange = std::abs(lowerRange) + std::abs(upperRange);
    maximumA2DConverterReading = pow(2, numberOfBits) - 2;
    minimumA2DConverterReading = 0;
}

std::vector<int> CurrentSensor::calculateCurrentFromA2DConverterReadings(std::vector<int> A2DConverterReadings)
{
    //Not yet implemented
    std::vector<int> currentSensorReadings{-1};
    return currentSensorReadings;
}