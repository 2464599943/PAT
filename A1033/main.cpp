#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<math.h>
#define inf 100000000
using namespace std;
struct station{
    double price;
    double distance;
};
bool cmp(station a,station b){
    return a.distance<b.distance;
}
int main()
{
    double Cmax,D,Davg;
    int N;
    scanf("%lf %lf %lf %d",&Cmax,&D,&Davg,&N);
    station *record=new station[N+1];
    for(int i=0;i<N;i++){
        scanf("%lf %lf",&record[i].price,&record[i].distance);
    }
    record[N].distance=D;
    record[N].price=0.0;
    sort(record,record+N,cmp);
    bool ok=true;
    double distance=0.0;
    double cost=0.0,yuan=Cmax*Davg;
    int countt=0;
    double gas=0.0;
    if(record[0].distance!=0){
        ok=false;
    }
    if(ok){
        while(countt<N){
           double minn=inf;
           int k=-1;
           for(int i=countt+1;i<N+1&&record[i].distance<=record[countt].distance+yuan;i++){
              if(record[i].price<minn){
                 minn=record[i].price;
                 k=i;
                 if(minn<record[countt].price){
                    break;
                 }
              }
           }
           if(k==-1){
              ok=false;
              distance+=yuan;
              break;
           }
           double need=(record[k].distance-record[countt].distance)/Davg;
           if(minn<record[countt].price){
              distance+=record[k].distance-record[countt].distance;
              if(need<=gas){
                gas-=need;
              }else{
                 cost+=(need-gas)*record[countt].price;
                 gas=0.0;
              }
              countt=k;
           }else{
               distance+=(record[k].distance-record[countt].distance);
               cost+=(Cmax-gas)*record[countt].price;
               gas=Cmax-need;
               countt=k;
           }

        }
    }
    if(ok){
        printf("%.2f",cost);
    }
    else{
        printf("The maximum travel distance = %.2f",distance);
    }
    return 0;
}
