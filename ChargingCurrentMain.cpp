#include <iostream>
#include <assert.h>
#include "ChargingCurrent.h"
#include "CurrentSensor.h"
#include "TestChargingCurrent.h"
#include "TestCurrentSensor.h"
#include "TestChargingCurrentSensor.h"

int main()
{
    testChargingCurrent();
    test12BitCurrentSensor();
    test12BitChargingCurrentSensor();
    return 0;
}