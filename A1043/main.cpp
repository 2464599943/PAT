#include <iostream>
#include<stdio.h>
#include<string.h>
#define maxNum 10010
using namespace std;

int main()
{
    int a[maxNum];
    for(int i=0;i<maxNum;i++)a[i]=0;
    int N;
    scanf("%d",&N);
    int *b=new int[N];
    for(int i=0;i<N;i++){
        scanf("%d",&b[i]);
        a[b[i]]++;
    }
    int ii;
    for(ii=0;ii<N;ii++){
        if(a[b[ii]]==1){printf("%d",b[ii]);break;}
    }
    if(ii>=N){
        printf("None");
    }
    return 0;
}
