#include <iostream>
#include <string>
using namespace std;

const int MAX_DIGITS = 20;

int* readNumber(int &length) {
    string num;
    cin >> num;
    length = (int)num.length();
    int* digits = new int[length];
    for (int i = 0; i < length; i++) digits[i] = num[length - 1 - i] - '0';
    return digits;
}

void outputSum(int* num1, int len1, int* num2, int len2) {
    int maxLen = (len1 > len2) ? len1 : len2;
    int* sum = new int[maxLen + 1];
    int carry = 0;
    for (int i = 0; i < maxLen; i++) {
        int d1 = (i < len1) ? num1[i] : 0;
        int d2 = (i < len2) ? num2[i] : 0;
        int s = d1 + d2 + carry;
        sum[i] = s % 10;
        carry = s / 10;
    }
    int sumLen = maxLen;
    if (carry) { sum[sumLen] = carry; sumLen++; }

    cout << "Sum: ";
    if (sumLen > MAX_DIGITS) cout << "(result exceeds " << MAX_DIGITS << " digits) ";
    for (int i = sumLen - 1; i >= 0; i--) cout << sum[i];
    cout << endl;

    delete[] sum;
}

class largeIntegers {
private:
    int* digits;
    int size;

    static int compareDigits(const int* a, int lenA, const int* b, int lenB) {
        if (lenA != lenB) return (lenA > lenB) ? 1 : -1;
        for (int i = lenA - 1; i >= 0; i--) {
            if (a[i] != b[i]) return (a[i] > b[i]) ? 1 : -1;
        }
        return 0;
    }

public:
    largeIntegers() {
        size = 1;
        digits = new int[1];
        digits[0] = 0;
    }

    largeIntegers(string num) {
        size = (int)num.length();
        digits = new int[size];
        for (int i = 0; i < size; i++) digits[i] = num[size - 1 - i] - '0';
    }

    largeIntegers(const largeIntegers &other) {
        size = other.size;
        digits = new int[size];
        for (int i = 0; i < size; i++) digits[i] = other.digits[i];
    }

    largeIntegers& operator=(const largeIntegers &other) {
        if (this != &other) {
            delete[] digits;
            size = other.size;
            digits = new int[size];
            for (int i = 0; i < size; i++) digits[i] = other.digits[i];
        }
        return *this;
    }

    ~largeIntegers() {
        delete[] digits;
    }

    void setValue(string num) {
        delete[] digits;
        size = (int)num.length();
        digits = new int[size];
        for (int i = 0; i < size; i++) digits[i] = num[size - 1 - i] - '0';
    }

    string getValue() const {
        string result;
        for (int i = size - 1; i >= 0; i--) result += (char)(digits[i] + '0');
        return result;
    }

    void printValue() const { cout << getValue(); }

    largeIntegers add(const largeIntegers &other) const {
        int maxLen = (size > other.size) ? size : other.size;
        int* result = new int[maxLen + 1];
        int carry = 0;
        for (int i = 0; i < maxLen; i++) {
            int d1 = (i < size) ? digits[i] : 0;
            int d2 = (i < other.size) ? other.digits[i] : 0;
            int s = d1 + d2 + carry;
            result[i] = s % 10;
            carry = s / 10;
        }
        int resultLen = maxLen;
        if (carry) { result[resultLen] = carry; resultLen++; }

        string resStr;
        for (int i = resultLen - 1; i >= 0; i--) resStr += (char)(result[i] + '0');
        delete[] result;
        return largeIntegers(resStr);
    }

    largeIntegers subtract(const largeIntegers &other) const {
        const largeIntegers *bigger, *smaller;
        if (compareDigits(digits, size, other.digits, other.size) >= 0) {
            bigger = this; smaller = &other;
        } else {
            bigger = &other; smaller = this;
        }

        int* result = new int[bigger->size];
        int borrow = 0;
        for (int i = 0; i < bigger->size; i++) {
            int d1 = bigger->digits[i];
            int d2 = (i < smaller->size) ? smaller->digits[i] : 0;
            int diff = d1 - d2 - borrow;
            if (diff < 0) { diff += 10; borrow = 1; } else borrow = 0;
            result[i] = diff;
        }

        int resultLen = bigger->size;
        while (resultLen > 1 && result[resultLen - 1] == 0) resultLen--;

        string resStr;
        for (int i = resultLen - 1; i >= 0; i--) resStr += (char)(result[i] + '0');
        delete[] result;
        return largeIntegers(resStr);
    }

    largeIntegers multiply(const largeIntegers &other) const {
        int resultSize = size + other.size;
        int* result = new int[resultSize];
        for (int i = 0; i < resultSize; i++) result[i] = 0;

        for (int i = 0; i < size; i++) {
            int carry = 0;
            for (int j = 0; j < other.size; j++) {
                int prod = digits[i] * other.digits[j] + result[i + j] + carry;
                result[i + j] = prod % 10;
                carry = prod / 10;
            }
            int k = i + other.size;
            while (carry) {
                int s = result[k] + carry;
                result[k] = s % 10;
                carry = s / 10;
                k++;
            }
        }

        int resLen = resultSize;
        while (resLen > 1 && result[resLen - 1] == 0) resLen--;

        string resStr;
        for (int i = resLen - 1; i >= 0; i--) resStr += (char)(result[i] + '0');
        delete[] result;
        return largeIntegers(resStr);
    }

    int compare(const largeIntegers &other) const {
        int lenA = size, lenB = other.size;
        while (lenA > 1 && digits[lenA - 1] == 0) lenA--;
        while (lenB > 1 && other.digits[lenB - 1] == 0) lenB--;
        return compareDigits(digits, lenA, other.digits, lenB);
    }
};

int main() {
    cout << "INT_MAX in C++ is 2147483647 -- confirmed (32-bit signed int).\n\n";

    cout << "=== Part 1: Adding two large integers (array-based) ===\n";
    cout << "Enter first positive integer (up to " << MAX_DIGITS << " digits): ";
    int len1, len2;
    int* num1 = readNumber(len1);
    cout << "Enter second positive integer (up to " << MAX_DIGITS << " digits): ";
    int* num2 = readNumber(len2);
    outputSum(num1, len1, num2, len2);
    delete[] num1;
    delete[] num2;

    cout << "\n=== Part 2: largeIntegers class demo ===\n";
    string s1, s2;
    cout << "Enter first large integer: ";
    cin >> s1;
    cout << "Enter second large integer: ";
    cin >> s2;

    largeIntegers a(s1), b(s2);

    largeIntegers sum = a.add(b);
    cout << "Sum: "; sum.printValue(); cout << endl;

    int cmp = a.compare(b);
    largeIntegers diff = a.subtract(b);
    cout << "Difference: ";
    if (cmp < 0) cout << "-";
    diff.printValue();
    cout << endl;

    largeIntegers prod = a.multiply(b);
    cout << "Product: "; prod.printValue(); cout << endl;

    if (cmp > 0) cout << "First number is greater.\n";
    else if (cmp < 0) cout << "Second number is greater.\n";
    else cout << "Both numbers are equal.\n";

    return 0;
}
