//Ashley Openshaw 1761298- Problem Sheet 3

#ifndef TIME_SERIES_TRANSFORMATIONS_H_
#define TIME_SERIES_TRANSFORMATIONS_H_

#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

namespace OOP {
	class TimeSeriesTransformations
	{
	public:
		//TimeSeriesTransformations(); //dummy constructor - can be removed
		//TimeSeriesTransformations(const long value); //dummy constructor - can be removed
		TimeSeriesTransformations(const std::string filename); // constructor to load data from given filename
		TimeSeriesTransformations(const  double shareprice);

		~TimeSeriesTransformations(); // destructor

		friend double mean(const TimeSeriesTransformations& sharedata) // Function calculates the mean share price
		{
			double sum_value = 0.0;

			for (auto iterator : sharedata.share_vect)
				sum_value += iterator.second;

			return(sum_value / sharedata.share_vect.size());
		}

		friend double standardDeviation(const TimeSeriesTransformations& sharedata) // Function calculates the standard deviation of share prices
		{
			double standard_deviation_value = 0.0;

			double mean_value = mean(sharedata);

			for (auto iterator : sharedata.share_vect)
				standard_deviation_value += pow(iterator.second - mean_value, 2);

			return (sqrt(standard_deviation_value / sharedata.share_vect.size()));
		};

		friend double computeIncrementMean(const TimeSeriesTransformations& sharedata) // Function calculates mean of the increments in share prices
		{
			double sum_value = 0.0;

			for (unsigned idx = 1; idx < sharedata.share_vect.size(); ++idx)
				sum_value += sharedata.share_vect[idx].second - sharedata.share_vect[idx - 1].second;

			return(sum_value / (sharedata.share_vect.size() - 1));
		}

		friend double compIncrementMean(const TimeSeriesTransformations& sharedata)
			// Repeat of computeIncrementMean with different name as compiler issue with friend names over 20 characters when call from another friend function
		{
			double sum_value = 0.0;

			for (unsigned idx = 1; idx < sharedata.share_vect.size(); idx++)
				sum_value += sharedata.share_vect[idx].second - sharedata.share_vect[idx - 1].second;

			return(sum_value / (sharedata.share_vect.size() - 1));
		}

		friend double computeIncrementStandardDeviation(const TimeSeriesTransformations& sharedata) // Function calculates standard deviation of the increments in share prices
		{
			double standard_deviation_value = 0.0;

			double mean_increment = compIncrementMean(sharedata);

			for (unsigned idx = 1; idx < sharedata.share_vect.size(); idx++)
				standard_deviation_value += pow(
					(sharedata.share_vect[idx].second - sharedata.share_vect[idx - 1].second - mean_increment), 2);

			return (sqrt(standard_deviation_value / (sharedata.share_vect.size() - 1)));
		}

		static bool compare(const std::pair<time_t, double>& i, const std::pair<time_t, double>& j) // Function compares pairs of a vector
		{
			return i.first < j.first;
		}

		friend void appendPrice(TimeSeriesTransformations& sharedata, const time_t time_t_to_add, const double share_price_to_add) // Function appends share price to data
		{
			sharedata.share_vect.push_back(std::make_pair(time_t_to_add, share_price_to_add));

			std::sort(sharedata.share_vect.begin(), sharedata.share_vect.end(), compare); // Calls sort function to add user share price in the correct place

		}

		friend double GreatestIncrememt(const TimeSeriesTransformations& sharedata) // Function calculates the greatest increment in share price
		{
			double greatest_increment = std::numeric_limits<double>::lowest();
			double increment = 0.0;

			for (unsigned idx = 1; idx < sharedata.share_vect.size(); idx++)
			{
				increment = sharedata.share_vect[idx].second - sharedata.share_vect[idx - 1].second;

				if (increment > greatest_increment)
					greatest_increment = increment;
			}

			return greatest_increment;
		}

