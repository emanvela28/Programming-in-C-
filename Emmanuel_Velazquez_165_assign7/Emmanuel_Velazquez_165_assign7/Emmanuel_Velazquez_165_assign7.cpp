#include <iostream>
#include <string>
#include <vector>
using namespace std;

void selectionSort(vector<string>&);

vector<string> getBoyNames() {
    vector<string> boyNames = {
        "Jacob", "Michael", "Joshua", "Matthew", "Daniel", "Christopher", // Add more names
    };
    return boyNames;
}

vector<string> getGirlNames() {
    vector<string> girlNames = {
        "Emily", "Madison", "Emma", "Olivia", "Hannah", "Abigail", // Add more names
    };
    return girlNames;
}

string getName(const string& gender) {
    string name;
    cout << "Enter a " << gender << " name: ";
    cin >> name;
    return name;
}

bool search(const string& name, const vector<string>& names) {
    for (const string& n : names) {
        if (n == name) {
            return true;
        }
    }
    return false;
}

void displayResult(const string& gender, const string& name, bool found) {
    if (found) {
        cout << name << " is a popular " << gender << " name." << endl;
    }
    else {
        cout << name << " is not a popular " << gender << " name." << endl;
    }
}

void writeToFile(const string& filename, const vector<string>& data) {
    // Implement this function as before, but with the correct file paths.
    // Use the path to the file you want to write to.
    // Example: ofstream file("C:/path/to/Boynames_asc.txt");
    // Continue with writing the data to the file.
    // Be sure to handle file errors.
}

void reverseVector(vector<string>& data) {
    int start = 0;
    int end = data.size() - 1;

    while (start < end) {
        // Swap elements at start and end indices
        swap(data[start], data[end]);
        start++;
        end--;
    }
}

int main() {
    string boyName, girlName;
    bool boyNameFound, girlNameFound;

    vector<string> boyNames = getBoyNames();
    vector<string> girlNames = getGirlNames();

    boyName = getName("boy's");
    girlName = getName("girl's");

    selectionSort(boyNames);
    selectionSort(girlNames);

    boyNameFound = search(boyName, boyNames);
    girlNameFound = search(girlName, girlNames);

    displayResult("boy's", boyName, boyNameFound);
    displayResult("girl's", girlName, girlNameFound);

    // Implement writeToFile with the correct file paths as before.

    reverseVector(boyNames);
    reverseVector(girlNames);

    // Implement writeToFile for reversed vectors with the correct file paths.

    cout << endl;

    return 0;
}
