#include <iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct node{
    int address;
    int key;
    int next;
    int index;
};
map<int,node> m;
vector<node> v[3];
int main()
{
    int address,N,K,temp1,temp2,temp3;
    scanf("%d%d%d",&address,&N,&K);
    node n;
    for(int i=0;i<N;i++){
        scanf("%d%d%d",&temp1,&temp2,&temp3);
        n.address=temp1;
        n.key=temp2;
        n.next=temp3;
        m[temp1]=n;
    }
    int num=address;
    int cnt=0;
    while(num!=-1){
        m[num].index=cnt;
        if(m[num].key<0){
            v[0].push_back(m[num]);
        }else if(m[num].key>=0&&m[num].key<=K){
            v[1].push_back(m[num]);
        }else{
            v[2].push_back(m[num]);
        }
        cnt++;
        num=m[num].next;
    }
    for(int i=0;i<v[1].size();i++){
        v[0].push_back(v[1][i]);
    }
     for(int i=0;i<v[2].size();i++){
        v[0].push_back(v[2][i]);
    }
    for(int i=0;i<v[0].size();i++){
        if(i<v[0].size()-1){
            v[0][i].next=v[0][i+1].address;
        }else{
            v[0][i].next=-1;
        }
    }
    for(int i=0;i<v[0].size();i++){
        if(i<v[0].size()-1){
           printf("%05d %d %05d\n",v[0][i].address,v[0][i].key,v[0][i].next);
        }else{
             printf("%05d %d %d\n",v[0][i].address,v[0][i].key,v[0][i].next);
        }
    }
    return 0;
}
