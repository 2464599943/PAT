#include <iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#define maxN 100010
using namespace std;
vector<int> v[maxN];
double ans=0.0;
int in=0;
void dfs(int depth,int index,double P,double r){
    double price=0.0;
    if(v[index].size()==0){
        price=P*pow(1+0.01*r,depth);
        if(price>ans){
            ans=price;
            in=1;
        }else if(price==ans){
            in++;
        }
        return ;
    }
    for(int i=0;i<v[index].size();i++){
        dfs(depth+1,v[index][i],P,r);
    }
}
int main()
{
    int N,num,root;
    double P,r;
    scanf("%d %lf %lf",&N,&P,&r);
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        if(num!=-1){
            v[num].push_back(i);
        }else{
            root=i;
        }
    }
    dfs(0,root,P,r);
    printf("%.2f %d",ans,in);
    return 0;
}
