#ifndef TESTCHARGINGCURRENTSENSOR
#define TESTCHARGINGCURRENTSENSOR

void testForEmpty12BitCurrentSensorReadings(ChargingCurrentSensor &chargingCurrentSensor, std::vector<int> &A2DConverterReadings, std::stringstream &expectedOutput)
{
    A2DConverterReadings = {};
    expectedOutput.str("");
    expectedOutput << "\nNo Current Samples are given!!!";
    assert(chargingCurrentSensor.classifyCurrentRangeFromSensorReadings(A2DConverterReadings) == expectedOutput.str());
}

void testForError12BitCurrentSensorReadings(ChargingCurrentSensor &chargingCurrentSensor, std::vector<int> &A2DConverterReadings, std::stringstream &expectedOutput)
{
    A2DConverterReadings = {-1, 4095};
    expectedOutput.str("");
    expectedOutput << "\nNo Current Samples are given!!!";
    assert(chargingCurrentSensor.classifyCurrentRangeFromSensorReadings(A2DConverterReadings) == expectedOutput.str());
}

void testForSingle12BitCurrentSensorReading(ChargingCurrentSensor &chargingCurrentSensor, std::vector<int> &A2DConverterReadings, std::stringstream &expectedOutput)
{
    A2DConverterReadings = {4094};
    expectedOutput.str("");
    expectedOutput << "\nRange, Readings\n10-10, 1";
    assert(chargingCurrentSensor.classifyCurrentRangeFromSensorReadings(A2DConverterReadings) == expectedOutput.str());
}

void testFor12BitCurrentSensorReadings(ChargingCurrentSensor &chargingCurrentSensor, std::vector<int> &A2DConverterReadings, std::stringstream &expectedOutput)
{
    A2DConverterReadings = {0, 249, 987, 1234, 2566, 3625, 4000, 4094};
    expectedOutput.str("");
    expectedOutput << "\nRange, Readings\n0-3, 4\n6-6, 1\n9-10, 3";
    assert(chargingCurrentSensor.classifyCurrentRangeFromSensorReadings(A2DConverterReadings) == expectedOutput.str());
}

void test12BitChargingCurrentSensor()
{
    ChargingCurrentSensor chargingCurrentSensor(0, 10, 12);
    std::vector<int> A2DConverterReadings;
    std::stringstream expectedOutput;
    testForEmpty12BitCurrentSensorReadings(chargingCurrentSensor, A2DConverterReadings, expectedOutput);
    testForError12BitCurrentSensorReadings(chargingCurrentSensor, A2DConverterReadings, expectedOutput);
    testForSingle12BitCurrentSensorReading(chargingCurrentSensor, A2DConverterReadings, expectedOutput);
    testFor12BitCurrentSensorReadings(chargingCurrentSensor, A2DConverterReadings, expectedOutput);
}

#endif