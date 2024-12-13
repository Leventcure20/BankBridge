#include <iostream>
#include "Bank.h"
using namespace std;

int main() {
    
    bool running = true; // Control the loop
    Bank bank;
    int accountNumber;
    string accountName;
    double balance;
    decltype(bank.getAccount(0)) account;
    int toAccount;
    int fromAccount;
    double transferAmount;

    while (running) {
        // Step 1: Display the menu
        cout << "Welcome to the ATM!" << endl;
        cout << "1. Add a new account" << endl;
        cout << "2. Display all accounts" << endl;
        cout << "3. Transfer funds" << endl;
        cout << "4. Remove an account" << endl;
        cout << "5. Search for an account by number" << endl;
        cout << "6. Exit" << endl;

        // Step 2: Prompt for user input
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
    

        // Step 3: Process input in switch
        switch (choice) {
            case 1:
                // Add account
                cout << "You chose to add a new account." << endl;
                
                cout << "Enter an account number: " << endl;
                cin >> accountNumber;

                cin.ignore();
                cout << "Enter the name for your account " << endl;
                getline(cin, accountName);

                cout << "Enter your current available balance: " << endl;
                cin >> balance;

                bank.addAccount(accountNumber, accountName, balance);
                

                // Call a function or write logic for adding an account
                break;
            case 2:
                // Display accounts
                cout << "Displaying all accounts..." << endl;

                // Call listAllAccounts function
                bank.listAllAccounts();
                break;

            case 3:
                // Transfer funds
                cout << "You chose to transfer funds." << endl;
                // Call transferFunds function
                cout << "Enter the account number that you would like to transfer from: " << endl;
                cin >> fromAccount;

                cout << "Enter the account number that you would like to transfer to:" << endl;
                cin >> toAccount;

                cout << "Enter the amount that amount that you would like to tranfer: " << endl;
                cin >> transferAmount;

                bank.transferFunds(fromAccount, toAccount, transferAmount);
                cout << "Thank you for your transaction! " << endl;



                break;

            case 4:
                // Remove an account
                cout << "You chose to remove an account." << endl;
                // Call removeAccount function
                cout << "Enter the account number: " << endl;
                cin >> accountNumber;

                bank.removeAccount(accountNumber);
                
                break;

            case 5:
                // Search for account by name
                cout << "You chose to search for an account by account number." << endl;
                cout << "Enter the account number: " << endl;

                cin >> accountNumber;
                account = bank.getAccount(accountNumber);

                if (account != nullptr) {
                    cout << "Account found!" << endl;
                    cout << "Name: " << account->first << ", Balance: $" << account->second << endl;
                } else {
                    cout << "Account not found!" << endl;
                }
                break;

            case 6:
                // Exit
                cout << "Exiting the program. Thank you!" << endl;
                running = false; // Set flag to false to break the loop
                break;

            default:
                // Handle invalid input
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
}