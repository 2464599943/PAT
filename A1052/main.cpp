#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct node{
    int address;
    int key;
    int next;
};
bool cmp(node a,node b){
    return a.key<b.key;
}
int main()
{
    int N,address;
    scanf("%d%d",&N,&address);
    vector<node> v;
    map<int,node> m;
    node n;
    for(int i=0;i<N;i++){
        scanf("%d%d%d",&n.address,&n.key,&n.next);
        m[n.address]=n;
    }
    int num=address;
    while(num!=-1){
        n=m[num];
        num=n.next;
        v.push_back(n);
    }
    if(v.size()!=0)
       sort(v.begin(),v.end(),cmp);
    if(v.size()!=0){
    for(int i=0;i<v.size()-1;i++){
        v[i].next=v[i+1].address;
    }
       v[v.size()-1].next=-1;
    }
    if(v.size()!=0){
    printf("%d %05d\n",v.size(),v[0].address);
    for(int i=0;i<v.size()-1;i++){
        printf("%05d %d %05d\n",v[i].address,v[i].key,v[i].next);
    }
     printf("%05d %d %d\n",v[v.size()-1].address,v[v.size()-1].key,v[v.size()-1].next);
    }
    else{
        printf("%d %d\n",0,-1);
    }
    return 0;
}
