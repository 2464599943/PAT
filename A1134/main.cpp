#include <iostream>
#include<vector>
#include<map>
#include<stdio.h>
using namespace std;
struct edge{
    int v1;
    int v2;
};
vector<edge> v;
map<int,bool> m;
map<int,bool> ::iterator it1;
map<int,bool>::iterator it2;
int main()
{
    int N,M,temp1,temp2;
    scanf("%d%d",&N,&M);
    edge e;
    for(int i=0;i<M;i++){
        scanf("%d%d",&temp1,&temp2);
        e.v1=temp1;
        e.v2=temp2;
        v.push_back(e);
    }
    int K,num;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        m.clear();
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            scanf("%d",&temp1);
            m[temp1]=false;
        }
        bool result=true;
        for(int j=0;j<v.size();j++){
            it1=m.find(v[j].v1);
            it2=m.find(v[j].v2);
            if(it1==m.end()&&it2==m.end()){
                result=false;
                break;
            }
        }
        if(result){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
