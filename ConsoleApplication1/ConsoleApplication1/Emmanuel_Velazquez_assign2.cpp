#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int QUIT = 4;

// Making the computer choose a random number 1-3 using modulo.
int getComputerChoice() {
    return rand() % 3 + 1;
}

// Printing the game menu and using \n to superate the lines.
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
        // Taking in the users choice and assigning it to the variable choice.
        cin >> choice;
    } while (choice < 1 || choice > 4);
    // Returning choice to ask the user to input a valid number within the range provided in the menu.
    return choice;
}

void displayChoice(int choice) {
    // Using switch and case here to assign variables to the users choice. Switch takes in the assigned variable and that 
    // choice value controls case so later when the variable is called, it can print the users choice.
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
    // Here is where the conditionals are made, all the possible outcomes of the game, along with the messages for the winning side.
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
    // Seeding the random number generator.
    srand(static_cast<unsigned int>(time(0)));
    int userChoice;
    int computerChoice;

    computerChoice = getComputerChoice();

    userChoice = getUserChoice();

    while (userChoice != QUIT) {
    // As long as the user has a valid input and it is not equal to 4, we are going to play the rock paper scissors game and 
    // display the choice of both users.

        cout << "\nYou selected: ";
        displayChoice(userChoice);
        cout << "\nThe computer selected: ";
        displayChoice(computerChoice);

        //This is our function that is going to determine the outcome and decide what message needs to be printed based on the winner.
        determineOutcome(userChoice, computerChoice);
        cout << endl;

        computerChoice = getComputerChoice();

        userChoice = getUserChoice();
    }

    // The pause is going to wait for the program to be terminated to close the console.
    system("PAUSE");
    return 0;
}