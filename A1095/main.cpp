#include <iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<set>
using namespace std;
struct record{
    char id[10];
    int time;
    int status;
    int valid;
};
bool cmp1(record a,record b){
    if(strcmp(a.id,b.id)!=0)return strcmp(a.id,b.id)<0;
    return a.time<b.time;
}
bool cmp2(record a,record b){
    if(a.time!=b.time)return a.time<b.time;
    return strcmp(a.id,b.id)<0;
}
int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    record *car=new record[N];
    char str[10];
    char type[5];
    for(int i=0;i<N;i++){
        scanf("%s%s%s",car[i].id,str,type);
        car[i].time=((str[0]-'0')*10+(str[1]-'0'))*3600+((str[3]-'0')*10+(str[4]-'0'))*60+
                        (str[6]-'0')*10+(str[7]-'0');
        if(strcmp(type,"in")==0){
            car[i].status=1;
        }else if(strcmp(type,"out")==0){
            car[i].status=-1;
        }
        car[i].valid=1;
    }
    sort(car,car+N,cmp1);
    int maxx=-1;
    set<char *> s;
     set<char *>::iterator it;
    int lei=0;
    for(int i=0;i<N;i++){
        if(i+1<N&&strcmp(car[i].id,car[i+1].id)==0){
            if(car[i].status==1&&car[i+1].status==-1){
                lei+=(car[i+1].time-car[i].time);
                if(lei>maxx){
                   maxx=lei;
                   s.clear();
                    s.insert(car[i].id);
                }else if(lei==maxx){
                    s.insert(car[i].id);
                }
                car[i].valid=1;
                car[i+1].valid=1;
                if(i+2<N&&strcmp(car[i].id,car[i+2].id)!=0){
                    lei=0;
                }
                i=i+1;
            }else{
                car[i].valid=0;
            }
        }else{
            lei=0;
            car[i].valid=0;
        }

    }
     char **a=new char*[s.size()];
     for(int i=0;i<s.size();i++){
        a[i]=new char[10];
     }
     int one=0;
     for(it=s.begin();it!=s.end();it++){
            strcpy(a[one],*it);
            one++;
     }

    sort(car,car+N,cmp2);
    int index=0,time;
    int all=0;
    for(int i=0;i<K;i++){
        scanf("%s",str);
        time=((str[0]-'0')*10+(str[1]-'0'))*3600+((str[3]-'0')*10+(str[4]-'0'))*60+
                        (str[6]-'0')*10+(str[7]-'0');
        int j;
        for(j=index;j<N&&car[j].time<=time;j++){
            if(car[j].valid==1){
                all+=car[j].status;
            }
        }
        index=j;
        printf("%d\n",all);
    }
    int hour=maxx/3600;
    int minute=(maxx-hour*3600)/60;
    int second=maxx-hour*3600-minute*60;
    for(int i=0;i<one;i++){
        printf("%s ",a[i]);
    }
    printf("%02d:%02d:%02d",hour,minute,second);
    return 0;
}
