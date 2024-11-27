/* Assignment C++: 2
   Author1: Guy Cohen, ID: 207881004
   Author1: Liav Ben Or, ID: 315909390
*/

#ifndef SavingsAccount_H_
#define SavingsAccount_H_
#include <chrono>
#include <thread>
#include "Account.h"
using namespace std;
#include <cmath>

// Derived class representing a savings account, inherits from the Account class
class SavingsAccount : public Account
{
    double annualInterestRate;  // Annual interest rate for the savings account
    chrono::steady_clock::time_point lastTransactionTime;  // Time of the last transaction

public:

    // Default constructor
    SavingsAccount(){};

    // Parameterized constructor to initialize savings account details
    SavingsAccount(const string& number, const string& holder, double initialBalance, double annualRate);

    // Overridden function to deposit money into the savings account
    void deposit(double amount) override;

    // Overridden function to withdraw money from the savings account
    void withdraw(double amount) override;

    // Function to update the balance based on the annual interest rate
    void update_balance();

    // Overridden function to print savings account details
    void print() override;

    // Destructor
    ~SavingsAccount() {};
};

#endif
