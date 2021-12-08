#ifndef calendar_hpp
#define calendar_hpp
#include <vector>

class Calendar {
public:
    Calendar(int inputYear);

private:
    int dayNumber(int month, int year);
    int numberOfDays(int monthNumber, int year);

    void printerCalendar(int year);
    std::string getMonthName(int monthNumber);
    void displayMonths(int inputNumber);
    void displayDays(int& current, int days);
    std::string correctionOf(int inputNumber);
};

#include "calendar.cpp"
#endif