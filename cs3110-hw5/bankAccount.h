#ifndef BANKACCOUNT_H_INCLUDED
#define BANKACCOUNT_H_INCLUDED
#include <string>
#include <iostream>

using std::string;

// nested structures

struct name
{
    string firstName;
    string lastName;
};

struct depositor
{
    name firstAndLast;
    int SSNumber;
};

struct bankAccount
{
    depositor nameAndNumber;
    int accountNumber;
    string accountType;
    double balance;
};

int read_accts(bankAccount account[], int max_accts);

void menuDisplay();

//void menu();

int findacct(const bankAccount account[], int num_accts, int requested_account);

void withdrawal(bankAccount account[], int num_accts);

void deposit(bankAccount account[], int num_accts);

int new_acct(bankAccount account[], int num_accts);

int close_acct(bankAccount account[], int num_accts);

void balance(const bankAccount account[], int num_accts);

void account_info(const bankAccount account[], int num_accts);

void print_accts(const bankAccount account[], int num_accts);

#endif // BANKACCOUNT_H_INCLUDED
