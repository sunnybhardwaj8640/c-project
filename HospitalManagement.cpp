#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Structure to store patient details
struct Patient {
    string name, disease, admitDate;
    int id, age;
};

// Structure to store bill details
struct Bill {
    int patientId;
    double amount;
    string date;
};

// Structure to store appointment details
struct Appointment {
    int patientId;
    string doctorName;
    string appointmentDate;
};

// Structure to store medical report details
struct MedicalReport {
    int patientId;
    string reportDetails;
    string reportDate;
};

// Class for Hospital Management
class HospitalManagement {
    vector<Patient> patients; // Vector to store patient records
    vector<Bill> bills;       // Vector to store bill records
    vector<Appointment> appointments; // Vector to store appointment records
    vector<MedicalReport> reports;    // Vector to store medical reports

public:
    void loadFromFile();   // Load patients from file
    void saveToFile();     // Save patients to file
    void addPatient();     // Add a new patient
    void displayPatient(); // Display all patients

    void addBill();        // Add a new bill
    void displayBills();   // Display all bills

    void addAppointment(); // Add a new appointment
    void displayAppointments(); // Display all appointments

    void addMedicalReport(); // Add a new medical report
    void displayMedicalReports(); // Display all medical reports
};

// Implementation of Patient Management
void HospitalManagement::loadFromFile() {
    ifstream file("hospital.txt");
    if (!file) {
        cout << "No existing patient data found. Starting fresh.\n";
        return;
    }
    patients.clear(); // Clear the vector before loading
    Patient patient_records;
    while (file >> patient_records.id >> patient_records.name >> patient_records.age >> patient_records.disease >> patient_records.admitDate) {
        patients.push_back(patient_records); // Add each patient to the vector
    }
    file.close();
}

void HospitalManagement::saveToFile() {
    ofstream file("hospital.txt");
    for (const auto& patient_records : patients) {
        file << patient_records.id << endl
             << patient_records.name << endl
             << patient_records.age << endl
             << patient_records.disease << endl
             << patient_records.admitDate << endl;
    }
    file.close();
}

void HospitalManagement::addPatient() {
    Patient patient_records;
    cout << "\nEnter the Patient ID: ";
    cin >> patient_records.id;
    cin.ignore(); // Ignore newline character
    cout << "Enter the Patient Name: ";
    getline(cin, patient_records.name);
    cout << "Enter the Patient Age: ";
    cin >> patient_records.age;
    cin.ignore(); // Ignore newline character
    cout << "Enter the Patient Disease: ";
    getline(cin, patient_records.disease);
    cout << "Enter the Patient Admit-Date: ";
    getline(cin, patient_records.admitDate);

    patients.push_back(patient_records); // Add the patient to the vector
    cout << "Patient added Successfully!" << endl;
}

void HospitalManagement::displayPatient() {
    if (patients.empty()) {
        cout << "No Patient Record Found.\n";
        return;
    }
    cout << "\n------------------ HOSPITAL PATIENT DETAILS -----------------\n";
    cout << "Patient ID\tPatient Name\tPatient Age\tDisease\tAdmit Date\n";
    cout << "-------------------------------------------------------------------------------------\n";
    for (const auto& patient_records : patients) {
        cout << patient_records.id << "\t\t" << patient_records.name << "\t\t" << patient_records.age
             << "\t\t" << patient_records.disease << "\t\t" << patient_records.admitDate << endl;
    }
    cout << "------------------------------------------------------------------------------------\n";
}

// Implementation of Bill Management
void HospitalManagement::addBill() {
    Bill bill;
    cout << "\nEnter the Patient ID for the bill: ";
    cin >> bill.patientId;
    cout << "Enter the Bill Amount: ";
    cin >> bill.amount;
    cin.ignore(); // Ignore newline character
    cout << "Enter the Bill Date: ";
    getline(cin, bill.date);

    bills.push_back(bill); // Add the bill to the vector
    cout << "Bill added Successfully!" << endl;
}

void HospitalManagement::displayBills() {
    if (bills.empty()) {
        cout << "No Bill Record Found.\n";
        return;
    }
    cout << "\n------------------ BILL DETAILS -----------------\n";
    cout << "Patient ID\tBill Amount\tBill Date\n";
    cout << "-------------------------------------------------\n";
    for (const auto& bill : bills) {
        cout << bill.patientId << "\t\t" << bill.amount << "\t\t" << bill.date << endl;
    }
    cout << "-------------------------------------------------\n";
}

// Implementation of Appointment Management
void HospitalManagement::addAppointment() {
    Appointment appointment;
    cout << "\nEnter the Patient ID for the appointment: ";
    cin >> appointment.patientId;
    cin.ignore(); // Ignore newline character
    cout << "Enter the Doctor Name: ";
    getline(cin, appointment.doctorName);
    cout << "Enter the Appointment Date: ";
    getline(cin, appointment.appointmentDate);

    appointments.push_back(appointment); // Add the appointment to the vector
    cout << "Appointment added Successfully!" << endl;
}

void HospitalManagement::displayAppointments() {
    if (appointments.empty()) {
        cout << "No Appointment Record Found.\n";
        return;
    }
    cout << "\n------------------ APPOINTMENT DETAILS -----------------\n";
    cout << "Patient ID\tDoctor Name\tAppointment Date\n";
    cout << "-------------------------------------------------------\n";
    for (const auto& appointment : appointments) {
        cout << appointment.patientId << "\t\t" << appointment.doctorName << "\t\t" << appointment.appointmentDate << endl;
    }
    cout << "-------------------------------------------------------\n";
}

// Implementation of Medical Report Management
void HospitalManagement::addMedicalReport() {
    MedicalReport report;
    cout << "\nEnter the Patient ID for the medical report: ";
    cin >> report.patientId;
    cin.ignore(); // Ignore newline character
    cout << "Enter the Report Details: ";
    getline(cin, report.reportDetails);
    cout << "Enter the Report Date: ";
    getline(cin, report.reportDate);

    reports.push_back(report); // Add the report to the vector
    cout << "Medical Report added Successfully!" << endl;
}

void HospitalManagement::displayMedicalReports() {
    if (reports.empty()) {
        cout << "No Medical Report Record Found.\n";
        return;
    }
    cout << "\n------------------ MEDICAL REPORT DETAILS -----------------\n";
    cout << "Patient ID\tReport Details\tReport Date\n";
    cout << "----------------------------------------------------------\n";
    for (const auto& report : reports) {
        cout << report.patientId << "\t\t" << report.reportDetails << "\t\t" << report.reportDate << endl;
    }
    cout << "----------------------------------------------------------\n";
}

// Main function
int main() {
    HospitalManagement hm;
    hm.loadFromFile(); // Load existing patient data from file

    char choice;
    do {
        // Display the main menu
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Add Bill\n";
        cout << "4. Display Bills\n";
        cout << "5. Add Appointment\n";
        cout << "6. Display Appointments\n";
        cout << "7. Add Medical Report\n";
        cout << "8. Display Medical Reports\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle the user's choice
        switch (choice) {
        case '1':
            hm.addPatient();
            hm.saveToFile(); // Save changes to file
            break;

        case '2':
            hm.displayPatient();
            break;

        case '3':
            hm.addBill();
            break;

        case '4':
            hm.displayBills();
            break;

        case '5':
            hm.addAppointment();
            break;

        case '6':
            hm.displayAppointments();
            break;

        case '7':
            hm.addMedicalReport();
            break;

        case '8':
            hm.displayMedicalReports();
            break;

        case '9':
            cout << "Exiting the system. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '9');

    return 0;
}