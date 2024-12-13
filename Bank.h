#ifndef BANK_H
#define BANK_H

// Necessary includes
#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;

// Class declaration, functions, etc.


class Account {
    private: 
    int accountNumber;
    string accountHolderName;
    double balance;

    public:
    Account() {}

    Account (int accountNumber, string accountHolderName, double balance) {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    void setAccountNumber(int number) {
        accountNumber = number;
    }
    
    void setAccountName(string name) {
        accountHolderName = name;
    }
    
    void setBalance(double balance) {
        this->balance = balance;
    }

    string getName() {
        return accountHolderName;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        double newBalance = getBalance() + amount;
        setBalance(newBalance);
    }

    void withdraw(double amount) {
        if (getBalance() < amount) {
            cout<<"Insufficient Amount!"<<endl;
        } else {
            double newBalance = getBalance() - amount;
            setBalance(newBalance);
        }
    }
    
    void displayAccountInfo() {
        cout<<"Hi "<<getName()<<"!"<<endl;
        cout<<"Your account number: "<<getAccountNumber()<<endl;
        cout<<"Your current balance: "<<getBalance()<<endl; 
    }
};

class SavingsAccount : public Account {
    private:
    double interestRate;

    public:
    SavingsAccount(double interestRate, int accountNumber, string accountHolderName, double balance) : 
    Account(accountNumber, accountHolderName, balance) {
        this->interestRate = interestRate;
    }

    void applyInterestRate() {
        double savings = getBalance() * (1 + (interestRate/100));
        setBalance(savings);
    }
};

class Bank {
    private:
    unordered_map<int, pair<string, double> >Accounts;

    public:

    void addAccount(int accountNumber, string name, double balance) {
        if (Accounts.find(accountNumber) != Accounts.end()) { // Check if account exists
            cout << "Account already exists!" << endl;
        } else {
            Accounts[accountNumber] = make_pair(name, balance); // Add new account
            cout << "Account added successfully!" << endl;
        }
    }

    void removeAccount(int accountNumber) {
        auto it = Accounts.find(accountNumber);
        if (it != Accounts.end()) {
            Accounts.erase(it); // or Accounts.erase(accountNumber);
            cout << "Account removed successfully!" << endl;
        } else {
            cout << "Account was not found!" << endl;
        }
    }

    void listAllAccounts() {
        for (const auto& pair: Accounts) {
            cout << "Name: " << pair.second.first << endl;
            cout << "Balance: " << pair.second.second << endl;
        }
    }
    pair<string, double>* getAccount(int accountNumber) {
        auto it = Accounts.find(accountNumber);
        if (it != Accounts.end()) {
            return &(it->second); // Return a pointer to the value
        } else {
            cout << "Account not found!" << endl;
            return nullptr; // Return null pointer if the account is not found
        }
    }
    void transferFunds(int fromAccount, int toAccount, double amount) {
        auto it = Accounts.find(fromAccount);
        auto it_to = Accounts.find(toAccount);
        if (it != Accounts.end() && it_to != Accounts.end()) {
            if (it->second.second < amount) {
                cout<<"Insufficient Amount! Transfer is not possible"<<endl;
            } else {
                it->second.second = (it->second.second) - amount;
                it_to->second.second = (it_to->second.second) + amount;
                cout << "Hi " << it_to->second.first << "! " << "Your new balance is $" << it_to->second.second << endl;
                
            }
        } else {
            cout << "One or more accounts do not exist!" << endl;
        }
    }
};

#endif // BANK_H
