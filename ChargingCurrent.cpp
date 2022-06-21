#include "ChargingCurrent.h"
#include "TestChargingCurrent.h"

std::string ChargingCurrent::classifyChargingCurrentRange(std::vector<int> currentSamples)
{
    clearAllValues();
    sort(currentSamples.begin(), currentSamples.end());
    updateCurrentRangeValues(currentSamples);
    updateResult();
    return result.str();
}

void ChargingCurrent::clearAllValues()
{
    result.str("");
    chargingCurrentReadings.startingValue.clear();
    chargingCurrentReadings.endingValue.clear();
    chargingCurrentReadings.numberOfReadings.clear();
    incrementValue = 0;
    presentValue = 0;
    samplesIndex = 0;
    readingsIndex = 0;
    rangeIndex = 0;
}

void ChargingCurrent::updateCurrentRangeValues(std::vector<int> currentSamples)
{
    while(samplesIndex < currentSamples.size())
    {
        chargingCurrentReadings.startingValue.push_back(currentSamples.at(samplesIndex));
        chargingCurrentReadings.endingValue.push_back(currentSamples.at(samplesIndex));
        chargingCurrentReadings.numberOfReadings.push_back(0);
        incrementValue = 1;
        presentValue = currentSamples.at(samplesIndex);
        updateCurrentReadingsRange(currentSamples);
        if(rangeIndex == currentSamples.size())
        {
            chargingCurrentReadings.endingValue.at(readingsIndex) = presentValue;
        }
        samplesIndex = rangeIndex;
        readingsIndex++;
    }
}

void ChargingCurrent::updateCurrentReadingsRange(std::vector<int> currentSamples)
{
    for(rangeIndex=samplesIndex; rangeIndex<currentSamples.size(); rangeIndex++)
    {
        if(isValueWithinRange(currentSamples))
        {
            chargingCurrentReadings.numberOfReadings.at(readingsIndex)++;
        }
        else
        {
            chargingCurrentReadings.endingValue.at(readingsIndex) = presentValue;
            break;
        }
    }
}

bool ChargingCurrent::isValueWithinRange(std::vector<int> currentSamples)
{
    bool returnValue = false;
    if(presentValue == currentSamples.at(rangeIndex))
    {
        returnValue = true;
    }
    else if (presentValue+incrementValue == currentSamples.at(rangeIndex))
    {
        presentValue += incrementValue;
        returnValue = true;
    }
    return returnValue;
}

void ChargingCurrent::updateResult()
{
    if(chargingCurrentReadings.startingValue.size() != 0)
    {
        result << "\nRange, Readings";
        for(size_t k=0; k<chargingCurrentReadings.startingValue.size(); k++)
        {
            result << "\n" << chargingCurrentReadings.startingValue.at(k) << "-" << chargingCurrentReadings.endingValue.at(k) << ", " << chargingCurrentReadings.numberOfReadings.at(k);
        }
    }
    else
    {
        result << "\nNo Current Samples are given!!!";
    }
}

int main()
{
    testChargingCurrent();
    return 0;
}