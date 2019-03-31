#include <iostream>
#include<stdio.h>
#include<map>
#include<stack>
#include<vector>
using namespace std;
struct node{
    int address;
    int key;
    int next;
};
map<int,node> m;
stack<node> s;
stack<node> ss;
vector<node> v;
int main()
{
    int address,N,K;
    scanf("%d%d%d",&address,&N,&K);
    node n;
    for(int i=0;i<N;i++){
        scanf("%d%d%d",&n.address,&n.key,&n.next);
        m[n.address]=n;
    }
    int num=address;
    int cnt=0;
    while(num!=-1){
        if(cnt<K){
            s.push(m[num]);
            cnt++;
            if(cnt==K){
                while(!s.empty()){
                    v.push_back(s.top());
                    s.pop();
                }
                cnt=0;
            }
        }
        num=m[num].next;
    }
    while(!s.empty()){
        ss.push(s.top());
        s.pop();
    }
    while(!ss.empty()){
        v.push_back(ss.top());
        ss.pop();
    }
    for(int i=0;i<v.size();i++){
        if(i==v.size()-1){
            v[i].next=-1;
        }else{
            v[i].next=v[i+1].address;
        }
    }
    for(int i=0;i<v.size();i++){
        if(i!=v.size()-1)
        printf("%05d %d %05d\n",v[i].address,v[i].key,v[i].next);
        else
          printf("%05d %d %d\n",v[i].address,v[i].key,v[i].next);
    }
    return 0;
}
