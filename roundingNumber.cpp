// Copyright (c) 2021 Crestel Ong All rights reserved
//
// Created by: Crestel Ong
// Created on: October 2021
// This is the Rounding number program in C++

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>


void RoundingNumber(float &numberToRound, int roundedByNumberInt) {
    // this program rounds a number to a user inputted decimal place

    // declare
    float roundedNumber;

    // process
    numberToRound = numberToRound * pow(10, roundedByNumberInt);
    numberToRound = numberToRound + 0.5;
    // https://www.ibm.com/docs/en/zos/2.3.0?topic=expressions-static-cast-operator-c-only
                    // so can divide with a float
    numberToRound = static_cast<int>(numberToRound);
    numberToRound = numberToRound/pow(10, roundedByNumberInt);
}


main() {
    // this function gets the number to round and rounded by number
    // declaring
    std::string numberToRoundString;
    std::string roundedByNumberString;
    float returnedRoundedNumber;
    int roundedByNumberInt;
    float numberToRoundFloat;

    // input
    std::cout << "Enter the number you want to round: ";
    std::cin >> numberToRoundString;
    std::cout << "Enter how many decimal places you want to round by: ";
    std::cin >> roundedByNumberString;
    std::cout << "" << std::endl;

    try {
        // convert string to float
        numberToRoundFloat = std::stof(numberToRoundString);
        roundedByNumberInt = std::stoi(roundedByNumberString);
        if (numberToRoundFloat == std::stof(numberToRoundString) &&
            roundedByNumberInt == std::stoi(roundedByNumberString)) {
        // call functions
        RoundingNumber(numberToRoundFloat, roundedByNumberInt);
        } else {
            std::cout << "Invalid input." << std::endl;
        }
        // output
        std::cout << "The rounded number is " << numberToRoundFloat;
    } catch (std::invalid_argument) {
        std::cout << "Invalid input." << std::endl;
    }
    std::cout << "\n";
    std::cout << "\nDone.";
}
