#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>   // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream>   // std::stringstream 

void write_csv(std::string filename, std::vector<std::pair<std::string, std::vector<int>>> dataset) {
  // Make a CSV file with one or more columns of integer values
  // Each column of data is represented by the pair <column name, column data>
  //   as std::pair<std::string, std::vector<int>>
  // The dataset is represented as a vector of these columns
  // Note that all columns should be the same size

  // Create an output filestream object
  std::ofstream _file(filename);

  // Send column names to the stream
  for (int j = 0; j < dataset.size(); ++j)  {
    _file << dataset.at(j).first;
    if (j != dataset.size() - 1) _file << ","; // No comma at end of line
  }
  _file << "\n";

  // Send data to the stream
  for (int i = 0; i < dataset.at(0).second.size(); ++i)  {
    for (int j = 0; j < dataset.size(); ++j)
    {
      _file << dataset.at(j).second.at(i);
      if (j != dataset.size() - 1) _file << ","; // No comma at end of line
    }
    _file << "\n";
  }

  // Close the file
  _file.close();
}



std::vector<std::pair<std::string, std::vector<int>>> read_csv(std::string filename) {
  // Reads a CSV file into a vector of <string, vector<int>> pairs where
  // each pair represents <column name, column values>

  // Create a vector of <string, int vector> pairs to store the result
  std::vector<std::pair<std::string, std::vector<int>>> result;

  // Create an input filestream
  std::ifstream _file(filename);

  // Make sure the file is open
  if (!_file.is_open()) 
    throw std::runtime_error("Could not open file");

  // Helper vars
  std::string line, colname;
  int val;

  // Read the column names
  if (_file.good()) {
    // Extract the first line in the file
    std::getline(_file, line);

    // Create a stringstream from line
    std::stringstream ss(line);

    // Extract each column name
    while (std::getline(ss, colname, ',')) {

      // Initialize and add <colname, int vector> pairs to result
      result.push_back({ colname, std::vector<int> {} });
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
      result.at(colIdx).second.push_back(val);

      // If the next token is a comma, ignore it and move on
      if (ss.peek() == ',') ss.ignore();

      // Increment the column index
      colIdx++;
    }
  }

  // Close file
  _file.close();

  return result;
}

int main() {
  // Read csv_data.csv 
  srand(static_cast <unsigned int> (time(0)));
  // Make three vectors, each of length 10000 filled with 0s 
  std::vector<int> a(10000, 0);
  std::vector<int> b(10000, 0);
  std::vector<int> c(10000, 0);

  // Wrap into a vector
  std::vector<std::pair<std::string, std::vector<int>>> csv_data = { {"X", a}, {"Y", b}, {"Z", c} };

  for (int i = 0; i < 10000; ++i) {
    int compRand1 = rand() % 100 + 1; //Generates number between 1 - 100
    int compRand2 = rand() % 100 + 1; //Generates number between 1 - 100
    int compRand3 = rand() % 100 + 1; //Generates number between 1 - 100
    csv_data.at(0).second.at(i) = compRand1;
    csv_data.at(1).second.at(i) = compRand2;
    csv_data.at(2).second.at(i) = compRand3;
  
  }

  // Write to another file to check that this was successful
  write_csv("csv_data.csv", csv_data);
  std::vector<std::pair<std::string, std::vector<int>>> csv_data1 = read_csv("csv_data.csv");

  // check values are the same
  for (int j = 0; j < 3; ++j) {
    for (int i = 0; i < 10000; ++i) {
      if (csv_data.at(j).second.at(i) != csv_data1.at(j).second.at(i)) {
        std::cout << "data readin is different at:" << i << " original:" << csv_data.at(j).second.at(i) << ":read in:" << csv_data.at(j).second.at(i) << std::endl;
      }
    }
  }
  return 0;
}