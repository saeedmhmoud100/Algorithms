//
// Created by saeed on 10/26/2024.
//

#include<iostream>
using namespace std;

int fibonacciDynamic1(int n) {
    int f[n + 2];
    int i;
    f[0] = 0;
    f[1] = 1;
    for (i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int db[1000];

int fibonacciDynamic2(int n) {
    if (n <= 1)
        return n;
    if (db[n] != -1)
        return db[n];
    db[n] = fibonacciDynamic2(n - 1) + fibonacciDynamic2(n - 2);
    return db[n];
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    // n = 10;
    cout << "Fibonacci of " << n << " is: " << fibonacciDynamic1(n) << endl;
    for (int i = 0; i < 1000; i++)
        db[i] = -1;
    cout << "Fibonacci of " << n << " is: " << fibonacciDynamic2(n) << endl;
    return 0;
}