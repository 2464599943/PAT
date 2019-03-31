#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define maxN 1010
int graph[maxN][maxN];
bool iftraverse[maxN];
using namespace std;
void dfs(int index,int N){
    iftraverse[index]=true;
    for(int i=1;i<=N;i++){
        if(graph[index][i]==1&&!iftraverse[i]){
            dfs(i,N);
        }
    }
}
int dfstraverse(int num,int N){
    memset(iftraverse,false,sizeof(iftraverse));
    iftraverse[num]=true;
    int countt=0;
    for(int i=1;i<=N;i++){
        if(!iftraverse[i]){
            countt++;
            dfs(i,N);
        }
    }
    return countt;
}

int main()
{
    int N,M,K,check;
    int location1,location2;
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<M;i++){
        scanf("%d%d",&location1,&location2);
        graph[location1][location2]=1;
        graph[location2][location1]=1;
    }
    int num;
    for(int i=0;i<K;i++){
        scanf("%d",&check);
        num=dfstraverse(check,N);
        printf("%d\n",num-1);
    }
    return 0;
}
