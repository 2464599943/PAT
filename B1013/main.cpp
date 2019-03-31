#include <iostream>
#include<stdio.h>
#include<math.h>
#define inf 100000
using namespace std;
int M,N;
bool ifprime(int num){
    if(num==1)return false;
    int half=(int)pow(num*1.0,0.5);
    for(int i=2;i<=half;i++){
        if(num%i==0)return false;
    }
    return true;
}
void handle(){
    int cnt=0;
    int row=0;
    for(int i=1;i<=inf&&cnt<N;i++){
        if(ifprime(i)){
            if(cnt>=M-1){
            if(row==0){
                printf("%d",i);
            }else {
                printf(" %d",i);
            }
            if(row==9){
                printf("\n");
            }
            row=(row+1)%10;
            }
            cnt++;
        }
    }
}
int main()
{
    scanf("%d%d",&M,&N);
    handle();
    return 0;
}
