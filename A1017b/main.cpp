#include <iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#define inf 100000000
#define maxK 105
using namespace std;
struct customer{
    int arrive;
    int finish;
    int process;
};
queue<customer> wait;
queue<customer> serve[maxK];
vector<customer> v;
bool cmp(customer a,customer b){
    return a.arrive<b.arrive;
}
int main()
{
    int N,K,temp1,temp2,temp3,temp4;
    scanf("%d%d",&N,&K);
    int starttime=8*60*60;
    int finishtime=17*60*60;
    customer cust;
    for(int i=0;i<N;i++){
        scanf("%d:%d:%d %d",&temp1,&temp2,&temp3,&temp4);
        cust.arrive=temp1*3600+temp2*60+temp3;
        cust.process=temp4*60;
        cust.finish=inf;
        if(cust.arrive<=finishtime){
             v.push_back(cust);
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        wait.push(v[i]);
    }
    int realpeople=wait.size();
    int cnt=0;
    while(!wait.empty()&&cnt<K){
        cust=wait.front();
        wait.pop();
        cust.finish=max(starttime,cust.arrive)+cust.process;
        serve[cnt].push(cust);
        cnt++;
    }
    customer temp;
    double all=0.0;
    while(true){
        int u=-1;
        for(int i=0;i<K;i++){
            if(u==-1&&serve[i].size()>0){
                u=i;
            }else if(u!=-1&&serve[i].size()>0){
                if(serve[u].front().finish>serve[i].front().finish){
                    u=i;
                }
            }
        }
        if(u==-1){
            break;
        }
        cust=serve[u].front();
        serve[u].pop();
        all+=cust.finish-cust.arrive-cust.process;
        if(!wait.empty()){
            temp=wait.front();
            wait.pop();
            temp.finish=max(cust.finish,temp.arrive)+temp.process;
            serve[u].push(temp);
        }
    }
    double num=(all/60)/realpeople;
    printf("%.1f\n",num);
    return 0;
}
