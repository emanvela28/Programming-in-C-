#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Function to read a list of names from a file
vector<string> readNamesFromFile(const string& filename);

// Function to prompt the user to enter a name of a specific type
string enterName(const string& typeName);

// Function to sort the list of names in ascending order
void sortNamesAscending(vector<string>& names);

int main() {
    string boyName, girlName;
    bool boyNameFound, girlNameFound;

    // Comment 1: Reading a list of boy's names from a file
    vector<string> boyNames = readNamesFromFile("C:\\Users\\adamv\\Downloads\\BoyNames.txt");

    // Comment 2: Reading a list of girl's names from a file
    vector<string> girlNames = readNamesFromFile("C:\\Users\\adamv\\Downloads\\GirlNames.txt");

    // Comment 3: Prompting the user to enter a boy's and girl's name
    boyName = enterName("boy's");
    girlName = enterName("girl's");

    sortNamesAscending(boyNames);
    sortNamesAscending(girlNames);

    if (boyName == "N") {
        cout << "You chose not to enter a boy's name." << endl;
    }
    else {
        // Comment 4: Checking if the boy's name is in the list and displaying popularity
        boyNameFound = isNameInList(boyName, boyNames);
        displayPopularity("boy's", boyName, boyNameFound);

        // Comment 5: Writing the boy's names in ascending order to a file
        writeNamesToFile("Boynames_asc.txt", boyNames);

        // Comment 6: Reversing the order of boy's names and writing to a file
        reverseNames(boyNames);
        writeNamesToFile("Boynames_desc.txt", boyNames);
    }

    if (girlName == "N") {
        cout << "You chose not to enter a girl's name." << endl;
    }
    else {
        // Comment 7: Checking if the girl's name is in the list and displaying popularity
        girlNameFound = isNameInList(girlName, girlNames);
        displayPopularity("girl's", girlName, girlNameFound);

        // Comment 8: Writing the girl's names in ascending order to a file
        writeNamesToFile("Girlnames_asc.txt", girlNames);

        // Comment 9: Reversing the order of girl's names and writing to a file
        reverseNames(girlNames);
        writeNamesToFile("Girlnames_desc.txt", girlNames);

        cout << endl;
        system("PAUSE");
    }

    return 0;
}

// Comment 10: Function to check if a given name is in the list of names
bool isNameInList(const string& name, const vector<string>& names) {
    for (int i = 0; i < names.size(); i++) {
        if (names[i] == name) {
            return true;
        }
    }
    return false;
}

// Function to display whether a name is popular or not
void displayPopularity(const string& typeName, const string& name, bool isPopular) {
    if (isPopular) {
        cout << name << " is one of the most popular " << typeName << " names." << endl;
    }
    else {
        cout << name << " is NOT one of the most popular " << typeName << " names." << endl;
    }
}

// Function to write a list of names to a file
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

// Function to reverse the order of names in a list
void reverseNames(vector<string>& names) {
    string temp;
    int length = names.size();

    for (int i = 0, j = length - 1; i < (length / 2); i++, j--) {
        temp = names[i];
        names[i] = names[j];
        names[j] = temp;
    }
}
