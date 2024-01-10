//Ashley Openshaw 1761298- Problem Sheet 3

// TimeSeries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <windows.h>

#include "TimeSeriesTransformations.h"
#include "TimeSeriesHelpers.h"

using namespace std;
using namespace OOP;

void OOP::PrintAllSharePricesOnADate(const TimeSeriesTransformations& sharedata) // Function prints all share prices on a selected day with time stamps
{
	// Defines variables
	int day, mth, year; 
	struct tm timeinfo_date_to_search; 
	char date_time_string[80];

	time_t min_unix_time = sharedata.share_vect[0].first;
	time_t max_unix_time = sharedata.share_vect[0].first;

	for (unsigned idx = 0; idx < sharedata.share_vect.size(); ++idx) // Loops through data
	{
		if (sharedata.share_vect[idx].first < min_unix_time) // Checks for min unix time
			min_unix_time = sharedata.share_vect[idx].first;

		if (sharedata.share_vect[idx].first > max_unix_time) // Checks for max unix time
			max_unix_time = sharedata.share_vect[idx].first;
	}

	string min_date = DatetimeToString(min_unix_time).substr(0, 10);
	string max_date = DatetimeToString(max_unix_time).substr(0, 10);

	std::cout << "Please enter date in the format YYYY/MM/DD in the range " << min_date << " to " << max_date << std::endl;

	scanf_s("%4d/%2d/%2d", &year, &mth, &day);

	timeinfo_date_to_search.tm_year = year - 1900;
	timeinfo_date_to_search.tm_mon = mth - 1;
	timeinfo_date_to_search.tm_mday = day;

	timeinfo_date_to_search.tm_hour = 0;
	timeinfo_date_to_search.tm_min = 0;
	timeinfo_date_to_search.tm_sec = 0;

	time_t unix_time_string = mktime(&timeinfo_date_to_search);

	strftime(date_time_string, 80, "%Y/%m/%d-%H:%M", &timeinfo_date_to_search); // Converts date and time information to string

	printEntriesOnDay(sharedata, timeinfo_date_to_search); // Calls EntriesOnDate function
}

void OOP::PrintSharePricesOnDate(const TimeSeriesTransformations& sharedata) // Function prints all share prices on a given date
{
	int day, mth, year;
	struct tm timeinfo_date_to_search;
	char date_time_string[80];

	time_t min_unix_time = sharedata.share_vect[0].first;
	time_t max_unix_time = sharedata.share_vect[0].first;

	for (unsigned idx = 0; idx < sharedata.share_vect.size(); ++idx)
	{
		if (sharedata.share_vect[idx].first < min_unix_time)
			min_unix_time = sharedata.share_vect[idx].first;

		if (sharedata.share_vect[idx].first > max_unix_time)
			max_unix_time = sharedata.share_vect[idx].first;
	}

	string min_date = DatetimeToString(min_unix_time).substr(0, 10);
	string max_date = DatetimeToString(max_unix_time).substr(0, 10);

	std::cout << "Please enter date in the format YYYY/MM/DD in the range " << min_date << " to " << max_date << std::endl;

	scanf_s("%4d/%2d/%2d", &year, &mth, &day);

	timeinfo_date_to_search.tm_year = year - 1900;
	timeinfo_date_to_search.tm_mon = mth - 1;
	timeinfo_date_to_search.tm_mday = day;

	timeinfo_date_to_search.tm_hour = 0;
	timeinfo_date_to_search.tm_min = 0;
	timeinfo_date_to_search.tm_sec = 0;

	time_t unix_time_string = mktime(&timeinfo_date_to_search);

	strftime(date_time_string, 80, "%Y/%m/%d-%H:%M", &timeinfo_date_to_search);

	printSharePricesOnDate(sharedata, timeinfo_date_to_search); // Calls printSharePriceOnDate function
}

