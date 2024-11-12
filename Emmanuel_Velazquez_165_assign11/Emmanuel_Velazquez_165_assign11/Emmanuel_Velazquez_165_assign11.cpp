#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Comment 1: Structure to store drink information
struct Drink {
    string name;
    double cost;
    int quantity;
};

// Comment 2: Function to display the list of drinks with corresponding values
void displayDrinks(const Drink drinks[], int size) {
    cout << "\n";
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ") " << left << setw(24) << drinks[i].name << setw(15) << fixed << setprecision(2) << drinks[i].cost << endl;
    }
    cout << "6) Leave the drink machine\n";
}

// Comment 3: Function allowing user to make selections
void simulateDrinkMachine(Drink drinks[], int size) {
    double totalEarnings = 0;

    displayDrinks(drinks, size);  // Display drinks outside the loop

    while (true) {
        cout << "\nChoose one: ";
        int choice;
        cin >> choice;

        // Comment 4: Validate user input for drink selection
        if (choice < 1 || choice > size && choice != 6) {
            cout << "Invalid choice. Please try again.\n";
            continue;
        }

        // Comment 5: Quit the program
        if (choice == 6) {
            cout << "Quitting the program." << endl;
            break;
        }

        int selectedDrinkIndex = choice - 1;

        // Comment 6: Check if the selected drink is sold out
        if (drinks[selectedDrinkIndex].quantity == 0) {
            cout << "Sorry, " << drinks[selectedDrinkIndex].name << " is sold out. Please choose another drink.\n";
            continue;
        }

        // Comment 7: Prompt the user to enter a valid amount if the input is invalid
        cout << "Enter the amount of money ($0.75 - $1.00): ";
        double amount;
        cin >> amount;

        // Comment 8: Validate the amount of money and display an error message if invalid
        while (amount < 0.75 || amount > 1.00) {
            cout << "Invalid amount. Please enter a value between 0.75 and $1.00.\n";
            // Prompt for a valid amount
            cout << "Enter the amount of money ($0.75 - $1.00): ";
            cin >> amount;
        }

        // Comment 9: Check if user has inserted enough money for the selected drink
        if (amount < drinks[selectedDrinkIndex].cost) {
            cout << "Insufficient funds. Please insert more money.\n";
            continue;
        }

        // Comment 10: Update quantity, calculate change, and add to total earnings
        drinks[selectedDrinkIndex].quantity--;
        double change = amount - drinks[selectedDrinkIndex].cost;
        totalEarnings += drinks[selectedDrinkIndex].cost;

        cout << "Enjoy your beverage!" << endl;
        cout << "Change: $" << fixed << setprecision(2) << change << endl;
        cout << "Your change, " << fixed << setprecision(2) << change << " has just dropped into the Change Dispenser." << endl;
        cout << "There are " << drinks[selectedDrinkIndex].quantity << " drinks left of that type." << endl;
    }
}

int main() {
    // Comment 11: Initializing drink array with default values
    Drink drinks[5] = {
        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grape Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
    };

    simulateDrinkMachine(drinks, 5);

    return 0;
}
