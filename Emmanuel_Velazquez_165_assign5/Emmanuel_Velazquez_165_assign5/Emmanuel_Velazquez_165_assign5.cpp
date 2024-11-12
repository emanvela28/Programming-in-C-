#include <iostream>
using namespace std;

const int COLS = 5;

// Comment 1: Calculate the total of all elements in a 2D array.
int getTotal(int array[][COLS], int rows) {
    int total = 0;
    // Comment 2: Iterate through each row and column.
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < COLS; col++) {
            // Comment 3: The value at the current row and column is added to the total.
            total += array[row][col];
        }
    }
    return total;
}

// Comment 4: Calculate the average value of elements in a 2D array.
double getAverage(int array[][COLS], int rows) {
    // Comment 5: Total is calculated using the previous function.
    int total = getTotal(array, rows);
    // Comment 6: Divide the total by the number of elements for the average
    return static_cast<double>(total) / (rows * COLS);
}

// Comment 7: Calculate the total of values in a specific row of a 2D array.
int getRowTotal(int array[][COLS], int rowToTotal) {
    int total = 0;
    // Comment 8: A loop iterates through the columns of the current row.
    for (int col = 0; col < COLS; col++) {
        // Comment 9: The value of the current column in the specified row is added to the total.
        total += array[rowToTotal][col];
    }
    return total;
}

// Comment 10: This function calculates the total of values in a specific column of a 2D array.
int getColumnTotal(int array[][COLS], int colToTotal, int rows) {
    int total = 0;
    // Comment 11: A loop iterates through the rows of the specified column.
    for (int row = 0; row < rows; row++) {
        // Comment 12: The value at the current row in the specified column is added to the total.
        total += array[row][colToTotal];
    }
    return total;
}

// Comment 13: Highest value in a specific row of a 2D array.
int getHighestInRow(int array[][COLS], int rowToSearch) {
    int highest = array[rowToSearch][0];
    for (int col = 1; col < COLS; col++) {
        if (array[rowToSearch][col] > highest) {
            highest = array[rowToSearch][col];
        }
    }
    return highest;
}

// Comment 14: This function finds the lowest value in a specific row of a 2D array.
int getLowestInRow(int array[][COLS], int rowToSearch) {
    int lowest = array[rowToSearch][0];
    for (int col = 1; col < COLS; col++) {
        if (array[rowToSearch][col] < lowest) {
            lowest = array[rowToSearch][col];
        }
    }
    return lowest;
}

int main() {
    const int ROWS = 4;

    int testArray[ROWS][COLS] = {
        {51, 52, 53, 54, 55},
        {56, 57, 58, 59, 510},
        {711, 712, 713, 714, 715},
        {716, 717, 718, 719, 720}
    };

    cout << "The total of the array elements is " << getTotal(testArray, ROWS) << endl;
    cout << "The average value of an element is " << getAverage(testArray, ROWS) << endl;
    cout << "The total of row 0 is " << getRowTotal(testArray, 0) << endl;
    cout << "The total of col 2 is " << getColumnTotal(testArray, 2, ROWS) << endl;
    cout << "The highest value in row 2 is " << getHighestInRow(testArray, 2) << endl;
    cout << "The lowest value in row 2 is " << getLowestInRow(testArray, 2) << endl;

    return 0;
}