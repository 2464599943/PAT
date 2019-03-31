#include <iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#include<map>
#define maxN 30
using namespace std;
int tree[maxN];
int help[maxN];
struct node{
    int left;
    int right;
};
struct couple{
    int index;
    int where;
};
int main()
{
    int N;
    scanf("%d",&N);
    char a[10];
    char b[10];
    int index1,index2;
    node n;
    map<int,node> m;
    fill(help,help+maxN,0);
    for(int i=0;i<N;i++){
        scanf("%s %s",a,b);
        if(a[0]=='-'){
            index1=-1;
        }else{
            sscanf(a,"%d",&index1);
            help[index1]++;
        }
        if(b[0]=='-'){
            index2=-1;
        }else{
            sscanf(b,"%d",&index2);
            help[index2]++;
        }
        n.left=index1;
        n.right=index2;
        m[i]=n;
    }
    int root;
    for(int i=0;i<N;i++){
        if(help[i]==0){
            root=i;
            break;
        }
    }
    fill(help,help+maxN,-1);
    help[1]=root;
    queue<couple> q;
    couple c;
    couple c2;
    c.index=root;
    c.where=1;
    q.push(c);
    while(!q.empty()){
        c=q.front();
        q.pop();
        n=m[c.index];
        if(2*c.where<=N){
            help[2*c.where]=n.left;
            if(n.left!=-1){
                c2.index=n.left;
                c2.where=2*c.where;
                q.push(c2);
            }
        }
        if(2*c.where+1<=N){
            help[2*c.where+1]=n.right;
            if(n.right!=-1){
                c2.index=n.right;
                c2.where=2*c.where+1;
                q.push(c2);
            }
        }
    }
    bool result=true;
    for(int i=1;i<=N;i++){
        if(help[i]==-1){
            result=false;
            break;
        }
    }
    if(result){
        printf("YES %d",help[N]);
    }else{
        printf("NO %d",root);
    }

    return 0;
}
