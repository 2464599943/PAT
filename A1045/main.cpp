#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#define inf 100000000
#define maxM  210
#define maxL 10010
int colors[maxL];
int help[maxL];
int dp[maxL];
using namespace std;

int main()
{
    int N,M,L,num;
    scanf("%d",&N);
    scanf("%d",&M);
    map<int,int> m;
    map<int,int>::iterator it;
    for(int i=0;i<M;i++){
       scanf("%d",&num);
       m[num]=i;
    }
    scanf("%d",&L);
    for(int i=0;i<L;i++){
        scanf("%d",&colors[i]);
        it=m.find(colors[i]);
        if(it==m.end()){
            help[i]=inf;
        }else{
            help[i]=m[colors[i]];
        }
    }
    int ans=0;
    if(help[0]==inf){
        dp[0]=0;
    }else{
        dp[0]=1;
    }
    if(dp[0]>ans){
      ans=dp[0];
    }
    for(int i=1;i<L;i++){
        if(help[i]==inf){
            dp[i]=dp[i-1];
            if(dp[i]>ans){
              ans=dp[i];
            }
            continue;
        }
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(help[j]<=help[i]&&dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
            }
        }
        if(dp[i]>ans){
            ans=dp[i];
        }
    }
    printf("%d\n",ans);

    return 0;
}
