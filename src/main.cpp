#include <iostream>
#include "Account.hpp"
#include "BankSystem.hpp"
#include "Card.hpp"

using namespace std;

template <class T>
string check(T a, T b) {
    if (a == b) return "OK";
    return "FAIL";
}

void testAccount() {
  cout << "TEST ACCOUNT" << endl;
  Account account1("account1");
  Account acc1(account1);
  cout << check<string>(acc1.getAccountId(), account1.getAccountId()) << endl;
  cout << check<int>(acc1.getBalance(),  account1.getBalance() ) << endl;
  cout << check<bool>(acc1.deposit(10), true) << endl;
  cout << check<int>(acc1.getBalance(), 10) << endl;
  cout << check<bool>(acc1.withdraw(5), true) << endl;
  cout << check<bool>(acc1.withdraw(10), false) << endl;
  cout << check<int>(acc1.getBalance(), 5) << endl;
}

void testCard() {
    cout << "TEST CARD" << endl;
    Card card1("card1", "123");
    cout << check<string>(card1.getCardNumber(), "card1") << endl;
    cout << check<string>(card1.getPIN(), "123") << endl;
    cout << check<bool>(card1.checkCard(), true) << endl;
    cout << check<bool>(card1.checkPIN(), true) << endl;

    shared_ptr<Account> acc1 = make_shared<Account>("account1");
    cout << check<bool>(acc1->deposit(10), true) << endl;
    cout << check<int>(acc1->getBalance(), 10) << endl;

    Card card(card1);
    cout << check<bool>(card.hasAccount(acc1), false) << endl;
    cout << check<int>(card.addAccount(acc1), 0) << endl;
    cout << check<bool>(card.hasAccount(acc1), true) << endl;
    if (card.hasAccount(acc1)) {
        shared_ptr<Account> acc = card.getAccount(0);
        cout << check<bool>((acc.get()->operator==(*acc1)), true) << endl;
    }

    vector<shared_ptr<Account>>& accVec = card.getAccountVector();
    cout << check<int>(accVec.size(), 1) << endl;
    cout << check<bool>((accVec[0].get()->operator==(*acc1)), true) << endl;
}

void testScenario() {
    cout << "TEST SCENARIO" << endl;
    Card card("card", "123");
    shared_ptr<Account> acc1 = make_shared<Account>("account1");
    shared_ptr<Account> acc2 = make_shared<Account>("account2");
    acc1->deposit(100);
    acc2->deposit(500);
    card.addAccount(acc1);
    card.addAccount(acc2);

    // insert card
    cout << check<bool>(card.checkCard(), true) << endl;
    // check pin
    cout << check<bool>(card.checkPIN(), true) << endl;
    // select account
    cout << check<bool>(card.hasAccount(acc1), true) << endl;
    if (card.hasAccount(acc1)) {
        int accountNumber = card.getAccountNumber(acc1);
        shared_ptr<Account> acc = card.getAccount(accountNumber);
        // check balance, deposit, withdraw
        cout << check<int>(acc->getBalance(), 100) << endl;
        cout << check<bool>(acc->deposit(100), true) << endl;
        cout << check<int>(acc->getBalance(), 200) << endl;
        cout << check<bool>(acc->withdraw(100), true) << endl;
        cout << check<int>(acc->getBalance(), 100) << endl;
    }
}

int main(void) { 
    testAccount();
    testCard();
    testScenario();
    return 0;
}

