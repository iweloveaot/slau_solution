#include <random>
#include <chrono>
#include <cmath>
#include "slau_solution.h"


double residual(double **H, double *x, double *b, int n) {
    double b1[n];
    for (int i=0; i<n; i++) {
        double sum = 0;
        for (int j=0; j<n; j++) {
            sum += H[i][j] * x[j];
        }
        b1[i] = sum;
    }

    double max_dif = -1;
    for (int i=0; i<n; i++)
        max_dif = std::max(std::abs(b1[i]-b[i]), max_dif);
    
    return max_dif;
}

double relativeError(double *x1, double *x, int n) {
    double max_dif = -1, max_x = -1;
    for (int i=0; i<n; i++) {
        max_dif = std::max(std::abs(x1[i]-x[i]), max_dif);
        max_x = std::max(std::abs(x[i]), max_x);
    }
    return max_dif / max_x;
}

void HilbertMatrix(double **H, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            H[i][j] = 1.0 / ((i+1) + (j+1) - 1);
        }
    }
}

void generateMatrix(double **A, int n) {
    std::mt19937 gen(42);
    std::uniform_real_distribution<> dis(-1.0, 1.0); 
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            A[i][j] = dis(gen);
        }
    }
}

void generateAnswers(double *b, int n) {
    std::mt19937 gen(42);
    std::uniform_real_distribution<> dis(-1.0, 1.0); 
    for (int i=0; i<n; i++) {
        b[i] = dis(gen);
    }
}

long long LU_time(double **A, double **L, double **U, int size) {
    
    auto start = std::chrono::steady_clock::now();
    LU(A, L, U, size);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    return elapsed.count(); 
} 

long long LUsolution_time(double **L, double **U, double *b, double *x, int size) {
    
    auto start = std::chrono::steady_clock::now();
    LUsolve(L, U, b, x, size);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    return elapsed.count(); 
} 

long long Qmatrix_time(double **A, double **Q, int size) {
    
    auto start = std::chrono::steady_clock::now();
    Qmatrix(A, Q, size);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    return elapsed.count(); 
} 

long long Rmatrix_time(double **A, double **Q, double **R, int size) {
    
    auto start = std::chrono::steady_clock::now();
    Rmatrix(A, Q, R, size);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    return elapsed.count(); 
} 

long long QRsolution_time(double **Q, double **R, double *b, double *x, int size) {
    
    auto start = std::chrono::steady_clock::now();
    QRsolve(Q, R, b, x, size);
    auto end = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    return elapsed.count(); 
} 