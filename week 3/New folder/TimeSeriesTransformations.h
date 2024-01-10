//------------------------------------------------------------------------------
//
// OOP
// rows.h
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include guard

#ifndef OOP_TIMESERIESTRANS_H
#define OOP_TIMESERIESTRANS_H

//------------------------------------------------------------------------------
// include files
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

//------------------------------------------------------------------------------
// namespace definition
namespace OOP {

	//------------------------------------------------------------------------------
	/*! \class TimeSeriesTransformations in row.h
		 * \brief This is the class for a row with a pointer
		 */
	class TimeSeriesTransformations {
	public:
		TimeSeriesTransformations(string filename);
		TimeSeriesTransformations(std::vector<double> timeSeries, std::vector<double> sharePrice);

		double mean();
		double standardDeviation();

		double computeIncrementMean();
		double computeIncrementStandardDeviation();

		void appendPrice(tm date, double price);

		void getTimestampsMatchingPrice(double price);

		void printEntriesOnDay(tm date);

		void removeEntryAtTime(tm date);
		void removePricesEqualTo(double price);
		void removePricesGreaterThan(double price);
		void removePricesLessThan(double price);

		double greatestIncrementInPrices();

		void saveData(string fileName);

	private:

		void read_csv(std::string filename);
		TimeSeriesTransformations() {}; // hide default constructor
		std::vector<std::pair<std::string, std::vector<double>>> m_result;

		double generalMean(std::vector<double> data);

	}; // end of class

} //namespace

#endif // OOP_TIMESERIESTRANS_H