#ifndef TESTCHARGINGCURRENT
#define TESTCHARGINGCURRENT

#include <assert.h>

void testForEmptyCurrentSample(ChargingCurrent &chargingCurrent, std::vector<int> &currentSamples, std::stringstream &expectedOutput)
{
    currentSamples = {};
    expectedOutput.str("");
    expectedOutput << "\nNo Current Samples are given!!!";
    assert(chargingCurrent.classifyChargingCurrentRange(currentSamples) == expectedOutput.str());
}

void testForOnePositiveCurrentSample(ChargingCurrent &chargingCurrent, std::vector<int> &currentSamples, std::stringstream &expectedOutput)
{
    currentSamples = {2};
    expectedOutput.str("");
    expectedOutput << "\nRange, Readings\n2-2, 1";
    assert(chargingCurrent.classifyChargingCurrentRange(currentSamples) == expectedOutput.str());
}

void testForTwoPositiveCurrentSamples(ChargingCurrent &chargingCurrent, std::vector<int> &currentSamples, std::stringstream &expectedOutput)
{
    currentSamples = {4,5};
    expectedOutput.str("");
    expectedOutput << "\nRange, Readings\n4-5, 2";
    assert(chargingCurrent.classifyChargingCurrentRange(currentSamples) == expectedOutput.str());
}

void testForPositiveCurrentSamples(ChargingCurrent &chargingCurrent, std::vector<int> &currentSamples, std::stringstream &expectedOutput)
{
    currentSamples = {10,12,9,11,16,1,3,3,1,4,2};
    expectedOutput.str("");
    expectedOutput << "\nRange, Readings\n1-4, 6\n9-12, 4\n16-16, 1";
    assert(chargingCurrent.classifyChargingCurrentRange(currentSamples) == expectedOutput.str());
}

void testForNegativeCurrentSamples(ChargingCurrent &chargingCurrent, std::vector<int> &currentSamples, std::stringstream &expectedOutput)
{
    currentSamples = {-4,-5,-4,-3,-7,-8,-8,-3};
    expectedOutput.str("");
    expectedOutput << "\nRange, Readings\n-8--7, 3\n-5--3, 5";
    assert(chargingCurrent.classifyChargingCurrentRange(currentSamples) == expectedOutput.str());
}

void testForPositiveAndNegativeCurrentSamples(ChargingCurrent &chargingCurrent, std::vector<int> &currentSamples, std::stringstream &expectedOutput)
{
    currentSamples = {5,8,-3,-1,-3,-2,6,6,7,15,15,15,16,6};
    expectedOutput.str("");
    expectedOutput << "\nRange, Readings\n-3--1, 4\n5-8, 6\n15-16, 4";
    assert(chargingCurrent.classifyChargingCurrentRange(currentSamples) == expectedOutput.str());
}

void testChargingCurrent()
{
    ChargingCurrent chargingCurrent;
    std::vector<int> currentSamples;
    std::stringstream expectedOutput;
    testForEmptyCurrentSample(chargingCurrent, currentSamples, expectedOutput);
    testForOnePositiveCurrentSample(chargingCurrent, currentSamples, expectedOutput);
    testForTwoPositiveCurrentSamples(chargingCurrent, currentSamples, expectedOutput);
    testForPositiveCurrentSamples(chargingCurrent, currentSamples, expectedOutput);
    testForNegativeCurrentSamples(chargingCurrent, currentSamples, expectedOutput);
    testForPositiveAndNegativeCurrentSamples(chargingCurrent, currentSamples, expectedOutput);
}

#endif