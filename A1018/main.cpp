#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define maxN 510
#define inf 100000000
using namespace std;
int bike[maxN];
int graph[maxN][maxN];
bool help[maxN];
int dist[maxN];
vector<int> qian[maxN];
int allbike[maxN];
int route[maxN];
int need=0;
int remain=0;
bool Dij(int s,int v,int N){
    fill(dist,dist+N+1,inf);
    fill(help,help+N+1,false);

    dist[s]=0;
    for(int i=0;i<N+1;i++){
        int u=-1;
        int minn=inf;
        for(int j=0;j<N+1;j++){
            if(!help[j]&&dist[j]!=inf&&minn>dist[j]){
                minn=dist[j];
                u=j;
            }
        }
        if(u==-1)return false;
        help[u]=true;
        for(int j=0;j<N+1;j++){
            if(!help[j]&&graph[u][j]!=inf){
                if(dist[u]+graph[u][j]<dist[j]){
                    dist[j]=dist[u]+graph[u][j];
                    qian[j].clear();
                    qian[j].push_back(u);
                    allbike[j]=allbike[u]+bike[j];
                }else if(dist[u]+graph[u][j]==dist[j]){
                    qian[j].push_back(u);

                }
            }
        }
    }
    return true;
}
int countt=-1;
int num;
vector<int> temp,road;
int minneed=inf;
int minremain=inf;
void dfs(int s,int v){
    temp.push_back(v);
    if(v==s){
        need=0;
        remain=0;
        for(int i=temp.size()-2;i>=0;i--){
            if(bike[temp[i]]<0){
                if(remain>abs(bike[temp[i]])){
                    remain-=abs(bike[temp[i]]);
                }else{

                    need+=abs(bike[temp[i]])-remain;
                    remain=0;
                }
            }else{
                remain+=bike[temp[i]];

            }

        }
        if(minneed>need){
            minneed=need;
            minremain=remain;
            road.clear();
            road.assign(temp.begin(),temp.end());
        }else if(minneed==need){
            if(minremain>remain){
                minremain=remain;
                road.clear();
                road.assign(temp.begin(),temp.end());
            }
        }
        temp.pop_back();
        return;
    }

    for(int i=0;i<qian[v].size();i++){
        dfs(s,qian[v][i]);
    }
    temp.pop_back();
}
int main()
{
    int Cmax,N,Sp,M,location1,location2,length;
    scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
     int half=Cmax/2,num;
    for(int i=1;i<=N;i++){
        scanf("%d",&num);
        bike[i]=num-half;
    }
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            graph[i][j]=inf;
        }
    }
    for(int i=0;i<M;i++){
        scanf("%d%d%d",&location1,&location2,&length);
        graph[location1][location2]=length;
        graph[location2][location1]=length;
    }
    Dij(0,Sp,N);
    dfs(0,Sp);
    printf("%d ",minneed);
    for(int i=road.size()-1;i>=0;i--){
        if(i==road.size()-1)
            printf("%d",road[i]);
        else
            printf("->%d",road[i]);
    }
    printf(" %d",minremain);
    return 0;
}
