#include <iostream>
#include<stdio.h>
#define maxN 100010
using namespace std;

int main()
{
    int a[maxN];
    for(int i=0;i<maxN;i++)a[i]=0;
    int N,M,num;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        a[num]++;
    }
    bool ok=false;
    for(int i=1;i<M;i++){
        if(a[i]>=1&&a[M-i]>=1&&i<=M-i){
            if(i==M-i&&a[i]<=1){
                ok=false;
                continue;
            }
            ok=true;
            printf("%d %d",i,M-i);
            break;
        }
    }
    if(!ok){
        printf("No Solution");
    }

    return 0;
}
