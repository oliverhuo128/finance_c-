
#include "TimeSeriesTransformations.h"
#include <fstream> 
#include <algorithm> 
#include <functional> 
#include <utility>   // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream>   // std::stringstream 
#include <ctime>

using namespace std;
using namespace OOP;

TimeSeriesTransformations::TimeSeriesTransformations(string filename) {
	read_csv(filename);
}


void TimeSeriesTransformations::read_csv(std::string filename) {
	// Reads a CSV file into a vector of <string, vector<double>> pairs where  
	// each pair represents <column name, column values>  
	// Create a vector of <string, int vector> pairs to store the result 

	// Create an input filestream
	std::ifstream _file(filename);
	// Make sure the file is open  
	if (!_file.is_open())
		throw std::runtime_error("Could not open file");
	// Helper vars  
	std::string line, colname;
	double val;
	// Read the column names  
	if (_file.good()) {
		// Extract the first line in the file    
		std::getline(_file, line);
		// Create a stringstream from line    
		std::stringstream ss(line);
		// Extract each column name    
		while (std::getline(ss, colname, ',')) {
			// Initialize and add <colname, int vector> pairs to result      
			m_result.push_back({ colname, std::vector<double> {}
			});
		}
	}

	// Read data, line by line  
	while (std::getline(_file, line)) {
		// Create a stringstream of the current line    
		std::stringstream ss(line);
		// Keep track of the current column index    
		int colIdx = 0;
		// Extract each integer    
		while (ss >> val) {
			// Add the current integer to the 'colIdx' column's values vector
			m_result.at(colIdx).second.push_back(val);
			// If the next token is a comma, ignore it and move on      
			if (ss.peek() == ',')
				ss.ignore();
			// Increment the column index      
			colIdx++;
		}
	}
	// Close file  
	_file.close();
}

// Constructor which populates the data of the class from the input vectors
TimeSeriesTransformations::TimeSeriesTransformations(std::vector<double> timeSeries, std::vector<double> sharePrice) {

	// Add column names
	m_result.push_back({ "TIMESTAMP", std::vector<double> {}
	});
	m_result.push_back({ "ShareX", std::vector<double> {}
	});

	// Copy data from vectors into class
	for (int i = 0; i != timeSeries.size(); i++)
	{
		m_result.at(0).second.push_back(timeSeries.at(i));
		m_result.at(1).second.push_back(sharePrice.at(i));
	}
}

// Calculates the mean of a vector
double TimeSeriesTransformations::generalMean(std::vector<double> data){

	// Sum value of vector
	double total = 0.0;
	for (int i = 0; i < data.size(); i++)
	{
		total += data.at(i);
	}

	// Divide by number of values to get the mean
	return total / (double)data.size();
}

// Finds mean of the prices
double TimeSeriesTransformations::mean(){
	return generalMean(m_result.at(1).second);
}

// Finds standard deviation of the prices
double TimeSeriesTransformations::standardDeviation(){
	
	// Get mean of the prices
	double meanvalue = mean();

	// Calculate square of values minus mean and store in a vector
	vector<double> adjusted;
	for (int i = 0; i < m_result.at(1).second.size(); i++)
	{
		adjusted.push_back(pow((m_result.at(1).second.at(i) - meanvalue), 2));
	}

	// Find mean of the vector and square root
	return sqrt(generalMean(adjusted));
}

// Finds the mean of the increments
double TimeSeriesTransformations::computeIncrementMean(){

	// Create vector of the increments
	vector<double> adjusted;
	for (int i = 0; i < m_result.at(1).second.size() - 1; i++)
	{
		adjusted.push_back(m_result.at(1).second.at(i) - m_result.at(1).second.at(i + 1));
	}

	// Calculate mean of vector
	return generalMean(adjusted);
}

// Finds the standard deviation of the increments
double TimeSeriesTransformations::computeIncrementStandardDeviation(){

	// Get mean of the increments
	double meanvalue = computeIncrementMean();

	// Calculate square of increments minus mean and store in a vector
	vector<double> adjusted;
	for (int i = 0; i < m_result.at(1).second.size() - 1; i++)
	{
		adjusted.push_back(pow(((m_result.at(1).second.at(i) - m_result.at(1).second.at(i + 1)) - meanvalue), 2));
	}

	// Find mean of the vector and square root
	return sqrt(generalMean(adjusted));
}

// Add date price pair to the class
void TimeSeriesTransformations::appendPrice(tm date, double price){
	m_result.at(0).second.push_back(mktime(&date));
	m_result.at(1).second.push_back(price);
}

