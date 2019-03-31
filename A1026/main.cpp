#include <iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h>
#define maxK 110
using namespace std;
struct customer{
    int hour;
    int minute;
    int second;
    int arrive;
    int play;
    int serve;
    int finish;
    int type;
};
bool isvip[maxK];
bool help[maxK];
int people[maxK];
queue<customer> wan[maxK];
queue<customer> wait;
queue<customer> vipwait;
vector<customer> v;
set<int> s;
set<int>::iterator it;
bool cmp(customer a,customer b){
    return a.arrive<b.arrive;
}
int main()
{
    int N,K,M,ttemp;
    scanf("%d",&N);
    customer cust;
    fill(isvip,isvip+maxK,false);
    fill(help,help+maxK,false);
    fill(people,people+maxK,0);
    int starttime=8*3600;
    int finishtime=21.0*3600;
    for(int i=0;i<N;i++){
        scanf("%d:%d:%d %d %d",&cust.hour,&cust.minute,&cust.second,&cust.play,&cust.type);
        cust.arrive=cust.hour*3600+cust.minute*60+cust.second;
        if(cust.play>120){
            cust.play=120;
        }
        cust.play=cust.play*60;
        v.push_back(cust);
    }

    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        if(v[i].type==0){
            wait.push(v[i]);
        }else{
            vipwait.push(v[i]);
        }
    }
    scanf("%d %d",&K,&M);
    for(int i=0;i<M;i++){
        scanf("%d",&ttemp);
        s.insert(ttemp);
        isvip[ttemp]=true;
    }
    int cnt=0;
    int where=0;
    int real;
    int temp1,temp2,temp3;
    double temp5,temp4;
    while((!wait.empty()||!vipwait.empty())&&cnt<K){
        cnt++;
        where++;
        while(help[where]){
            where++;
        }
        if(!vipwait.empty()&&vipwait.front().arrive<=starttime&&s.size()>0){
             it=s.begin();
                if(it!=s.end()){
                    wan[*it].push(cust);
                    help[*it]=true;
                    real=*it;
                    s.erase(s.begin());
                }
        }else{
        if(!wait.empty()&&!vipwait.empty()){
            if(wait.front().arrive<vipwait.front().arrive){
                cust=wait.front();
                wait.pop();
                cust.serve=max(cust.arrive,starttime);
                cust.finish=cust.serve+cust.play;
                wan[where].push(cust);
                real=where;
                help[where]=true;
            }else{
                cust=vipwait.front();
                vipwait.pop();
                cust.serve=max(cust.arrive,starttime);
                cust.finish=cust.serve+cust.play;
                it=s.begin();
                if(it!=s.end()){
                    wan[*it].push(cust);
                    help[*it]=true;
                    real=*it;
                    s.erase(s.begin());
                }else{
                    wan[where].push(cust);
                    help[where]=true;
                    real=where;
                }
            }
        }else if(wait.empty()&&!vipwait.empty()){
            cust=vipwait.front();
            vipwait.pop();
            cust.serve=max(cust.arrive,starttime);
            cust.finish=cust.serve+cust.play;
            it=s.begin();
            if(it!=s.end()){
                wan[*it].push(cust);
                help[*it]=true;
                real=*it;
                s.erase(s.begin());
            }else{
                wan[where].push(cust);
                help[where]=true;
                real=where;
            }
        }else if(!wait.empty()&&vipwait.empty()){
            cust=wait.front();
            wait.pop();
            cust.serve=max(cust.arrive,starttime);
            cust.finish=cust.serve+cust.play;
            wan[where].push(cust);
            help[where]=true;
            real=where;
        }
        if(wan[real].front().serve<finishtime){
            people[real]++;
            temp1=wan[real].front().serve/3600;
            temp2=(wan[real].front().serve-temp1*3600)/60;
            temp3=wan[real].front().serve-temp1*3600-temp2*60;
            temp4=wan[real].front().serve-wan[real].front().arrive;
            temp4=temp4*1.0;
            temp5=ceil(temp4/60);
            printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",wan[real].front().hour,wan[real].front().minute,wan[real].front().second,temp1,temp2,temp3,temp5);
        }

    }
    }
    customer temp;
    cnt=0;
    while(true){
        int u=-1;
        for(int i=1;i<=K;i++){
            if(u==-1&&wan[i].size()>0){
                u=i;
            }else if(u!=-1&&wan[i].size()>0){
                if(wan[u].front().finish>wan[i].front().finish){
                    u=i;
                }
            }
        }
        if(u==-1){
            break;
        }
        cust=wan[u].front();
        wan[u].pop();
        cnt++;
        if(cnt>N){
            break;
        }
        if(isvip[u]&&!vipwait.empty()&&vipwait.front().arrive<=cust.finish){
            temp=vipwait.front();
            vipwait.pop();
        }else{
            if(!vipwait.empty()&&!wait.empty()){
                if(vipwait.front().arrive<wait.front().arrive){
                    temp=vipwait.front();
                    vipwait.pop();
                }else{
                    temp=wait.front();
                    wait.pop();
                }
            }else if(!vipwait.empty()&&wait.empty()){
                    temp=vipwait.front();
                    vipwait.pop();
            }else if(vipwait.empty()&&!wait.empty()){
                    temp=wait.front();
                    wait.pop();
            }
        }
        temp.serve=max(temp.arrive,cust.finish);
        temp.finish=temp.serve+temp.play;
        wan[u].push(temp);
        if(temp.serve<finishtime){
            people[u]++;
            temp1=temp.serve/3600;
            temp2=(temp.serve-temp1*3600)/60;
            temp3=temp.serve-temp1*3600-temp2*60;
            temp4=temp.serve-temp.arrive;
            temp4=temp4*1.0;
            temp5=ceil(temp4/60);
            printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",temp.hour,temp.minute,temp.second,temp1,temp2,temp3,temp5);
        }
    }
    for(int i=1;i<=K;i++){
        if(i==1){
            printf("%d",people[i]);
        }
       else{
           printf(" %d",people[i]);
       }
    }
    return 0;
}
