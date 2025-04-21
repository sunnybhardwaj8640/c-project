
#include <iostream>
#include <fstream>
using namespace std;

class temp {  //Make class of string and one object
    string title, description; 
    fstream file;

public:
    void addnote();
    void shownote();
    void deletenote();
} obj;

int main() {
    char choice;
    cout << "---------------------NOTES-------------------------" << endl;
    cout << "\n1- Add Notes";
    cout << "\n2- Show Notes";
    cout << "\n3- Delete Notes" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "\nEnter Your Choice: ";
    cin >> choice;

    switch (choice) {
        case '1':
            cin.ignore();
            obj.addnote();
            break;
        case '2':
            cin.ignore();
            obj.shownote();
            break;
        case '3':
            cin.ignore();
            obj.deletenote();
            break;
        case '4':
            return 0;
            break;
        default:
            cout << "Invalid Selection..!";
    }

    return 0;
}

void temp::addnote() {
    cout << "\nEnter the Note Title: ";  //Make first fuction  of add notes
    cin.ignore();
    getline(cin, title);
    cout << "Enter the Note Description: ";
    getline(cin, description);

    file.open("noteData.txt", ios::out | ios::app);  //Make text file to store data
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    file << title << "*" << description << "*" << endl;
    file.close();
    cout << "Note added successfully!" << endl;
}

void temp::shownote() {   //Then Make second function to show notes
    file.open("noteData.txt", ios::in);
    if (!file) {
        cout << "No notes found!" << endl;
        return;
    }

    cout << "\n--- Notes ---\n";
    while (getline(file, title, '*')) {    //in while statment it Show the Title and description
        getline(file, description, '*');
        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;
        cout << "-------------------\n";
    }
    file.close();
}

void temp::deletenote() {       //IN Third Function in which we delete the Notes
    string searchTitle;
    bool found = false;

    cout << "Enter the Note Title to delete: ";
    cin.ignore();
    getline(cin, searchTitle);

    ifstream inFile("noteData.txt");
    ofstream outFile("temp.txt");

    if (!inFile) {
        cout << "No notes found!" << endl;
        return;
    }

    while (getline(inFile, title, '*')) {
        getline(inFile, description, '*');
        if (title == searchTitle) {
            found = true;
        } else {
            outFile << title << "*" << description << "*" << endl;
        }
    }

    inFile.close();
    outFile.close();

    remove("noteData.txt");
    rename("temp.txt", "noteData.txt");

    if (found) {
        cout << "Note deleted successfully!" << endl;
    } else {
        cout << "Note not found!" << endl;
    }
}