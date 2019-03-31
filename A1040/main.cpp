#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define maxN 1010
int dp[maxN][maxN];
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int ans=1;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<str.size();i++){
        dp[i][i]=1;
        if(i<str.size()-1&&str[i]==str[i+1]){
            dp[i][i+1]=1;
            ans=2;
        }
    }
    for(int i=3;i<=str.size();i++){
        for(int j=0;j+i-1<str.size();j++){
            int k=j+i-1;
            if(str[j]==str[k]&&dp[j+1][k-1]==1){
                dp[j][k]=1;
                ans=i;
            }
        }


    }
    printf("%d\n",ans);
    return 0;
}
