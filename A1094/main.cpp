#include <iostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<math.h>
#define maxN 110
using namespace std;
struct node{
    int generation;
    vector<int> v;
};
node a[maxN];
int ans=0;
int g;
void bfs(int N){
    queue<int> q;
    if(N==0){
        ans=0;
        g=0;
        return;
    }
    a[1].generation=1;
    q.push(1);
    int num;
    while(!q.empty()){
        num=q.front();
        q.pop();
        for(int i=0;i<a[num].v.size();i++){
            int who=a[num].v[i];
            a[who].generation=a[num].generation+1;
            q.push(who);
        }
    }
    int help[N+1];
    for(int i=0;i<N+1;i++){
        help[i]=0;
    }
    for(int i=1;i<=N;i++){
        help[a[i].generation]++;
    }
    for(int i=0;i<N+1;i++){
        if(ans<help[i]){
            ans=help[i];
            g=i;
        }
    }
}
int main()
{
    int N,M,K,num,index;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d",&index,&K);
        for(int j=0;j<K;j++){
            scanf("%d",&num);
            a[index].v.push_back(num);
        }
    }
    bfs(N);
    printf("%d %d\n",ans,g);
    return 0;
}
