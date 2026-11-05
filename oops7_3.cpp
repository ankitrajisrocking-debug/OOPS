#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class invalidHr {};
class invalidMin {};
class invalidSec {};

int main()
{
    int h, m, s;
    string period;

    try
    {
        cout << "Enter time (HH MM SS AM/PM): ";
        cin >> h >> m >> s >> period;

        if(h < 1 || h > 12)
            throw invalidHr();

        if(m < 0 || m > 59)
            throw invalidMin();

        if(s < 0 || s > 59)
            throw invalidSec();

        if(period != "AM" && period != "PM")
            throw invalidHr();

        if(period == "AM" && h == 12)
            h = 0;
        else if(period == "PM" && h != 12)
            h += 12;

        cout << "24-hour format: "
             << setfill('0') << setw(2) << h << ":"
             << setw(2) << m << ":"
             << setw(2) << s << endl;
    }
    catch(invalidHr)
    {
        cout << "Invalid Hour!" << endl;
    }
    catch(invalidMin)
    {
        cout << "Invalid Minutes!" << endl;
    }
    catch(invalidSec)
    {
        cout << "Invalid Seconds!" << endl;
    }

    return 0;
}

