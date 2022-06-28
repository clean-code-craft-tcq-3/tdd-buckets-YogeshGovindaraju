#include "CurrentSensor.h"

CurrentSensor::CurrentSensor(int lowerRange, int upperRange, int numberOfBits)
{
    lowerCurrentSensorRange = lowerRange;
    totalCurrentRange = std::abs(lowerRange) + std::abs(upperRange);
    maximumA2DConverterReading = pow(2, numberOfBits) - 2;
    minimumA2DConverterReading = 0;
}

int CurrentSensor::convertA2DReadingToCurrent(int A2DConverterReading)
{
    int currentSensorReading = INVALID;
    if((A2DConverterReading >= minimumA2DConverterReading) && (A2DConverterReading <= maximumA2DConverterReading))
    {
        currentSensorReading = round((float)totalCurrentRange*A2DConverterReading/maximumA2DConverterReading);
        currentSensorReading = std::abs(lowerCurrentSensorRange + currentSensorReading);
    }
    return currentSensorReading;
}

std::vector<int> CurrentSensor::calculateCurrentFromA2DConverterReadings(std::vector<int> A2DConverterReadings)
{
    std::vector<int> currentSensorReadings;
    int currentSensorReading = 0;
    for(size_t i=0; i<A2DConverterReadings.size(); i++)
    {
        currentSensorReading = convertA2DReadingToCurrent(A2DConverterReadings.at(i));
        if(currentSensorReading != INVALID)
        {
            currentSensorReadings.push_back(currentSensorReading);
        }
    }
    return currentSensorReadings;
}