		friend void printEntriesOnDay(const TimeSeriesTransformations& sharedata, struct tm timeinfo_date_to_search) // Function prints all data from all entries on a given date
		{
			struct tm timeinfo_of_record;
			time_t rawtime;

			char datetime_string[20];

			std::cout << "\nDates within daylight saving time may impact number of results returned due to conversion from Unix timestamp\n";

			for (auto iterator : sharedata.share_vect)
			{
				rawtime = iterator.first;
				localtime_s(&timeinfo_of_record, &rawtime);

				// Checks the date
				if (timeinfo_of_record.tm_year == timeinfo_date_to_search.tm_year)
				{
					if (timeinfo_of_record.tm_mon == timeinfo_date_to_search.tm_mon)
					{
						if (timeinfo_of_record.tm_mday == timeinfo_date_to_search.tm_mday)
						{
							strftime(datetime_string, 20, "%Y/%m/%d-%H:%M:%S", &timeinfo_of_record);

							std::cout << "Matching record for date: " << rawtime

								<< " = " << datetime_string
								<< " share price: " << std::setprecision(8) << std::fixed << iterator.second << std::endl;
						}
					}
				};
			}
		}

		friend void getTimestampsMatchingPrice(const TimeSeriesTransformations& sharedata, double share_price_to_match) // Function finds the time stamps of share prices with equal value to user inputted value
		{
			std::cout << "\nDates within daylight saving time may impact number of results returned due to conversion from Unix timestamp\n";

			int count = 0;

			for (auto iterator : sharedata.share_vect)
			{
				if (iterator.second == share_price_to_match)
				{
					std::cout << "Matching record for share price: " << share_price_to_match
						<< " = " << iterator.first << std::endl;
					count = count + 1;
				}
			}
			
			if (count == 0) { // Outputs 'error' message and finds similar share prices
				std::cout << "No records match that share price. The following data is similar to your share price" << std::endl << std::endl;

				getTimestampsSimilarPrice(sharedata, share_price_to_match); // Calls getTimestampsSimilarPrice function
			}
		}

		friend void getTimestampsSimilarPrice(const TimeSeriesTransformations& sharedata, double share_price_to_match) // Function finds similar share prices to user inputted share price
		{
			for (auto iterator:sharedata.share_vect)
			{
				if (share_price_to_match - 0.1 <= iterator.second and share_price_to_match + 0.1 >= iterator.second) {
					std::cout << "A similar record for share price (within 0.1) of "
						<< std::setprecision(8) << std::fixed <<  share_price_to_match << " is : " << iterator.second
						<< " at " << iterator.first << std::endl;
				}
			}
		}


		//Defines class functions
		friend void PrintShareDataForDebug(const TimeSeriesTransformations share_data);

		friend bool saveData(TimeSeriesTransformations  share_data);

		friend void PrintAllSharePricesOnADate(const TimeSeriesTransformations& sharedata);

		friend void PrintSharePricesOnDate(const TimeSeriesTransformations& sharedata);

		friend void PrintIncrementsOnADate(const TimeSeriesTransformations& sharedata);

		friend void DisplaySharePriceRange(TimeSeriesTransformations& sharedata);

		friend void RemoveValueAtTimestamp(TimeSeriesTransformations& sharedata);

		friend void RemoveEqual(TimeSeriesTransformations& sharedata);

		friend void RemoveBelow(TimeSeriesTransformations& sharedata);

		friend void RemoveAbove(TimeSeriesTransformations& sharedata);

		friend bool TimestampToDelete(TimeSeriesTransformations& sharedata)
		{
			return true;
		}

		friend void removeEntryAtTime(TimeSeriesTransformations& sharedata, const time_t timestamp_to_delete) // Function removes entry at a given timestamp
		{
			sharedata.share_vect.erase(
				std::remove_if(sharedata.share_vect.begin(), sharedata.share_vect.end(), [&](auto& elem) { return elem.first == timestamp_to_delete; })
				, sharedata.share_vect.end());
		}

