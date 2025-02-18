#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool login() {
    string username, password, un, pw;

    cout << "\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream input("database.txt");
    while (input >> un >> pw) {
        if (un == username && pw == password) {
            input.close();
            return true;
        }
    }
    input.close();
    return false;
}

void registration() {
    string username, password;

    cout << "\nChoose a username: ";
    cin >> username;
    cout << "Choose a password: ";
    cin >> password;

    ofstream output("database.txt", ios::app);
    output << username << " " << password << endl;
    output.close();

    cout << "\nRegistration successful!\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registration();
                break;
            case 2:
                if (login()) {
                    cout << "\nLogin successful! Welcome.\n";
                } else {
                    cout << "\nInvalid username or password.\n";
                }
                break;
            case 3:
                cout << "\nGoodbye!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}