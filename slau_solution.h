#ifndef _SLAY_SOLUTION_H_
#define _SLAY_SOLUTION_H_

void generateMatrix(double**, int);
void generateAnswers(double*, int);
void LU(double**, double**, double**, int);
void LUsolve(double**, double**, double*, double*, int);
void Qmatrix(double**, double**, int);
void Rmatrix(double**, double**, double**, int);
void QRsolve(double**, double**, double*, double*, int);

long long LUtime(double**, double**, double**, int);

#endif /*_SLAY_SOLUTION_H_*/