#include "calendar.hpp"
#include <iostream>

Calendar::Calendar(int inputYear) {
    printerCalendar(inputYear);
}

int Calendar::dayNumber(int month, int year) {
    return (numberOfDays(month, year) + (13 * (month + 1) / 5) +
             (year % 100) + ((year % 100) / 4) + ((year / 100) / 4) -
             (2 * (year / 100))) % 7;
}

std::string Calendar::getMonthName(int monthNumber) {
    std::string months[] = {"Jan", "Feb", "Mar", "Apr",
                            "May", "Jun", "Jul", "Aug",
                            "Sep", "Oct", "Nov", "Dec"};
    return months[monthNumber - 3];
}

bool isLeapYear(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int Calendar::numberOfDays(int monthNumber, int year) {
    std::vector<int> lastDay = {
        31, (isLeapYear(year) ? 29 : 28) , 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    return lastDay[monthNumber - 1];
    // while(m < 7) { //no need to use while
    //     if() {
    //         return  //exit out this function
    //     } else if {
    //         return //exit
    //     }
    //     //No way to break the condition -> infinite loop
    //     //return <- no need to use while-loop at all
    // }
}

std::string Calendar::correctionOf(int inputNumber) {
    std::string total = "";

    for(int i = 0; i < 28 - (((inputNumber - 1) * 2) * 2); i++) {
        total += " ";
    }
    return total;
}

void Calendar::displayMonths(int inputNumber) {
        std::string month = getMonthName(inputNumber);
        std::cout << "\n-------------" << month << "-------------\n";
        std::cout << "| Sun Mon Tue Wed Thu Fri Sat|\n";
}

void Calendar::displayDays(int& current, int days) {
    int k = 1;
    std::cout << "|";

    for(k = 1; k < current; k++) {
        std::cout << "    ";
    }

    
    
    for(int j = 1; j <= days; j++) {
        if(j < 10) {
            std::cout << "   " << j;
        } else {
            std::cout << "  " << j;
        }

        if(++k > 7) {
            k = 1;
            std::cout << "|\n";
            if(j < days) {
                std::cout << "|";
            }
        }
    }

    if(k > 1) {
        std::cout << correctionOf(k) << "|\n";
    }
    current = k;
    std::cout << "-----------------------------\n";
}



void Calendar::printerCalendar(int year) {
    std::cout << "Type year: " << year << std::endl;
    int days = 0;
    int current = dayNumber(13, year);

    for(int i = 3; i < 15; i++) {
        days = numberOfDays(i - 2, year);
        displayMonths(i);
        displayDays(current, days);
    }
}