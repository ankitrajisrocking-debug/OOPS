#include <iostream>
#include <string>
using namespace std;

class dayType
{
private:
    string day;

    string days[7] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    int getIndex(string d)
    {
        for (int i = 0; i < 7; i++)
        {
            if (days[i] == d)
                return i;
        }

        return -1;
    }

public:

    // Default constructor
    dayType()
    {
        day = "Sunday";
    }

    // Parameterized constructor
    dayType(string d)
    {
        setDay(d);
    }

    // 1. Set the day
    void setDay(string d)
    {
        if (getIndex(d) != -1)
            day = d;
        else
            day = "Sunday";
    }

    // 2. Print the day
    void printDay()
    {
        cout << day << endl;
    }

    // 3. Return the day
    string getDay()
    {
        return day;
    }

    // 4. Return next day
    string nextDay()
    {
        int index = getIndex(day);
        return days[(index + 1) % 7];
    }

    // 5. Return previous day
    string previousDay()
    {
        int index = getIndex(day);
        return days[(index + 6) % 7];
    }

    // 6. Add days to current day
    string addDays(int n)
    {
        int index = getIndex(day);

        n = n % 7;

        return days[(index + n) % 7];
    }
};


// Derived class
class eventType : public dayType
{
private:
    string eventName;
    int daysRemaining;

public:

    // Default constructor
    eventType() : dayType()
    {
        eventName = "";
        daysRemaining = 0;
    }

    // Parameterized constructor
    eventType(string day, string event, int days)
        : dayType(day)
    {
        eventName = event;
        daysRemaining = days;
    }

    // Set event details
    void setEvent(string event, int days)
    {
        eventName = event;
        daysRemaining = days;
    }

    // Print event details
    void printEvent()
    {
        cout << "Event: " << eventName << endl;
        cout << "Days remaining: " << daysRemaining << endl;
    }
};


int main()
{
    // Testing dayType

    dayType d("Monday");

    cout << "Current day: ";
    d.printDay();

    cout << "Next day: "
         << d.nextDay() << endl;

    cout << "Previous day: "
         << d.previousDay() << endl;

    cout << "After 4 days: "
         << d.addDays(4) << endl;

    cout << "After 13 days: "
         << d.addDays(13) << endl;


    cout << "\n----------------------\n";

    // Testing eventType

    eventType e("Monday", "Minor Test", 5);

    cout << "Event details:\n";
    e.printEvent();

    cout << "Current day: ";
    e.printDay();

    cout << "Next day: "
         << e.nextDay() << endl;

    return 0;
}
