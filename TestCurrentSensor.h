#ifndef TESTCURRENTSENSOR
#define TESTCURRENTSENSOR

void testForEmpty12BitA2DConverterReadings(CurrentSensor &currentSensor, std::vector<int> &A2DConverterReadings, std::vector<int> &currentSensorReadings)
{
    A2DConverterReadings = {};
    currentSensorReadings = {};
    assert(currentSensor.calculateCurrentFromA2DConverterReadings(A2DConverterReadings) == currentSensorReadings);
}

void testForError12BitA2DConverterReadings(CurrentSensor &currentSensor, std::vector<int> &A2DConverterReadings, std::vector<int> &currentSensorReadings)
{
    A2DConverterReadings = {-1, 4095};
    currentSensorReadings = {};
    assert(currentSensor.calculateCurrentFromA2DConverterReadings(A2DConverterReadings) == currentSensorReadings);
}

void testForSingle12BitA2DConverterReading(CurrentSensor &currentSensor, std::vector<int> &A2DConverterReadings, std::vector<int> &currentSensorReadings)
{
    A2DConverterReadings = {4094};
    currentSensorReadings = {10};
    assert(currentSensor.calculateCurrentFromA2DConverterReadings(A2DConverterReadings) == currentSensorReadings);
}

void testFor12BitA2DConverterReadings(CurrentSensor &currentSensor, std::vector<int> &A2DConverterReadings, std::vector<int> &currentSensorReadings)
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
    testForEmpty12BitA2DConverterReadings(currentSensor, A2DConverterReadings, currentSensorReadings);
    testForError12BitA2DConverterReadings(currentSensor, A2DConverterReadings, currentSensorReadings);
    testForSingle12BitA2DConverterReading(currentSensor, A2DConverterReadings, currentSensorReadings);
    testFor12BitA2DConverterReadings(currentSensor, A2DConverterReadings, currentSensorReadings);
}

void testForEmpty10BitA2DConverterReadings(CurrentSensor &currentSensor, std::vector<int> &A2DConverterReadings, std::vector<int> &currentSensorReadings)
{
    A2DConverterReadings = {};
    currentSensorReadings = {};
    assert(currentSensor.calculateCurrentFromA2DConverterReadings(A2DConverterReadings) == currentSensorReadings);
}

void testForError10BitA2DConverterReadings(CurrentSensor &currentSensor, std::vector<int> &A2DConverterReadings, std::vector<int> &currentSensorReadings)
{
    A2DConverterReadings = {-1, 1023};
    currentSensorReadings = {};
    assert(currentSensor.calculateCurrentFromA2DConverterReadings(A2DConverterReadings) == currentSensorReadings);
}

void testForSingle10BitA2DConverterReading(CurrentSensor &currentSensor, std::vector<int> &A2DConverterReadings, std::vector<int> &currentSensorReadings)
{
    A2DConverterReadings = {1022};
    currentSensorReadings = {15};
    assert(currentSensor.calculateCurrentFromA2DConverterReadings(A2DConverterReadings) == currentSensorReadings);
}

void testFor10BitA2DConverterReadings(CurrentSensor &currentSensor, std::vector<int> &A2DConverterReadings, std::vector<int> &currentSensorReadings)
{
    A2DConverterReadings = {0, 42, 88, 389, 420, 464, 482, 511, 530, 895, 921, 956, 1022};
    currentSensorReadings = {15, 14, 12, 4, 3, 1, 1, 0, 1, 11, 12, 13, 15};
    assert(currentSensor.calculateCurrentFromA2DConverterReadings(A2DConverterReadings) == currentSensorReadings);
}

void test10BitCurrentSensor()
{
    CurrentSensor currentSensor(-15, 15, 10);
    std::vector<int> A2DConverterReadings;
    std::vector<int> currentSensorReadings;
    testForEmpty10BitA2DConverterReadings(currentSensor, A2DConverterReadings, currentSensorReadings);
    testForError10BitA2DConverterReadings(currentSensor, A2DConverterReadings, currentSensorReadings);
    testForSingle10BitA2DConverterReading(currentSensor, A2DConverterReadings, currentSensorReadings);
    testFor10BitA2DConverterReadings(currentSensor, A2DConverterReadings, currentSensorReadings);
}

#endif