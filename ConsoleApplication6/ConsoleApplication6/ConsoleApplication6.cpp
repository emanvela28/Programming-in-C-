#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> readNamesFromFile(const string & filename);
string enterName(const string& typeName);
void sortNamesAscending(vector<string>& names);
bool isNameInList(const string& name, const vector<string>& names);
void displayPopularity(const string& typeName, const string& name, bool isPopular);
void writeNamesToFile(const string& filename, const vector<string>& names);
void reverseNames(vector<string>& names);

int main() {
    // Comment 1: Create 2 boolean variables in order to determine wether or not we find the names in the list
    string boyName, girlName;
    bool boyNameFound, girlNameFound;

    vector<string> boyNames = readNamesFromFile("C:\\Users\\adamv\\Downloads\\BoyNames.txt");
    vector<string> girlNames = readNamesFromFile("C:\\Users\\adamv\\Downloads\\GirlNames.txt");

    boyName = enterName("boy's");
    girlName = enterName("girl's");

    sortNamesAscending(boyNames);
    sortNamesAscending(girlNames);

    // Comment 2: If inpput for boys is eqaul to N, display the no selection message.
    if (boyName == "N") {
        cout << "You chose not to enter a boy's name." << endl;
    }
    else {
        boyNameFound = isNameInList(boyName, boyNames);
        displayPopularity("boy's", boyName, boyNameFound);
        writeNamesToFile("Boynames_asc.txt", boyNames);
        reverseNames(boyNames);
        writeNamesToFile("Boynames_desc.txt", boyNames);
    }

    // Comment 3: If inpput for girls is eqaul to N, display the no selection message.
    if (girlName == "N") {
        cout << "You chose not to enter a girl's name." << endl;
    }
    else {
        girlNameFound = isNameInList(girlName, girlNames);
        displayPopularity("girl's", girlName, girlNameFound);
        writeNamesToFile("Girlnames_asc.txt", girlNames);
        reverseNames(girlNames);
        writeNamesToFile("Girlnames_desc.txt", girlNames);

        cout << endl;
        system("PAUSE");
    }

    return 0;
}

// Comment 4: Function to sort the new list of names with the new file we have from a to z
void sortNamesAscending(vector<string>& names) {
    int startScan, minIndex;
    string minValue;

    for (startScan = 0; startScan < (names.size() - 1); startScan++) {
        minIndex = startScan;
        minValue = names[startScan];

        for (int index = startScan + 1; index < names.size(); index++) {
            if (names[index] < minValue) {
                minValue = names[index];
                minIndex = index;
            }
        }

        names[minIndex] = names[startScan];
        names[startScan] = minValue;
    }
}

// Comment 5: Function to read names from the file and display the error message if we are unable to
vector<string> readNamesFromFile(const string& filename) {
    ifstream fileStream;
    vector<string> namesList;
    string name;
    fileStream.open(filename.c_str());

    if (!fileStream) {
        cout << "File cannot be opened for reading" << endl;
        exit(0);
    }

    while (!fileStream.eof()) {
        fileStream >> name;
        namesList.push_back(name);
    }

    fileStream.close();
    return namesList;
}


// Comment 6: Getting the user input and assigning it to the variable called name
string enterName(const string& typeName) {
    string name;
    cout << "Enter the " << typeName << " name or N if you do not wish to enter the " << typeName << " name: ";
    cin >> name;
    return name;
}

// Comment 7: For the input given sort through the list and if the name matches one of the names in the list return true
bool isNameInList(const string& name, const vector<string>& names) {
    for (int i = 0; i < names.size(); i++) {
        if (names[i] == name) {
            return true;
        }
    }
    return false;
}

// Comment 8: Use the popularity function to determine wether or not the name is popular, if it is return the message.
void displayPopularity(const string& typeName, const string& name, bool isPopular) {
    if (isPopular) {
        cout << name << " is one of the most popular " << typeName << " names." << endl;
    }
    else {
        cout << name << " is NOT one of the most popular " << typeName << " names." << endl;
    }
}

// Comment 9: Create a new file for the names and write the names into that file
void writeNamesToFile(const string& filename, const vector<string>& names) {
    ofstream fileStream;
    fileStream.open(filename.c_str());

    if (!fileStream) {
        cout << "File cannot be opened for writing" << endl;
        exit(0);
    }

    for (int i = 0; i < names.size(); i++) {
        fileStream << names[i] << endl;
    }

    fileStream.close();
}

// Comment 10: Function to sort the new list of names with the new file we have from z to a
void reverseNames(vector<string>& names) {
    string temp;
    int length = names.size();

    for (int i = 0, j = length - 1; i < (length / 2); i++, j--) {
        temp = names[i];
        names[i] = names[j];
        names[j] = temp;
    }
}
