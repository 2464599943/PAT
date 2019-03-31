#include <iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#define inf 100000000
#define maxN 510
using namespace std;
int graph[maxN][maxN];
int timee[maxN][maxN];
bool help[maxN];
int dist[maxN];
int tt[maxN];
int qian1[maxN];
int qian2[maxN];
vector<int> v1;
vector<int> v2;
bool same=true;
int finaldist;
int finalcost;
void Dij1(int s,int v,int N){
    fill(help,help+maxN,false);
    fill(dist,dist+maxN,inf);
    fill(tt,tt+maxN,inf);
    dist[s]=0;
    tt[s]=0;
    for(int i=0;i<N;i++){
        int u=-1;
        int minn=inf;
        for(int j=0;j<N;j++){
            if(!help[j]&&dist[j]!=inf&&dist[j]<minn){
                minn=dist[j];
                u=j;
            }
        }
        if(u==-1)return ;
        help[u]=true;
        for(int j=0;j<N;j++){
            if(!help[j]&&graph[u][j]!=inf){
                if(dist[u]+graph[u][j]<dist[j]){
                    dist[j]=dist[u]+graph[u][j];
                    qian1[j]=u;
                    tt[j]=tt[u]+timee[u][j];
                }else if(dist[u]+graph[u][j]==dist[j]&&tt[j]>tt[u]+timee[u][j]){
                    qian1[j]=u;
                    tt[j]=tt[u]+timee[u][j];
                }
            }
        }
    }
    finaldist=dist[v];
}
void Dij2(int s,int v,int N){
    fill(help,help+maxN,false);
    fill(dist,dist+maxN,inf);
    fill(tt,tt+maxN,inf);
    dist[s]=1;
    tt[s]=0;
    for(int i=0;i<N;i++){
        int u=-1;
        int minn=inf;
        for(int j=0;j<N;j++){
            if(!help[j]&&tt[j]!=inf&&tt[j]<minn){
                minn=tt[j];
                u=j;
            }
        }
        if(u==-1)return ;
        help[u]=true;
        for(int j=0;j<N;j++){
            if(!help[j]&&timee[u][j]!=inf){
                if(tt[u]+timee[u][j]<tt[j]){
                    dist[j]=dist[u]+1;
                    qian2[j]=u;
                    tt[j]=tt[u]+timee[u][j];
                }else if( tt[j]==tt[u]+timee[u][j]&&dist[j]>dist[u]+1){
                    qian2[j]=u;
                    dist[j]=dist[u]+1;
                }
            }
        }
    }
    finalcost=tt[v];
}
void dfs1(int s,int v){
    if(s==v){
        v1.push_back(v);
        return ;
    }
    dfs1(s,qian1[v]);
    v1.push_back(v);
}
void dfs2(int s,int v){
    if(s==v){
        v2.push_back(v);
        return ;
    }
    dfs2(s,qian2[v]);
    v2.push_back(v);
}
void compare(){
    if(v1.size()!=v2.size()){
        same=false;
        return;
    }
    for(int i=0;i<v1.size();i++){
        if(v1[i]!=v2[i]){
            same=false;
            return ;
        }
    }
    same=true;
}
int main()
{
   for(int i=0;i<maxN;i++){
    for(int j=0;j<maxN;j++){
        graph[i][j]=inf;
        timee[i][j]=inf;
    }
   }
    int N,M,V1,V2,one_way,length,ttime,S,D;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d%d%d%d",&V1,&V2,&one_way,&length,&ttime);
        if(one_way==1){
            graph[V1][V2]=min(length,graph[V1][V2]);
            timee[V1][V2]=min(ttime,timee[V1][V2]);
        }else if(one_way==0){
            graph[V1][V2]=min(length,graph[V1][V2]);
            graph[V2][V1]=min(length,graph[V2][V1]);
            timee[V1][V2]=min(ttime,timee[V1][V2]);
            timee[V2][V1]=min(ttime,timee[V2][V1]);
        }
    }
    scanf("%d%d",&S,&D);
    Dij1(S,D,N);
    dfs1(S,D);
    Dij2(S,D,N);
    dfs2(S,D);
    compare();
    if(same){
        printf("Distance = %d; Time = %d: ",finaldist,finalcost);
        for(int i=0;i<v1.size();i++){
            if(i==0){
                printf("%d",v1[i]);
            }else{
                printf(" -> %d",v1[i]);
            }
        }
        printf("\n");
    }else{
        printf("Distance = %d: ",finaldist);
        for(int i=0;i<v1.size();i++){
            if(i==0){
                printf("%d",v1[i]);
            }else{
                printf(" -> %d",v1[i]);
            }
        }
        printf("\n");
        printf("Time = %d: ",finalcost);
         for(int i=0;i<v2.size();i++){
            if(i==0){
                printf("%d",v2[i]);
            }else{
                printf(" -> %d",v2[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
