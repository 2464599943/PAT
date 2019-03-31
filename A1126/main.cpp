#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define maxN 510
using namespace std;
int degree[maxN];
int graph[maxN][maxN];
bool help[maxN];
bool connect=true;
void dfs(int v,int N){
    help[v]=true;
    for(int i=1;i<=N;i++){
        if(!help[i]&&graph[v][i]==1){
            dfs(i,N);
        }
    }
}
void dfstraverse(int N){
    int countt=0;
    fill(help,help+maxN,false);
    for(int i=1;i<=N;i++){
        if(!help[i]){
            countt++;
            dfs(i,N);
        }
    }
    if(countt==1){
        connect=true;
    }else{
        connect=false;
    }
}
int main()
{
    int N,M,index1,index2;
    fill(degree,degree+maxN,0);
    for(int i=0;i<maxN;i++){
        for(int j=0;j<maxN;j++){
            graph[i][j]=0;
        }
    }
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d",&index1,&index2);
        degree[index1]++;
        degree[index2]++;
        graph[index1][index2]=1;
        graph[index2][index1]=1;
    }
    int cnt=0;
    for(int i=1;i<=N;i++){
        if(i==1){
            printf("%d",degree[i]);
        }else{
            printf(" %d",degree[i]);
        }
        if(degree[i]%2==1){
            cnt++;
        }
    }
    printf("\n");
    dfstraverse(N);
    if(connect){
        if(cnt==0){
            printf("Eulerian\n");
        }else if(cnt==2){
            printf("Semi-Eulerian\n");
        }else{
            printf("Non-Eulerian\n");
        }
    }else{
        printf("Non-Eulerian\n");
    }
    return 0;
}
