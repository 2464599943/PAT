#include <iostream>
#include<stdio.h>
#include<vector>
#include<set>
#define maxN 10010
using namespace std;
vector<int> v[maxN];
bool help[maxN];
int height[maxN];
set<int> result;
set<int>::iterator it;
void dfs(int index,int N,int tall){
    help[index]=true;
    height[index]=tall;
    for(int i=0;i<v[index].size();i++){
        if(!help[v[index][i]]){
            dfs(v[index][i],N,tall+1);
        }
    }
}
int dfstraverese(int N){
    fill(help,help+maxN,false);
    fill(height,height+maxN,0);
    int cnt=0;
    for(int i=1;i<=N;i++){
        if(!help[i]){
            cnt++;
            dfs(i,N,0);
        }
    }
    return cnt;
}
void findheight(int N){
    int maxx=0;
    for(int i=1;i<=N;i++){
        if(height[i]>maxx){
            maxx=height[i];
        }
    }
    for(int i=1;i<=N;i++){
        if(height[i]==maxx){
            result.insert(i);
        }
    }
}
void seconddfs(int N){
    it=result.begin();
    fill(height,height+maxN,0);
    fill(help,help+maxN,false);
    dfs(*it,N,0);
}
int main()
{
    int N,v1,v2;
    scanf("%d",&N);
    for(int i=0;i<N-1;i++){
        scanf("%d%d",&v1,&v2);
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    int num=dfstraverese(N);
    if(num==1){
        findheight(N);
        seconddfs(N);
        findheight(N);
        for(it=result.begin();it!=result.end();it++){
            printf("%d\n",*it);
        }

    }else{
        printf("Error: %d components\n",num);
    }
    return 0;
}
