#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<map>
#define inf 100000000
#define maxN 210
using namespace std;
int cost[maxN][maxN];
int happiness[maxN];
bool help[maxN];
int num[maxN];
int qian[maxN];
int parent[maxN];
int all[maxN];
int dist[maxN];
map<string,int> m1;
map<int,string> m2;
void Dij(int s,int v,int N){
    fill(help,help+N,false);
    fill(num,num+N,0);
    fill(qian,qian+N,0);
    fill(dist,dist+N,inf);
    fill(all,all+N,0);
    dist[s]=0;
    num[s]=1;
    for(int i=0;i<N;i++){
        int u=-1;
        int minn=inf;
        for(int j=0;j<N;j++){
            if(!help[j]&&dist[j]!=inf&&dist[j]<minn){
                minn=dist[j];
                u=j;
            }
        }
        help[u]=true;
        for(int j=0;j<N;j++){
            if(!help[j]&&cost[u][j]!=inf){
                if(dist[j]>dist[u]+cost[u][j]){
                    dist[j]=dist[u]+cost[u][j];
                    num[j]=num[u];
                    qian[j]=qian[u]+1;
                    all[j]=all[u]+happiness[j];
                    parent[j]=u;
                }else if(dist[j]==dist[u]+cost[u][j]){
                    num[j]+=num[u];
                    double temp1=all[j]/qian[j];
                    double temp2=(all[u]+happiness[j])/(qian[u]+1);
                    if(all[u]+happiness[j]>all[j]){
                        qian[j]=qian[u]+1;
                        all[j]=all[u]+happiness[j];
                        parent[j]=u;
                    }
                    else if(all[u]+happiness[j]==all[j]&&temp1<temp2){
                        qian[j]=qian[u]+1;
                        parent[j]=u;
                    }
                }
            }
        }
    }
}
void dfs(int s,int v){
    if(s==v){
        printf("%s",m2[v].c_str());
        return;
    }
    dfs(s,parent[v]);
    printf("->%s",m2[v].c_str());
}
int main()
{
    int N,K,root,dest,happy,consume;
   string city,city2;
   string another="ROM";
    map<string,int> ::iterator it1;
    int countt=0;
    scanf("%d %d",&N,&K);
    cin>>city;
    it1=m1.find(city);
    if(it1==m1.end()){
        m1[city]=countt;
        m2[countt]=city;
        countt++;
    }
    root=m1[city];
    it1=m1.find(another);
    if(it1==m1.end()){
        m1[another]=countt;
        m2[countt]=another;
        countt++;

    }
    dest=m1[another];
    for(int i=0;i<N-1;i++){
            cin>>city;
        scanf("%d",&happy);
        it1=m1.find(city);
        if(it1==m1.end()){
            m1[city]=countt;
            m2[countt]=city;
            countt++;
        }
        happiness[m1[city]]=happy;
    }
    int num1,num2;
    for(int i=0;i<countt;i++){
        for(int j=0;j<countt;j++){
            cost[i][j]=inf;
        }
    }
    for(int i=0;i<K;i++){
        cin>>city>>city2;
        scanf("%d",&consume);
        num1=m1[city];
        num2=m1[city2];
        cost[num1][num2]=min(consume,cost[num1][num2]);
        cost[num2][num1]=min(consume,cost[num2][num1]);
    }
    Dij(root,dest,countt);
    printf("%d %d %d %d\n",num[dest],dist[dest],all[dest],all[dest]/qian[dest]);
    dfs(root,dest);
    return 0;
}
