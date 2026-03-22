#include <iostream>
#include <iomanip>
#include "slau_solution.h"
#include "experiments.h"



int main() {

    // Эксперимент 1 -- сравнение времени решения одной системы

    // int sizes[] = {100, 200, 500, 1000};
    // for (auto n: sizes) {
        // double** A = new double*[n];
        // for (int i = 0; i < n; ++i) A[i] = new double[n];
        // double** L = new double*[n];
        // for (int i = 0; i < n; ++i) L[i] = new double[n];
        // double** U = new double*[n];
        // for (int i = 0; i < n; ++i) U[i] = new double[n];
        // double** Q = new double*[n];
        // for (int i = 0; i < n; ++i) Q[i] = new double[n];
        // double** R = new double*[n];
        // for (int i = 0; i < n; ++i) R[i] = new double[n];
        // for (int i=0; i<n; i++) for (int j=0; j<n; j++) L[i][j] = 0;
        // for (int i=0; i<n; i++) for (int j=0; j<n; j++) U[i][j] = 0;
        // for (int i=0; i<n; i++) for (int j=0; j<n; j++) Q[i][j] = 0;
        // for (int i=0; i<n; i++) for (int j=0; j<n; j++) R[i][j] = 0;
        // for (int i=0; i<n; i++) L[i][i] = 1;
        // double b[n];

    //     generateMatrix(A, n);
    //     generateAnswers(b, n);

    //     long long lu_time = LU_time(A, L, U, n);
    //     double x[n];
    //     long long lusolve_time = LUsolution_time(L, U, b, x, n);

    //     long long qmatr_time = Qmatrix_time(A, Q, n);
    //     long long rmatr_time = Rmatrix_time(A, Q, R, n);
    //     double x1[n];
    //     long long qrsolve_time = QRsolution_time(Q, R, b, x1, n);
        
    //     std::cout << "Matrix size: " << n << std::endl;
    //     std::cout << "                   decomposition time   substitution time   total solution time" << std::endl;
    //     std::cout << "LU-decomposition   " << lu_time << "             " << lusolve_time << "            " << lu_time+lusolve_time << std::endl;
    //     std::cout << "QR-decomposition   " << qmatr_time+rmatr_time << "            " << qrsolve_time << "             " << qmatr_time+rmatr_time+qrsolve_time << std::endl;
        
    //     for (int i=0; i<n; i++) delete[] A[i];
    //     delete[] A;
    //     for (int i=0; i<n; i++) delete[] L[i];
    //     delete[] L;
    //     for (int i=0; i<n; i++) delete[] U[i];
    //     delete[] U;
    //     for (int i=0; i<n; i++) delete[] Q[i];
    //     delete[] Q;
    //     for (int i=0; i<n; i++) delete[] R[i];
    //     delete[] R;
            
    //     std::cout << std::endl;
    // }

    // Эксперимент 2 -- экономия времени при множественных правых частях
    // int n = 500;
    // double** A = new double*[n];
    // for (int i = 0; i < n; ++i) A[i] = new double[n];
    // double** L = new double*[n];
    // for (int i = 0; i < n; ++i) L[i] = new double[n];
    // double** U = new double*[n];
    // for (int i = 0; i < n; ++i) U[i] = new double[n];
    // double** Q = new double*[n];
    // for (int i = 0; i < n; ++i) Q[i] = new double[n];
    // double** R = new double*[n];
    // for (int i = 0; i < n; ++i) R[i] = new double[n];
    // for (int i=0; i<n; i++) for (int j=0; j<n; j++) L[i][j] = 0;
    // for (int i=0; i<n; i++) for (int j=0; j<n; j++) U[i][j] = 0;
    // for (int i=0; i<n; i++) for (int j=0; j<n; j++) Q[i][j] = 0;
    // for (int i=0; i<n; i++) for (int j=0; j<n; j++) R[i][j] = 0;
    // for (int i=0; i<n; i++) L[i][i] = 1;
    // double b[n];
    
    // generateMatrix(A, n);

    // long long lu_time = LU_time(A, L, U, n);
    // long long qr_time = Qmatrix_time(A, Q, n) + Rmatrix_time(A, Q, R, n);

    // int K[] = {1, 10, 100};
    // long long LUsols[3];
    // long long QRsols[3];
    // for (int k = 0; k<3; k++) {
    //     long long lusol_time = 0, qrsol_time = 0;
    //     for (int i=0; i<k; i++) {
    //         generateAnswers(b, n);
    //         double x[n];
    //         lusol_time += LUsolution_time(L, U, b, x, n);
    //         double x1[n];
    //         qrsol_time += QRsolution_time(Q, R, b, x1, n);
    //     }
    //     LUsols[k] = lusol_time;
    //     QRsols[k] = qrsol_time;
    // }
    // for (int k = 0; k<3; k++) {
    //     std::cout << "k = " << K[k] << std::endl;
    //     std::cout << "LU time: " << lu_time << " " << LUsols[k] << " " << lu_time+LUsols[k] << std::endl;
    //     std::cout << "QR time: " << qr_time << " " << QRsols[k] << " " << qr_time+QRsols[k] << std::endl;
    // }

    // for (int i=0; i<n; i++) delete[] A[i];
    // delete[] A;
    // for (int i=0; i<n; i++) delete[] L[i];
    // delete[] L;
    // for (int i=0; i<n; i++) delete[] U[i];
    // delete[] U;
    // for (int i=0; i<n; i++) delete[] Q[i];
    // delete[] Q;
    // for (int i=0; i<n; i++) delete[] R[i];
    // delete[] R;
            

    // Эксперимент 3 -- проверка точности на плохо обусловленных матрицах
    int sizes[] = {5, 10, 15};
    for (auto n: sizes) {
        double** A = new double*[n];
        for (int i = 0; i < n; ++i) A[i] = new double[n];
        double** L = new double*[n];
        for (int i = 0; i < n; ++i) L[i] = new double[n];
        double** U = new double*[n];
        for (int i = 0; i < n; ++i) U[i] = new double[n];
        double** Q = new double*[n];
        for (int i = 0; i < n; ++i) Q[i] = new double[n];
        double** R = new double*[n];
        for (int i = 0; i < n; ++i) R[i] = new double[n];
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) L[i][j] = 0;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) U[i][j] = 0;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) Q[i][j] = 0;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) R[i][j] = 0;
        for (int i=0; i<n; i++) L[i][i] = 1;
        double b[n];

        HilbertMatrix(A, n);
        
        double x[n];
        for (int i=0; i<n; i++) x[i] = 1;
        for (int i=0; i<n; i++) {
            double sum=0;
            for (int j=0; j<n; j++) sum += A[i][j];
            b[i] = sum; 
        }

        double x1[n];
        double x2[n];
        LU(A, L, U, n);
        LUsolve(L, U, b, x1, n);
        Qmatrix(A, Q, n);
        Rmatrix(A, Q, R, n);
        QRsolve(Q, R, b, x2, n);

        double rel_er1 = relativeError(x1, x, n);
        double rel_er2 = relativeError(x2, x, n);

        double resid1 = residual(A, x1, b, n);
        double resid2 = residual(A, x2, b, n);

        std::cout << rel_er1 << "   " << resid1 << std::endl;
        std::cout << rel_er2 << "   " << resid2 << std::endl;
        std::cout << std::endl;

        for (int i=0; i<n; i++) delete[] A[i];
        delete[] A;
        for (int i=0; i<n; i++) delete[] L[i];
        delete[] L;
        for (int i=0; i<n; i++) delete[] U[i];
        delete[] U;
        for (int i=0; i<n; i++) delete[] Q[i];
        delete[] Q;
        for (int i=0; i<n; i++) delete[] R[i];
        delete[] R;
    }
         
    return 0;
}






    // int n;
    // std::cout << "Enter the number of equations: ";
    // std::cin >> n;

    // for (int i=0; i<n; i++) for (int j=0; j<n; j++) A[i][j] = 0;

    // std::cout << "Enter your coefficients separated by space - one line for one equation:" << std::endl;
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         std::cin >> A[i][j];
    //     }
    // }

    // std::cout << "Enter the answers to equations separated by space: ";
    // for (int i=0; i<n; i++) std::cin >> b[i];

    // int yn = 0;
    // std::cout << "Want to change answers? enter 1/0 (yes/no)" << std::endl;
    // std::cin >> yn;
    // if (yn) {
    //     // std::cout << "Enter the answers to equations separated by space: ";
    //     // for (int i=0; i<n; i++) std::cin >> b[i];

    //     LUsolve(L, U, b, x, n);
    //     for (int i=0; i<n; i++) std::cout << "x" << i+1 << ": " << std::fixed << std::setprecision(5) << x[i] << std::endl;
    //     QRsolve(Q, R, b, x1, n);
    //     for (int i=0; i<n; i++) std::cout << "x'" << i+1 << ": " << std::fixed << std::setprecision(5) << x1[i] << std::endl;
    // }

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         std::cout << A[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         std::cout << L[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         std::cout << U[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // for (int i=0; i<n; i++) std::cout << "x" << i+1 << ": " << std::fixed << std::setprecision(5) << x[i] << std::endl;