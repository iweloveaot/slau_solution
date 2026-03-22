#ifndef _FOR_EXPERIMENTS_H_
#define _FOR_EXPERIMENTS_H_

void HilbertMatrix(double**, int);
void generateMatrix(double**, int);
void generateAnswers(double*, int);

double relativeError(double*, double*, int);
double residual(double**, double*, double*, int);

long long LU_time(double**, double**, double**, int);
long long LUsolution_time(double**, double**, double*, double*, int);
long long Qmatrix_time(double**, double**, int);
long long Rmatrix_time(double**, double**, double**, int);
long long QRsolution_time(double**, double**, double*, double*, int);     


#endif /*_FOR_EXPERIMENTS_H_*/