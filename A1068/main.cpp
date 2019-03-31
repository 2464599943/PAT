#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define maxN 10010
#define maxM 110
using namespace std;
int dp[maxN][maxM];
int value[maxN];
vector<int> v;
vector<int> r;
int compare(vector<int> a,vector<int> b){
    for(int i=0;i<a.size()&&i<b.size();i++){
        if(a[i]<b[i])return 1;
        else if(a[i]>b[i])return -1;
    }
    if(a.size()<b.size())return 1;
    return -1;
}
void dfs(int i,int j){
    if(i<=1||j<=1){
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            printf("%d ",v[i]);
        }
        printf("\n");
        if(r.size()==0){
            r.assign(v.begin(),v.end());
        }else if(r.size()!=0&&v.size()!=0&&compare(v,r)==1){
            r.clear();
            r.assign(v.begin(),v.end());
        }
    }
    int k=i;
    while(k>=0&&dp[k][j]==1){
        if(dp[k-1][j-value[k]]==1){
            v.push_back(value[k]);
            dfs(k-1,j-value[k]);
            v.pop_back();
        }
         k--;
    }

}
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=N;i++){
        scanf("%d",&value[i]);
    }
    sort(value+1,value+N+1);
    for(int i=1;i<=M;i++){
        dp[1][i]=0;
    }
    for(int i=0;i<=N;i++){
        dp[i][0]=1;
    }
    dp[1][value[1]]=1;
    for(int i=2;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(dp[i-1][j]==1){
                dp[i][j]=1;
            }else if(j-value[i]>=0&&dp[i-1][j-value[i]]==1){
                dp[i][j]=1;
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    if(dp[N][M]==1){
        dfs(N,M);
        for(int i=0;i<r.size();i++){
            if(i==0){
                printf("%d",r[i]);
            }
            else printf(" %d",r[i]);
        }
    }else{
        printf("No Solution\n");
    }
    return 0;
}
