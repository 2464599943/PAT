#include <iostream>
#include<stdio.h>
#include<algorithm>
#define inf 100000000
#define maxN 510
using namespace std;
int graph[maxN][maxN];
int cost[maxN][maxN];
bool help[maxN];
int dist[maxN];
int qian[maxN];
int allcost[maxN];
void Dij(int s,int v,int N){
    fill(help,help+N,false);
    fill(dist,dist+N,inf);
    fill(allcost,allcost+N,0);
    dist[s]=0;
    for(int i=0;i<N;i++){
        int u=-1;
        int minn=inf;
        for(int j=0;j<N;j++){
            if(!help[j]&&dist[j]!=inf&&minn>dist[j]){
                u=j;
                minn=dist[j];
            }
        }
        if(u==-1)return;
        help[u]=true;
        for(int j=0;j<N;j++){
            if(!help[j]&&graph[u][j]!=inf){
                if(dist[u]+graph[u][j]<dist[j]){
                    dist[j]=dist[u]+graph[u][j];
                    allcost[j]=allcost[u]+cost[u][j];
                    qian[j]=u;
                }else if(dist[j]==dist[u]+graph[u][j]){
                    if(allcost[j]>allcost[u]+cost[u][j]){
                        allcost[j]=allcost[u]+cost[u][j];
                        qian[j]=u;
                    }
                }
            }
        }
    }
}
void dfs(int s,int v){
    if(s==v){
        printf("%d ",v);
        return;
    }
    dfs(s,qian[v]);
    printf("%d ",v);
}
int main()
{
    int N,M,S,L,location1,location2,length,consume;
    scanf("%d%d%d%d",&N,&M,&S,&L);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            graph[i][j]=inf;
            cost[i][j]=inf;
        }
    }
    for(int i=0;i<M;i++){
        scanf("%d%d%d%d",&location1,&location2,&length,&consume);
        graph[location1][location2]=length;
        graph[location2][location1]=length;
        cost[location1][location2]=consume;
        cost[location2][location1]=consume;
    }
    Dij(S,L,N);
    dfs(S,L);
    printf("%d %d",dist[L],allcost[L]);
    return 0;
}
