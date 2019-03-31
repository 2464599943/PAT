#include <iostream>
#include<stdio.h>
#define maxN 10000
using namespace std;
int a[maxN];
int b[maxN];
void handle(int &length){
    int last=0;
    int cnt=1;
    int where=0;
    for(int i=1;i<length;i++){
        if(a[last]==a[i]){
            cnt++;
        }else{
            b[where]=a[last];
            where++;
            b[where]=cnt;
            where++;
            last=i;
            cnt=1;
        }
    }
    b[where]=a[last];
    where++;
    b[where]=cnt;
    where++;
    length=where;
}
int main()
{
    int D,N;
    scanf("%d%d",&D,&N);
    int length=1;
    b[0]=D;
    while(--N){
        for(int i=0;i<length;i++){
            a[i]=b[i];
        }
        handle(length);
    }
    for(int i=0;i<length;i++){
        printf("%d",b[i]);
    }
    return 0;
}
