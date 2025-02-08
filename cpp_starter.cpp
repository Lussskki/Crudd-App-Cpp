#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Record {
    int choice, id;
    string name;
};

void createRecord (int id, string name) {
    ofstream file("data.txt", ios::app); // append mode
    if (file.is_open()){
        file << " " << name << endl;
        file.close();
        cout << "Record added successfully!\n";
    } else {
        cout << "Error opening file!\n";
    }
};

int main() {
    int choice, id;
    string name;
     

    do {
        cout << "\nCRUD operations:\n";
        cout << "1. Create Record.\n";
        cout << "Enter your choice: "; 
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter id: ";
                cin >> id;

                cout << "Enter name: ";
                cin >> name;
                  
                createRecord(id, name);
                break;    
        }
    } while (choice != 1);

    return 0;   
}