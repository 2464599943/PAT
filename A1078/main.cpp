#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#define inf 100000000
using namespace std;
bool ifprime(int num){
    if(num<=1)return false;
    else{
        int sqr=(int)sqrt(1.0*num);
        for(int i=2;i<=sqr;i++){
            if(num%i==0)return false;
        }
    }
    return true;
}
int findnum(int Msize){
    for(int i=Msize;i<inf;i++){
        if(ifprime(i))return i;
    }
    return -1;
}
int main()
{
    int Msize,N;
    scanf("%d%d",&Msize,&N);
    int sizee=findnum(Msize);
    if(sizee!=-1){
        int *a=new int[sizee];
        for(int i=0;i<sizee;i++){
            a[i]=inf;
        }
        int b;
        int countt=0,key;
       for(int i=0;i<N;i++){
            scanf("%d",&b);
            countt=0;
            key=b%sizee;
            while(countt<sizee&&a[key]!=inf){
                countt++;
                key=(b+countt*countt)%sizee;
            }
            if(countt>=sizee){
                if(i<N-1)
                  printf("- ");
                 else
                  printf("-");
            }else{
                a[key]=b;
                if(i<N-1)
                   printf("%d ",key);
                else
                   printf("%d",key);
            }
       }
    }
    return 0;
}
