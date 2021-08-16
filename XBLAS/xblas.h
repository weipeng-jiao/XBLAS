#ifndef XBLAS_H
#define XBLAS_H

//XBLAS LEVEL-1
float sasum (const  int n, const float *x, const  int incx);
double dasum (const  int n, const double *x, const  int incx);
float scasum (const  int n, const complex<float> * x, const  int incx);
double dzasum (const  int n, const complex<double> * x, const  int incx);


#endif