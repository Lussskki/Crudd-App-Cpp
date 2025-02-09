#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Record {
    int choice;
    string data;
};

// creating a file 
void createRecord (string data) {
    ofstream file("data.txt", ios::app); // append mode
    if (file.is_open()){
        file << " " << data << endl;
        file.close();
        cout << "Record added successfully!\n";
    } else {
        cout << "Error opening file!\n";
    }
};

// reading a file 
void readRecords () {
    ifstream file("data.txt");
    if (file.is_open()) {
        string data;
        cout << "Data\n";
        cout << "---------\n";
        while (getline(file,data)) {
            cout << data <<endl;
        }
        file.close();
    } else {
        cout << "Error opening file!\n";
    }
}

int main() {
    int choice;
    string data;
     

    do {
        cout << "\nCRUD operations:\n";
        cout << "1. Create Record.\n";
        cout << "2. Read Record.\n";
        cout << "3. Exit.\n";
        cout << "Enter your choice: "; 
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                getline(cin, data);
                  
                createRecord(data);
                break;
            case 2:
                readRecords();
                break;
            case 3:
                   cout << "Exiting...\n";
            default:
                cout << "Bye...\n";        
        }
    } while (choice != 3);

    return 0;   
}