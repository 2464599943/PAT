#include <iostream>
#include<stdio.h>
#include<string.h>
#define maxN 110
using namespace std;
int num[maxN];
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }
    int cnt=0;
    M=M%N;
    int where=(N-M)%N;
    while(cnt<N){
        if(cnt==0){
            printf("%d",num[where]);
        }else{
            printf(" %d",num[where]);
        }
        cnt++;
        where=(where+1)%N;
    }
    return 0;
}
