#include <iostream>
#include<stdio.h>
#include<map>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string.h>
#define maxN 2020
using namespace std;
struct call{
    int index;
    int all;
};
int graph[maxN][maxN];
bool ifgraph[maxN][maxN];
bool iftraverse[maxN];
int all=0;
int group=0;
int grouppeople=0;
map<string,int> m;
map<int,string> m2;
map<int,call> mm;
map<int,call>::iterator mmit;
pair<int,call> p;
vector<call> v;
call c;
bool cmp(call a,call b){
    return m2[a.index]<m2[b.index];
}
void dfs(int index,int N){
    iftraverse[index]=true;
    for(int i=0;i<N;i++){
        if(graph[index][i]>0&&!ifgraph[index][i]){
            ifgraph[index][i]=true;
            ifgraph[i][index]=true;
            all+=graph[index][i];
            if(!iftraverse[i])
               grouppeople++;
            mmit=mm.find(index);
            if(mmit==mm.end()){
                mm[index].all=graph[index][i];
                mm[index].index=index;
            }else{
                mm[index].all+=graph[index][i];
            }
            mmit=mm.find(i);
            if(mmit==mm.end()){
                mm[i].all=graph[index][i];
                mm[i].index=i;
            }else{
                mm[i].all+=graph[index][i];
            }
            dfs(i,N);
        }
    }
}
void dfstraverse(int N,int K){
    memset(iftraverse,false,sizeof(iftraverse));
    int maxx;
    for(int i=0;i<N;i++){
        if(!iftraverse[i]){
            all=0;
            grouppeople=1;
            dfs(i,N);
            if(all>K&&grouppeople>2){
                group++;
                mmit=mm.begin();
                p=*mmit;
                maxx=p.first;
                for(mmit=mm.begin();mmit!=mm.end();mmit++){
                    p=*mmit;
                    if(mm[maxx].all<mm[p.first].all){
                        maxx=p.first;
                    }
                }
                mm[maxx].all=grouppeople;
                v.push_back(mm[maxx]);

            }
            mm.clear();
        }

    }
    sort(v.begin(),v.end(),cmp);

}
int main()
{
    int N,K,length;
    scanf("%d%d",&N,&K);
    map<string,int>::iterator it1;
    map<string,int>::iterator it2;
    string name1,name2;
    int countt=-1,index1,index2;
    for(int i=0;i<N;i++){
        cin>>name1>>name2>>length;
        it1=m.find(name1);
        it2=m.find(name2);
        if(it1==m.end()){
            countt++;
            m[name1]=countt;
            m2[countt]=name1;
        }
        index1=m[name1];
        if(it2==m.end()){
            countt++;
            m[name2]=countt;
            m2[countt]=name2;

        }
        index2=m[name2];
        graph[index1][index2]+=length;
        graph[index2][index1]+=length;
    }
    for(int i=0;i<=countt;i++){
        for(int j=0;j<=countt;j++){
            ifgraph[i][j]=false;
        }
    }
   dfstraverse(countt+1,K);
   printf("%d\n",group);
   for(int i=0;i<v.size();i++){
     cout<<m2[v[i].index]<<" "<<v[i].all<<endl;
   }

    return 0;
}
