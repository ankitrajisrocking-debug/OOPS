#include <iostream>
#include <string>
using namespace std;

class addressType {
protected:
    string address;
public:
    addressType(string a = "") : address(a) {}

    void printAddress() const {
        cout << "Address: " << address << endl;
    }
};

class personType : public addressType {
protected:
    string firstName, lastName;
public:
    personType(string f = "", string l = "", string a = "")
        : addressType(a), firstName(f), lastName(l) {}

    void print() const {
        cout << "Name: " << firstName << " " << lastName << endl;
    }
};

class dateType {
    int d, m, y;
public:
    dateType(int dd = 1, int mm = 1, int yy = 2000)
        : d(dd), m(mm), y(yy) {}

    void printDate() const {
        cout << "DOB: " << d << "/" << m << "/" << y << endl;
    }
};

class extPersonType : public personType {
    string phone, type;
    dateType dob;

public:
    extPersonType(string f, string l, string a,
                  string p, string t, int d, int m, int y)
        : personType(f, l, a), phone(p), type(t), dob(d, m, y) {}

    void printPerson() const {
        print();
        printAddress();
        cout << "Phone: " << phone << endl;
        cout << "Type: " << type << endl;
        dob.printDate();
    }
};

int main() {
    extPersonType p("Ankit", "Kumar", "Patna, Bihar",
                    "9876543210", "Friend", 10, 5, 2005);

    p.printPerson();
    return 0;
}
