#include <iostream>
using namespace std;

int main() {
    string name;
    int accountNumber;
    double balance = 0;
    int choice;
    double amount;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> accountNumber;

    do {
        cout << "\n--- Banking System Menu ---";
        cout << "\n1. Deposit";
        cout << "\n2. Withdraw";
        cout << "\n3. Check Balance";
        cout << "\n4. Exit";
        cout << "\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    cout << "Deposit successful! New balance: $" << balance << "\n";
                } else {
                    cout << "Invalid amount.\n";
                }
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    cout << "Withdrawal successful! New balance: $" << balance << "\n";
                } else {
                    cout << "Insufficient balance or invalid amount.\n";
                }
                break;
            case 3:
                cout << "\nAccount Holder: " << name << "\n";
                cout << "Account Number: " << accountNumber << "\n";
                cout << "Current Balance: $" << balance << "\n";
                break;
            case 4:
                cout << "Thank you for using the banking system!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}