#include <iostream>
#include<stdio.h>
#include<queue>
#include<map>
#define maxN 25
#define inf 100000000
using namespace std;
struct customer{
    int id;
    int finish;
    int process;
};
queue<customer> qwait;
queue<customer> q[maxN];
map<int,customer> m;
int main()
{
    int N,M,K,Q,temp;
    scanf("%d%d%d%d",&N,&M,&K,&Q);
    customer cust;
    int start=8*60;
    int finally=17*60;
    for(int i=1;i<=K;i++){
        scanf("%d",&temp);
        cust.id=i;
        cust.process=temp;
        if(i<=N){
            cust.finish=start+temp;
        }else{
            cust.finish=inf;
        }
        qwait.push(cust);
    }
    int minn=0;
    int cnt=0;
    int where=0;
    while(!qwait.empty()&&cnt<N*M){
        cnt++;
        cust=qwait.front();
        qwait.pop();
        q[where].push(cust);
        where=(where+1)%N;
    }
    bool allempty=false;
    customer c1,c2;
    while(!allempty){
        int u=-1;
        for(int i=0;i<N;i++){
            if(u==-1&&q[i].size()>0){
                u=i;
            }else if(u!=-1&&q[i].size()>0){
                c2=q[i].front();
                c1=q[u].front();
                if(c1.finish>c2.finish){
                    u=i;
                }
            }
        }
        if(u==-1){
            allempty=true;
            break;
        }
        c1=q[u].front();
        q[u].pop();
        m[c1.id]=c1;
        if(!qwait.empty()){
           c2=qwait.front();
           qwait.pop();
           q[u].push(c2);
        }
        if(!q[u].empty()){
            q[u].front().finish=c1.finish+q[u].front().process;

        }
    }
    int hour;
    int minute;
    int time1,time2;
    for(int i=0;i<Q;i++){
        scanf("%d",&temp);
        c1=m[temp];
        time1=c1.finish-c1.process;
        time2=c1.finish;
        if(time1>=finally){
            printf("Sorry\n");
        }else{
            hour=time2/60;
            minute=time2-hour*60;
            printf("%02d:%02d\n",hour,minute);
        }
    }
    return 0;
}
