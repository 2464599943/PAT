#include <iostream>
#include<stdio.h>
using namespace std;
long long gcd(long long  a,long long b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int numerator1,numerator2,demo1,demo2;
    scanf("%d/%d %d/%d",&numerator1,&demo1,&numerator2,&demo2);
    int fuhao1=0,fuhao2=0;
    if(numerator1<0)fuhao1=1;
    if(numerator2<0)fuhao2=1;
    long long temp1,temp2,temp3,temp4;
    temp1=demo1*demo2;
    temp2=numerator1*demo2+numerator2*demo1;
    temp3=gcd(temp1,temp2);
    temp1=temp1/temp3;
    temp2=temp2/temp3;
    if(temp1>temp2){
        temp4=temp1/temp2;
        temp1=temp1%temp2;
    }else{
        temp4=0;
    }
    if(fuhao1==1&&fuhao2==1){
        printf("(2/3)+ (-2) = (-1 1/3)")
    }

    return 0;
}
