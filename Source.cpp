/*
Olympic Sprinters - Week 4 - Pointers
Andrew Moyer
1/31/20
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

double* Get_Times(int, string[], double[], int);
double* Validate_Time(double);
double* Highest_Time(double[], int);
double* Lowest_Time(double[], int);

int main()
{

	const int ROW = 5, COL = 4;
	int again;

	double totalHold = 0;
	double hold = 0, * average_p = &hold;
	double raceTimesInput[COL];
	double averages[ROW];
	double* avgArr_p = averages;
	string sprinterInput[ROW];
	string* nameArr_p = sprinterInput;
	int winnerCount = 0;


	// In main repeatedly process the five sprinters
	do {

		cout << fixed << setprecision(1) << endl;

		// collect five sprinter names
		// in main place sprinter’s name in array
		for (int i = 0; i < ROW; i++) {

			cout << "Enter the name of sprinter " << i + 1 << ": ";
			getline(cin, sprinterInput[i]);

		}

		// get sprint times
		// in main place sprinter’s average time in array
		for (int j = 0; j < ROW; j++) {

			average_p = Get_Times(j, sprinterInput, raceTimesInput, COL);
			averages[j] = *average_p;
			hold = 0;

		}

		// double test holds the starting value to test for best sprint average
		double test = averages[0];

		// point notation output of sprinter name and average time
		// also find best sprint time and the sprinter name

		cout << endl;
		cout << "----------------------------------------------------" << endl;
		cout << setw(20) << right << "Sprinter Name" << setw(9) << right << "|" << setw(18) << right << "Average Time" << endl;
		cout << "----------------------------------------------------" << endl;


		for (int i = 0; i < ROW; i++) {

			cout << "   " << setw(24) << left << *(nameArr_p + i) << setw(2) << right << "|" << setw(15) << right << *(avgArr_p + i) << endl;
			cout << "----------------------------------------------------" << endl;
			if (*(avgArr_p + i) < test) {
				test = *(avgArr_p + i);
				winnerCount = i;
			}
		}


		// outout lowest sprint average and the sprinters name
		cout << "The winner is " << *(nameArr_p + winnerCount) << "!" << endl;
		cout << "With the lowest average time of " << *(avgArr_p + winnerCount) << endl;
		cout << endl;

		// again or stop
		cout << "Enter 1 to quit or enter any number to continue: ";
		cin >> again;

		cin.ignore();

	} while (again != 1);

	return 0;

}

double* Get_Times(int j, string sprinterInput[], double raceTimesInput[], int COL)
{

	// variables for time and validating sprint times
	double race1, race2, race3, race4, holdTotal = 0;

	// valid time use
	double testHold = 0, * hold_p = &testHold;

	// highest time use
	double testHigh = 0, * high_p = &testHigh;

	// lowest time use
	double testLow = 0, * low_p = &testLow;

	// average time us
	double tempAvg = 0, * avg_p = &tempAvg;

	// output racer name and ask for times
	// user enters the four times (in seconds) for this sprinter (prompt with sprinter’s name).
	cout << "Enter the four sprint times for " << sprinterInput[j] << ": ";
	cin >> race1 >> race2 >> race3 >> race4;

	// validate times and assign times to input array
	for (int i = 0; i < COL; i++) {
		if (i == 0) {
			hold_p = Validate_Time(race1);
			raceTimesInput[i] = *hold_p;
			testHold = 0;
		}
		if (i == 1) {
			hold_p = Validate_Time(race2);
			raceTimesInput[i] = *hold_p;
			testHold = 0;
		}
		if (i == 2) {
			hold_p = Validate_Time(race3);
			raceTimesInput[i] = *hold_p;
			testHold = 0;
		}
		if (i == 3) {
			hold_p = Validate_Time(race4);
			raceTimesInput[i] = *hold_p;
			testHold = 0;
		}

	}

	// total input times
	for (j = 0; j < COL; j++) {
		holdTotal += raceTimesInput[j];
	}

	/*
	The Get_Times function will then call two other functions which both accept the four times.
	One of the functions will return the highest of the four times using a pointer,
	and the other function will return the lowest of the four times using a pointer.
	*/

	// find high/low and average
	high_p = Highest_Time(raceTimesInput, COL);

	holdTotal = holdTotal - *high_p;

	low_p = Lowest_Time(raceTimesInput, COL);

	holdTotal = holdTotal - *low_p;

	holdTotal = holdTotal / 2;

	*avg_p = holdTotal;

	return avg_p;

}

// Valide time entered is greater than zero but less than 60 seconds
double* Validate_Time(double seconds)
{

	while (seconds < 0 || seconds > 60)
	{
		cout << "Time must be greater than zero seconds and less than 60 seconds" << endl;
		cout << "Enter a valid time: ";
		cin >> seconds;

	}

	return &seconds;

}

// Find highest of four entered times
double* Highest_Time(double raceTimeInput[], int COL)
{

	double test = raceTimeInput[0];
	double tempHoldHigh = 0;
	double* tempHigh_p = &tempHoldHigh;

	// compare to find high
	for (int i = 1; i < COL; i++) {
		if (raceTimeInput[i] > test)
			test = raceTimeInput[i];
	}

	*tempHigh_p = test;

	return tempHigh_p;
}

// Find lowest of four entered times
double* Lowest_Time(double raceTimeInput[], int COL)
{

	double test = raceTimeInput[0];
	double tempHoldLow = 0;
	double* tempLow_p = &tempHoldLow;

	// compare to find low
	for (int i = 1; i < COL; i++) {
		if (raceTimeInput[i] < test)
			test = raceTimeInput[i];
	}

	*tempLow_p = test;

	return tempLow_p;
}
