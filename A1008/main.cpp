#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int *a=new int[N+1];
    for(int i=1;i<=N;i++){
        scanf("%d",&a[i]);
    }
    a[0]=0;
    int up=0;
    int down=0;
    for(int i=0;i<N;i++){
        if(a[i+1]-a[i]>0){
            up+=a[i+1]-a[i];
        }else{
            int num=a[i+1]-a[i];
            num=-num;
            down+=num;
        }
    }
    int result=up*6+down*4+N*5;
    printf("%d",result);
    return 0;
}
