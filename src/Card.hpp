#pragma once
#include "Account.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

using namespace std;


class Card {
public:
    Card() {};
    Card(const string cardNumber, const string PIN): cardNumber(cardNumber), PIN(PIN) {};
    Card(Card& card);

    string getCardNumber();
    string getPIN();
    bool checkCard();
    bool checkPIN();
    bool hasAccount(shared_ptr<Account>& account);
    int getAccountNumber(shared_ptr<Account>& account);
    int addAccount(shared_ptr<Account>& account);
    shared_ptr<Account>& getAccount(int accountNumber);
    vector<shared_ptr<Account>>& getAccountVector();
    // before BankSystem
    bool hasAccountTest(shared_ptr<Account>& account);
    int getAccountNumberTest(shared_ptr<Account>& account);
    int addAccountTest(shared_ptr<Account>& account);
    shared_ptr<Account>& getAccountTest(int accountNumber);
    vector<shared_ptr<Account>>& getAccountVectorTest();

private:
  string cardNumber;
  string PIN;
  unordered_map<string, int> accIndex;
  vector<shared_ptr<Account>> accVec; 
};
