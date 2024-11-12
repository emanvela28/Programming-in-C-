#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Comment 1: Function to read the file and store it inside of a vector
void readDataFromFile(const string& filename, vector<string>& data) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            data.push_back(line);
        }
        // Comment 2: Close the file when we are done reading the contents
        file.close();
    }
}

void displayTeams(const vector<string>& teams) {
    cout << "The following teams have won the World Series at least once:" << endl;
    cout << endl;
    // Comment 3: Create an integer named columns to format the text from the file that we are reading in from and the same thing for the width of the columns
    int columns = 3;
    int width = 25;

    // Comment 4: While we are reading through the teams file, we are going to print the names into a format using the iomanip library.
    for (int i = 0; i < teams.size(); i++) {
        cout << left << setw(width) << teams[i];
        if ((i + 1) % columns == 0) {
            cout << endl;
        }
    }

    // Comment 5: If the side of the vector modulo columns does NOT equal 0, print a new line.
    if (teams.size() % columns != 0) {
        cout << endl;
    }
}

// Comment 6: Function to ask the user to input a team name from the provided list.
string promptUserForTeam() {
    string team;
    cout << "\nEnter the name of one of the teams: ";
    //Comment 7: We are going to get the input from the user and assign that input to the string we created earlier named team.
    getline(cin, team);
    return team;
}

int countWins(const vector<string>& winners, const string& team) {
    int count = 0;
    for (const string& winner : winners) {

        if (team == winner) {
            count++;
        }
    }

    return count;
}
// Comment 8: We are goign to display the team with the number of wins that it has using the varibles we assigned it earlier in code.
void displayWinCount(const string& team, int count) {
    cout << "The " << team << " have won the World Series " << count << " time(s)." << endl;
}

int main() {
    vector<string> teams;
    vector<string> winners;

    // Comment 9: We are going to read the files and assign them to a varibale for the teams file.
    readDataFromFile("C:\\Users\\adamv\\Downloads\\Teams.txt", teams);

    // Comment 10: We are going to read the files and assign them to a varibale for the teams file.
    readDataFromFile("C:\\Users\\adamv\\Downloads\\Winners.txt", winners);

    displayTeams(teams);

    string team = promptUserForTeam();
    int winCount = countWins(winners, team);

    displayWinCount(team, winCount);

    return 0;
}