// Find all dates with the given price
void TimeSeriesTransformations::getTimestampsMatchingPrice(double price){

	for (int i = 0; i < m_result.at(1).second.size(); i++)
	{
		// When comparing doubles check whether the difference is within tolerance
		if (std::abs(m_result.at(1).second.at(i) - price) < 0.0001){

			// Create date time
			time_t dataTime = (time_t)m_result.at(0).second.at(i);
			tm dataDate;
			localtime_s(&dataDate, &dataTime);

			// Print date time data
			cout << endl << "Year:" << 1900 + dataDate.tm_year << endl;
			cout << "Month: " << 1 + dataDate.tm_mon << endl;
			cout << "Day: " << dataDate.tm_mday << endl;
			cout << "Hour: " << 5 + dataDate.tm_hour << endl;
			cout << "Minute: " << 5 + dataDate.tm_hour << endl << endl;
		}
	}
}

// Prints all prices from the given day
void TimeSeriesTransformations::printEntriesOnDay(tm date){

	for (int i = 0; i < m_result.at(1).second.size(); i++)
	{
		// Create date time
		time_t dataTime = (time_t)m_result.at(0).second.at(i);
		tm dataDate;
		localtime_s(&dataDate, &dataTime);

		// If the relevant times match print the price
		if (date.tm_year == dataDate.tm_year && date.tm_mon == dataDate.tm_mon  && date.tm_mday == dataDate.tm_mday){
			cout << m_result.at(1).second.at(i) << endl;
		}
	}
}

// Removes entries at a given time
void TimeSeriesTransformations::removeEntryAtTime(tm date){

	for (int i = 0; i < m_result.at(1).second.size();)
	{
		// Create data time
		time_t dataTime = (time_t)m_result.at(0).second.at(i);
		tm dataDate;
		localtime_s(&dataDate, &dataTime);

		// If the relevant times match delete the price
		if (date.tm_year == dataDate.tm_year && date.tm_mon == dataDate.tm_mon && date.tm_mday == dataDate.tm_mday && date.tm_hour == dataDate.tm_hour && date.tm_min == dataDate.tm_min){
			m_result.at(0).second.erase(m_result.at(0).second.begin() + i);
			m_result.at(1).second.erase(m_result.at(1).second.begin() + i);
		}
		else{
			// Only update on no delete since delete reduces vector size
			i++;
		}
	}
}

// Removes entries at a certain price
void TimeSeriesTransformations::removePricesEqualTo(double price){
	for (int i = 0; i < m_result.at(1).second.size();)
	{
		// When comparing doubles check whether the difference is within tolerance. Delete entry
		if (std::abs(m_result.at(1).second.at(i) - price) < 0.0001){
			m_result.at(0).second.erase(m_result.at(0).second.begin() + i);
			m_result.at(1).second.erase(m_result.at(1).second.begin() + i);
		}
		else{
			// Only update on no delete since delete reduces vector size
			i++;
		}
	}
}

// Removes entries above a certain price
void TimeSeriesTransformations::removePricesGreaterThan(double price){
	for (int i = 0; i < m_result.at(1).second.size();)
	{
		// Check if the price is greater. Delete entry
		if (m_result.at(1).second.at(i) > price){
			m_result.at(0).second.erase(m_result.at(0).second.begin() + i);
			m_result.at(1).second.erase(m_result.at(1).second.begin() + i);
		}
		else{
			// Only update on no delete since delete reduces vector size
			i++;
		}
	}
}

// Removes entries below a certain price
void TimeSeriesTransformations::removePricesLessThan(double price){
	for (int i = 0; i < m_result.at(1).second.size();)
	{
		// Check if the price is lower. Delete entry
		if (m_result.at(1).second.at(i) < price){
			m_result.at(0).second.erase(m_result.at(0).second.begin() + i);
			m_result.at(1).second.erase(m_result.at(1).second.begin() + i);
		}
		else{
			// Only update on no delete since delete reduces vector size
			i++;
		}
	}
}

// Finds the greatest increment in price
double TimeSeriesTransformations::greatestIncrementInPrices(){
	
	// By default sets the greatest to the first possible increment
	double greatest = 0;
	if (m_result.at(1).second.size() > 1){
		greatest = m_result.at(1).second.at(0) - m_result.at(1).second.at(1);
	}

	// Loops through all other increments. If any are greater than the greatest then update the greatest.
	for (int i = 0; i < m_result.at(1).second.size() - 1; i++)
	{
		if (greatest < m_result.at(1).second.at(i) - m_result.at(1).second.at(i + 1)){
			greatest = m_result.at(1).second.at(i) - m_result.at(1).second.at(i + 1);
		}
	}

	return greatest;
}

// Outputs the class to a csv file
void TimeSeriesTransformations::saveData(string fileName){

	// Create and open file
	std::ofstream myFile(fileName);

	// Add column headers
	myFile << "TIMESTAMP" << "," << "ShareX" << "\n";

	// Add price and time data
	for (int i = 0; i < m_result.at(1).second.size(); i++)
	{
		myFile << m_result.at(0).second.at(i) << "," << m_result.at(1).second.at(i) << "\n";
	}

	// Close file
	myFile.close();
}