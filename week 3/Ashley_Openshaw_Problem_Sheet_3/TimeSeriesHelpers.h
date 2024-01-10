//Ashley Openshaw 1761298- Problem Sheet 3

#ifndef TIME_SERIES_HELPERS_H_
#define TIME_SERIES_HELPERS_H_

#include <string>
#include <vector>

#include "TimeSeriesTransformations.h"

// Defines functions
bool CheckFileExists(std::string filename);
bool CheckShareDateCorrect(std::string filename_from_user, OOP::TimeSeriesTransformations share_data);
bool DatetimeChange(int& value1);
bool ReadShareCSV(std::string filename, std::vector<time_t>& unix_timestamp, std::vector<double>& share_price);
bool OOP::saveData(OOP::TimeSeriesTransformations share_data); 

std::string DatetimeToString(time_t& raw_time);

void OOP::PrintShareDataForDebug(OOP::TimeSeriesTransformations share_data);
void TestDatetimeToString(void);

#endif // TIME_SERIES_HELPERS_H_