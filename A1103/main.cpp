#include <iostream>
#include<vector>
#include<math.h>
#include<stdio.h>
using namespace std;
vector<int> tempans;
vector<int> ans;
vector<int> help;
int maxSum=-1,K,N,P;
void  init(){
    int temp=0,index=0;
    while(temp<=N){
        help.push_back(temp);
        index++;
        temp=pow(index,P);
    }

}
void dfs(int index,int time,int Tempsum,int FactorSum){
    if(time==K){
        if(Tempsum==N&&FactorSum>maxSum){
            ans=tempans;
            maxSum=FactorSum;
        return;
        }
        return;
    }

    while(index>=1){
        if(Tempsum+help[index]<=N){
            tempans[time]=index;
            dfs(index,time+1,Tempsum+help[index],FactorSum+index);

        }
        if(index==1)return;
        index--;
    }
    return;
}
int main()
{
    scanf("%d%d%d",&N,&K,&P);
    init();
    tempans.resize(K);
    dfs(help.size()-1,0,0,0);
    if(maxSum==-1){
        printf("Impossible\n");
    }else{
        printf("%d =",N);
        for(int i=0;i<ans.size();i++){
            if(i==0){
                printf(" %d^%d",ans[i],P);
            }else{
                printf(" + %d^%d",ans[i],P);
            }
        }
    }
    return 0;
}
