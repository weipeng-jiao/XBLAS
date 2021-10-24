
#include "xblas.h"
#include "ehm.h"
#include <cmath>
#include <complex>


double zdotu (const  int n,  const complex<dounle> *x, const int incx, const complex<double> *y, const int incy)
{
    double sum=0;
    int xstep=0;
    int ystep=0;
    int xnums=sizeof(x)/sizeof(x[0]);    //number of x-vector element
    int ynums=sizeof(y)/sizeof(y[0]);    //number of y-vector element
    int ixnums=1+(n-1)*incx; //number of interval
    int iynums=1+(n-1)*incy; //number of interval
   
    //exception handling
    BlasErrorIF(n<=0||incx<=0||xnums<ixnums||ynums<iynums||xnums!=ynums);

 

    //calculation
    if(incx==1&&incy==1)
    {
        for(int i=0;i<n;i++)
        {
            sum=real(x[i])*real(y[i])+imag(x[i])*imag(y[i]);
        }
    }
    else
    {
       for(int i=0;i<n;i++)
        {
            sum=real(x[xstep])*real(y[xstep])+imag(x[xstep])*imag(y[xstep]);
            xstep+=incx;
            ystep+=incy;
        } 
    }
    return sum;
}