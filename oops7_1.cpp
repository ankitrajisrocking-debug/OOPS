#include <iostream>
using namespace std;

class shape
{
protected:
    double x, y;

public:
    void get_data(double a, double b = 0)
    {
        x = a;
        y = b;
    }

    virtual void display_area()
    {
        cout << "Area of Shape";
    }
};

class rectangle : public shape
{
public:
    void display_area()
    {
        cout << "Area of Rectangle = " << x * y;
    }
};

class triangle : public shape
{
public:
    void display_area()
    {
        cout << "Area of Triangle = " << 0.5 * x * y;
    }
};

class circle : public shape
{
public:
    void display_area()
    {
        cout << "Area of Circle = " << 3.14 * x * x;
    }
};

int main()
{
    rectangle r;
    triangle t;
    circle c;
    double a, b;
    int ch;

    cout << "1.Rectangle  2.Triangle  3.Circle\n";
    cout << "Enter choice: ";
    cin >> ch;

    if(ch == 1)
    {
        cout << "Enter length and breadth: ";
        cin >> a >> b;
        r.get_data(a, b);
        r.display_area();
    }
    else if(ch == 2)
    {
        cout << "Enter base and height: ";
        cin >> a >> b;
        t.get_data(a, b);
        t.display_area();
    }
    else if(ch == 3)
    {
        cout << "Enter radius: ";
        cin >> a;
        c.get_data(a);
        c.display_area();
    }
    else
        cout << "Invalid choice";

    return 0;
}

