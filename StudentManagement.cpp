#include <iostream>
#include <fstream>
using namespace std;

// Class to manage student records
class temp {
    string name, rollno, branch; // Variables to store student details
    fstream file;                // File stream for file operations

public:
    void addStudent();    // Function to add a new student
    void viewStudent();   // Function to view all students
    void updateStudent(); // Function to update a student's details
    void deleteStudent(); // Function to delete a student
} obj;

int main() {
    char choice;

    do {
        // Display the menu
        cout << "Welcome to Student Management System\n";
        cout << "1. Add Student\n";
        cout << "2. View Student\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";

        cout << "Enter your Choice: ";
        cin >> choice;

        // Handle the user's choice
        switch (choice) {
            case '1':
                obj.addStudent(); // Add a new student
                break;
            case '2':
                obj.viewStudent(); // View all students
                break;
            case '3':
                obj.updateStudent(); // Update a student's details
                break;
            case '4':
                obj.deleteStudent(); // Delete a student
                break;
            case '5':
                cout << "Thank you for using Student Management System\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5'); // Repeat until the user chooses to exit

    return 0;
}

// Function to add a new student
void temp::addStudent() {
    cout << "\nEnter Student Name: ";
    cin >> name; // Input student name
    cout << "\nEnter Roll No: ";
    cin >> rollno; // Input student roll number
    cout << "\nEnter Branch: ";
    cin >> branch; // Input student branch

    // Open the file in append mode
    file.open("student.txt", ios::app | ios::out);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Write student details to the file
    file << name << endl << rollno << endl << branch << endl;
    file.close();
    cout << "Student added successfully!" << endl;
}

// Function to view all students
void temp::viewStudent() {
    // Open the file in read mode
    file.open("student.txt", ios::in);
    if (!file) {
        cout << "File not found\n";
        return;
    }

    bool isEmpty = true; // Flag to check if the file is empty
    cout << "Student Details:\n";

    // Read student details from the file
    while (file >> name >> rollno >> branch) {
        isEmpty = false;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "Branch: " << branch << endl;
    }

    if (isEmpty) {
        cout << "No student records found.\n";
    }

    file.close();
}

// Function to update a student's details
void temp::updateStudent() {
    string rollnoToUpdate; // Roll number of the student to update
    bool found = false;    // Flag to check if the student is found

    cout << "Enter Roll No of student to update: ";
    cin >> rollnoToUpdate;

    // Open the input file and a temporary output file
    ifstream inFile("student.txt");
    ofstream outFile("temp.txt");

    if (!inFile) {
        cout << "File not found\n";
        return;
    }

    // Read student details from the input file
    while (inFile >> name >> rollno >> branch) {
        if (rollno == rollnoToUpdate) {
            // If the roll number matches, update the details
            cout << "Enter new Name: ";
            cin >> name;
            cout << "Enter new Branch: ";
            cin >> branch;
            found = true;
        }
        // Write the (updated or unchanged) details to the temporary file
        outFile << name << endl << rollno << endl << branch << endl;
    }

    inFile.close();
    outFile.close();

    // Replace the original file with the updated file
    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found) {
        cout << "Student updated successfully!" << endl;
    } else {
        cout << "Student with Roll No " << rollnoToUpdate << " not found!" << endl;
    }
}

// Function to delete a student
void temp::deleteStudent() {
    string rollnoToDelete; // Roll number of the student to delete
    bool found = false;    // Flag to check if the student is found

    cout << "Enter Roll No of student to delete: ";
    cin >> rollnoToDelete;

    // Open the input file and a temporary output file
    ifstream inFile("student.txt");
    ofstream outFile("temp.txt");

    if (!inFile) {
        cout << "File not found\n";
        return;
    }

    // Read student details from the input file
    while (inFile >> name >> rollno >> branch) {
        if (rollno == rollnoToDelete) {
            // If the roll number matches, skip writing it to the temporary file
            found = true;
        } else {
            // Write the details to the temporary file
            outFile << name << endl << rollno << endl << branch << endl;
        }
    }

    inFile.close();
    outFile.close();

    // Replace the original file with the updated file
    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found) {
        cout << "Student with Roll No " << rollnoToDelete << " deleted successfully!" << endl;
    } else {
        cout << "Student with Roll No " << rollnoToDelete << " not found!" << endl;
    }
}