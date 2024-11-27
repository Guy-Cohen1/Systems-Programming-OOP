/* Assignment C++: 2
   Author1: Guy Cohen, ID: 207881004
   Author1: Liav Ben Or, ID: 315909390
*/

#ifndef Chech_h
#define Chech_h
#include <string>
#include "Account.h"
using namespace std;

// Derived class representing a checking account, inherits from the Account class
class CheckingAccount : public Account
{
    double overdraftLimit;  // Maximum allowed overdraft for the checking account

public:

    // Default constructor
    CheckingAccount(){};

    // Parameterized constructor to initialize checking account details
    CheckingAccount(const string& number, const string& holder, double initialBalance, double overdraft);

    // Overridden function to deposit money into the checking account
    void deposit(double amount);

    // Overridden function to withdraw money from the checking account
    void withdraw(double amount);
};

#endif
