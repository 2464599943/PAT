#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
bool compare(int *a,int *b,int N){
    bool result=true;
    for(int i=0;i<N;i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}
bool cmp(int a,int b){
    return a<b;
}

int main()
{
    int N;
    scanf("%d",&N);
    int *a=new int[N];
    int *b=new int[N];
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&b[i]);
    }
    int num;
    bool type1=false;
    for(int i=1;i<N;i++){
        num=a[i];
        int j=i-1;
        while(j>=0&&num<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=num;
        if(type1){
            printf("Insertion Sort\n");
            printf("%d",a[0]);
            for(int k=1;k<N;k++){
                printf(" %d",a[k]);
            }
            break;
        }
        type1=compare(a,b,N);
    }
    bool type2=false;
    if(!type1){
         printf("Merge Sort\n");
         for(int i=2;i/2<N;i=i*2){

            for(int j=0;j<N;j=j+i){
                int u=min(N,j+i);
                sort(a+j,a+u);
            }
             if(type2){
                printf("%d",a[0]);
                for(int k=1;k<N;k++){
                     printf(" %d",a[k]);
                }
                 break;
            }
            type2=compare(a,b,N);
         }
    }
    return 0;
}
