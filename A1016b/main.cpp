#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<map>
#define maxN 1010
using namespace std;
struct client{
    string name;
    int month;
    int date;
    int hour;
    int minute;
    int time;
    int type;
};
vector<client> v;
map<string,vector<client> >m;
map<string,vector<client> >::iterator it;
pair<string,vector<client> >p;
int cclock[30],day;
bool cmp(client a,client b){
    if(a.name!=b.name)return a.name<b.name;
    return a.time<b.time;

}
double help(client a){
    int result=0;
    result+=day*a.date;
    for(int i=0;i<a.hour;i++){
        result+=cclock[i]*60;
    }
    result+=cclock[a.hour]*a.minute;
    return result*0.01;
}
double calucate(client a,client b){
    double num1=0;
    double num2=0;
    num1=help(a);
    num2=help(b);
    return num2-num1;
}
int main()
{
    int N;
    for(int i=0;i<24;i++){
        scanf("%d",&cclock[i]);
        day+=cclock[i]*60;
    }
    scanf("%d",&N);
    string str;
    client c;
    for(int i=0;i<N;i++){
        cin>>c.name;
        scanf("%d:%d:%d:%d",&c.month,&c.date,&c.hour,&c.minute);
        c.time=c.date*24*60+c.hour*60+c.minute;
        cin>>str;
        if(str=="on-line")c.type=1;
        else if(str=="off-line")c.type=-1;
        v.push_back(c);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<v.size();i++){

        if(v[i-1].name==v[i].name){
            if(v[i-1].type==1&&v[i].type==-1){
                m[v[i-1].name].push_back(v[i-1]);
                m[v[i].name].push_back(v[i]);
            }

        }
    }
    vector<client> vv;
    double all=0.0;
    double cost;
    for(it=m.begin();it!=m.end();it++){
        p=*it;
        vv=p.second;
        str=p.first;
        printf("%s %02d\n",str.c_str(),vv[0].month);
        all=0.0;
        for(int i=1;i<vv.size();i=i+2){
            cost=calucate(vv[i-1],vv[i]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",vv[i-1].date,vv[i-1].hour,vv[i-1].minute,vv[i].date,vv[i].hour,vv[i].minute,vv[i].time-vv[i-1].time,cost);
            all+=cost;
        }
        printf("Total amount: $%.2f\n",all);
    }


    return 0;
}
