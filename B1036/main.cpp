#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
     int N,row,col;
     char a;
     cin>>N;
     cin>>a;
     row=round(N*0.5);
     col=N;
     for(int i=1;i<=row;i++){
        if(i==1||i==row){
           for(int j=1;j<=col;j++){
            printf("%c",a);
           }
        }else{
            printf("%c",a);
            for(int j=1;j<=col-2;j++){
            printf(" ",a);
           }
            printf("%c",a);
        }
        printf("\n");
     }
    return 0;
}
