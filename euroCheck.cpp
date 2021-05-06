#include "euroCheck.h"
#include <iostream>

using std::string;


bool isLetter(char c);
bool isNumber(char c);
int toNumber(char c);


int getEuroSerialNumberVersion(string & serialNumber) {
    if (serialNumber.size() != 12){
        return 0;
    }
    if (isLetter(serialNumber[0])) {
        if(isLetter(serialNumber[1])) {
            if (isLetter(serialNumber[3])) {
                return 0;
            } else {
                return 2;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}


bool checkEuroSerialNumber2002(string & serialNumber) {
    int temp = toNumber(serialNumber[0]);
    int sum = querSumme(temp);
    for(int i = 1; i <= 10; i ++ ) {
        sum += toNumber(serialNumber[i]);
    }
    sum = sum % 9;
    sum = 8 - sum ;
    if (sum == 0) {
        sum = 9;
    }
    if (sum == toNumber(serialNumber[11])) {
        return true;
    } else {
        return false;
    }
}


bool checkEuroSerialNumber2013(string & serialNumber) {
    int temp = toNumber(serialNumber[0]);
    int temp2 = toNumber(serialNumber[1]);
    int sum = querSumme(temp) + querSumme(temp2);
    for(int i = 2; i <= 10; i ++ ) {
        sum += toNumber(serialNumber[i]);
    }
    sum = sum % 9;
    sum = 7 - sum ;
    if (sum == 0) {
        sum = 9;
    }
    if (sum == -1) {
        sum = 8;
    }
    if (sum == toNumber(serialNumber[11])) {
        return true;
    } else {
        return false;
    }
}


// L
bool isLetter(char c) {
    return 'A' <= c && c <= 'Z';
}
// N
bool isNumber(char c) {
    return '0' <= c && c <= '9';
}
int toNumber(char c) {
    if (isNumber(c)) {
        return c - '0';
    }
    if (isLetter(c)) {
        return c - 'A' + 1;
    }
    std::cout << "Error: toNumber(char): " << c << std::endl;
    return 0;
}

int querSumme (int & num) {
    int sum = 0;
    int temp;
    while(num>0)
    {
        temp = num %10;
        sum = sum + temp;
        num = num / 10;
    }
    return sum;
}