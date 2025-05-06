#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string phoneNo, name, address, description, search;

    fstream file;

public:
    void addContact();
    void showAll();
    void serachContact();
} obj;

int main()
{
    char choice;
    cout << "\n--- Contact Management System ---\n";
    cout << "1. Add Contact\n";
    cout << "2. Show all Contact\n";
    cout << "3. Serach Contact\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        obj.addContact();
        break;
    case '2':
        obj.showAll();
        break;
    case '3':
        obj.serachContact();
        break;
    case '4':
        cout << "Exiting the system. Goodbye!\n";
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
    }

    return 0;
}

void temp ::addContact()
{
    cout << "Enter Phone Number : ";
    getline(cin, phoneNo);
    cout << "Enter Name : ";
    getline(cin, name);
    cout << "Enter Address : ";
    getline(cin, address);
    cout << "Enter Description : ";
    getline(cin, description);

    file.open("data.csv", ios::out | ios::app);
    file << phoneNo << "," << name << "," << address << "," << description << "\n";
    file.close();
}

void temp ::showAll()
{
    file.open("data.csv", ios ::in);

    getline(file, phoneNo, ',');
    getline(file, name, ',');
    getline(file, address, ',');
    getline(file, description, '\n');

    while (!file.eof())
    {
        // cout<<"Phone Number : "<<phoneNo<<endl;
        // cout<<"Phone Name : "<<name<<endl;
        // cout<<"Phone Address : "<<address<<endl;
        // cout<<"Phone Description : "<<description<<endl<<endl;
        cout << "Phone Number \t\t    Contact Name \t\tContact Address \t\tContact Description" << endl;
        cout << phoneNo << "\t\t\t" << name << "\t\t\t" << address << "\t\t\t" << description << endl;

        getline(file, phoneNo, ',');
        getline(file, name, ',');
        getline(file, address, ',');
        getline(file, description, '\n');
    }
    file.close();
}

void temp::serachContact()
{
    cout << "Enter the Phone Number : ";
    getline(cin, search);

    file.open("data.csv", ios ::in);

    getline(file, phoneNo, ',');
    getline(file, name, ',');
    getline(file, address, ',');
    getline(file, description, '\n');

    while (!file.eof())
    {
        if (phoneNo == search)
        {
            cout << "Phone Number : " << phoneNo << endl;
            cout << "Phone Name : " << name << endl;
            cout << "Phone Address : " << address << endl;
            cout << "Phone Description : " << description << endl
                 << endl;
        }

        getline(file, phoneNo, ',');
        getline(file, name, ',');
        getline(file, address, ',');
        getline(file, description, '\n');
    }
    file.close();
}