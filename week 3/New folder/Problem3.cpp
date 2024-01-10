// Problem3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TimeSeriesTransformations.h"
using namespace OOP;

int main()
{
	// Ask user for filename
	cout << "Please enter the filename of the csv file to load data from (do not include .csv): " << endl;

	// Get user filename
	string filename;
	cin >> filename;
	filename = filename + ".csv";

	// Load csv data
	TimeSeriesTransformations T(filename);

	// Keep going until the user enters 0
	int input = -1;
	while (input != 0){

		// Print Main Menu
		cout << "Please Choose:" << endl;
		cout << "1) Print all share price on a date" << endl;
		cout << "2) Print mean and standard deviation of prices" << endl;
		cout << "3) Print mean and standard deviation of price increments" << endl;
		cout << "4) Add a share price" << endl;
		cout << "5) Remove share price" << endl;
		cout << "6) Filter share price by date" << endl;
		cout << "7) Find greatest increment in prices" << endl;
		cout << "8) Save the data to a file" << endl;

		// Get user input
		std::cin >> input;

		// Print all share prices on a date
		if (input == 1){

			// Get date from user 
			string date;
			cout << "Please enter a date and time in the format YYYY/MM/DD" << endl;
			cin >> date;

			// Extra data from user input
			string year = date.substr(0, 4);
			string month = date.substr(5, 2);
			string day = date.substr(8, 2);

			// Create date time using data
			time_t filler = time(0);
			tm time;
			localtime_s(&time, &filler);
			time.tm_year = stoi(year) - 1900;
			time.tm_mon = stoi(month) - 1;
			time.tm_mday = stoi(day);

			// Print share prices on date
			T.printEntriesOnDay(time);
		}
		// Show mean and standard deviation of prices
		else if (input == 2){

			cout << "Mean: " << T.mean() << endl;
			cout << "Standard Deviation: " << T.standardDeviation() << endl;
		}
		// Show mean and standard deviation of increments
		else if (input == 3){

			cout << "Mean of Price Increments: " << T.computeIncrementMean() << endl;
			cout << "Standard Deviation of Price Increments: " << T.computeIncrementStandardDeviation() << endl;
		}
		// Add a share price
		else if (input == 4){

			// Get date and price from user 
			string date;
			double price;
			cout << "Please enter a date and time in the format YYYY/MM/DD-HH:MM and the corresponding share price share." << endl;
			cin >> date >> price;

			// Extra data from user input
			string year = date.substr(0, 4);
			string month = date.substr(5, 2);
			string day = date.substr(8, 2);
			string hour = date.substr(11, 2);
			string minute = date.substr(14, 2);

			// Create date time using data
			time_t filler = time(0);
			tm time;
			localtime_s(&time, &filler);
			time.tm_year = stoi(year) - 1900;
			time.tm_mon = stoi(month) - 1;
			time.tm_mday = stoi(day);
			time.tm_hour = stoi(hour);
			time.tm_min = stoi(minute);

			// Add price
			T.appendPrice(time, price);
		}
		// Remoce value(s)
		else if (input == 5){

			// Remove Value Menu
			cout << "Please enter either:" << endl;
			cout << "1) Remove value at timestamp" << endl;
			cout << "2) Remove all prices above share value" << endl;
			cout << "3) Remove all prices below share value" << endl;
			cout << "4) Remove all prices equal to share value" << endl;

			// Get user input
			int secondInput = -1;
			std::cin >> secondInput;

			// Remove values matching date
			if (secondInput == 1){

				// Get date from user 
				string date;
				cout << "Please enter a date and time in the format YYYY/MM/DD-HH:MM" << endl;
				cin >> date;

				// Extra data from user input
				string year = date.substr(0, 4);
				string month = date.substr(5, 2);
				string day = date.substr(8, 2);
				string hour = date.substr(11, 2);
				string minute = date.substr(14, 2);

				// Create date time using data
				time_t filler = time(0);
				tm time;
				localtime_s(&time, &filler);
				time.tm_year = stoi(year) - 1900;
				time.tm_mon = stoi(month) - 1;
				time.tm_mday = stoi(day);
				time.tm_hour = stoi(hour);
				time.tm_min = stoi(minute);

				// Remove entries at that time
				T.removeEntryAtTime(time);
			}
			// Remove prices above certain value
			else if (secondInput == 2){

				// Get user input
				double value;
				cout << "Please value to remove above" << endl;
				cin >> value;

				// Remove prices
				T.removePricesGreaterThan(value);
			}
			// Remove prices below certain value
			else if (secondInput == 3){

				// Get user input
				double value;
				cout << "Please value to remove below" << endl;
				cin >> value;

				// Remove prices
				T.removePricesLessThan(value);
			}
			// Remove prices matching certain value
			else if (secondInput == 4){

				// Get user input
				double value;
				cout << "Please value to remove" << endl;
				cin >> value;

				// Remove prices
				T.removePricesEqualTo(value);
			}
		}
		// Get dates of a certain price
		else if (input == 6){

			// Get price from user
			double value;
			cout << "Enter price to get dates matching that price: " << endl;
			cin >> value;

			// Print dates for that price
			T.getTimestampsMatchingPrice(value);
		}
		// Get greatest increment
		else if (input == 7){

			cout << "Greatest increment in prices is: " << T.greatestIncrementInPrices() << endl;
		}
		// Output data to csv file
		else if (input == 8){

			// Get filename from user
			string filename;
			cout << "Enter a filename (do not include .csv)" << endl;
			cin >> filename;
			filename = filename + ".csv";

			// Ouput data to file
			T.saveData(filename);
		}

		// Alert user to how to quit and get their input
		cout << endl << "Enter 0 if you wish to quit" << endl << endl;
	}
}
