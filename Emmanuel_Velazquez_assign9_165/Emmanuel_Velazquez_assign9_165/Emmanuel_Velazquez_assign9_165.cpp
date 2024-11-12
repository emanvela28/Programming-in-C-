// Comment 1: Including the necessary header file for input and output operations.
#include <iostream>
using namespace std;

int getMode(int*, int); // Function prototype for getMode
int* makeArray(int);   // Function prototype for makeArray

int main()
{
    const int SIZE = 11;
    int test[SIZE] = { 3, 7, 4, 3, 5, 8, 0, 9, 8, 6, 1, };
    int mode;

    mode = getMode(test, SIZE);

    // Comment 2: Checking if the mode is -1, indicating no mode, and displaying the result accordingly.
    if (mode == -1)
        cout << "The test set has no mode.\n";
    else
        cout << "\nThe mode of the test set is: " << mode << endl;

    system("PAUSE");
    return 0;
}

int getMode(int* array, int size)
{
    // Comment 3: Dynamically allocating an array of integers to store frequencies.
    int* frequencies = makeArray(size);

    // Comment 4: Initializing the frequencies array with 0s.
    for (int i = 0; i < size; i++)
    {
        *(frequencies + i) = 0;
    }

    // Comment 5: Calculating frequencies of values in the 'array' and storing them in the 'frequencies' array.
    for (int i = 0; i < size; i++)
    {
        int value = *(array + i);
        *(frequencies + value) += 1;
    }

    int maxFrequency = 0;
    int maxIndex = 0;

    // Comment 6: Finding the value with the highest frequency to determine the mode.
    for (int i = 0; i < size; i++)
    {
        if (*(frequencies + i) > maxFrequency)
        {
            maxFrequency = *(frequencies + i);
            maxIndex = i;
        }
    }

    // Comment 7: Deallocating the dynamically allocated 'frequencies' array to free memory.
    delete[] frequencies;

    // Comment 8: Checking if the maxFrequency is 1 or less, indicating no mode, and returning -1.
    if (maxFrequency <= 1)
    {
        return -1;
    }

    // Comment 9: Returning the value with the highest frequency as the mode.
    return maxIndex;
}

// Comment 10: Definition of the makeArray function that dynamically allocates an integer array.
int* makeArray(int size)
{
    return new int[size];
}
