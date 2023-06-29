#include "Card.hpp"
#include "BankSystem.hpp"

using namespace std;


Card::Card(Card& card) {
    cardNumber = card.getCardNumber();
    PIN = card.getPIN();
    for (auto account : card.getAccountVector()) {
        accIndex[account->getAccountId()] = accIndex.size();
        accVec.push_back(account);
    }
}

string Card::getCardNumber() {
    return cardNumber;
}

string Card::getPIN() {
    return PIN;
}

bool Card::checkCard() {
    return BankSystem::checkCard(*this);
}
bool Card::checkPIN() {
    return BankSystem::checkPIN(*this);
}

bool Card::hasAccount(shared_ptr<Account>& account) {
    return BankSystem::hasAccount(*this, account);
}

int Card::getAccountNumber(shared_ptr<Account>& account) {
    return BankSystem::getAccountNumber(*this, account);
}

int Card::addAccount(shared_ptr<Account>& account) {
    return BankSystem::addAccount(*this, account);
}

shared_ptr<Account>& Card::getAccount(int accountNumber) {
    return BankSystem::getAccount(*this, accountNumber);
}

vector<shared_ptr<Account>>& Card::getAccountVector() {
    return BankSystem::getAccountVector(*this);
}

bool Card::hasAccountTest(shared_ptr<Account>& account) {
    return accIndex.count(account->getAccountId()) > 0;
}

int Card::getAccountNumberTest(shared_ptr<Account>& account) {
    if(accIndex.count(account->getAccountId()) == 0) return -1;
    return accIndex[account->getAccountId()];
}

int Card::addAccountTest(shared_ptr<Account>& account) {
    if (accIndex.count(account->getAccountId()) > 0) return -1;
    accIndex[account->getAccountId()] = accVec.size();
    accVec.push_back(account);
    return accIndex[account->getAccountId()];
}

shared_ptr<Account>& Card::getAccountTest(int accountNumber) {
    return accVec[accountNumber];
}

vector<shared_ptr<Account>>& Card::getAccountVectorTest() {
    return accVec;
}
