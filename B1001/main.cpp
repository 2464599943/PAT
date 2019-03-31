#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int cnt=0;
    while(N!=1){
        if(N%2==0){
            N=N/2;
            cnt++;
        }else{
            N=(3*N+1)/2;
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
