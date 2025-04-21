#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

string getPassword(int length) {
    if (length <= 0) {
        cout << "Password length must be greater than 0!" << endl;
        return "";
    }

    string Password = "";
    string characters = "aquickbrownjumpsoverthelazydogAQUICKBROWNJUMPSOVERTHELAZYDOG123456789";
    int charSize = characters.size();

    srand(time(0));
    int randomIndex;
    for (int i = 0; i < length; i++) {
        randomIndex = rand() % charSize;
        Password += characters[randomIndex];
    }
    return Password;
}

int main() {
    int Length;
    cout << "Enter the length of Password: ";
    cin >> Length;

    string password = getPassword(Length);
    if (!password.empty()) {
        cout << "Generated Password: " << password << endl;
    }

    return 0;
}