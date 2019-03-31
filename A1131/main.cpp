#include <iostream>
#include<stdio.h>
#include<vector>
#include<unordered_map>
#define maxNN 10000
#define inf 100000000
using namespace std;

vector<int> v[maxNN];
unordered_map<int,int> m;
int mincnt=inf,mintranfer=inf;
int start,dest;
bool visit[maxNN];
vector<int> temppath,path;
int tranfer(vector<int> a){
    int temp=-1,preline=0;
    for(int i=1;i<a.size();i++){
        if(m[a[i-1]*maxNN+a[i]]!=preline){
            temp++;
        }
        preline=m[a[i-1]*maxNN+a[i]];
    }
    return temp;
}
void dfs(int s,int vv,int height){
    if(s==vv&&((mincnt>height)||(mincnt==height&&mintranfer>tranfer(temppath)))){
           path=temppath;
           mincnt=height;
           mintranfer=tranfer(temppath);
           return;
       }
       if(s==vv){
         return;
       }
       for(int i=0;i<v[s].size();i++){
           if(!visit[v[s][i]]){
               visit[v[s][i]]=true;
               temppath.push_back(v[s][i]);
               dfs(v[s][i],vv,height+1);
               visit[v[s][i]]=false;
               temppath.pop_back();
           }
       }
}
int main()
{
    int N,M,pre,temp;
    scanf("%d",&N);
    fill(visit,visit+maxNN,false);
    for(int i=1;i<=N;i++){
        scanf("%d%d",&M,&pre);
        for(int j=1;j<M;j++){
            scanf("%d",&temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            m[pre*maxNN+temp]=i;
            m[temp*maxNN+pre]=i;
            pre=temp;
        }
    }
    int K;
    scanf("%d",&K);
    for(int j=0;j<K;j++){
        scanf("%d %d",&start,&dest);
        visit[start]=true;
        path.clear();
        temppath.clear();
        temppath.push_back(start);
        mincnt=inf;
        mintranfer=inf;
        dfs(start,dest,0);
        visit[start]=false;
        int preline,last=0;
        printf("%d\n",mincnt);
        for(int i=1;i<path.size();i++){
            if(i==1){
                preline=m[path[i-1]*maxNN+path[i]];
                last=0;
            }else if(preline!=m[path[i-1]*maxNN+path[i]]){
                printf("Take Line#%d from %04d to %04d.\n",preline,path[last],path[i-1]);
                preline=m[path[i-1]*maxNN+path[i]];
                last=i-1;
            }
        }
        printf("Take Line#%d from %04d to %04d.\n",preline,path[last],dest);

    }
    return 0;
}
