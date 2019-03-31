#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    long long temp11,temp12,temp13,temp21,temp22,temp23;
    scanf("%lld.%lld.%lld %lld.%lld.%lld",&temp11,&temp12,&temp13,&temp21,&temp22,&temp23);
    long long a,b;
    a=temp11*17*29+temp12*29+temp13;
    b=temp21*17*29+temp22*29+temp23;
    a=b-a;
    if(a<0){
        printf("-");
        a=-a;
    }
    printf("%lld.%lld.%lld",a/(17*29),(a%(17*29))/29,a%29);
    return 0;
}