void OOP::PrintIncrementsOnADate(const TimeSeriesTransformations& sharedata) // Prints incremements on a given date
{
	int day, mth, year;
	struct tm timeinfo_date_to_search;
	char date_time_string[80];

	time_t min_unix_time = sharedata.share_vect[0].first;
	time_t max_unix_time = sharedata.share_vect[0].first;

	for (unsigned idx = 0; idx < sharedata.share_vect.size(); ++idx)
	{
		if (sharedata.share_vect[idx].first < min_unix_time)
			min_unix_time = sharedata.share_vect[idx].first;

		if (sharedata.share_vect[idx].first > max_unix_time)
			max_unix_time = sharedata.share_vect[idx].first;
	}

	string min_date = DatetimeToString(min_unix_time).substr(0, 10);
	string max_date = DatetimeToString(max_unix_time).substr(0, 10);

	std::cout << "Please enter date in the format YYYY/MM/DD in the range " << min_date << " to " << max_date << std::endl;

	scanf_s("%4d/%2d/%2d", &year, &mth, &day);

	timeinfo_date_to_search.tm_year = year - 1900;
	timeinfo_date_to_search.tm_mon = mth - 1;
	timeinfo_date_to_search.tm_mday = day;

	timeinfo_date_to_search.tm_hour = 0;
	timeinfo_date_to_search.tm_min = 0;
	timeinfo_date_to_search.tm_sec = 0;

	time_t unix_time_string = mktime(&timeinfo_date_to_search);

	strftime(date_time_string, 80, "%Y/%m/%d-%H:%M", &timeinfo_date_to_search);

	printIncrementsOnDate(sharedata, timeinfo_date_to_search); // Calls printIncrementsOnDate function
}

void AddASharePrice(TimeSeriesTransformations& sharedata) // Functions adds a share price inputted by user
{
	int day, mth, year, hour, minute;
	struct tm timeinfo_date_to_add;
	double share_price_to_add;

	std::cout << "Please enter date and time in the format YYYY/MM/DD-HH:MM" << std::endl << ">";

	scanf_s("%4d/%2d/%2d-%2d:%2d", &year, &mth, &day, &hour, &minute);

	timeinfo_date_to_add.tm_year = year - 1900;
	timeinfo_date_to_add.tm_mon = mth - 1;
	timeinfo_date_to_add.tm_mday = day;

	timeinfo_date_to_add.tm_hour = hour;
	timeinfo_date_to_add.tm_min = minute;
	timeinfo_date_to_add.tm_sec = 0;

	time_t unix_time_string = mktime(&timeinfo_date_to_add);

	std::cout << "Please enter corresponding share price" << "\n" << ">";
	std::cin >> share_price_to_add;

	appendPrice(sharedata, unix_time_string, share_price_to_add); // Calls appendPrice function
}

void FilterBySharePrice(TimeSeriesTransformations& sharedata) // Function filters data by share price
{
	double  share_price_to_filter;

	std::cout << "Please enter share price to filter by (e.g. 67.89445722)" << std::endl << ">";
	std::cin >> share_price_to_filter;

	getTimestampsMatchingPrice(sharedata, share_price_to_filter); // Calls getTimestampsMatchingPrice function

}

void OOP::RemoveValueAtTimestamp(TimeSeriesTransformations& sharedata) // Function removes value at a given time stamp
{

	time_t timestamp_to_remove;

	time_t min_unix_time = sharedata.share_vect[0].first, max_unix_time = sharedata.share_vect[0].first;

	for (unsigned idx = 0; idx < sharedata.share_vect.size(); ++idx)
	{
		if (sharedata.share_vect[idx].first < min_unix_time)
			min_unix_time = sharedata.share_vect[idx].first;

		if (sharedata.share_vect[idx].first > max_unix_time)
			max_unix_time = sharedata.share_vect[idx].first;
	}

	std::cout << "Please enter timestamp for share removal " << min_unix_time << " to " << max_unix_time << std::endl;

	std::cin >> timestamp_to_remove;

	removeEntryAtTime(sharedata, timestamp_to_remove); // Calls removeEntryAtTime function
}

