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

void testForEmpty10BitCurrentSensorReadings(ChargingCurrentSensor &chargingCurrentSensor, std::vector<int> &A2DConverterReadings, std::stringstream &expectedOutput)
{
    expectedOutput.str("");
    A2DConverterReadings = {};
    expectedOutput << "\nNo Current Samples are given!!!";
    assert(chargingCurrentSensor.classifyCurrentRangeFromSensorReadings(A2DConverterReadings) == expectedOutput.str());
}

void testForError10BitCurrentSensorReadings(ChargingCurrentSensor &chargingCurrentSensor, std::vector<int> &A2DConverterReadings, std::stringstream &expectedOutput)
{
    A2DConverterReadings = {-1, 1023};
    expectedOutput.str("");
    expectedOutput << "\nNo Current Samples are given!!!";
    assert(chargingCurrentSensor.classifyCurrentRangeFromSensorReadings(A2DConverterReadings) == expectedOutput.str());
}

void testForSingle10BitCurrentSensorReading(ChargingCurrentSensor &chargingCurrentSensor, std::vector<int> &A2DConverterReadings, std::stringstream &expectedOutput)
{
    A2DConverterReadings = {1022};
    expectedOutput.str("");
    expectedOutput << "\nRange, Readings\n15-15, 1";
    assert(chargingCurrentSensor.classifyCurrentRangeFromSensorReadings(A2DConverterReadings) == expectedOutput.str());
}

void testFor10BitCurrentSensorReadings(ChargingCurrentSensor &chargingCurrentSensor, std::vector<int> &A2DConverterReadings, std::stringstream &expectedOutput)
{
    A2DConverterReadings = {0, 42, 88, 389, 420, 464, 482, 511, 530, 895, 921, 956, 1022};
    expectedOutput.str("");
    expectedOutput << "\nRange, Readings\n0-1, 4\n3-4, 2\n11-15, 7";
    assert(chargingCurrentSensor.classifyCurrentRangeFromSensorReadings(A2DConverterReadings) == expectedOutput.str());
}

void test10BitChargingCurrentSensor()
{
    ChargingCurrentSensor chargingCurrentSensor(-15, 15, 10);
    std::vector<int> A2DConverterReadings;
    std::stringstream expectedOutput;
    testForEmpty10BitCurrentSensorReadings(chargingCurrentSensor, A2DConverterReadings, expectedOutput);
    testForError10BitCurrentSensorReadings(chargingCurrentSensor, A2DConverterReadings, expectedOutput);
    testForSingle10BitCurrentSensorReading(chargingCurrentSensor, A2DConverterReadings, expectedOutput);
    testFor10BitCurrentSensorReadings(chargingCurrentSensor, A2DConverterReadings, expectedOutput);
}

#endif