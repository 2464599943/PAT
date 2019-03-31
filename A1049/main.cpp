#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int num1=N,num2,num3=0;
    int result=0;
    int sizee=1;
    while(num1!=0){
        num2=num1%10;
        num1=num1/10;
        if(num2==1){
            result+=(num1*sizee+num3+1);
        }else if(num2>1){
            result+=(num1+1)*sizee;
        }else{
            result+=num1*sizee;
        }
        num3=num3+num2*sizee;
        sizee*=10;
    }
    printf("%d",result);

    return 0;
}
