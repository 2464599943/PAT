#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#define inf 100000
using namespace std;
bool Prime[inf];
struct number{
    int prime;
    int exponent;
};
bool ifPrime(int num){
    if(num<=1)return false;
    int jie=(int)pow(num,0.5);
    for(int i=2;i<=jie;i++){
        if(num%i==0)return false;
    }
    return true;
}
void findPrime(){
    for(int i=1;i<inf;i++){
        Prime[i]=ifPrime(i);
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    findPrime();
    number a[15];
    int countt=0,num,where=0;
    for(int i=2;i<inf;i++){
        if(Prime[i]&&N%i==0){
            countt=0;
            num=N;
            while(num%i==0){
                countt++;
                num=num/i;
            }
            a[where].prime=i;
            a[where].exponent=countt;
            where++;

        }
    }
    if(where==0){
        printf("%d=%d",N,N);
    }
    else{
     if(a[0].exponent==1){
        printf("%d=%d",N,a[0].prime);
     }
     else{
        printf("%d=%d^%d",N,a[0].prime,a[0].exponent);
     }
     for(int i=1;i<where;i++){
        if(a[i].exponent==1){
           printf("*%d",a[i].prime);
         }
        else{
           printf("*%d^%d",a[i].prime,a[i].exponent);
         }
      }
    }
    return 0;
}
