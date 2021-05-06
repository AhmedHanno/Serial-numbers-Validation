#ifndef BLATT2_EUROCHECK_H
#define BLATT2_EUROCHECK_H

#include <string>


int getEuroSerialNumberVersion(std::string &serialNumber);
bool checkEuroSerialNumber2002(std::string &serialNumber);
bool checkEuroSerialNumber2013(std::string &serialNumber);
int querSumme(int &num);

#endif //BLATT2_EUROCHECK_H
