#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

void readWeatherData(char* ptr, const string& fileName);
void displayReport(const char* ptr);
int findMostRainyMonth(const char* ptr);
void calculateTotals(const char* ptr, int& totalRainy, int& totalCloudy, int& totalSunny);

// Comment 1: Define constants for the number of months and days in the summer season
const int NUM_OF_MONTHS = 3;
const int NUM_OF_DAYS = 30;

int main()
{
    // Comment 2: Declare a 2D array to store weather data and a pointer to the beginning of the array
    char weather[NUM_OF_MONTHS][NUM_OF_DAYS];
    char* ptr = &weather[0][0];

    // Comment 3: Read weather data from the specified file into the 2D array
    readWeatherData(ptr, "C:\\Users\\adamv\\Downloads\\RainOrShine.txt");

    // Comment 4: Display the header for the summer weather report
    cout << "Summer Weather Report\n\n";
    cout << setw(10) << left << "Month" << setw(10) << "Rainy" << setw(10) << "Cloudy" << setw(10) << "Sunny" << endl;
    cout << "------------------------------------\n";


    displayReport(ptr);

    // Comment 5: Display the totals for the entire three-month period
    cout << "------------------------------------\n";
    int totalRainy, totalCloudy, totalSunny;
    calculateTotals(ptr, totalRainy, totalCloudy, totalSunny);
    cout << setw(10) << left << "Totals" << setw(10) << totalRainy << setw(10) << totalCloudy << setw(10) << totalSunny << endl;

    // Comment 6: Determine and print the month with the most rainy days
    int mostRainyMonth = findMostRainyMonth(ptr);
    cout << "\nThe month with the most rainy days is: ";
    switch (mostRainyMonth)
    {
    case 0:
        cout << "June";
        break;
    case 1:
        cout << "July";
        break;
    case 2:
        cout << "August";
        break;
    default:
        cout << "Unknown";
    }
    cout << endl;

    return 0;
}

// Comment 7: Function to read weather data from a file into the 2D array using a pointer
void readWeatherData(char* ptr, const string& fileName)
{
    ifstream file(fileName);

    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> *ptr; 
            ptr++;        
        }

        file.close();
    }
    else
    {
        cout << "Error opening file: " << fileName << endl;
    }
}

// Comment 8: Function to display the weather report for each month
void displayReport(const char* ptr)
{
    int rainyCount, cloudyCount, sunnyCount;
    const string months[] = { "June", "July", "August" };

    for (int month = 0; month < NUM_OF_MONTHS; month++)
    {
        rainyCount = cloudyCount = sunnyCount = 0;

        for (int day = 0; day < NUM_OF_DAYS; day++)
        {
            char currentWeather = *(ptr + month * NUM_OF_DAYS + day);

            switch (currentWeather)
            {
            case 'R':
                rainyCount++;
                break;
            case 'C':
                cloudyCount++;
                break;
            case 'S':
                sunnyCount++;
                break;
            }
        }

        cout << setw(10) << left << months[month] << setw(10) << rainyCount << setw(10) << cloudyCount << setw(10) << sunnyCount << endl;
    }
}

// Comment 9: Function to find the month with the most rainy days
int findMostRainyMonth(const char* ptr)
{
    int mostRainyMonth = 0;
    int maxRainyDays = 0;

    for (int month = 0; month < NUM_OF_MONTHS; month++)
    {
        int rainyCount = 0;

        for (int day = 0; day < NUM_OF_DAYS; day++)
        {
            char currentWeather = *(ptr + month * NUM_OF_DAYS + day);

            if (currentWeather == 'R')
            {
                rainyCount++;
            }
        }

        if (rainyCount > maxRainyDays)
        {
            maxRainyDays = rainyCount;
            mostRainyMonth = month;
        }
    }

    return mostRainyMonth;
}

// Comment 10: Function to calculate totals for rainy, cloudy, and sunny days
void calculateTotals(const char* ptr, int& totalRainy, int& totalCloudy, int& totalSunny)
{
    totalRainy = totalCloudy = totalSunny = 0;

    for (int month = 0; month < NUM_OF_MONTHS; month++)
    {
        for (int day = 0; day < NUM_OF_DAYS; day++)
        {
            char currentWeather = *(ptr + month * NUM_OF_DAYS + day);

            switch (currentWeather)
            {
            case 'R':
                totalRainy++;
                break;
            case 'C':
                totalCloudy++;
                break;
            case 'S':
                totalSunny++;
                break;
            }
        }
    }
}
