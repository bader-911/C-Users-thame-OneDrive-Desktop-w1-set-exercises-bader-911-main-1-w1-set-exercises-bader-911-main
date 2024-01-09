#include "task1-functions.h"
#include <iostream>
#include <math.h>
using namespace std;

#define KM_PER_MILE 1.609344

// setEngineMode - outputs the engine mode based on speed S (mph) and battery level B (%)
// Returns 0 for battery mode and 1 for petrol
int setEngineMode(int speed, int batteryLevel)
{

	cin >> speed >> batteryLevel;

    // Convert speed from miles/hour to kilometers/hour and round to nearest integer
    int speedInKmph = round(speed * 1.609);

    // Display the converted speed in kilometers/hour
    cout << "Speed in km/h: " << speedInKmph << endl;

    // Determine engine mode based on speed and battery level conditions
    if (speed >= 3 && speed <= 10 && batteryLevel >= 25) {
        engineMode = 0; // Set engine mode to 0 (Battery) if speed and battery conditions are met
    } else if (speed >= 11 && speed <= 30 && batteryLevel >= 45) {
        engineMode = 0; // Set engine mode to 0 (Battery) if speed and battery conditions are met
    } else {
        engineMode = 1; // Otherwise, set engine mode to 1 (Petrol)
    }

    // Display the determined engine mode
    cout << "Engine Mode: " << (engineMode == 0 ? "Battery" : "Petrol") << endl;
	return 0;
}
