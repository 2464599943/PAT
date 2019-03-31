#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int temp,record;
    bool result=true;
    for(int i=0;i<=9;i++){
        scanf("%d",&temp);
        if(i==0&&temp!=0){
            record=temp;
            result=false;
        }else if(i!=0&&temp!=0&&!result){
            printf("%d",i);
            temp--;
            for(int j=1;j<=record;j++){
                printf("%d",0);
            }
            for(int j=1;j<=temp;j++){
                printf("%d",i);
            }
            result=true;

        }else if(i!=0&&temp!=0&&result){
            for(int j=1;j<=temp;j++){
                printf("%d",i);
            }
        }
    }
    return 0;
}
