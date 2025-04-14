#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

struct Transaction {
    string type;
    double amount;
    string date;
};

struct Account {
    int accountNumber;
    string name;
    double balance;
    vector<Transaction> transactions;
};

string getCurrentTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    dt[strlen(dt) - 1] = '\0';
    return string(dt);
}

void saveAccount(const Account& acc) {
    ofstream out("account_" + to_string(acc.accountNumber) + ".dat");
    out << acc.accountNumber << '\n' << acc.name << '\n' << acc.balance << '\n';
    for (auto& t : acc.transactions) {
        out << t.type << '|' << t.amount << '|' << t.date << '\n';
    }
    out.close();
}

Account loadAccount(int accNo) {
    Account acc;
    ifstream in("account_" + to_string(accNo) + ".dat");
    if (!in) throw runtime_error("Account not found.");
    string line;
    getline(in, line); acc.accountNumber = stoi(line);
    getline(in, acc.name);
    getline(in, line); acc.balance = stod(line);

    while (getline(in, line)) {
        Transaction t;
        size_t p1 = line.find('|');
        size_t p2 = line.find('|', p1 + 1);
        t.type = line.substr(0, p1);
        t.amount = stod(line.substr(p1 + 1, p2 - p1 - 1));
        t.date = line.substr(p2 + 1);
        acc.transactions.push_back(t);
    }
    in.close();
    return acc;
}

void createAccount() {
    Account acc;
    cout << "Enter account number: ";
    cin >> acc.accountNumber;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, acc.name);
    acc.balance = 0.0;
    saveAccount(acc);
    cout << "Account created successfully!\n";
}

void viewAccount() {
    int accNo;
    cout << "Enter account number: ";
    cin >> accNo;
    try {
        Account acc = loadAccount(accNo);
        cout << "\nAccount Number: " << acc.accountNumber << "\nName: " << acc.name << "\nBalance: $" << acc.balance << '\n';
    } catch (exception& e) {
        cout << e.what() << '\n';
    }
}

void deposit() {
    int accNo;
    double amount;
    cout << "Enter account number: ";
    cin >> accNo;
    cout << "Enter amount to deposit: $";
    cin >> amount;
    try {
        Account acc = loadAccount(accNo);
        acc.balance += amount;
        acc.transactions.push_back({"Deposit", amount, getCurrentTime()});
        saveAccount(acc);
        cout << "Deposited successfully!\n";
    } catch (exception& e) {
        cout << e.what() << '\n';
    }
}

void withdraw() {
    int accNo;
    double amount;
    cout << "Enter account number: ";
    cin >> accNo;
    cout << "Enter amount to withdraw: $";
    cin >> amount;
    try {
        Account acc = loadAccount(accNo);
        if (amount > acc.balance) {
            cout << "Insufficient balance!\n";
            return;
        }
        acc.balance -= amount;
        acc.transactions.push_back({"Withdraw", amount, getCurrentTime()});
        saveAccount(acc);
        cout << "Withdrawn successfully!\n";
    } catch (exception& e) {
        cout << e.what() << '\n';
    }
}

void viewStatement() {
    int accNo;
    cout << "Enter account number: ";
    cin >> accNo;
    try {
        Account acc = loadAccount(accNo);
        cout << "\nTransaction History for Account " << acc.accountNumber << ":\n";
        for (auto& t : acc.transactions) {
            cout << t.date << " | " << t.type << " | $" << t.amount << '\n';
        }
    } catch (exception& e) {
        cout << e.what() << '\n';
    }
}

int main() {
    int choice;
    do {
        cout << "\n\n--- Bank Management System ---\n";
        cout << "1. Create Account\n2. View Account\n3. Deposit\n4. Withdraw\n5. View Statement\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccount(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: viewStatement(); break;
            case 6: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}

