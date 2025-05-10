#include <iostream>
#include <vector> // STL (Standard Template Library)
#include <string>
#include <fstream>
using namespace std;

// Structure for Student
struct Student
{
    string name;
    string rollNo;
    string department;
    float grade;
};

// Structure for Faculty
struct Faculty
{
    string name;
    string empId;
    string department;
    string designation;
};

// Structure for Course
struct Course
{
    string courseCode;
    string courseName;
    string department;
    int credits;
};

// Class for Student Management
class StudentManagement
{
    vector<Student> students; // Vector to store student records

public:
    void loadFromFile();  // Load students from file
    void saveToFile();    // Save students to file
    void addStudent();    // Add a new student
    void viewStudents();  // View all students
    void updateStudent(); // Update a student's details
    void deleteStudent(); // Delete a student
};

// Class for Faculty Management
class FacultyManagement
{
    vector<Faculty> faculties; // Vector to store faculty records

public:
    void addFaculty();    // Add a new faculty
    void viewFaculties(); // View all faculties
    void updateFaculty(); // Update a faculty's details
    void deleteFaculty(); // Delete a faculty
};

// Class for Course Management
class CourseManagement
{
    vector<Course> courses; // Vector to store course records

public:
    void addCourse();    // Add a new course
    void viewCourses();  // View all courses
    void updateCourse(); // Update a course's details
    void deleteCourse(); // Delete a course
};

// Implementation of Student Management
void StudentManagement::loadFromFile()
{
    ifstream file("students.txt");
    if (!file)
    {
        cout << "No existing student data found. Starting fresh.\n";
        return;
    }

    students.clear(); // Clear the vector before loading
    Student student;
    while (file >> student.name >> student.rollNo >> student.department >> student.grade)
    {
        students.push_back(student); // Add each student to the vector
    }
    file.close();
}

void StudentManagement::saveToFile()
{
    ofstream file("students.txt");
    for (const auto &student : students)
    {
        file << student.name << endl
             << student.rollNo << endl
             << student.department << endl
             << student.grade << endl;
    }
    file.close();
}

void StudentManagement::addStudent()
{
    Student student;
    cout << "\nEnter the Student Name: ";
    cin >> student.name;
    cout << "Enter the Roll No: ";
    cin >> student.rollNo;
    cout << "Enter the Department: ";
    cin >> student.department;
    cout << "Enter the Grade: ";
    cin >> student.grade;

    students.push_back(student); // Add the student to the vector
    cout << "Student added successfully!" << endl;
}

void StudentManagement::viewStudents()
{
    if (students.empty())
    {
        cout << "No Student Record Found.\n";
        return;
    }

    cout << "\n----------------- STUDENT DETAILS ------------------\n";
    for (const auto &student : students)
    {
        cout << "Name: " << student.name << ", Roll No: " << student.rollNo
             << ", Department: " << student.department << ", Grade: " << student.grade << endl;
    }
    cout << "---------------------------------------------------\n";
}

void StudentManagement::updateStudent()
{
    string rollNoToUpdate;
    cout << "Enter the Roll No of the student to update: ";
    cin >> rollNoToUpdate;

    for (auto &student : students)
    {
        if (student.rollNo == rollNoToUpdate)
        {
            cout << "Enter new Name: ";
            cin >> student.name;
            cout << "Enter new Department: ";
            cin >> student.department;
            cout << "Enter new Grade: ";
            cin >> student.grade;
            cout << "Student updated successfully!" << endl;
            return;
        }
    }
    cout << "Student with Roll No " << rollNoToUpdate << " not found." << endl;
}

void StudentManagement::deleteStudent()
{
    string rollNoToDelete;
    cout << "Enter the Roll No of the student to delete: ";
    cin >> rollNoToDelete;

    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->rollNo == rollNoToDelete)
        {
            students.erase(it); // Remove the student from the vector
            cout << "Student with Roll No " << rollNoToDelete << " deleted successfully!" << endl;
            return;
        }
    }
    cout << "Student with Roll No " << rollNoToDelete << " not found!" << endl;
}

// Implementation of Faculty Management
void FacultyManagement::addFaculty()
{
    Faculty faculty;
    cout << "\nEnter the Faculty Name: ";
    cin >> faculty.name;
    cout << "Enter the Employee ID: ";
    cin >> faculty.empId;
    cout << "Enter the Department: ";
    cin >> faculty.department;
    cout << "Enter the Designation: ";
    cin >> faculty.designation;

    faculties.push_back(faculty); // Add the faculty to the vector
    cout << "Faculty added successfully!" << endl;
}

void FacultyManagement::viewFaculties()
{
    if (faculties.empty())
    {
        cout << "No Faculty Record Found.\n";
        return;
    }

    cout << "\n----------------- FACULTY DETAILS ------------------\n";
    for (const auto &faculty : faculties)
    {
        cout << "Name: " << faculty.name << ", Employee ID: " << faculty.empId
             << ", Department: " << faculty.department << ", Designation: " << faculty.designation << endl;
    }
    cout << "---------------------------------------------------\n";
}

