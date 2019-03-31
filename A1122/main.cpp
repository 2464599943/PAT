#include <iostream>
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
#define maxN 210
#define inf 100000000
int graph[maxN][maxN];
int main()
{
    for(int i=0;i<maxN;i++){
        for(int j=0;j<maxN;j++){
            graph[i][j]=inf;
        }
    }
    int N,M,v1,v2;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d",&v1,&v2);
        graph[v1][v2]=1;
        graph[v2][v1]=1;
    }
    int K,num,temp,first1,fin,first;
    scanf("%d",&K);
    map<int,int> m;
    map<int,int>::iterator it;
    for(int i=0;i<K;i++){
        scanf("%d",&num);
        bool result=true;
        if(num<=N){
            result=false;
        }
        m.clear();
        for(int j=0;j<num;j++){
            scanf("%d",&temp);
            if(j==0){
                first1=temp;
                first=temp;
                m[first]=1;
                continue;
            }else if(j==num-1){
                fin=temp;
                if(fin!=first1){
                    result=false;
                }
            }
            if(graph[first][temp]==inf){
                result=false;
            }
            first=temp;
            it=m.find(temp);
            if(it!=m.end()){
                if(j!=num-1){
                    result=false;
                    m[temp]++;
                }
            }else{
                m[temp]=1;
            }

        }
        if(result){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
