#include <iostream>
#include <cmath>
#include <string>
#include <iomanip> // For better formatting
using namespace std;

int logn(long long time) {
    int n = 1;
    while (log2(n) <= time) {
        n++;
    }
    return n - 1;
}

int sqrtn(long long time) {
    int n = 1;
    while (sqrt(n) <= time) {
        n++;
    }
    return n - 1;
}

int calculaten(long long time) {
    return time;
}

int nlogn(long long time) {
    int n = 1;
    while (n * log2(n) <= time) {
        n++;
    }
    return n - 1;
}

int nsquare(long long time) {
    int n = 1;
    while (n * n <= time) {
        n++;
    }
    return n - 1;
}

int ncube(long long time) {
    int n = 1;
    while (n * n * n <= time) {
        n++;
    }
    return n - 1;
}

int two_n(long long time) {
    int n = 1;
    while ((1LL << n) <= time) { // Faster way to calculate 2^n
        n++;
    }
    return n - 1;
}

int factorial(long long time) {
    int n = 1;
    long long fact = 1;
    while (fact <= time) {
        n++;
        fact *= n;
        if (fact > time) break;
    }
    return n - 1;
}

int main() {
    long long time[] = {1, 60, 3600, 86400, 2592000, 31536000, 3153600000};
    string functions[] = {"log n", "sqrt n", "n", "n log n", "n square", "n cube", "2^n", "n!"};
    int (*functionPtrs[])(long long) = {logn, sqrtn, calculaten, nlogn, nsquare, ncube, two_n, factorial};

    // Print header
    cout << setw(12) << "Function\\Time";
    for (string unit : {"1 sec", "1 min", "1 hr", "1 day", "1 mo", "1 yr", "1 century"}) {
        cout << setw(10) << unit;
    }
    cout << endl;

    // Print results
    for (int i = 0; i < 8; i++) {
        cout << setw(12) << functions[i];
        for (long long t : time) {
            int result = functionPtrs[i](t);
            cout << setw(10) << result;
        }
        cout << endl;
    }

    return 0;
}
