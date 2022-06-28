#ifndef TESTCHARGINGCURRENTSENSOR
#define TESTCHARGINGCURRENTSENSOR

void test12BitChargingCurrentSensor()
{
    ChargingCurrentSensor chargingCurrentSensor(0, 10, 12);
    std::vector<int> A2DConverterReadings{4094};
    std::stringstream expectedOutput;
    expectedOutput << "\nRange, Readings\n10-10, 1";
    assert(chargingCurrentSensor.classifyCurrentRangeFromSensorReadings(A2DConverterReadings) == expectedOutput.str());
}

#endif