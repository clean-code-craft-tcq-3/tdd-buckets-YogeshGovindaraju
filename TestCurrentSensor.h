#ifndef TESTCURRENTSENSOR
#define TESTCURRENTSENSOR

void testForEmptyA2DConverterReadings(CurrentSensor &currentSensor, std::vector<int> &A2DConverterReadings, std::vector<int> &currentSensorReadings)
{
    A2DConverterReadings = {};
    currentSensorReadings = {};
    assert(currentSensor.calculateCurrentFromA2DConverterReadings(A2DConverterReadings) == currentSensorReadings);
}

void testForErrorA2DConverterReadings(CurrentSensor &currentSensor, std::vector<int> &A2DConverterReadings, std::vector<int> &currentSensorReadings)
{
    A2DConverterReadings = {-1, 4095};
    currentSensorReadings = {};
    assert(currentSensor.calculateCurrentFromA2DConverterReadings(A2DConverterReadings) == currentSensorReadings);
}

void testForSingleA2DConverterReading(CurrentSensor &currentSensor, std::vector<int> &A2DConverterReadings, std::vector<int> &currentSensorReadings)
{
    A2DConverterReadings = {4094};
    currentSensorReadings = {10};
    assert(currentSensor.calculateCurrentFromA2DConverterReadings(A2DConverterReadings) == currentSensorReadings);
}

void testForA2DConverterReadings(CurrentSensor &currentSensor, std::vector<int> &A2DConverterReadings, std::vector<int> &currentSensorReadings)
{
    A2DConverterReadings = {0, 249, 987, 1234, 2566, 3625, 4000, 4094};
    currentSensorReadings = {0, 1, 2, 3, 6, 9, 10, 10};
    assert(currentSensor.calculateCurrentFromA2DConverterReadings(A2DConverterReadings) == currentSensorReadings);
}

void test12BitCurrentSensor()
{
    CurrentSensor currentSensor(0, 10, 12);
    std::vector<int> A2DConverterReadings;
    std::vector<int> currentSensorReadings;
    testForEmptyA2DConverterReadings(currentSensor, A2DConverterReadings, currentSensorReadings);
    testForErrorA2DConverterReadings(currentSensor, A2DConverterReadings, currentSensorReadings);
    testForSingleA2DConverterReading(currentSensor, A2DConverterReadings, currentSensorReadings);
    testForA2DConverterReadings(currentSensor, A2DConverterReadings, currentSensorReadings);
}

#endif