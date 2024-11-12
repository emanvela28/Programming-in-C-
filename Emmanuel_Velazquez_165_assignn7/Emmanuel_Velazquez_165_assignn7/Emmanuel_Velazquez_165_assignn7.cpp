#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> getVector(const std::string&);
std::string getName(const std::string&);
void selectionSort(std::vector<std::string>&);
bool search(const std::string&, const std::vector<std::string>&);
void displayResult(const std::string&, const std::string&, bool);
void writeToFile(const std::string&, const std::vector<std::string>&);
void reverseVector(std::vector<std::string>&);

int main()
{
    std::string boyName, girlName;
    bool boyNameFound, girlNameFound;

    std::vector<std::string> boyNames(getVector("BoyNames.txt"));
    std::vector<std::string> girlNames(getVector("GirlNames.txt"));

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

    return 0;
}

void selectionSort(std::vector<std::string>& arr)
{
    int startScan, minIndex;
    std::string minValue;

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

std::vector<std::string> getVector(const std::string& filename)
{
    std::vector<std::string> vect;
    std::ifstream infile(filename);
    std::string names;
    while (infile >> names)
    {
        vect.push_back(names);
    }
    return vect;
}

std::string getName(const std::string& str)
{
    std::string name;

    std::cout << "Enter a " << str << " name, or N if you do not wish to enter a " << str << " name: ";
    getline(std::cin, name);
    return name;
}

bool search(const std::string& findName, const std::vector<std::string>& vectlist)
{
    for (int i = 0; i < vectlist.size(); i++)
    {
        if (findName == vectlist[i])
        {
            return true;
        }
    }
    return false;
}

void displayResult(const std::string& genderName, const std::string& Name, bool popular)
{
    if (popular)
    {
        std::cout << Name << " is one of the most popular " << genderName << " names." << std::endl;
    }
    else if (Name == "N")
    {
        std::cout << "You chose not to enter a " << genderName << " name." << std::endl;
    }
    else
    {
        std::cout << Name << " is NOT one of the most popular " << genderName << " names." << std::endl;
    }
}

void writeToFile(const std::string& name, const std::vector<std::string>& vect)
{
    std::ofstream outfile(name);
    for (int i = 0; i < vect.size(); i++)
    {
        outfile << vect[i] << std::endl;
    }
}

void reverseVector(std::vector<std::string>& vect)
{
    std::string temp;
    int last = (vect.size() - 1);
    for (int i = 0; i < (vect.size() / 2); i++)
    {
        temp = vect[i];
        vect[i] = vect[last - i];
        vect[last - i] = temp;
    }
}
