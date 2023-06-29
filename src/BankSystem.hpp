#pragma once
#include <iostream>
#include <vector>
#include "Account.hpp"
#include "Card.hpp"

using namespace std;

class Account;
class BankSystem {
public:
    // for the future, it returns appropriate value from DB
    // Account
    static bool checkAccount(Account& account);
    static int getBalance(Account& account);
    static bool deposit(Account& account, const int delta);
    static bool withdraw(Account& account, const int delta);
    // Card
    static bool checkCard(Card& card);
    static bool checkPIN(Card& card);
    static bool hasAccount(Card& card, shared_ptr<Account>& account);
    static int getAccountNumber(Card& card, shared_ptr<Account>& account);
    static int addAccount(Card& card, shared_ptr<Account>& account);
    static shared_ptr<Account>& getAccount(Card& card, int accountNumber);
    static vector<shared_ptr<Account>>& getAccountVector(Card& card);
private:
    // DBAccess db;
};
