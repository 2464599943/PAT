#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int A1=0,A2=0,A3=0,A5=-1;
    double A4=0.0;
    int N,temp;
    int fuhao=1,cnt2=0,cnt4=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        if(temp%5==0){
            if(temp%2==0){
                A1+=temp;
            }
        }else if(temp%5==1){
            cnt2++;
            A2+=temp*fuhao;
            fuhao=-fuhao;
        }else if(temp%5==2){
            A3++;
        }else if(temp%5==3){
            cnt4++;
            A4+=temp;
        }else if(temp%5==4){
            if(A5<temp){
                A5=temp;
            }
        }
    }
    if(A1==0){
        printf("N");
    }else{
        printf("%d",A1);
    }
    if(cnt2==0){
        printf(" N");
    }else{
        printf(" %d",A2);
    }
    if(A3==0){
        printf(" N");
    }else{
        printf(" %d",A3);
    }
    if(cnt4==0){
        printf(" N");
    }else{
        double result=(double)A4/cnt4;
        printf(" %.1f",result);
    }
    if(A5==-1){
        printf(" N");
    }else{
        printf(" %d",A5);
    }
    return 0;

}
