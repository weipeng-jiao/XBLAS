#include "xblas.h"
#include "ehm.h"
#include <cmath>
#include <complex>


double dzasum (const  int n, const complex<double> * x, const  int incx)
{
    double asum=0;
    int step=0;
    int xnums=sizeof(x)/sizeof(x[0]);    //number of x-vector element
    int inums=1+(n-1)*incx; //number of interval

    //exception handling
    BlasErrorIF(n<=0||incx<=0||xnums<inums);

    //calculation
    if(incx==1)
    {
        for(int i=0;i<n;i++)
        {
            asum+=abs(real(x[i]))+abs(imag(x[i]));
        }
    }
    else
    {
       for(int i=0;i<n;i++)
        {
            asum+=abs(real(x[step]))+abs(imag(x[step]));
            step+=incx;
        } 
    }
    return asum;
}