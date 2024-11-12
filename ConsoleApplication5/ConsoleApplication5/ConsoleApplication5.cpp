#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> readNamesFromFile(const string& filename);
string enterName(const string& typeName);
void sortNamesAscending(vector<string>& names);
bool isNameInList(const string& name, const vector<string>& names);
void displayPopularity(const string& typeName, const string& name, bool isPopular);
void writeNamesToFile(const string& filename, const vector<string>& names);
void reverseNames(vector<string>& names);

int main() {
    string boyName, girlName;
    bool boyNameFound, girlNameFound;

    vector<string> boyNames = readNamesFromFile("C:\\Users\\adamv\\Downloads\\BoyNames.txt");
    vector<string> girlNames = readNamesFromFile("C:\\Users\\adamv\\Downloads\\GirlNames.txt");

    boyName = enterName("boy's");
    girlName = enterName("girl's");

    sortNamesAscending(boyNames);
    sortNamesAscending(girlNames);

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

string enterName(const string& typeName) {
    string name;
    cout << "Enter the " << typeName << " name or N if you do not wish to enter the " << typeName << " name: ";
    cin >> name;
    return name;
}

bool isNameInList(const string& name, const vector<string>& names) {
    for (int i = 0; i < names.size(); i++) {
        if (names[i] == name) {
            return true;
        }
    }
    return false;
}

void displayPopularity(const string& typeName, const string& name, bool isPopular) {
    if (isPopular) {
        cout << name << " is one of the most popular " << typeName << " names." << endl;
    }
    else {
        cout << name << " is NOT one of the most popular " << typeName << " names." << endl;
    }
}

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

void reverseNames(vector<string>& names) {
    string temp;
    int length = names.size();

    for (int i = 0, j = length - 1; i < (length / 2); i++, j--) {
        temp = names[i];
        names[i] = names[j];
        names[j] = temp;
    }
}
