#ifndef CHARGINGCURRENTSENSOR
#define CHARGINGCURRENTSENSOR

#include "ChargingCurrent.h"
#include "CurrentSensor.h"

class ChargingCurrentSensor : public ChargingCurrent, public CurrentSensor
{
    public:
    ChargingCurrentSensor(int lowerRange, int upperRange, int numberOfBits);
    std::string classifyCurrentRangeFromSensorReadings(std::vector<int> A2DConverterReadings);
};

#endif