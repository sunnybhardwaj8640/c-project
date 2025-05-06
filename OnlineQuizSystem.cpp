#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct User
{
    string username;
    string password;
};
bool login(const string &username, const string &password)
{
    User user;
    ifstream file("users.txt");
    while (file >> user.username >> user.password)
    {
        if (user.username == username && user.password == password)
        {
            return true;
        }
    }
    return false;
}
void signup()
{
    User user;
    cout << "Enter username: ";
    cin >> user.username;
    cout << "Enter password: ";
    cin >> user.password;

    ofstream file("users.txt", ios::app);
    file << user.username << " " << user.password << endl;
    cout << "Signup successful! You can now login.\n";
}
int quiz()
{
    int score = 0;
    string answer;
    cout << "Question 1: Who Invented C++?\n";
    cout << "a) Dennis Ritchie\nb) Ken Thompson\nc) Brian Kernighan\nd) Bjarne Stroustrup\nYour answer: ";
    cin >> answer;
    if (answer == "d")
    {
        score++;
    }

    cout << "Question 2: Which of the following extension is used for user-defined header file in C++?\n";
    cout << "a) hg\nb) cpp\nc) h\nd) hf\nYour answer: ";
    cin >> answer;
    if (answer == "c")
    {
        score++;
    }

    cout << "Question 3: Which of the following approach is used by C++?\n";
    cout << "a) Left-right\nb) Right-left\nc) Bottom-up\nd) Top-Down\nYour answer: ";
    cin >> answer;
    if (answer == "c")
    {
        score++;
    }

    cout << "Question 4: Which of the following is not a type of Constructor C++?\n";
    cout << "a) Default Constructor\nb) Parameterized Constructor\nc) Copy Constructor\nd) Friend Constructor\nYour answer: ";
    cin >> answer;
    if (answer == "d")
    {
        score++;
    }


    cout << "Question 4: Which is more effective while calling the C++ functions?\n";
    cout << "a) call by object\nb) call by pointer\nc) call bu value\nd) call by reference\nYour answer: ";
    cin >> answer;
    if (answer == "d")
    {
        score++;
    }

    
    return score;
}

int main()
{

    int choice;
    string username, password;
    cout << "1. Signup\n2.Login\nChoose option: ";
    cin >> choice;

    if (choice == 1)
    {
        signup();
    }
    cout << "Login now\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (login(username, password))
    {
        cout << "\nLogin successfuly!Starting quiz....\n";
        int score = quiz();
        cout << "\nYour score is: " << score << "/5\n";
        cout << "Thank you for playing!\n";
    }
    else
    {
        cout << "\nLogin failed! Please check your username and password.\n";
        cout << "Please try again.\n";
    }
    return 0;
}