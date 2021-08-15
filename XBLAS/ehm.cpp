#include "ehm.h"
#include <iostream>
using namespace std;

void BlasErrorIF(bool x)
{
    if(x==1)
    {
     cout <<"错误：请检查输入参数是否符合要求"<< endl;
     cout <<"Error：Please check whether the input parameters meet the requirements"<< endl;
     abort();
    }
}