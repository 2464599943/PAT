#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    int NN=(int)pow(N,0.5);
    int countt=0,maxx=0,num;
    int maxi,maxj;
    for(int i=2;i<=NN;i++){
        if(N%i!=0)continue;
        countt=1;
        num=N/i;
        int j;
        for(j=i+1;j<=NN+1;j++){
            if(num%j==0){
                countt++;
                num=num/j;
            }else break;
        }
        if(countt>maxx){
            maxx=countt;
            maxi=i;
            maxj=j-1;
        }
    }
    if(maxx==0){
        printf("%d\n",1);
        printf("%d",N);
    }
    else{
        printf("%d\n",maxx);
        for(int i=maxi;i<maxj;i++){
            printf("%d*",i);
        }
        printf("%d",maxj);
    }
    return 0;
}
