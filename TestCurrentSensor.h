#ifndef TESTCURRENTSENSOR
#define TESTCURRENTSENSOR

void test12BitCurrentSensor()
{
    CurrentSensor currentSensor(0, 10, 12);
    std::vector<int> A2DConverterReadings{4094};
    std::vector<int> currentSensorReadings{10};
    assert(currentSensor.calculateCurrentFromA2DConverterReadings(A2DConverterReadings) == currentSensorReadings);
}

#endif