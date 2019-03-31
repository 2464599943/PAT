#include <iostream>
#include<stdio.h>
#include<set>
#include<map>
#define maxN 1010
using namespace std;
int graph[maxN][maxN];
int help1[maxN];
int help2[maxN];
int main()
{
    int N,M,v1,v2;
    scanf("%d%d",&N,&M);
    fill(help1,help1+maxN,0);
    for(int i=0;i<maxN;i++){
        for(int j=0;j<maxN;j++){
            graph[i][j]=0;
        }
    }
    for(int i=0;i<M;i++){
        scanf("%d%d",&v1,&v2);
        graph[v1][v2]=1;
        help1[v2]++;
    }
    int K,temp;
    scanf("%d",&K);
    int cnt=0;
    for(int i=0;i<K;i++){
        for(int j=1;j<=N;j++){
            help2[j]=help1[j];
        }
        bool result=true;
        for(int j=1;j<=N;j++){
            scanf("%d",&temp);
            if(help2[temp]>0){
                result=false;
            }
            for(int k=1;k<=N;k++){
                if(graph[temp][k]==1){
                help2[k]--;
               }
            }
        }
        if(!result){
            cnt++;
            if(cnt==1){
                printf("%d",i);
            }else{
                printf(" %d",i);
            }
        }
    }
    return 0;
}
