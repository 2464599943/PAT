#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
char A[20];
char B[20];
char DA;
char DB;
char reala[20];
char realb[20];
int main()
{
    scanf("%s %c %s %c",A,&DA,B,&DB);
    int cnta=0,cntb=0;
    for(int i=0;i<strlen(A);i++){
        if(A[i]==DA){
            cnta++;
        }
    }
    if(cnta==0){
        reala[0]='0';
    }
    for(int i=0;i<cnta;i++){
        reala[i]=DA;
    }
    for(int i=0;i<strlen(B);i++){
        if(B[i]==DB){
            cntb++;
        }
    }
    for(int i=0;i<cntb;i++){
        realb[i]=DB;
    }
    if(cntb==0){
        realb[0]='0';
    }
    long long aa,bb;
    sscanf(reala,"%lld",&aa);
    sscanf(realb,"%lld",&bb);
    printf("%lld",aa+bb);
    return 0;
}
