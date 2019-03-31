#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int N,temp;
    char c;
    cin>>N;
    cin>>c;
    temp=N-1;
    int index;
    for(index=1;index<=1000;index++){
        temp-=2*(2*index+1);
        if(temp<0){
            break;
        }
    }

    temp=temp+2*(2*index+1);
    index--;
   for(int i=index;i>=0;i--){
       for(int j=index-i;j>=1;j--){
          printf(" ");
       }
        for(int j=1;j<=2*i+1;j++){
            printf("%c",c);
        }

       printf("\n");
   }
   for(int i=1;i<=index;i++){
       for(int j=index-i;j>=1;j--){
          printf(" ");
       }
        for(int j=1;j<=2*i+1;j++){
            printf("%c",c);
        }

       printf("\n");
   }
   printf("%d",temp);
    return 0;
}
