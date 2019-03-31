#include <iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
bool ifprime(long long num){
    long long a=(long long)sqrt(num*1.0);
    if(num<=1)return false;
    for(long long i=2;i<=a;i++){
        if(num%i==0)return false;
    }
    return true;
}
bool sovle(long long num,long long radix){
    if(!ifprime(num))return false;
    long long num1=num,num2;
    long long result=0;
    while(num1!=0){
       num2=num1%radix;
       num1=num1/radix;
       result=result*radix+num2;

    }
     return ifprime(result);
}

int main()
{
    long long num1,num2;
    scanf("%lld",&num1);
    while(num1>0){
        scanf("%lld",&num2);
        if(num1!=1){
        if(sovle(num1,num2)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
        scanf("%lld",&num1);

    }
    else{
         printf("No\n");
    }
    }
    return 0;
}
