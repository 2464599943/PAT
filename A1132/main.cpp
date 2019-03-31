#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define maxN 15
int main()
{
    char a[maxN];
    char b[maxN];
    char c[maxN];
    int N,length;
    int num1,num2,num3;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s",a);
        length=strlen(a)/2-1;
        for(int j=0;j<=length;j++){
            b[j]=a[j];
        }
        b[length+1]='\0';
        for(int j=0;j<=length;j++){
            c[j]=a[length+1+j];
        }
        c[length+1]='\0';
        sscanf(b,"%d",&num1);
        sscanf(c,"%d",&num2);
        sscanf(a,"%d",&num3);
        if(num2==0){
            printf("No\n");
        }
        else{
            if(num3%(num1*num2)==0){
               printf("Yes\n");
            }else{
               printf("No\n");
            }
        }


    }
    return 0;
}
