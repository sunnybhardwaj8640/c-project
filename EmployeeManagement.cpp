#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string EmpId, EmpName, EmpDes, EmpDept, EmpSal;
    fstream file;

public:
    void addEmp();
    void viewEmp();
    void updateEmp();
    void deleteEmp();

} obj;


void temp::addEmp(){
    cout<<"\nEnter Employee Id : ";
    cin>>EmpId;
    cout<<"\nEnter Employee Name : ";
    cin>>EmpName;
    cout<<"\nEnter Employee Designation : ";
    cin>>EmpDes;
    cout<<"\nEnter Employee Department : ";
    cin>>EmpDept;
    cout<<"\nEnter Employee Salary : ";
    cin>>EmpSal;

    file.open("employee.txt", ios::app | ios::out); //open file in append mode
    if(!file){
        cout<<"Error opening file!"<<endl;
        return;
    }

    file<< EmpId <<endl<< EmpName <<endl << EmpDes <<endl << EmpDept << endl << EmpSal <<endl;
    file.close();
    cout<<"Employee Added Successfuly!" <<endl;
}

void temp ::viewEmp(){
    file.open("employee.txt" ,ios::in); // open file in read mode
    if(!file){
        cout<<"File not Found\n";
        return;
    }

    bool isEmpty =true; // flag to check the file is empty
    cout<<"Employee Detalis:\n";

    while(file >> EmpId >> EmpName >> EmpDes >> EmpDept >> EmpSal){
        isEmpty = false;
        cout<<"Employee Id : "<<EmpId<<endl;
        cout<<"Employee Name : "<<EmpName<<endl;
        cout<<"Employee Designation : "<<EmpDes<<endl;
        cout<<"Employee Department : "<<EmpDept<<endl;
        cout<<"Employee Salary : "<<EmpSal<<endl;
    }
    if(isEmpty){
        cout<<"No Employee Records Found.\n";
    }
    file.close();
}


void temp ::updateEmp (){
    string EmpIdToUpdate; // Employee Id to update
    bool found = false;   // Flag to check if the employee is found

    cout << "Enter Employee Id to update: ";
    cin >> EmpIdToUpdate;

    // Open the input file and a temporary output file
    ifstream inFile("employee.txt");
    ofstream outFile("temp.txt");

    if (!inFile) {
        cout << "File not found\n";
        return;
    }

    // Read employee details from the input file
    while (inFile >> EmpId >> EmpName >> EmpDes >> EmpDept >> EmpSal) {
        if (EmpId == EmpIdToUpdate) {
            // If the employee ID matches, update the details
            cout << "Enter new Name: ";
            cin >> EmpName;
            cout << "Enter new Designation: ";
            cin >> EmpDes;
            cout << "Enter new Department: ";
            cin >> EmpDept;
            cout << "Enter new Salary: ";
            cin >> EmpSal;
            found = true;
        }
        // Write the (updated or unchanged) details to the temporary file
        outFile << EmpId << endl << EmpName << endl << EmpDes << endl << EmpDept << endl << EmpSal << endl;
    }

    inFile.close();
    outFile.close();

    // Replace the original file with the updated file
    remove("employee.txt");
    rename("temp.txt", "employee.txt");

    if (found) {
        cout << "Employee updated successfully!" << endl;
    } else {
        cout << "Employee with ID " << EmpIdToUpdate << " not found!" << endl;
    }
}

void temp::deleteEmp(){
    string EmpIdToDelete; // Employee Id to delete
    bool found = false;   // Flag to check if the employee is found

    cout << "Enter Employee Id to delete: ";
    cin >> EmpIdToDelete;

    // Open the input file and a temporary output file
    ifstream inFile("employee.txt");
    ofstream outFile("temp.txt");

    if (!inFile) {
        cout << "File not found\n";
        return;
    }

    // Read employee details from the input file
    while (inFile >> EmpId >> EmpName >> EmpDes >> EmpDept >> EmpSal) {
        if (EmpId == EmpIdToDelete) {
            found = true; // Employee found, do not write to the temporary file
            continue;
        }
        // Write the (unchanged) details to the temporary file
        outFile << EmpId << endl << EmpName << endl << EmpDes << endl << EmpDept << endl << EmpSal << endl;
    }

    inFile.close();
    outFile.close();

    // Replace the original file with the updated file
    remove("employee.txt");
    rename("temp.txt", "employee.txt");

    if (found) {
        cout << "Employee deleted successfully!" << endl;
    } else{
        cout << "Employee with ID " << EmpIdToDelete << " not found!" << endl;
    }

}

int main()
{
    char choice;
    do
    {
        cout<<"\nWelcome to Employee Management Sysyem";
        cout << "\n1-Add Employee : ";
        cout << "\n2-View Employee : ";
        cout << "\n3-Update Employee : ";
        cout << "\n4-Delete Employee : ";
        cout << "\n5-Exit : "<<endl;

        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            obj.addEmp();
            break;

        case '2':
            obj.viewEmp();
            break;

        case '3':
            obj.updateEmp();
            break;

        case '4':
            obj.deleteEmp();
            break;

        case '5':
            cout << "Exiting the Empolyee Management. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again!" << endl;
        }

    } while (choice != '5');

    return 0;
}