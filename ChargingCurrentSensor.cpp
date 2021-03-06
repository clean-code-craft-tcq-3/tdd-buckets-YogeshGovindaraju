#include "ChargingCurrentSensor.h"

ChargingCurrentSensor::ChargingCurrentSensor(int lowerRange, int upperRange, int numberOfBits) : 
    CurrentSensor(lowerRange, upperRange, numberOfBits)
{
}

std::string ChargingCurrentSensor::classifyCurrentRangeFromSensorReadings(std::vector<int> A2DConverterReadings)
{
    std::vector<int> currentSensorReadings = calculateCurrentFromA2DConverterReadings(A2DConverterReadings);
    return classifyChargingCurrentRange(currentSensorReadings);
}