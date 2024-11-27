/* Assignment C++: 2
   Author1: Guy Cohen, ID: 207881004
   Author1: Liav Ben Or, ID: 315909390
*/

#ifndef MENU_H
#define MENU_H

#include "Array.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "Account.h"
#include <iostream>
#include <string>

using namespace std;

// Class representing the menu for managing bank accounts
class Menu
{
    Array<Account*> bankAccounts;  // Dynamic array to store pointers to Account objects

public:

    // Default constructor
    Menu(){};

    // Function to display the main menu options
    void mainMenu();

    // Function to add a new bank account to the array
    void add_account();

    // Function to deposit money into a bank account
    void deposit();

    // Function to withdraw money from a bank account
    void withdraw();

    // Function to delete a bank account from the array
    void delete_();

    // Function to print the details of all bank accounts in the array
    void printing();

    // Destructor
    ~Menu(){};
};

#endif
