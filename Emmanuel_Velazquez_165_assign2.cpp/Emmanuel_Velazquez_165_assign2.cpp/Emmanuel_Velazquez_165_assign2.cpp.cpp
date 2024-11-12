
#include <iostream>
using namespace std;
#include <string>
#include <random>

int userchoice;
int random_number;

// Function for generating a random number.
int random() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, 3);
    random_number = distribution(gen);
    return random_number;
}

void rock() {
    cout << "\nYou selected: Rock" << endl;
}

void paper() {
    cout << "\nYou selected: Paper" << endl;
}
    
void scissors() {
    cout << "\nYou selected: Scissors" << endl;
}

//Mapping the computers choice to the game menu, 1 is rock, 2 is paper, 3 is scissors.
void getComputerChoice() {
    if (random_number == 1) {
        cout << "The computer selected: Rock" << endl;
    }

    if (random_number == 2) {
        cout << "The computer selected: Paper" << endl;
    }

    if (random_number == 3) {
        cout << "The computer selected: Scissors" << endl;
    }

}


int main() {
    random();
    //Printing the menu.
    cout << "Game Menu" << endl;
    cout << "---------" << endl;
    cout << "1) Rock \n2) Paper \n3) Scissors \n4) Quit \n" << endl;
    cout << "Enter your choice: ";
    cin >> userchoice;

    //Checking to see if we have a valid input.
    while (userchoice <= 0 || userchoice >= 5) {
        cout << "Invalid selection. Enter 1, 2, 3, or 4: ";
        cin >> userchoice;
    }

    //User wins, rock over scissors.
    if (userchoice == 1 && random_number == 3) {
        rock();
        getComputerChoice();
        cout << "You win! Rock smashes scissors." << endl;
    }

    //Compputer wins, paper over rock.
    if (userchoice == 1 && random_number == 2) {
        rock();
        getComputerChoice();
        cout << "Computer wins! Paper covers rock." << endl;
    }

    //There is a tie, both selected rock.
    if (userchoice == 1 && random_number == 1) {
        rock();
        getComputerChoice();
        cout << "Tie. No winner." << endl;
    }

    //User wins, paper over rock.
    if (userchoice == 2 && random_number == 1) {
        paper();
        getComputerChoice();
        cout << "You win! Paper covers rock." << endl;
    }

    //User loses, scissors cut paper.
    if (userchoice == 2 && random_number == 3) {
        paper();
        getComputerChoice();
        cout << "Computer wins! Scissors cut paper." << endl;
    }

    //Tie both have paper.
    if (userchoice == 2 && random_number == 2) {
        paper();
        getComputerChoice();
        cout << "Tie. No winner." << endl;
    }

    //User wins, scissors cut paper.
    if (userchoice == 3 && random_number == 2) {
        scissors();
        getComputerChoice();
        cout << "You win! Scissors cut paper." << endl;
    }

    //User loses, rock smashes scissors.
    if (userchoice == 3 && random_number == 1) {
        scissors();
        getComputerChoice();
        cout << "Computer wins! Rock smashes scissors." << endl;
    }

    //Tie, both have scissors.
    if (userchoice == 3 && random_number == 3) {
        scissors();
        getComputerChoice();
        cout << "Tie. No winner." << endl;
    }

    //Quitting if we do not have a valid input.
    if (userchoice == 4) {
        cout << "Pressssssss any key to continue...";
    }

}