void FacultyManagement::updateFaculty()
{
    string empIdToUpdate;
    cout << "Enter the Employee ID of the faculty to update: ";
    cin >> empIdToUpdate;

    for (auto &faculty : faculties)
    {
        if (faculty.empId == empIdToUpdate)
        {
            cout << "Enter new Name: ";
            cin >> faculty.name;
            cout << "Enter new Department: ";
            cin >> faculty.department;
            cout << "Enter new Designation: ";
            cin >> faculty.designation;
            cout << "Faculty updated successfully!" << endl;
            return;
        }
    }
    cout << "Faculty with Employee ID " << empIdToUpdate << " not found." << endl;
}

void FacultyManagement::deleteFaculty()
{
    string empIdToDelete;
    cout << "Enter the Employee ID of the faculty to delete: ";
    cin >> empIdToDelete;

    for (auto it = faculties.begin(); it != faculties.end(); ++it)
    {
        if (it->empId == empIdToDelete)
        {
            faculties.erase(it); // Remove the faculty from the vector
            cout << "Faculty with Employee ID " << empIdToDelete << " deleted successfully!" << endl;
            return;
        }
    }
    cout << "Faculty with Employee ID " << empIdToDelete << " not found!" << endl;
}

// Implementation of Course Management
void CourseManagement::addCourse()
{
    Course course;
    cout << "\nEnter the Course Code: ";
    cin >> course.courseCode;
    cout << "Enter the Course Name: ";
    cin >> course.courseName;
    cout << "Enter the Department: ";
    cin >> course.department;
    cout << "Enter the Credits: ";
    cin >> course.credits;

    courses.push_back(course); // Add the course to the vector
    cout << "Course added successfully!" << endl;
}

void CourseManagement::viewCourses()
{
    if (courses.empty())
    {
        cout << "No Course Record Found.\n";
        return;
    }

    cout << "\n----------------- COURSE DETAILS ------------------\n";
    for (const auto &course : courses)
    {
        cout << "Course Code: " << course.courseCode << ", Course Name: " << course.courseName
             << ", Department: " << course.department << ", Credits: " << course.credits << endl;
    }
    cout << "---------------------------------------------------\n";
}

void CourseManagement::updateCourse()
{
    string courseCodeToUpdate;
    cout << "Enter the Course Code to update: ";
    cin >> courseCodeToUpdate;

    for (auto &course : courses)
    {
        if (course.courseCode == courseCodeToUpdate)
        {
            cout << "Enter new Course Name: ";
            cin >> course.courseName;
            cout << "Enter new Department: ";
            cin >> course.department;
            cout << "Enter new Credits: ";
            cin >> course.credits;
            cout << "Course updated successfully!" << endl;
            return;
        }
    }
    cout << "Course with Code " << courseCodeToUpdate << " not found." << endl;
}

void CourseManagement::deleteCourse()
{
    string courseCodeToDelete;
    cout << "Enter the Course Code to delete: ";
    cin >> courseCodeToDelete;

    for (auto it = courses.begin(); it != courses.end(); ++it)
    {
        if (it->courseCode == courseCodeToDelete)
        {
            courses.erase(it); // Remove the course from the vector
            cout << "Course with Code " << courseCodeToDelete << " deleted successfully!" << endl;
            return;
        }
    }
    cout << "Course with Code " << courseCodeToDelete << " not found!" << endl;
}

// Main function
int main()
{
    StudentManagement sm;
    FacultyManagement fm;
    CourseManagement cm;

    sm.loadFromFile(); // Load existing student data from file

    char choice;
    do
    {
        cout << "\n--- University Management System ---\n";
        cout << "1. Student Management\n";
        cout << "2. Faculty Management\n";
        cout << "3. Course Management\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            char studentChoice;
            do
            {
                cout << "\n--- Student Management ---\n";
                cout << "1. Add Student\n";
                cout << "2. View Students\n";
                cout << "3. Update Student\n";
                cout << "4. Delete Student\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> studentChoice;

                switch (studentChoice)
                {
                case '1':
                    sm.addStudent();
                    sm.saveToFile();
                    break;
                case '2':
                    sm.viewStudents();
                    break;
                case '3':
                    sm.updateStudent();
                    sm.saveToFile();
                    break;
                case '4':
                    sm.deleteStudent();
                    sm.saveToFile();
                    break;
                case '5':
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (studentChoice != '5');
            break;
        }
        case '2':
        {
            char facultyChoice;
            do
            {
                cout << "\n--- Faculty Management ---\n";
                cout << "1. Add Faculty\n";
                cout << "2. View Faculties\n";
                cout << "3. Update Faculty\n";
                cout << "4. Delete Faculty\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> facultyChoice;

                switch (facultyChoice)
                {
                case '1':
                    fm.addFaculty();
                    break;
                case '2':
                    fm.viewFaculties();
                    break;
                case '3':
                    fm.updateFaculty();
                    break;
                case '4':
                    fm.deleteFaculty();
                    break;
                case '5':
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (facultyChoice != '5');
            break;
        }
        case '3':
        {
            char courseChoice;
            do
            {
                cout << "\n--- Course Management ---\n";
                cout << "1. Add Course\n";
                cout << "2. View Courses\n";
                cout << "3. Update Course\n";
                cout << "4. Delete Course\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> courseChoice;

                switch (courseChoice)
                {
                case '1':
                    cm.addCourse();
                    break;
                case '2':
                    cm.viewCourses();
                    break;
                case '3':
                    cm.updateCourse();
                    break;
                case '4':
                    cm.deleteCourse();
                    break;
                case '5':
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (courseChoice != '5');
            break;
        }
        case '4':
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '4');

    return 0;
}