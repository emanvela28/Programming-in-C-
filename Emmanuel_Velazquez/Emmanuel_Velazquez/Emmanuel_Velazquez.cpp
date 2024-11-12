#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> getVector(const string&);
string getName(const string&);
void selectionSort(vector<string>&);
bool search(const string&, const vector<string>&);
void displayResult(const string&, const string&, bool);
void writeToFile(const string&, const vector<string>&);
void reverseVector(vector<string>&);

int main()
{
    string boyName, girlName;
    bool boyNameFound, girlNameFound;


    vector<string> boyNames(getVector("BoyNames.txt"));
    vector<string> girlNames(getVector("GirlNames.txt"));


    boyName = getName("boy's");
    girlName = getName("girl's");

    selectionSort(boyNames);
    selectionSort(girlNames);

    boyNameFound = search(boyName, boyNames);
    girlNameFound = search(girlName, girlNames);

    displayResult("boy's", boyName, boyNameFound);
    displayResult("girl's", girlName, girlNameFound);

    writeToFile("Boynames_asc.txt", boyNames);
    writeToFile("Girlnames_asc.txt", girlNames);

    reverseVector(boyNames);
    reverseVector(girlNames);

    writeToFile("Boynames_desc.txt", boyNames);
    writeToFile("Girlnames_desc.txt", girlNames);

    cout << endl;

    system("PAUSE");
    return 0;
}


void selectionSort(vector<string>& arr)
{

    int startScan, minIndex;
    string minValue;

    for (startScan = 0; startScan < (arr.size() - 1); startScan++)
    {
        minIndex = startScan;
        minValue = arr[startScan];
        for (int index = startScan + 1; index < arr.size(); index++)
        {
            if (arr[index] < minValue)
            {
                minValue = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minValue;
    }


}

vector<string> getVector(const string& filename)
{
    vector<string> vect; //ceclare the vector
    ifstream infile; //declaration to read from the file
    infile.open(filename);
    string names; //declaration for variable that will hold the names coming from the file
    while (infile >> names) //loop to iterate through the file
    {
        vect.push_back(names); //puts a name at the end of every vector
    }
    return vect; // returns the vector
}

string getName(const string& str)
{
    string name; //variable placeholder

    cout << "Enter a " << str
        << " name, or N if you do not wish to enter a " <<
        str << " name: ";

    getline(cin, name); //get the user input for names

    return name; //return the name form the user
}


bool search(const string& findName, const vector<string>& vectlist)
{

    for (int i = 0; i < (vectlist.size()); i++) //iterates through the vector
    {
        if (findName == vectlist[i])
        {
            return true; //return true if there is a matching name within the iteration
        }
    }

    return false; //return false if otherwise

}

void displayResult(const string& genderName, const string& Name, bool popular)
{
    if (popular == true) //output if the name is found within the list
    {
        cout << Name << " is one of the most popular " << genderName << " names." << endl;
    }
    else if (Name == "N") //output if the user decided to enter N
    {
        cout << "You chose not to enter a " << genderName << " name." << endl;
    }
    else //otherwise, when it is not found within the list
    {
        cout << Name << " is NOT one of the most popular " << genderName << " names." << endl;
    }
}

void writeToFile(const string& name, const vector<string>& vect)
{
    ofstream outfile; //declares the ofstream function
    outfile.open(name); //opens the ofstream file to write into
    for (int i = 0; i < vect.size(); i++)
    {
        outfile << vect[i] << endl; //writes out all the contents of the vector into the file
    }
}