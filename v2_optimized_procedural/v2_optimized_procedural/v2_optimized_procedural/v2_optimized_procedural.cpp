#include <iostream>
using namespace std;

// Constants
const int CORRECT_PASSWORD = 9988;

// Global variables
double balance = 1000.0;

// Function declarations
void showMenu();
bool login();
void showBalance();
void withdraw();
void deposit();
void process();

int main() {
    process();
    return 0;
}

// Function to display the main menu
void showMenu() {
    cout << "\n========== ATM Menu ==========\n";
    cout << "1. Check Balance\n";
    cout << "2. Withdraw\n";
    cout << "3. Deposit\n";
    cout << "4. Exit\n";
    cout << "==============================\n";
}

// Function to handle user login
bool login() {
    int enteredPassword;
    cout << "Enter your password: ";
    cin >> enteredPassword;

    return enteredPassword == CORRECT_PASSWORD;
}

// Function to display the current balance
void showBalance() {
    cout << "Your current balance is: $" << balance << "\n";
}

// Function to handle withdrawals
void withdraw() {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount. Please enter a positive number.\n";
    }
    else if (amount > balance) {
        cout << "Insufficient balance.\n";
    }
    else {
        balance -= amount;
        cout << "Withdrawal successful. New balance: $" << balance << "\n";
    }
}

// Function to handle deposits
void deposit() {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid deposit amount.\n";
    }
    else {
        balance += amount;
        cout << "Deposit successful. New balance: $" << balance << "\n";
    }
}

// Function to manage the ATM process
void process() {
    int choice;
    bool exitProgram = false;

    if (!login()) {
        char retry;
        cout << "Incorrect password. Try again? (Y/N): ";
        cin >> retry;

        if (retry == 'Y' || retry == 'y') {
			system("cls"); // to clear the console
            process(); // retry login
        }
        else {
            cout << "Exiting ATM. Goodbye!\n";
            return;
        }
    }

    while (!exitProgram) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            showBalance();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            deposit();
            break;
        case 4:
            cout << "Thank you for using the ATM. Goodbye!\n";
            exitProgram = true;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
