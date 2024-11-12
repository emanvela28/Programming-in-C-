#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int QUIT = 4;

int getComputerChoice() {
    return rand() % 3 + 1;
}

int getUserChoice() {
    int choice;
    cout << "\nGame Menu\n";
    cout << "-----------\n";
    cout << "1) Rock\n";
    cout << "2) Paper\n";
    cout << "3) Scissors\n";
    cout << "4) Quit\n";
    do {
        cout << "Enter your choice: ";
        cin >> choice;
    } while (choice < 1 || choice > 4);
    return choice;
}

void displayChoice(int choice) {
    switch (choice) {
    case ROCK:
        cout << "Rock ";
        break;
    case PAPER:
        cout << "Paper ";
        break;
    case SCISSORS:
        cout << "Scissors ";
        break;
    }
}

void determineOutcome(int user, int computer) {
    cout << endl;
    if (user == computer) {
        cout << "Tie. No winner.";
    }
    else if ((user == ROCK && computer == SCISSORS)) {
        cout << "You win! Rock smashes scissors.";
    }
    else if ((user == SCISSORS && computer == PAPER)) {
        cout << "You win! Scissors cut paper.";
    }
    else if ((user == PAPER && computer == ROCK)) {
        cout << "You win! Paper wraps rock.";
    }
    else if ((computer == ROCK && user == SCISSORS)) {
        cout << "Computer wins! Rock smashes scissors.";
    }
    else if ((computer == SCISSORS && user == PAPER)) {
        cout << "Computer wins! Scissors cut paper.";
    }
    else if ((computer == PAPER && user == ROCK)) {
        cout << "Computer wins! Paper wraps rock.";
    }
    else {
        cout << "Unknown outcome.";
    }
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    int userChoice;
    int computerChoice;

    computerChoice = getComputerChoice();

    userChoice = getUserChoice();

    while (userChoice != QUIT) {

        cout << "\nYou selected: ";
        displayChoice(userChoice);
        cout << "\nThe computer selected: ";
        displayChoice(computerChoice);

        determineOutcome(userChoice, computerChoice);
        cout << endl;

        computerChoice = getComputerChoice();

        userChoice = getUserChoice();
    }

    system("PAUSE");
    return 0;
}