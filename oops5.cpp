#include <iostream>
#include <string>
using namespace std;

// 1. Address class
class addressType {
    string street, city, state, pin;

public:
    addressType(string s = "", string c = "",
                string st = "", string p = "")
        : street(s), city(c), state(st), pin(p) {}

    void inputAddress() {
        cout << "Street: ";
        getline(cin, street);
        cout << "City: ";
        getline(cin, city);
        cout << "State: ";
        getline(cin, state);
        cout << "PIN: ";
        getline(cin, pin);
    }

    void printAddress() const {
        cout << street << ", " << city << ", "
             << state << " - " << pin << endl;
    }
};

// 2. Person class
class personType {
    string firstName, lastName;

public:
    personType(string f = "", string l = "")
        : firstName(f), lastName(l) {}

    void inputName() {
        cout << "First name: ";
        cin >> firstName;
        cout << "Last name: ";
        cin >> lastName;
    }

    void print() const {
        cout << firstName << " " << lastName << endl;
    }
};

// 3. Date class
class dateType {
    int day, month, year;

public:
    dateType(int d = 1, int m = 1, int y = 2000)
        : day(d), month(m), year(y) {}

    void inputDate() {
        cout << "DOB (day month year): ";
        cin >> day >> month >> year;
    }

    void printDate() const {
        cout << day << "/" << month << "/" << year;
    }
};

// 4. Multiple inheritance
class extPersonType : public personType,
                      public dateType,
                      public addressType {
    string phone, category;

public:
    void input() {
        inputName();
        inputDate();

        cin.ignore();
        inputAddress();

        cout << "Phone: ";
        getline(cin, phone);

        cout << "Category (Family/Friend/Business): ";
        getline(cin, category);
    }

    void printInfo() const {
        cout << "\nName: ";
        print();

        cout << "DOB: ";
        printDate();

        cout << "\nAddress: ";
        printAddress();

        cout << "Phone: " << phone << endl;
        cout << "Category: " << category << endl;
    }
};

int main() {
    extPersonType book[50];
    int n;

    cout << "Enter number of entries (max 50): ";
    cin >> n;

    if (n < 1 || n > 50) {
        cout << "Invalid number of entries!";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "\n--- Entry " << i + 1 << " ---\n";
        book[i].input();
    }

    cout << "\n===== ADDRESS BOOK =====\n";

    for (int i = 0; i < n; i++) {
        cout << "\nEntry " << i + 1 << ":";
        book[i].printInfo();
    }

    return 0;
}
