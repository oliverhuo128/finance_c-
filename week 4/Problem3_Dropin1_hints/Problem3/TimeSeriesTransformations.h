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

	private:

		void read_csv(std::string filename);
		TimeSeriesTransformations() {}; // hide default constructor
		std::vector<std::pair<std::string, std::vector<double>>> m_result;

	}; // end of class

} //namespace

#endif // OOP_TIMESERIESTRANS_H