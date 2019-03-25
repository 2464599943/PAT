#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define maxN 510
#define inf 1000000000
using namespace std;
int graph[maxN][maxN];
int team[maxN];
int people[maxN];
int dist[maxN];
bool help[maxN];
int num[maxN];
bool  Dij(int s,int v,int N){
    fill(help,help+N,false);
    fill(dist,dist+N,inf);
    fill(num,num+N,0);
    people[s]=team[s];
    num[s]=1;
    dist[s]=0;
    for(int i=0;i<N;i++){
        int u=-1;
        int minn=inf;
        for(int j=0;j<N;j++){
            if(!help[j]&&dist[j]!=inf&&minn>dist[j]){
                minn=dist[j];
                u=j;
            }
        }
        if(u==-1)return false;
        help[u]=true;
        for(int j=0;j<N;j++){
            if(!help[j]&&graph[u][j]!=inf){
                if(graph[u][j]+dist[u]<dist[j]){
                    dist[j]=dist[u]+graph[u][j];
                    num[j]=num[u];
                    people[j]=people[u]+team[j];
                }else if(graph[u][j]+dist[u]==dist[j]){
                    num[j]+=num[u];
                    if(people[u]+team[j]>people[j]){
                        people[j]=people[u]+team[j];
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    int N,M,C1,C2,location1,location2,length;
    scanf("%d%d%d%d",&N,&M,&C1,&C2);
    for(int i=0;i<N;i++){
        scanf("%d",&team[i]);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            graph[i][j]=inf;
        }
    }
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&location1,&location2,&length);
        graph[location1][location2]=length;
        graph[location2][location1]=length;
    }

    Dij(C1,C2,N);
    printf("%d %d\n",num[C2],people[C2]);
    return 0;
}
