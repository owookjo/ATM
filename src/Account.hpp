#pragma once
#include <iostream>
#include <string>

using namespace std;

class Account {
public:
    Account() {};

    Account(const string accountId): accountId(accountId), balance(0) {};
    Account(Account& account);

    string getAccountId();
    bool checkAccount();
    int getBalance();
    bool deposit(int delta);
    bool withdraw(int delta);
    // before BankSytem
    int getBalanceTest();
    bool depositTest(int delta);
    bool withdrawTest(int delta);

    bool operator==(Account& account);
private:
    string accountId;
    int balance;
};
