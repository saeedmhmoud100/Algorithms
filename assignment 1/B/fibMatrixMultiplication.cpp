//
// Created by saeed on 10/26/2024.
//


#include <iostream>
using namespace std;

void multiply(int matrix1[2][2], int matrix2[2][2]) {
    int x = matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0];
    int y = matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1];
    int z = matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0];
    int w = matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1];

    matrix1[0][0] = x;
    matrix1[0][1] = y;
    matrix1[1][0] = z;
    matrix1[1][1] = w;
}

void matrixPower(int matrix[2][2], int n) {
    if (n == 0 || n == 1)
        return;

    int baseMatrix[2][2] = {{1, 1}, {1, 0}};

    matrixPower(matrix, n / 2);
    multiply(matrix, matrix);

    if (n % 2 != 0)
        multiply(matrix, baseMatrix);
}

int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int fibMatrix[2][2] = {{1, 1}, {1, 0}};
    matrixPower(fibMatrix, n - 1);

    return fibMatrix[0][0];
}

int main() {
    int n = 1;
    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}