#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Record {
    int id;
    string data;
};

// Create a record with an ID
void createRecord(int id, string data) {
    ofstream file("data.txt", ios::app); // Append mode
    if (file.is_open()) {
        file << id << " " << data << endl; // Save ID and data
        file.close();
        cout << "Record added successfully!\n";
    } else {
        cout << "Error opening file!\n";
    }
}

// Update a record by ID
void updateRecord(int searchId, string newData) {
    ifstream file("data.txt");
    ofstream updated("updated.txt");
    bool found = false;

    if (file.is_open() && updated.is_open()) {
        int id;
        string data;
        
        while (file >> id) {
            file.ignore(); // Ignore space before reading string
            getline(file, data);

            if (id == searchId) {
                updated << id << " " << newData << endl; // Update record
                found = true;
            } else {
                updated << id << " " << data << endl; // Keep existing data
            }
        }
        
        file.close();
        updated.close();

        remove("data.txt"); // Remove old file
        rename("updated.txt", "data.txt"); // Rename new file

        if (found) 
            cout << "Record updated successfully!\n";
        else 
            cout << "Record not found!\n";
    } else {
        cout << "Error opening file!\n";
    }
}

// Read and display all records
void readRecords() {
    ifstream file("data.txt");
    if (file.is_open()) {
        int id;
        string data;
        
        cout << "ID  | Data\n";
        cout << "--------------\n";
        
        while (file >> id) {
            file.ignore(); // Ignore space before reading string
            getline(file, data);
            cout << id << " | " << data << endl;
        }
        
        file.close();
    } else {
        cout << "Error opening file!\n";
    }
}

int main() {
    int choice, id;
    string data;

    do {
        cout << "\nCRUD Operations:\n";
        cout << "1. Create Record\n";
        cout << "2. Read Records\n";
        cout << "3. Update Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline left in buffer

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter data: ";
                getline(cin, data);
                createRecord(id, data);
                break;
            case 2:
                readRecords();
                break;
            case 3:
                cout << "Enter ID to update: ";
                cin >> id;
                cin.ignore();
                cout << "Enter new data: ";
                getline(cin, data);
                updateRecord(id, data);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again!\n";
        }
    } while (choice != 4);

    return 0;
}
