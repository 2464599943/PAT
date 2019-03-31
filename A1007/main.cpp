#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxK 10010
#define inf 1000000000
int num[maxK];
int dp[maxK];
int qian[maxK];
int main()
{
    int K;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d",&num[i]);
    }
    dp[0]=num[0];
    qian[0]=0;
    for(int i=1;i<K;i++){
        if(dp[i-1]+num[i]>num[i]){
            dp[i]=dp[i-1]+num[i];
            qian[i]=qian[i-1];
        }else{
            dp[i]=num[i];
            qian[i]=i;
        }
    }
    int k=0;
    for(int i=1;i<K;i++){
        if(dp[k]<dp[i]){
            k=i;
        }
    }
    if(dp[k]<0){
        printf("%d %d %d\n",0,num[0],num[K-1]);
    }else{
        printf("%d %d %d\n",dp[k],num[qian[k]],num[k]);
    }

    return 0;
}
