#include <iostream>
#include <fstream>
using namespace std;

class temp {
    string itemID, itemName;
    int itemQuantity, itemPrice;
    fstream file;

public:
    void addProduct();   // Add a new product
    void viewProduct();  // View all products
    void buyProduct();   // Buy a product
} obj;

// Function to add a new product
void temp::addProduct() {
    cout << "\nEnter the Product ID: ";
    cin >> itemID;
    cout << "Enter the Product Name: ";
    cin >> itemName;
    cout << "Enter the Product Quantity: ";
    cin >> itemQuantity;
    cout << "Enter the Product Price: ";
    cin >> itemPrice;

    file.open("generalData.txt", ios::app | ios::out); // Open file in append mode
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Write product details to the file
    file << itemID << endl
         << itemName << endl
         << itemQuantity << endl
         << itemPrice << endl;
    file.close();
    cout << "Product Added Successfully!" << endl;
}

// Function to view all products
void temp::viewProduct() {
    file.open("generalData.txt", ios::in); // Open file in read mode
    if (!file) {
        cout << "Error opening file or no products found!" << endl;
        return;
    }

    cout << "\n---------------- Product List ----------------\n";
    cout << "Product ID\tProduct Name\tQuantity\tPrice\n";
    cout << "------------------------------------------------\n";

    while (file >> itemID >> itemName >> itemQuantity >> itemPrice) {
        cout << itemID << "\t\t" << itemName << "\t\t" << itemQuantity << "\t\t" << itemPrice << endl;
    }

    cout << "------------------------------------------------\n";
    file.close();
}

// Function to buy a product
void temp::buyProduct() {
    string searchID;
    int quantityToBuy;
    bool found = false;

    cout << "\nEnter the Product ID to buy: ";
    cin >> searchID;
    cout << "Enter the quantity to buy: ";
    cin >> quantityToBuy;

    fstream tempFile;
    file.open("generalData.txt", ios::in); // Open the original file in read mode
    tempFile.open("temp.txt", ios::out);  // Open a temporary file in write mode

    if (!file || !tempFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (file >> itemID >> itemName >> itemQuantity >> itemPrice) {
        if (itemID == searchID) {
            found = true;
            if (itemQuantity >= quantityToBuy) {
                itemQuantity -= quantityToBuy; // Reduce the quantity
                cout << "Purchase successful! Total cost: " << quantityToBuy * itemPrice << endl;
            } else {
                cout << "Insufficient stock! Available quantity: " << itemQuantity << endl;
            }
        }
        // Write the updated or unchanged product details to the temporary file
        tempFile << itemID << endl
                 << itemName << endl
                 << itemQuantity << endl
                 << itemPrice << endl;
    }

    file.close();
    tempFile.close();

    // Replace the original file with the updated file
    remove("generalData.txt");
    rename("temp.txt", "generalData.txt");

    if (!found) {
        cout << "Product with ID " << searchID << " not found!" << endl;
    }
}

// Main function
int main() {
    char choice;
    do {
        // Display the menu
        cout << "\n--- General Store Management ---\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Buy Product\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle the user's choice
        switch (choice) {
        case '1':
            obj.addProduct(); // Add a new product
            break;
        case '2':
            obj.viewProduct(); // View all products
            break;
        case '3':
            obj.buyProduct(); // Buy a product
            break;
        case '0':
            cout << "Thank you for using General Store Management System!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again!" << endl;
        }
    } while (choice != '0');

    return 0;
}