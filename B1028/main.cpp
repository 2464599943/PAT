#include <iostream>
#include<stdio.h>
#define inf 1000000000
using namespace std;
int maxyear=2014,maxmonth=9,maxday=6;
int minyear=2014-200,minmonth=9,minday=6;
int cnt=0;
string maxx;
string minn;
int N,year,month,day;
string temp;
int minnum=inf;
int maxnum=0;
void handle(){
    if(year<maxyear&&year>minyear){
        cnt++;
    }else if(year==maxyear&&month<maxmonth){
        cnt++;
    }else if(year==maxyear&&month==maxmonth&&day<=maxday){
        cnt++;
    }else if(year==minyear&&month>minmonth){
        cnt++;
    }else if(year==minyear&&month==minmonth&&day>=maxday){
        cnt++;
    }else{
        return;
    }
    int now=year*366+month*31+day;
    if(now>maxnum){
        maxnum=now;
        maxx=temp;
    }
    else if(now<minnum){
        minnum=now;
        minn=temp;
    }
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        cin>>temp;
        scanf("%d/%d/%d",&year,&month,&day);
         handle();
    }
    if(maxx!=""&&minn!="")
      cout<<cnt<<" "<<minn<<" "<<maxx<<endl;
    else if(maxx==""&&!(minn=="")){
        cout<<cnt<<" "<<minn<<endl;
    }else if(maxx==""&&minn==""){
        cout<<cnt<<endl;
    }else if(maxx!=""&&minn==""){
        cout<<cnt<<" "<<maxx<<endl;
    }
    return 0;
}
