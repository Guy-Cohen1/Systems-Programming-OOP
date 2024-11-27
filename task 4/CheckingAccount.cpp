/* Assignment C++: 2
   Author1: Guy Cohen, ID: 207881004
   Author1: Liav Ben Or, ID: 315909390
*/

#include "CheckingAccount.h"

// Parameterized constructor for CheckingAccount class
CheckingAccount::CheckingAccount(const string &number, const string &holder, double initialBalance, double overdraft) : Account(number, holder, initialBalance), overdraftLimit(overdraft){}

// Overridden function to withdraw money from the checking account
void CheckingAccount::withdraw(double amount)
{
    // Check if the withdrawal amount is within the allowed overdraft limit
    if(amount <= this->get_balance() - this->overdraftLimit)
        this->set_balance(this->get_balance() - amount);  // Update the balance after withdrawal
}

// Overridden function to deposit money into the checking account
void CheckingAccount::deposit(double amount)
{
    this->set_balance(this->get_balance() + amount);  // Update the balance after deposit
}
