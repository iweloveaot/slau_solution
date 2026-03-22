#include <cmath>
#include <iostream>


void LU(double **A, double **L, double **U, int n) {
    int move = 1;
    int i_0 = 1;
    int j_1 = 0;
    while (move < 2*n) {
        if (move % 2 == 1) {
            for (int i=0; i<=j_1; i++) {
                double sum=0;
                for (int k=0; k<=(i-1); k++) sum += (L[i][k] * U[k][j_1]);
                U[i][j_1] = A[i][j_1] - sum;
            }
            j_1++;    
        }
        else if (move % 2 == 0) {
            for (int j=0; j<i_0; j++) {
                double sum=0;
                for (int k=0; k<=(j-1); k++) sum += (L[i_0][k] * U[k][j]);
                L[i_0][j] = (A[i_0][j] - sum) / U[j][j];
            }
            i_0++;
        }
        move++;
    }
}

void LUsolve(double **L, double **U, double *b, double *x, int n) {
    
    double y[n];
    for (int i=0; i<n; i++) {
        double sum=0;
        for (int j=0; j<i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }

    for (int i=n-1; i>=0; i--) {
        double sum=0;
        for (int j=n-1; j>i; j--) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }
}

void projection(double *a, double *b, double *res, int size) {
    double scalAB = 0;
    double scalBB = 0;
    for (int i=0; i<size; i++) {
        scalAB += a[i] * b[i];
        scalBB += b[i] * b[i];
    }
    for (int i=0; i<size; i++) {
        res[i] = b[i] * (-(scalAB/scalBB));
    }
}

void vectorSum(double *a, double *b, int n) {
    for (int i=0; i<n; i++) {
        a[i] = a[i] + b[i];
    }
}

void transpose(double **A, double **At, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            At[j][i] = A[i][j];
        }
    }
}

void Qmatrix(double **A, double **Q, int n) {   // вычисление матрицы Q сразу в транспонированном виде
    double** At = new double*[n];
    for (int i = 0; i < n; ++i) At[i] = new double[n];
    transpose(A, At, n);

    Q[0] = At[0];
    int projected = 1;
    for (int i=1; i<n; i++) {
        double *projSum = new double[n];
        for (int j=0; j<n; j++) projSum[j] = 0;
        for (int k=0; k<projected; k++) {
            double *proj = new double[n];
            projection(At[i], Q[k], proj, n);
            vectorSum(projSum, proj, n);
            delete[] proj;
        }
        vectorSum(At[i], projSum, n);
        delete[] projSum;
        Q[i] = At[i];
        projected++;
    }

    for (int i=0; i<n; i++) {
        double norm = 0;
        for (int j=0; j<n; j++) {
            norm += Q[i][j] * Q[i][j];
        }
        norm = std::sqrt(norm);
        for (int j=0; j<n; j++) {
            Q[i][j] = Q[i][j] / norm;
        }
    }
}

void Rmatrix(double **A, double **Q, double **R, int n) { // вычисление R
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                R[i][j] += Q[i][k] * A[k][j];
            }
        }
    }
}

void QRsolve(double **Q, double **R, double *b, double *x, int n) {
    double y[n];
    for (int i=0; i<n; i++) y[i] = 0;
    for (int i=0; i<n; i++) {
        for (int k=0; k<n; k++) {
            y[i] += Q[i][k] * b[k];
        }
    }

    for (int i=n-1; i>=0; i--) {
        double sum=0;
        for (int j=n-1; j>i; j--) {
            sum += R[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / R[i][i];
    }

}