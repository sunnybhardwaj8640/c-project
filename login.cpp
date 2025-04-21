#include <iostream>
#include <fstream>
using namespace std;

/*-------------------------------LOGIN and SIGN-UP First Project-------------------------------*/

class temp
{ // make classes
    string userName, Email, password;
    string searchName, searchPass;
    string email, newPassword, line;
    fstream file;

public:
    void login(); // make functions
    void sign_up();
    void forget();
} obj;

int main()
{
    char choice; // Make choice of login and signup
    cout << "\n1- Login";
    cout << "\n2- Sign-up";
    cout << "\n3- Forget Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your Choice: ";
    cin >> choice;

    switch (choice)
    { // Use switch Statement enter the cases in for object login
    case '1':
        obj.login();
        break;
    case '2':
        obj.sign_up();
        break;
    case '3':
        obj.forget();
        break;
    case '4':
        return 0;
        break;
    default:
        cout << "Invalid Selection..!";
    }

    return 0;
}

void temp::sign_up()
{ // make Sign Up page
    cout << "\nEnter Your Name: ";
    cin.ignore();
    getline(cin, userName);

    cout << "\nEnter Your Email Address: ";
    getline(cin, Email);

    cout << "Enter Your Password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app); // make loginData text file
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
}

void temp::login()
{ // make login page
    cout << "--------------------LOGIN--------------------" << endl;
    cout << "Enter Your User Name: ";
    cin.ignore();
    getline(cin, searchName);
    cout << "Enter Your Password: ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    if (!file)
    { // use if statement
        cout << "No accounts found!" << endl;
        return;
    }

    while (getline(file, userName, '*')) // use while statement getline in file of username
    {
        getline(file, Email, '*');
        getline(file, password, '\n');
        if (userName == searchName)
        { // In if statement username is equal to searchname and some as a password
            if (password == searchPass)
            {
                cout << "\nAccount Login Successful..!";
                cout << "\nUsername: " << userName << endl;
                cout << "\nEmail: " << Email << endl;
                file.close(); // Than the close file
                return;
            }
            else
            {
                cout << "Password is Incorrect..!" << endl;
            }
        }
    }
    cout << "User not found!" << endl;
    file.close();
}

void temp::forget()
{
    bool found = false;

    cout << "Enter Your Email Address: ";
    cin.ignore();
    getline(cin, email);
    cout << "Enter Your New Password: ";
    getline(cin, newPassword);

    ifstream inFile("loginData.txt");
    ofstream outFile("temp.txt");

    while (getline(inFile, line))
    {
        size_t pos1 = line.find('*');
        size_t pos2 = line.rfind('*');

        string fileUserName = line.substr(0, pos1);
        string fileEmail = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string filePassword = line.substr(pos2 + 1);

        if (fileEmail == email)
        {
            outFile << fileUserName << "*" << fileEmail << "*" << newPassword << endl;
            found = true;
        }
        else
        {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();

    remove("loginData.txt");
    rename("temp.txt", "loginData.txt");

    if (found)
    {
        cout << "Your Password is Changed Successfully..!" << endl;
    }
    else
    {
        cout << "Email not found!" << endl;
    }
}