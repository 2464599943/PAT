#include <iostream>
#include<stdio.h>
#include<algorithm>
#define maxN 110
using namespace std;
int a1[maxN];
int a2[maxN];
int b[maxN];
bool com1(int N){
    for(int i=0;i<N;i++ ){
        if(a1[i]!=b[i])return false;
    }
    return true;
}
bool com2(int N){
    for(int i=0;i<N;i++ ){
        if(a2[i]!=b[i])return false;
    }
    return true;
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a1[i]);
        a2[i]=a1[i];
    }
    for(int i=0;i<N;i++){
        scanf("%d",&b[i]);
    }
    bool result1=false;
    bool result2=false;
    for(int i=2;i<=N;i++){
        sort(a1,a1+i);
        if(result1){
            printf("Insertion Sort\n");
            for(int j=0;j<N;j++){
                if(j==0){
                    printf("%d",a1[j]);
                }else{
                    printf(" %d",a1[j]);
                }
            }
            break;
        }
        result1=com1(N);

    }
    int help;
    if(!result1){
       for(int i=1;i/2<N;i=i*2){
          for(int j=0;j<N;j=j+i){
               help=min(i,N-j);
               sort(a2+j,a2+j+help);
          }
           if(result1){
            printf("Merge Sort\n");
            for(int j=0;j<N;j++){
                if(j==0){
                    printf("%d",a2[j]);
                }else{
                    printf(" %d",a2[j]);
                }
            }
            break;
        }
        result1=com2(N);

       }
    }
    return 0;
}
