#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxN 15
using namespace std;

int main()
{
    int a,b;
    char help[maxN];
    scanf("%d%d",&a,&b);
    int result=a+b;
    if(result<0){
        printf("-");
        result=-result;
    }
    sprintf(help,"%d",result);
    if(strlen(help)<4){
        for(int i=1;i<strlen(help)+1;i++){
         printf("%c",help[i-1]);
       }
    }else {
         for(int i=1;i<strlen(help)+1;i++){
         printf("%c",help[i-1]);
        if((strlen(help)-i)%3==0&&i!=strlen(help)){
            printf(",");
        }

    }
    }

    return 0;
}
