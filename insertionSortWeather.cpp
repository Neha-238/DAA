#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// Define a structure to hold weather data
struct WeatherData
{
    string city;
    string time;
    int temperature;
    int humidity;
    int rainfall;
};

// Insertion sort function to sort the data by city names
void insertionSort(vector<WeatherData> &data)
{
    int n = data.size();
    for (int i = 1; i < n; i++)
    {
        WeatherData key = data[i];
        int j = i - 1;

        // Compare city names and insert key in the correct position
        while (j >= 0 && data[j].city > key.city)
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Function to read data from a CSV file
vector<WeatherData> readCSV(const string &filename)
{
    vector<WeatherData> data;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not open the file " << filename << endl;
        return data;
    }

    string line, word;
    // Skip the header line
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);
        WeatherData record;
        getline(ss, record.city, ',');
        getline(ss, record.time, ',');
        ss >> record.temperature;
        ss.ignore(); // Ignore the comma
        ss >> record.humidity;
        ss.ignore(); // Ignore the comma
        ss >> record.rainfall;
        data.push_back(record);
    }

    file.close();
    return data;
}

// Function to write sorted data to a CSV file
void writeCSV(const string &filename, const vector<WeatherData> &data)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Could not write to the file " << filename << endl;
        return;
    }

    // Write the header
    file << "City,Time,Temperature,Humidity,Rainfall\n";

    // Write the data
    for (const auto &record : data)
    {
        file << record.city << ","
             << record.time << ","
             << record.temperature << ","
             << record.humidity << ","
             << record.rainfall << "\n";
    }

    file.close();
}

int main()
{
    // Input and output file names
    string inputFile = "input.csv";
    string outputFile = "output.csv";

    // Read data from the input CSV file
    vector<WeatherData> data = readCSV(inputFile);

    if (data.empty())
    {
        cerr << "No data to process!" << endl;
        return 1;
    }

    // Sort the data using insertion sort
    insertionSort(data);

    // Write the sorted data to the output CSV file
    writeCSV(outputFile, data);

    cout << "Data sorted and written to " << outputFile << " successfully." << endl;
    return 0;
}
