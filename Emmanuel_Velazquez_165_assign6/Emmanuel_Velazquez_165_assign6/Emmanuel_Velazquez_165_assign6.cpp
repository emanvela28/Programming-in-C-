#include <iostream>
using namespace std;


// Comment 1: Because we are using a 3 x 3 array we can set the colums to a constant of 3
const int COLS = 3;

void printSquare(int grid[][COLS]) {
    // Comment 2: This is going to print out the array row by row
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkRange(int grid[][COLS]) {
    // Comment 3: This is going to check to see if we have all values 1-9
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] < 1 || grid[i][j] > 9) {
                // Comment 4: This is going to return false if the square does not contain values 1-9/
                return false;
            }
        }
    }
    return true;
}

bool checkUnique(int grid[][COLS]) {
    // Comment 5: This is going to check to see if there are any duplicates
    bool seen[10] = { false };

    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (seen[grid[i][j]]) {
                return false;
            }
            seen[grid[i][j]] = true;
        }
    }
    return true;
}

bool checkRowSum(int grid[][COLS]) {
    // Comment 6: TThis is going to check to see if the sum of the rows are equal
    int sum = 0;
    for (int i = 0; i < COLS; i++) {
        int rowSum = 0;
        for (int j = 0; j < COLS; j++) {
            rowSum += grid[i][j];
        }
        if (i == 0) {
            sum = rowSum;
        }
        else if (rowSum != sum) {
            return false; 
        }
    }
    return true;
}

bool checkColSum(int grid[][COLS]) {
    // Comment 7: This is going to check if the sum of values in each column is equal.
    int sum = 0;
    for (int j = 0; j < COLS; j++) {
        int colSum = 0;
        for (int i = 0; i < COLS; i++) {
            colSum += grid[i][j];
        }
        if (j == 0) {
            sum = colSum;
        }
        else if (colSum != sum) {
            return false;
        }
    }
    return true;
}

bool checkDiagSum(int grid[][COLS]) {
    // Comment 8: This is going to check the sum for the diagonal rows
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < COLS; i++) {
        sum1 += grid[i][i];
        sum2 += grid[i][COLS - 1 - i];
    }
    return (sum1 == sum2);
}

bool isMagicSquare(int grid[][COLS]) {
    // Comment 9: This is going to check to see if it is a Magic Square
    printSquare(grid);
    return checkRange(grid) && checkUnique(grid) && checkRowSum(grid) && checkColSum(grid) && checkDiagSum(grid);
}

int main() {
    int magicSquare[COLS][COLS] = {
        {8, 1, 6},
        {3, 5, 7},
        {4, 9, 2}
    };

    if (isMagicSquare(magicSquare)) {
        // Comment 10: Printing the answer given if it is or if it isn't.
        cout << "This is a Lo Shu Magic Square." << endl;
    }
    else {
        cout << "This is not a Lo Shu Magic Square." << endl;
    }

    return 0;
}
