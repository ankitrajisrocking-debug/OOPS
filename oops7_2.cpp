#include <iostream>
using namespace std;

// Function template to find the largest element
template <class T>
T largest(T arr[], int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Class template
template <class T>
class Array {
    T arr[5];

public:
    void input() {
        cout << "Enter 5 elements: ";
        for (int i = 0; i < 5; i++)
            cin >> arr[i];
    }

    void display() {
        cout << "Elements: ";
        for (int i = 0; i < 5; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    T sum() {
        T s = 0;
        for (int i = 0; i < 5; i++)
            s += arr[i];
        return s;
    }
};

int main() {
    int a[5] = {10, 20, 30, 40, 50};
    float b[5] = {1.5, 2.5, 3.5, 4.5, 5.5};

    cout << "Largest Integer: " << largest(a, 5) << endl;
    cout << "Largest Float: " << largest(b, 5) << endl;

    Array<int> x;
    cout << "\nInteger Array:\n";
    x.input();
    x.display();
    cout << "Sum = " << x.sum() << endl;

    Array<float> y;
    cout << "\nFloat Array:\n";
    y.input();
    y.display();
    cout << "Sum = " << y.sum() << endl;

    return 0;
}

