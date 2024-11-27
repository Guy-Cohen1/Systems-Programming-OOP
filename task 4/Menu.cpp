/* Assignment C++: 2
   Author1: Guy Cohen, ID: 207881004
   Author1: Liav Ben Or, ID: 315909390
*/

#include "Menu.h"
#include <stdexcept>

// Function to add a new account to the menu
void Menu::add_account()
{
    try {
        string account_number;
        string holder_name;
        double balance;
        char type;
        double rate;
        double over_draft;

        // Gather account information from the user
        cout << "Enter account number:" << endl;
        cin >> account_number;
        cout << "Enter account holder name:" << endl;
        cin >> holder_name;
        cout << "Enter initial balance:" << endl;
        cin >> balance;
        cout << "Enter account type (S for Savings, C for Checking):" << endl;
        cin >> type;

        // Validate the account type input
        if (!(type == 's' || type == 'S' || type == 'c' || type == 'C'))
        {
            throw "Error: Invalid account type.";
        }

        // Create a new SavingsAccount or CheckingAccount based on the user input
        if (type == 's' || type == 'S') {
            cout << "Enter annual interest rate: " << endl;
            cin >> rate;
            this->bankAccounts.add(new SavingsAccount(account_number, holder_name, balance, rate));
            cout << "Account added successfully." << endl;
        } else if (type == 'c' || type == 'C') {
            cout << "Enter overdraft limit: " << endl;
            cin >> over_draft;
            this->bankAccounts.add(new CheckingAccount(account_number, holder_name, balance, over_draft));
            cout << "Account added successfully." << endl;
        } else {
            cout << "Error: Invalid account type." << endl;
        }
    }
    catch(const char* msg){
        cout << msg << endl;
    }
}

// Function to handle depositing money into a bank account
void Menu::deposit()
{
    try {
        double amount;
        int index;

        // Get the account index and deposit amount from the user
        cout << "Enter account index:" << endl;
        cin >> index;

        // Validate the account index input
        if (!(index >= 0 && index < this->bankAccounts.getSize())){
            throw "Error: Index out of range.";
        }

        cout << "Enter deposit amount: " << endl;
        cin >> amount;

        // Call the deposit function for the selected account
        this->bankAccounts[index]->deposit(amount);

    }
    catch(const char * msg) {
        cout << msg << endl;
    }
}

// Function to handle withdrawing money from a bank account
void Menu::withdraw()
{
    try {
        double amount;
        int index;

        // Get the account index and withdrawal amount from the user
        cout << "Enter account index:" << endl;
        cin >> index;

        // Validate the account index input
        if (!(index >= 0 && index < this->bankAccounts.getSize())) {
            throw "Error: Index out of range.";
        }

        cout << "Enter withdrawal amount: " << endl;
        cin >> amount;

        // Call the withdraw function for the selected account
        this->bankAccounts[index]->withdraw(amount);
    }
    catch(const char * msg) {
        cout << msg << endl;
    }
}

// Function to delete a bank account from the menu
void Menu::delete_()
{
    try {
        int index;

        // Get the account index to delete from the user
        cout << "Enter account index to delete:" << endl;
        cin >> index;

        // Validate the account index input
        if (!(index >= 0 && index < this->bankAccounts.getSize())) {
            throw "Error: Index out of range.";
        }

        // Remove the selected account from the array
        this->bankAccounts.remove(index);
        cout << "Account deleted successfully." << endl;
    }
    catch(const char * msg) {
        cout << msg << endl;
    }
}

// Function to print the details of all bank accounts in the menu
void Menu::printing()
{
    cout << "====== Account Details ======" << endl;
    cout << this->bankAccounts << endl;
}

// Function to display the main menu options and handle user input
void Menu::mainMenu()
{
    int choice;
    do{
        try {
            // Display the main menu options
            cout << "====== Main Menu ======" << endl;
            cout << "1 - Add a new account" << endl;
            cout << "2 - Deposit (index, amount)" << endl;
            cout << "3 - Withdraw (index, amount)" << endl;
            cout << "4 - Delete an account (index)" << endl;
            cout << "5 - Print details of all accounts" << endl;
            cout << "6 - Exit" << endl;
            cout << "=======================================" << endl;
            cout << "Enter your choice: " << endl;
            cin >> choice;

            // Validate the user choice input
            if(choice > 6 || choice < 1)
            {
                throw "Invalid choice. Please try again.";
            }

            // Execute the chosen menu option
            switch (choice) {
                case 1: {
                    this->add_account();
                    break;
                }
                case 2: {
                    this->deposit();
                    break;
                }
                case 3: {
                    this->withdraw();
                    break;
                }
                case 4: {
                    this->delete_();
                    break;
                }
                case 5: {
                    this->printing();
                    break;
                }

            }
        }
        catch (const char* msg){
            cout << msg << endl;
        }
    } while (choice != 6);
}
