//Ashley Openshaw 1761298- Problem Sheet 3

// TimeSeriesHelpers.cpp : This file contain utilities for TImeSeries and TimeSeriesTransformations

#include "TimeSeriesHelpers.h"
#include "TimeSeriesTransformations.h"

#include <fstream>

std::string DatetimeToString(time_t& raw_time) // convert UNIX timestamp raw_time into human readable string
{
	struct tm timeinfo;
	char datetime_string[20];

	localtime_s(&timeinfo, &raw_time);

	strftime(datetime_string, 20, "%Y/%m/%d-%H:%M:%S", &timeinfo); // Converts callender date and time to string
	return datetime_string;
}

bool OOP::saveData(OOP::TimeSeriesTransformations  share_data) // Function saves data to a file
{
	bool writefileokay = true;

	char savefilename_from_user[128];

	std::cout << "Please enter filename of share data file to be written" << std::endl << ">";

	std::cin.ignore();

	std::cin.getline(savefilename_from_user, sizeof(savefilename_from_user)); // Gets file name that will data will be saved as

	std::ofstream share_price_file(savefilename_from_user); // Create an input filestream

	if (!share_price_file.is_open()) 	// Make sure the file is open
	{
		std::cout << "Unable to open file: " << savefilename_from_user;
		writefileokay = false;
	}

	if (writefileokay == true)
	{
		share_price_file << "TIMESTAMP,ShareX\n"; // write headers to CSV file

		for (unsigned idx = 0; idx < (share_data.share_vect.size()); ++idx) //Send to UNIX timestamp and share price data to stream
		{
			share_price_file
				<< share_data.share_vect[idx].first
				<< ","
				<< std::setprecision(8) << std::fixed
				<< share_data.share_vect[idx].second
				<< "\n";
		}

		share_price_file.close(); // Closes file
	}
	return writefileokay;
}

void OOP::PrintShareDataForDebug(OOP::TimeSeriesTransformations share_data) // Function prints all data for debug
{
	size_t size_UnixTimestampData = share_data.share_vect.size();

	std::cout
		<< "First ten records" << "\n" 
		<< "=================" << "\n\n";

	size_t max_idx = 10;

	if (size_UnixTimestampData < 10) // Prints first 10 records
	{
		max_idx = size_UnixTimestampData;
	}

	for (size_t idx = 0; idx < max_idx; ++idx)
	{
		std::cout << "Idx: " << std::setfill('0') << std::setw(5) << idx << " ";
		std::cout << share_data.share_vect[idx].first << " = " << DatetimeToString(share_data.share_vect[idx].first) << " ";
		std::cout << std::setprecision(8) << std::fixed << share_data.share_vect[idx].second << std::endl;
	}

	if (size_UnixTimestampData > 10) // Prints middle records in steps of 20
	{
		std::cout
			<< "Next set of records in steps of 20" << "\n"
			<< "==================================" << "\n\n";

		for (size_t idx = 10; idx < size_UnixTimestampData - 10; idx = idx + 20)
		{
			std::cout << "Idx: " << std::setfill('0') << std::setw(5) << idx << " ";
			std::cout << share_data.share_vect[idx].first << " = " << DatetimeToString(share_data.share_vect[idx].first) << " ";
			std::cout << std::setprecision(8) << std::fixed << share_data.share_vect[idx].second << std::endl;
		}

		std::cout
			<< "Last ten records" << "\n"
			<< "================" << "\n\n";

		for (size_t idx = size_UnixTimestampData - 10; idx < size_UnixTimestampData; ++idx) // Prints last 10 records
		{
			std::cout << "Idx: " << std::setfill('0') << std::setw(5) << idx << " ";
			std::cout << share_data.share_vect[idx].first << " = " << DatetimeToString(share_data.share_vect[idx].first) << " ";
			std::cout << std::setprecision(8) << std::fixed << share_data.share_vect[idx].second << std::endl;
		}
	}
}

bool CheckFileExists(std::string filename) // Function checks if called file exists
{
	bool return_value = true;

	std::ifstream share_price_file(filename); // Create an input filestream

	if (!share_price_file.is_open()) 	// Make sure the file is open
	{
		std::cout << "Unable to open file: " << filename << std::endl << std::endl;
		return_value = false;
	}

	return return_value;
}