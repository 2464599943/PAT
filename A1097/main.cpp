#include <iostream>
#include<map>
#include<vector>
#include<math.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct node{
    int address;
    int key;
    int next;
};

int main()
{
    int N,address;
    scanf("%d %d",&address,&N);
    node n;
    vector<node> v1,v2;
    map<int,node> m1;
    map<int,int> m2;
    map<int,int> ::iterator it;
    for(int i=0;i<N;i++){
        scanf("%d%d%d",&n.address,&n.key,&n.next);
        m1[n.address]=n;
    }
        int num=address;
        int first=1,key;
        while(num!=-1){
            n=m1[num];
            key=abs(n.key);
                it=m2.find(key);
                if(it==m2.end()){
                    v1.push_back(n);
                     m2[key]=1;
                }else{
                    v2.push_back(n);
                    m2[key]++;
                }
            num=n.next;
        }
        for(int i=0;i<v1.size()-1;i++){
            v1[i].next=v1[i+1].address;
        }
        v1[v1.size()-1].next=-1;
        if(v2.size()!=0){
         for(int i=0;i<v2.size()-1;i++){
              v2[i].next=v2[i+1].address;
         }
              v2[v2.size()-1].next=-1;
         }
         for(int i=0;i<v1.size()-1;i++){
            printf("%05d %d %05d\n",v1[i].address,v1[i].key,v1[i].next);
         }
            printf("%05d %d %d\n",v1[v1.size()-1].address,v1[v1.size()-1].key,v1[v1.size()-1].next);
         if(v2.size()!=0){
            for(int i=0;i<v2.size()-1;i++){
               printf("%05d %d %05d\n",v2[i].address,v2[i].key,v2[i].next);
            }
            printf("%05d %d %d\n",v2[v2.size()-1].address,v2[v2.size()-1].key,v2[v2.size()-1].next);
         }

    return 0;
}
