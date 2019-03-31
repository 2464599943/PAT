#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define maxN 1100
#define inf 100000000
using namespace std;
int graph[maxN][maxN];
double mindist=0.0;
double avermindist=inf;
int dist2[maxN];
bool help[maxN];
int which=-1;
bool ok=true;
void Dij(int s,int N,int h,int Ds){
    fill(help,help+maxN,false);
    fill(dist2,dist2+maxN,inf);
    dist2[s]=0;
    for(int i=1;i<=N;i++){
        int u=-1;
        int minn=inf;
        for(int j=1;j<=N;j++){
            if(!help[j]&&dist2[j]!=inf&&minn>dist2[j]){
                u=j;
                minn=dist2[j];
            }
        }
        if(u==-1){return;}
        help[u]=true;
        for(int j=1;j<=N;j++){
            if(!help[j]&&graph[u][j]!=inf){
                if(dist2[j]>dist2[u]+graph[u][j]){
                    dist2[j]=dist2[u]+graph[u][j];
                }
            }
        }
    }
    double minhouse=inf*1.0;
    double all=0.0;
    double aver;
    for(int i=1;i<=h;i++){
        if(dist2[i]>Ds){
            ok=false;
            return;
        }
        if(minhouse>dist2[i]){
            minhouse=dist2[i];
        }
        all+=dist2[i];
    }
    ok=true;
    if(minhouse>mindist){
        mindist=minhouse;
        avermindist=all/h;
        which=s;
    }else if(minhouse==mindist){
        aver=all/h;
        if(aver<avermindist){
            avermindist=aver;
            which=s;
        }
    }

}
int main()
{
    int N,M,K,Ds,length,location1,location2;
    scanf("%d%d%d%d",&N,&M,&K,&Ds);
    char gas1[5];
    char gas2[5];
    for(int i=0;i<maxN;i++){
        for(int j=0;j<maxN;j++){
            graph[i][j]=inf;
        }
    }
    int realN=0;
    for(int i=0;i<K;i++){
      scanf("%s %s %d",gas1,gas2,&length);
        if(gas1[0]=='G'){
            location1=gas1[1]-'0';

            if(gas1[2]=='0'){
                location1=location1*10;
            }
            location1+=N;
            realN=max(location1,realN);
        }else{
            location1=atoi(gas1);
        }
        if(gas2[0]=='G'){
            location2=gas2[1]-'0';
            if(gas2[2]=='0'){
                location2=location2*10;
            }
            location2+=N;
            realN=max(location2,realN);
        }else{
            location2=atoi(gas2);
        }
        graph[location1][location2]=length;
        graph[location2][location1]=length;
    }
    for(int i=N+1;i<=N+M;i++){
        Dij(i,N+M,N,Ds);
    }
    if(!ok){
        printf("No Solution\n");
    }
    else{
        which=which-N;
        printf("G%d\n",which);
        printf("%.1f %.1f",mindist,avermindist);
    }
    return 0;
}
