#include <iostream>

void testMenu(){
// post-condition: the test menu is displayed for choose
    using namespace std;
    cout << "****************************** \n";
    cout << "* Test Menu * \n";
    cout << "* 1. isLeapYear *\n";
    cout << "* 2. getCenturyValue *\n";
    cout << "* 3. getYearValue *\n";
    cout << "* 4. getMonthValue *\n";
    cout << "* 5. dayOfWeek(month, day, year) *\n";
    cout << "* 6. dayOfWeek(day) *\n";
    cout << "* 7. Quit *\n";    
}

bool isLeapYear(int year){
    return (((year % 400) == 0) || (((year % 4) == 0) && ((year % 100) != 0)));
}

int getCenturyValue(int year){
    int century = year/100;
    int remainder = (century % 4);
    return ((3 - remainder) * 2);
}

int getYearValue(int year){
    return (getCenturyValue(year) + (getCenturyValue(year)/4));
}
// fix

int getMonthValue(int month, int year){
    if(month == 1){
        return (isLeapYear(year)) ? 6 : 0;
    }
    else if(month == 2){
        return (isLeapYear(year)) ? 2 : 3;
    }
    else if(month == 3){
        return 3;
    }
    else if(month == 4){
        return 6;
    }
    else if(month == 5){
        return 1;
    }
    else if(month == 6){
        return 4;
    }
    else if(month == 7){
        return 6;
    }
    else if(month == 8){
        return 2;
    }
    else if(month == 9){
        return 5;
    }
    else if(month == 10){
        return 0;
    }
    else if(month == 11){
        return 3;
    }
    else if(month == 12){
        return 5;
    }
    else{
        return 0;
    }
}

int dayOfWeek(int month, int day, int year){
    day += getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);
    return day;
}
// test again after getYearValue fixed

std::string dayOfWeek(int day){
// pre-condition: day has integer value 0, 1, 2, 3, 4, 5, or 6
// post-condition: the name of the day of week is returned as a std::. If day
// has value 0, then SUNDAY is returned; 1, then MONDAY is returned; and so on.
    int x = day % 7;
    std::string weekday;
    if(x==0){
        weekday = "Sunday";
    }
    else if(x==1){
        weekday = "Monday";
    }
    else if(x==1){
        weekday = "Tuesday";
    }
    else if(x==1){
        weekday = "Wednesday";
    }
    else if(x==1){
        weekday = "Thursday";
    }
    else if(x==1){
        weekday = "Friday";
    }
    else if(x==1){
        weekday = "Saturday";
    }
    return weekday;
}
// fix

int main()
{
    using namespace std;
    int choice;
    int day, month, year;
    do{
        testMenu();
        cout << "Please choose from menu: ";
        cin >> choice;
        switch (choice)
        {
            case 1: // check if a given year is leap year
                cout << "Please enter a year: ";
                cin >> year;
                if (isLeapYear(year))
                cout << "Year " << year << " is a leap year" << endl;
                else
                cout << "Year " << year << " is NOT a leap year" << endl;
                break;
            case 2: // calculate the century value of a given year
                cout << "Please enter a year: ";
                cin >> year;
                cout << "The century value is: " << getCenturyValue(year) << endl;
                break;
            case 3: // calculate the year value of a given year
                cout << "Please enter a year: ";
                cin >> year;
                cout << "The year value is: " << getYearValue(year) << endl;
                break;
            case 4: // calculate the month value of a given month in a given year
                cout << "Please enter a year and month: ";
                cin >> year >> month;
                cout << "The month value is: " << getMonthValue(month, year) <<
                endl;
                break;
            case 5: // calculate the day of week of a given date
                cout << "Please enter a year, a month, and a day : ";
                cin >> year >> month >> day;
                cout << "The day of the week is: " << dayOfWeek(month, day, year)
                << endl;
                break;
            case 6: // print out the name of a given day of week
                cout << "Please enter a day of week (0 for Sunday, 1 for Monday, etc): ";
                cin >> day;
                cout << "The name of the day of the week is: " << dayOfWeek(day)
                << endl;
                break;
            case 7:
                cout << "Did you tested all functions yet ? if not, please rerun the program\n";
                break;
                default:
                cout << "wrong option. Please choose from menu\n";
                break;
            }
        system("pause");
    } while (choice != 7);
}