
#include "xblas.h"
#include "ehm.h"
#include <cmath>


double dsdot (const  int n,  const float *sx, const int incx, const float *sy, const int incy)
{
    double sum=0;
    int xstep=0;
    int ystep=0;
    int xnums=sizeof(sx)/sizeof(sx[0]);    //number of x-vector element
    int ynums=sizeof(sy)/sizeof(sy[0]);    //number of y-vector element
    int ixnums=1+(n-1)*incx; //number of interval
    int iynums=1+(n-1)*incy; //number of interval
   
    //exception handling
    BlasErrorIF(n<=0||incx<=0||xnums<ixnums||ynums<iynums||xnums!=ynums);

 
    //calculation
    if(incx==1&&incy==1)
    {
        for(int i=0;i<n;i++)
        {
            sum+=(double)sx[i]*(double)sy[i];
        }
    }
    else
    {
       for(int i=0;i<n;i++)
        {
            sum+=(double)sx[xstep]*(double)sy[ystep];
            xstep+=incx;
            ystep+=incy;
        } 
    }
    return sum;
}