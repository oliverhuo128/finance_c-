//Ashley Openshaw 1761298- Problem Sheet 3

// TimeSeriesTransformations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TimeSeriesTransformations.h"

#include <fstream>
#include <sstream>

using namespace OOP;

TimeSeriesTransformations::TimeSeriesTransformations(const std::string filename)
{
	// Load file given the filename and store the time data and the share prices internally

	std::string time_stamp_share_price_line;

	time_t unix_timestamp_in;
	double share_price_in;

	std::ifstream share_price_file(filename); // Create an input filestream

	if (!share_price_file.is_open()) 	// Make sure the file is open
	{
		std::cout << "Unable to open file: " << filename << std::endl;
	}
	else
	{
		if (share_price_file.good())
		{
			std::getline(share_price_file, time_stamp_share_price_line); // Extract the first line in the file and discard - header information not used

			while (std::getline(share_price_file, time_stamp_share_price_line)) // Read data, line by line
			{
				std::stringstream ss(time_stamp_share_price_line); // Create a stringstream of the current line

				ss >> unix_timestamp_in;

				if (ss.peek() == ',') ss.ignore(); // Ignore the comma separator between timestamp and share_price

				ss >> share_price_in;

				share_vect.push_back(std::make_pair(unix_timestamp_in, share_price_in));
			}
		}
	}

	std::cout << "share_vect size: " << share_vect.size() << "\n";
}

TimeSeriesTransformations::~TimeSeriesTransformations() // Destructor
{
}