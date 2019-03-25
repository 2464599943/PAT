#include <iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<string.h>
#include<algorithm>
#define maxN 110
using namespace std;
struct node{
    int generation;
    vector<int> v;
};
node a[maxN];
void bfs(int N){
    a[1].generation=1;
    queue<int> q;
    q.push(1);
    int who,num;
    int maxlevel=1;
    while(!q.empty()){
        who=q.front();
        q.pop();
        for(int i=0;i<a[who].v.size();i++){
            num=a[who].v[i];
            a[num].generation=a[who].generation+1;
            q.push(num);
            maxlevel=max(maxlevel,a[num].generation);
        }
    }
    int help[N+1];
    memset(help,0,sizeof(help));
    for(int i=1;i<=N;i++){
        if(a[i].v.size()==0){
            help[a[i].generation]++;
        }
    }
    for(int i=1;i<maxlevel;i++){
        printf("%d ",help[i]);
    }
    printf("%d",help[maxlevel]);
}
int main()
{
    int N,M,id,K,num;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d %d",&id,&K);
        for(int j=0;j<K;j++){
            scanf("%d",&num);
            a[id].v.push_back(num);
        }
    }
    bfs(N);
    return 0;
}
