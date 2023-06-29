#include "BankSystem.hpp"
//#include "Card.hpp"

using namespace std;

bool BankSystem::checkAccount(Account& account) {
    return true; // db.checkAccount(account);
}

int BankSystem::getBalance(Account& account) {
    return account.getBalanceTest(); // db.getBalance(account);
}

bool BankSystem::deposit(Account& account, const int delta) {
    return account.depositTest(delta); // db.deposit(account, delta);
}

bool BankSystem::withdraw(Account& account, const int delta) {
    return account.withdrawTest(delta); // db.withdraw(account, delta);
}

bool BankSystem::checkCard(Card& card) {
    return true; // db.checkCard(card);
}

bool BankSystem::checkPIN(Card& card) {
    return true; // db.checkPIN(card);
}

bool BankSystem::hasAccount(Card& card, shared_ptr<Account>& account) {
    return card.hasAccountTest(account); // db.hasAccount(card);
}

int BankSystem::getAccountNumber(Card& card, shared_ptr<Account>& account) {
    return card.getAccountNumberTest(account);
}

int BankSystem::addAccount(Card& card, shared_ptr<Account>& account) {
    return card.addAccountTest(account); // db.addAccount(card, account);
}

shared_ptr<Account>& BankSystem::getAccount(Card& card, int accountNumber) {
    return card.getAccountTest(accountNumber); // db.getAccount(card, account);
}

vector<shared_ptr<Account>>& BankSystem::getAccountVector(Card& card) {
    return card.getAccountVectorTest(); // db.getAccountVector(card);
}
