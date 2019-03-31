#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int temp1,temp2;
    char c;
    int cnt=0;
    do{
       scanf("%d%d",&temp1,&temp2);
       c=getchar();
       if(cnt==0){
          if(temp1==0&&temp2==0){
             printf("%d %d",temp1,temp2);
          }else if(temp2==0&&temp1!=0){
              printf("%d %d",0,0);
          }else{
              printf("%d %d",temp1*temp2,temp2-1);
          }
       }else{
           if(temp1!=0&&temp2==0){

           }else{
               printf(" %d %d",temp1*temp2,temp2-1);
           }
       }
       cnt++;
    }while(c!='\n');
    return 0;
}