void OOP::RemoveEqual(TimeSeriesTransformations& sharedata) // Function Removes share price equal to given value
{
	double price_to_remove;

	DisplaySharePriceRange(sharedata);

	std::cin >> price_to_remove;

	removePriceEqualTo(sharedata, price_to_remove); // Calls removePriceEqualTo function
}

void OOP::RemoveAbove(TimeSeriesTransformations& sharedata) // Function removes share prices above given value
{
	double price_to_remove;

	DisplaySharePriceRange(sharedata);

	std::cin >> price_to_remove;

	removePriceGreaterThan(sharedata, price_to_remove); // Calls removePriceGreaterThan function
}

void OOP::DisplaySharePriceRange(TimeSeriesTransformations& sharedata) // Function displays the range in share prices
{
	auto max_price = *std::max_element(begin(sharedata.share_vect), end(sharedata.share_vect), // Finds max share price value
		[](const std::pair<time_t, double>& left, const std::pair<time_t, double>& right) {
			return left.second < right.second;
		});

	auto min_price = *std::max_element(begin(sharedata.share_vect), end(sharedata.share_vect), // Finds min share price value
		[](const std::pair<time_t, double>& left, const std::pair<time_t, double>& right) {
			return left.second > right.second;
		});

	std::cout << "Please enter share price for removal "
		<< std::setprecision(8) << std::fixed << min_price.second
		<< " to "
		<< std::setprecision(8) << std::fixed << max_price.second
		<< std::endl;
}

void OOP::RemoveBelow(TimeSeriesTransformations& sharedata) // Removes share prices below a given value
{
	double price_to_remove;

	DisplaySharePriceRange(sharedata); // Calls DisplaySharePriceRange function

	std::cin >> price_to_remove;

	removePriceLessThan(sharedata, price_to_remove); // Calls removePriceLessThan function
}

void MainMenuColours(std::string str1, std::string str2) // Function makes numbers in menu red
{
#define TEXT_RED 4
#define TEXT_BRIGHT_RED 12
#define TEXT_BLACK 7

	try
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		SetConsoleTextAttribute(hConsole, TEXT_BRIGHT_RED);
		std::cout << str1;

		SetConsoleTextAttribute(hConsole, TEXT_BLACK);
		std::cout << str2 << std::endl;
	}
	catch (...) // Or if it can't... keeps them the standard boring colour
	{
		std::cout << str1;
		std::cout << str2 << std::endl;
	}
}

void RemoveShares(TimeSeriesTransformations& sharedata) // Function creates a menu for removing shares
{
	int main_menu_choice;
	bool valid_menu_choice = false;

	while (valid_menu_choice == false)
	{
		std::cout << ("\nPlease enter either:\n");

		MainMenuColours("1. ", "Remove value at timestamp");
		MainMenuColours("2. ", "Remove all prices above share value");
		MainMenuColours("3. ", "Remove all prices below share value");
		MainMenuColours("4. ", "Remove all prices equal to share value");

		cin >> main_menu_choice;

		switch (main_menu_choice) // Creates a switch board that goes to a specific case depending on input
		{
		case 1:
			RemoveValueAtTimestamp(sharedata); // Calls RemoveValueAtTimestamp function
			valid_menu_choice = true;
			break;

		case 2:
			RemoveAbove(sharedata); // Calls RemoveAbove function
			valid_menu_choice = true;
			break;

		case 3:
			RemoveBelow(sharedata); // Calls RemoveBelow function
			valid_menu_choice = true;
			break;

		case 4:
			RemoveEqual(sharedata); // Calls RemoveEqual function
			valid_menu_choice = true;
			break;

		default:
			valid_menu_choice = false;
			break;
		}
	}
}

