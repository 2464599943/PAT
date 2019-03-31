#include <iostream>
#include<stdio.h>
#include<math.h>
#define CLK_TCK1 100
using namespace std;

int main()
{
    int C1,C2;
    cin>>C1>>C2;
    double C3=C2-C1;
    int result=round(C3/CLK_TCK1);
    int hour=result/3600;
    int minute=(result%3600)/60;
    int second=result%60;
    printf("%02d:%02d:%02d",hour,minute,second);
    return 0;
}
