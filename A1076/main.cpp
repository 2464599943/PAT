#include <iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#define maxN 1010
using namespace std;
int graph [maxN][maxN];
bool iftraverse[maxN];
int countt=0;
struct node{
    int index;
    int level;
};
void dfs(int start,int N,int depth,int L){
    if(depth>1&&depth<=L)countt++;
    iftraverse[start]=true;
    for(int i=1;i<=N;i++){
        if(graph[start][i]==1&&!iftraverse[i]){
            dfs(i,N,depth+1,L);
        }
    }
}
void bfs(int start,int N,int L){
    node n;
    node c;
    queue<node> q;
    n.index=start;
    n.level=0;
    q.push(n);
    iftraverse[start]=true;
    int index;
    while(!q.empty()){
        n=q.front();
        q.pop();
        if(n.level>=1&&n.level<=L){
            countt++;
        }
        for(int i=1;i<=N;i++){
            if(graph[n.index][i]==1&&!iftraverse[i]){
                iftraverse[i]=true;
                c.index=i;
                c.level=n.level+1;
                q.push(c);
            }
        }
    }
}
int main()
{
    int N,L,K,num,index;
    scanf("%d%d",&N,&L);
    for(int i=1;i<=N;i++){
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            scanf("%d",&index);
            graph[index][i]=1;
        }
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d",&index);
        memset(iftraverse,false,sizeof(iftraverse));
        countt=0;
        bfs(index,N,L);
        printf("%d\n",countt);

    }
    return 0;
}
