#include "Account.hpp"
#include "BankSystem.hpp"

using namespace std;

Account::Account(Account& account) {
    accountId = account.getAccountId();
    balance = account.getBalance();
}

string Account::getAccountId() {
    return accountId;
}

bool Account::checkAccount() {
    return BankSystem::checkAccount(*this);
}

int Account::getBalance() {
    return BankSystem::getBalance(*this);
}

// for future, it returns false from bank API if bank system are unavailable
bool Account::deposit(int delta) {
    return BankSystem::deposit(*this, delta);
}

// for future, it returns false from bank API if bank system are unavailable
bool Account::withdraw(int delta) {
    return BankSystem::withdraw(*this, delta);
}

bool Account::operator==(Account& account) {
    if (account.getBalance() != getBalance()) return false;
    else if (account.getAccountId() != getAccountId()) return false;
    return true;
}

int Account::getBalanceTest() {
    return balance;
}

bool Account::depositTest(int delta) {
    balance += delta;
    return true;
}

bool Account::withdrawTest(int delta) {
    if (balance < delta) return false;
    balance -= delta;
    return true;
}
