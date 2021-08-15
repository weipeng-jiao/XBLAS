
#include "xblas.h"
#include "ehm.h"
#include <cmath>


float sasum (const  int n, const float *x, const  int incx)
{
    float asum=0;
    int step=0;
    int vnums=sizeof(x);    //number of vector element
    int inums=1+(n-1)*incx; //number of interval

    //exception handling
    BlasErrorIF(n<=0||incx<=0||vnums<inums);

    //calculation
    if(incx==1)
    {
        for(int i=0;i<n;i++)
        {
            asum+=abs(x[i]);
        }
    }
    else
    {
       for(int i=0;i<n;i++)
        {
            asum+=abs(x[step]);
            step+=incx;
        } 
    }
    return asum;
}

