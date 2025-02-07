#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream myFile;
    myFile.open("data.txt", ios :: out); // write or if doesn't exists it creates
    if(myFile.is_open()) {
        myFile << "It's working \n";
        myFile.close();
    }
    system("pause");
}