		friend void removePriceEqualTo(TimeSeriesTransformations& sharedata, const double price_to_delete) // Function removes share prices equal to a given value
		{
			std::cout << "Number of records to be deleted: "
				<< count_if(sharedata.share_vect.begin(), sharedata.share_vect.end(), [&](auto& elem) { return elem.second == price_to_delete; })
				<< std::endl;

			sharedata.share_vect.erase(
				std::remove_if(sharedata.share_vect.begin(), sharedata.share_vect.end(), [&](auto& elem) { return elem.second == price_to_delete; })
				, sharedata.share_vect.end());
		}

		friend void removePriceGreaterThan(TimeSeriesTransformations& sharedata, const double price_to_delete) // Function removes share prices greater than a given value
		{
			std::cout << "Number of records to be deleted: "
				<< count_if(sharedata.share_vect.begin(), sharedata.share_vect.end(), [&](auto& elem) { return elem.second > price_to_delete; })
				<< std::endl;

			sharedata.share_vect.erase(
				std::remove_if(sharedata.share_vect.begin(), sharedata.share_vect.end(), [&](auto& elem) { return elem.second > price_to_delete; })
				, sharedata.share_vect.end());
		}

		friend void removePriceLessThan(TimeSeriesTransformations& sharedata, const double price_to_delete) // Function removes share prices less than a given value
		{
			std::cout << "Number of records to be deleted: "
				<< count_if(sharedata.share_vect.begin(), sharedata.share_vect.end(), [&](auto& elem) { return elem.second < price_to_delete; })
				<< std::endl;

			sharedata.share_vect.erase(
				std::remove_if(sharedata.share_vect.begin(), sharedata.share_vect.end(), [&](auto& elem) { return elem.second < price_to_delete; })
				, sharedata.share_vect.end());
		}

		friend void printSharePricesOnDate(const TimeSeriesTransformations& sharedata, struct tm timeinfo_date_to_search) // Function prints the share prices on a given date
		{
			struct tm timeinfo_of_record;
			time_t rawtime;

			char datetime_string[20];

			for (auto iterator : sharedata.share_vect)
			{
				rawtime = iterator.first;
				localtime_s(&timeinfo_of_record, &rawtime);

				if (timeinfo_of_record.tm_year == timeinfo_date_to_search.tm_year)
				{
					if (timeinfo_of_record.tm_mon == timeinfo_date_to_search.tm_mon)
					{
						if (timeinfo_of_record.tm_mday == timeinfo_date_to_search.tm_mday)
						{
							strftime(datetime_string, 20, "%Y/%m/%d-%H:%M:%S", &timeinfo_of_record);

							std::cout
								<< " share price: " << std::setprecision(8) << std::fixed << iterator.second << std::endl;
						}
					}
				};
			}
		}

		friend void printIncrementsOnDate(const TimeSeriesTransformations& sharedata, struct tm timeinfo_date_to_search) // Function prints increments in share price on a given date
		{
			struct tm timeinfo_of_record;
			time_t rawtime;

			char datetime_string[20];
			int counter = 0;

			for (unsigned idx = 0; idx < sharedata.share_vect.size(); idx++)
			{
				rawtime = sharedata.share_vect[idx].first;
				localtime_s(&timeinfo_of_record, &rawtime);

				if (timeinfo_of_record.tm_year == timeinfo_date_to_search.tm_year)
				{
					if (timeinfo_of_record.tm_mon == timeinfo_date_to_search.tm_mon)
					{
						if (timeinfo_of_record.tm_mday == timeinfo_date_to_search.tm_mday)
						{
							strftime(datetime_string, 20, "%Y/%m/%d-%H:%M:%S", &timeinfo_of_record);

							double incr_value = 0.0;

							while (int i = idx) { // Calculates increment
								incr_value = sharedata.share_vect[idx].second - sharedata.share_vect[idx - 1].second;
								break;
							}

							if (counter == 0) { // Excludes first record on given date
								counter = 1;
							}
							else {
								std::cout
									<< " share price increment : " << std::setprecision(8) << std::fixed << incr_value << std::endl;
							}

						}
					}
				};
			}
		}

	private:

		std::vector<std::pair <time_t, double>> share_vect; // UNIX timestamp, double share price
	};
}

#endif // TIME_SERIES_TRANSFORMATIONS_H_
