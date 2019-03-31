#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<string.h>
#define maxN 10010
#define inf 100000000
using namespace std;
int graph[maxN][maxN];
bool iftraverse[maxN];
void dfs(int index,int N){
    iftraverse[index]=true;
    for(int i=1;i<=N;i++){
       if(graph[index][i]==1&&!iftraverse[i]){
          dfs(i,N);
       }
    }
}
int dfstraverse(int N){
    int countt=0;
    memset(iftraverse,false,sizeof(iftraverse));
    for(int i=1;i<=N;i++){
        if(!iftraverse[i]){
            countt++;
            dfs(i,N);
        }
    }
    return countt;
}
void all(int N){
    for(int k=1;k<=N;k++){
       for(int i=1;i<=N;i++){
          for(int j=1;j<=N;j++){
            if(graph[i][k]+graph[k][j]<graph[i][j]){
                graph[i][j]=graph[i][k]+graph[k][j];
            }
          }
       }
    }
}
int main()
{
    int N,locatioin1,location2;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
       for(int j=1;j<=N;j++){
           graph[i][j]=inf;
        }
    }
    for(int i=0;i<N-1;i++){
        scanf("%d%d",&locatioin1,&location2);
        graph[locatioin1][location2]=1;
        graph[location2][locatioin1]=1;
    }
    int result=dfstraverse(N);
    set<int> s;
    if(result==1){
        all(N);
        int maxx=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i!=j&&graph[i][j]!=inf&&graph[i][j]>maxx){
                     maxx=graph[i][j];
                }
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i!=j&&graph[i][j]==maxx){
                    s.insert(i);
                    s.insert(j);
                }
            }
        }
        set<int> ::iterator it;
        for(it=s.begin();it!=s.end();it++){
            printf("%d\n",*it);
        }

    }
    else
    {
        printf("Error: %d components",result);
    }
    if(N==1){
        printf("%d\n",1);
    }
    return 0;
}