void FilterByDay(TimeSeriesTransformations& sharedata) // Creates menu for filtering by date
{
	int main_menu_choice;
	bool valid_menu_choice = false;

	while (valid_menu_choice == false)
	{
		std::cout << ("\nPlease enter either:\n");

		MainMenuColours("1. ", "Print enteries on date");
		MainMenuColours("2. ", "Print share prices on date");
		MainMenuColours("3. ", "Print increments on date");

		cin >> main_menu_choice;

		switch (main_menu_choice)
		{
		case 1:
			PrintAllSharePricesOnADate(sharedata); // Calls PrintAllSharePricesOnADate function
			valid_menu_choice = true;
			break;

		case 2:
			PrintSharePricesOnDate(sharedata); // Calls PrintSharePricesOnDate function
			valid_menu_choice = true;
			break;

		case 3:
			PrintIncrementsOnADate(sharedata); // PrintIncrementsOnADate function
			valid_menu_choice = true;
			break;

		default:
			valid_menu_choice = false;
			break;
		}
	}
}

void MainMenu(TimeSeriesTransformations& share_data) // Function Creates main menu
{
	int main_menu_choice;

	while (true)
	{
		std::cout << ("\nPlease Choose:\n");

		MainMenuColours("1. ", "Filter share prices by date");
		MainMenuColours("2. ", "Print mean and standard deviation of prices");
		MainMenuColours("3. ", "Print mean and standard deviation of price increments");
		MainMenuColours("4. ", "Add a share price");
		MainMenuColours("5. ", "Remove a share price");
		MainMenuColours("6. ", "Find greatest increment in prices");
		MainMenuColours("7. ", "Save the data to file");
		MainMenuColours("8. ", "Filter timestamps by share price");

		std::cout << "\n";
		MainMenuColours("9. ", "Print share data DEBUG (every 20 records)");
		MainMenuColours("10. ", "Quit");

		cin >> main_menu_choice;

		switch (main_menu_choice)
		{
		case 1:
			FilterByDay(share_data); // Calls FilterByDay function
			break;

		case 2: // Outputs mean and standard deviation of share prices
			std::cout << std::setprecision(8) << std::fixed << "mean: " << mean(share_data) << std::endl;
			std::cout << std::setprecision(8) << std::fixed << "standard deviation: " << standardDeviation(share_data) << std::endl;
			break;

		case 3: // Outputs mean and standard deviation of increments of share prices
			std::cout << std::setprecision(8) << std::fixed << "mean of the increments: " << computeIncrementMean(share_data) << std::endl;
			std::cout << std::setprecision(8) << std::fixed << "standard deviation of the increments: " << computeIncrementStandardDeviation(share_data) << std::endl;
			break;

		case 4:
			AddASharePrice(share_data); // Calls AddASharePrice function
			break;

		case 5:
			RemoveShares(share_data); // Calls RemoveShares function
			break;

		case 6: // Outputs greatest increment in share prices
			std::cout << std::setprecision(8) << std::fixed << "Greatest increment in prices: " << GreatestIncrememt(share_data) << std::endl;
			break;

		case 7:
			saveData(share_data); // Calls saveData function
			break;

		case 8:
			FilterBySharePrice(share_data); // Calls FilterBySharePrice function
			break;

		case 9:
			PrintShareDataForDebug(share_data); // Calls PrintShareDataForDebug
			break;

		case 10:
			exit(0); // Exits code
			break;

		default:
			std::cout << "Not implemented yet"; // Debug message
			break;
		}
	}
}

int main()
{
	char filename_from_user[128];

	do
	{
		std::cout << "Please enter filename containing share data" << std::endl << ">";
		cin.getline(filename_from_user, sizeof(filename_from_user)); // Gets file location
	} while (CheckFileExists(filename_from_user) == false);

	TimeSeriesTransformations share_data(filename_from_user); // Creates class with data from file

	MainMenu(share_data); // Calls MainMenu function

	return 0;
}