#include "ChargingCurrent.h"
#include "TestChargingCurrent.h"

std::string classifyChargingCurrentRange(std::vector<int> currentSamples)
{
    std::stringstream result;
    std::vector<int> minimumValue;
    std::vector<int> maximumValue;
    std::vector<int> numberOfReadings;
    int incrementValue = 0;
    int currentValue = 0;
    size_t index = 0;
    int i = 0;
    size_t j = 0;
    while(index < currentSamples.size())
    {
        minimumValue.push_back(currentSamples.at(index));
        maximumValue.push_back(currentSamples.at(index));
        numberOfReadings.push_back(0);
        incrementValue = 1;
        currentValue = currentSamples.at(index);
        for(j=index; j<currentSamples.size(); j++)
        {
            if(currentValue == currentSamples.at(j))
            {
                numberOfReadings.at(i)++;
            }
            else if (currentValue+incrementValue == currentSamples.at(j))
            {
                currentValue += incrementValue;
                numberOfReadings.at(i)++;
            }
            else
            {
                maximumValue.at(i) = currentValue;
                break;
            }
            if(j+1 == currentSamples.size())
            {
                maximumValue.at(i) = currentValue;
            }
        }
        index = j;
        i++;
    }
    if(minimumValue.size() != 0)
    {
        result << "Range, Readings";
        for(size_t k=0; k<minimumValue.size(); k++)
        {
            result << "\n" << minimumValue.at(k) << "-" << maximumValue.at(k) << ", " << numberOfReadings.at(k);
        }
    }
    else
    {
        result << "No Current Samples are given!!!";
    }
    return result.str();
}

int main()
{
    testChargingCurrent();
    return 0;
}