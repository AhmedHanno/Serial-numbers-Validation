#include <iostream>
#include "euroCheck.h"
#include <fstream>


using std::string;
using std::cout;
using std::cin;
using std::endl;



string inputNextSerialNumber() {
    string serialNumber;
    cout << "Bitte geben Sie die Seriennummer oder fertig: ";
    cin >> serialNumber;
    return serialNumber;
}


void checkSerialNumberAndPrintResult(string & serialNumber) {
    int temp = getEuroSerialNumberVersion(serialNumber);
    switch (temp) {
        case 0:
            if (serialNumber == "fertig") {
                cout << "Goodbye....." << endl;
            } else {
                cout << "Ungultig!" << endl;
            }
            break;
        case 1:
            if (checkEuroSerialNumber2002(serialNumber)) {
                cout << "Der Jahr ist 2002!" << endl;
                cout << "Gultig" << endl;
            } else {
                cout << "Ungultig" << endl;
            }
            break;
        case 2:
            if (checkEuroSerialNumber2013(serialNumber)) {
                cout << "Der Jahr ist 2013!" << endl;
                cout << "Gultig" << endl;
            } else {
                cout << "Ungultig" << endl;
            }
            break;
    }
}

int main() {
    string serialNumber;

    std::ofstream file;
    file.open("myfile.txt");

    serialNumber = inputNextSerialNumber();
    if(serialNumber !="fertig") {
        do {
            checkSerialNumberAndPrintResult(serialNumber);
            serialNumber = inputNextSerialNumber();
        } while (serialNumber != "fertig");
    } else {
        cout << "Goodbye....." << endl;
    }

    return 0;
}
