
#include "TimeSeriesTransformations.h"
#include <fstream> 
#include <algorithm> 
#include <functional> 
#include <utility>   // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream>   // std::stringstream 

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