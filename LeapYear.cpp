//Preprocessor directives 
#include <iostream>
#include <iomanip>
#include<string> //to_string 
using namespace std;

//Function prototypes 
bool leapYear(int year);
int daysInMonth(int year, int month);
string tomorrow(int date);

int main() {

        //Variables
        int year;
        int month;
        int numberOfDays;
        int date;
        string tomorrowsDate;

        cout << "Enter a year: ";
        cin >> year;

        //Check if a year given is a leap year 
        if (leapYear(year)) {
                cout << "This is a leap year!" << endl << endl;
        }
        else {
                cout << "This is not a leap year!" << endl << endl;
        }

        cout << "Enter year and month: ";
        cin >> year >> month;

        numberOfDays = daysInMonth(year, month); //daysInmonth funtion gets called and return value is saved 
        cout << "The number of days in this month is " << numberOfDays << endl << endl;

        cout << "Enter a date in the form of YYYYMMDD: ";
        cin >> date;

        tomorrowsDate = tomorrow(date); //tomorrowsDate function gets called and return value is saved 
        cout << "Tomorrow it is: " << tomorrowsDate << endl;

        return 0;
}

//Function gets and returns boolean value if it is a leapYear
bool leapYear(int year) {

        if (year % 4 == 0 && year % 100 != 0) {
                return true;
        }
        else if (year % 100 == 0 && year % 400 == 0) {
                return true;
        }
        return false;
}

//Function returns the number of days in a month
int daysInMonth(int year, int month) {

        if (leapYear(year) && month == 2) {
                return 29;
        }
        else if (!leapYear(year) && month == 2) {
                return 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
                return 30;
        }
        return 31;
}

//Function returns tomorrows date 
string tomorrow(int date) {

        //Variables 
        int day;
        int month;
        int year;
        int checkDay;
        string tomorrowsDate;

        day = date % 100;  //Get day
        date /= 100;  //Decrement date value 
        month = date % 100; //Get month
        year = date / 100; //Get year

        checkDay = daysInMonth(year, month); //Get number of days in month and check if year is a leap year

        //Nested if and else satements are used to adjust the current date to tomorrows Date
        //The statments also checks to make sure leading zeroes are added  to get the correct date format 
        //to_string class is used to convert integer to string to manipulate date format 
        //Code is broken down as much as possible into seperate cases just to increase readibility 
        if (month == 2 && (checkDay == 29 || checkDay == 28) && day < checkDay) {
                day++;
                if (day <= 9) {
                        tomorrowsDate = to_string(year) + "0" + to_string(month) + "0" + to_string(day);
                }
                else {
                        tomorrowsDate = to_string(year) + "0" + to_string(month) + to_string(day);
                }
        }
        else if (month == 2 && (checkDay == 29 || checkDay == 28) && day == checkDay) {
                day = 1;
                month++;
                tomorrowsDate = to_string(year) + "0" + to_string(month) + "0" + to_string(day);
        }
        else if (month == 12 && day == 31) {
                day = 1;
                month = 1;
                year++;
                tomorrowsDate = to_string(year) + "0" + to_string(month) + "0" + to_string(day);
        }
        else if ((checkDay == 31 && day == 31) || (checkDay == 30 && day == 30)) {
                day = 1;
                month++;
                if (month > 9) {
                        tomorrowsDate = to_string(year) + to_string(month) + "0" + to_string(day);
                }
                else {
                        tomorrowsDate = to_string(year) + "0" + to_string(month) + "0" + to_string(day);
                }
        }
        else {
                day++;
                if (day <= 9 && month <= 9) {
                        tomorrowsDate = to_string(year) + "0" + to_string(month) + "0" + to_string(day);
                }
                else if (day <= 9 && month > 9) {
                        tomorrowsDate = to_string(year) + to_string(month) + "0" + to_string(day);
                }
                else if (day > 9 && month <= 9) {
                        tomorrowsDate = to_string(year) + "0" + to_string(month) + to_string(day);
                }
                else {
                        tomorrowsDate = to_string(year) + to_string(month) + to_string(day);
                }
        }

        return tomorrowsDate;
}


