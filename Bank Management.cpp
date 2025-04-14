 #include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class BankAccount {
private:
    int accNumber;
    char name[50];
    float balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNumber;
        cin.ignore();
        cout << "Enter Account Holder Name: ";
        cin.getline(name, 50);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void showAccount() const {
        cout << "\nAccount Number: " << accNumber;
        cout << "\nHolder Name: " << name;
        cout << "\nBalance: " << balance << "\n";
    }

    void deposit(float amount) {
        balance += amount;
    }

    void withdraw(float amount) {
        if (amount > balance)
            cout << "Insufficient balance!\n";
        else
            balance -= amount;
    }

    int getAccNumber() const {
        return accNumber;
    }

    float getBalance() const {
        return balance;
    }

    void updateAccount() {
        cout << "\nUpdate Account Holder Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Update Balance: ";
        cin >> balance;
    }
};

// Function Prototypes
void createAccount();
void displayAll();
void depositMoney();
void withdrawMoney();
void searchAccount();

int main() {
    int choice;
    do {
        cout << "\n====== Bank Menu ======";
        cout << "\n1. Create Account";
        cout << "\n2. Display All Accounts";
        cout << "\n3. Search Account";
        cout << "\n4. Deposit Money";
        cout << "\n5. Withdraw Money";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAll(); break;
            case 3: searchAccount(); break;
            case 4: depositMoney(); break;
            case 5: withdrawMoney(); break;
            case 6: cout << "Exiting system...\n"; break;
            default: cout << "Invalid option!\n";
        }
    } while (choice != 6);
    return 0;
}

// ===== Function Definitions =====

void createAccount() {
    BankAccount acc;
    acc.createAccount();
    ofstream outFile("accounts.dat", ios::binary | ios::app);
    outFile.write(reinterpret_cast<char*>(&acc), sizeof(BankAccount));
    outFile.close();
    cout << "Account created successfully!\n";
}

void displayAll() {
    BankAccount acc;
    ifstream inFile("accounts.dat", ios::binary);
    if (!inFile) {
        cout << "No accounts found!\n";
        return;
    }
    cout << "\n=== All Bank Accounts ===\n";
    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(BankAccount))) {
        acc.showAccount();
    }
    inFile.close();
}

void searchAccount() {
    int accNum, found = 0;
    cout << "Enter Account Number to search: ";
    cin >> accNum;

    BankAccount acc;
    ifstream inFile("accounts.dat", ios::binary);
    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(BankAccount))) {
        if (acc.getAccNumber() == accNum) {
            acc.showAccount();
            found = 1;
            break;
        }
    }
    inFile.close();
    if (!found)
        cout << "Account not found!\n";
}

void depositMoney() {
    int accNum;
    float amount;
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    fstream file("accounts.dat", ios::binary | ios::in | ios::out);
    BankAccount acc;
    bool found = false;

    while (!file.eof()) {
        streampos pos = file.tellg();
        file.read(reinterpret_cast<char*>(&acc), sizeof(BankAccount));

        if (acc.getAccNumber() == accNum) {
            acc.deposit(amount);
            file.seekp(pos);
            file.write(reinterpret_cast<char*>(&acc), sizeof(BankAccount));
            found = true;
            cout << "Deposit successful.\n";
            break;
        }
    }
    file.close();
    if (!found)
        cout << "Account not found.\n";
}

void withdrawMoney() {
    int accNum;
    float amount;
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    fstream file("accounts.dat", ios::binary | ios::in | ios::out);
    BankAccount acc;
    bool found = false;

    while (!file.eof()) {
        streampos pos = file.tellg();
        file.read(reinterpret_cast<char*>(&acc), sizeof(BankAccount));

        if (acc.getAccNumber() == accNum) {
            acc.withdraw(amount);
            file.seekp(pos);
            file.write(reinterpret_cast<char*>(&acc), sizeof(BankAccount));
            found = true;
            cout << "Withdrawal complete.\n";
            break;
        }
    }
    file.close();
    if (!found)
        cout << "Account not found.\n";
}

