#include "xblas.h"
#include "ehm.h"
#include <cmath>
#include <complex>


float scasum (const  int n, const complex<float> * x, const  int incx)
{
    float asum=0;
    int step=0;
    int vnums=sizeof(x)/sizeof(x[0]);    //number of vector element
    int inums=1+(n-1)*incx; //number of interval

    //exception handling
    BlasErrorIF(n<=0||incx<=0||vnums<inums);

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