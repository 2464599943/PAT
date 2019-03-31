#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define maxN 110
using namespace std;
struct node{
    int W;
    vector<int> v;
    vector<int> parent;
    int all;
};
node a[maxN];
void dfs(int index){
    if(a[index].v.size()==0){
        a[index].parent.push_back(a[index].W);
        return;
    }
    int who;
    for(int i=0;i<a[index].v.size();i++){
        who=a[index].v[i];
        a[who].all=a[index].all+a[who].W;
        a[who].parent.assign(a[index].parent.begin(),a[index].parent.end());
        a[who].parent.push_back(a[index].W);
        dfs(who);
    }
}
bool cmp(vector<int> a,vector<int> b){
    int i;
    for(i=0;i<a.size()&&i<b.size();i++){
        if(a[i]!=b[i])return a[i]>b[i];
    }
    return a.size()<b.size();
}
void findweight(int S,int N){
    vector<vector<int> > com;
    for(int i=0;i<N;i++){
        if(a[i].v.size()==0&&a[i].all==S){
            com.push_back(a[i].parent);
        }
    }
    sort(com.begin(),com.end(),cmp);
    for(int i=0;i<com.size();i++){
        for(int j=0;j<com[i].size()-1;j++){
            printf("%d ",com[i][j]);
        }
        printf("%d\n",com[i][com[i].size()-1]);
    }
}
int main()
{
    int N,M,S,id,K,num;
    scanf("%d%d%d",&N,&M,&S);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i].W);
    }
    a[0].all=a[0].W;
    for(int i=0;i<M;i++){
        scanf("%d%d",&id,&K);
        for(int j=0;j<K;j++){
            scanf("%d",&num);
            a[id].v.push_back(num);
        }
    }
    dfs(0);
    findweight(S,N);
    return 0;
}
