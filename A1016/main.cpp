#include <iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct client{
    char name[20];
    int month;
    int date;
    int hour;
    int minute;
    int type;
    int valid;
};
bool cmp(client a,client b){
    if(strcmp(a.name,b.name)!=0)return strcmp(a.name,b.name)==-1;
    else if(a.month!=b.month)return a.month<b.month;
    else if(a.date!=b.date)return a.date<b.date;
    else if(a.hour!=b.hour)return a.hour<b.hour;
    return a.minute<b.minute;
}
int main()
{
    int clock[24];
    int N,day=0;
    for(int i=0;i<24;i++){
        scanf("%d",&clock[i]);
        day+=clock[i]*60;
    }
    scanf("%d",&N);
    client *bill=new client[N];

    char str1[20];
    char str2[10];
    string month;
    string date;
    string hour;
    string minute;
    for(int i=0;i<N;i++){
        scanf("%s",bill[i].name);
        scanf("%s",str1);
        scanf("%s",str2);
        bill[i].month=(str1[0]-'0')*10+str1[1]-'0';
        bill[i].date=(str1[3]-'0')*10+str1[4]-'0';
        bill[i].hour=(str1[6]-'0')*10+str1[7]-'0';
        bill[i].minute=(str1[9]-'0')*10+str1[10]-'0';
        if(strcmp(str2,"on-line")==0)bill[i].type=1;
        else if(strcmp(str2,"off-line")==0)bill[i].type=-1;
        bill[i].valid=1;
    }
    sort(bill,bill+N,cmp);
    strcpy(str1,bill[0].name);
    int money=0,allminute=0,allmoney=0,minutea,minuteb;
    int countt=0;
    for(int i=0;i<N;i++){
        if(strcmp(str1,bill[i].name)==0){
            if(i+1<N&&strcmp(bill[i].name,bill[i+1].name)==0){
                if(bill[i].type==1&&bill[i+1].type==-1){
                     if(countt==0)
                        printf("%s %02d\n",bill[i].name,bill[i].month);
                   printf("%02d:%02d:%02d ",bill[i].date,bill[i].hour,bill[i].minute);
                   printf("%02d:%02d:%02d ",bill[i+1].date,bill[i+1].hour,bill[i+1].minute);
                   minutea=bill[i].date*24*60+bill[i].hour*60+bill[i].minute;
                   minuteb=bill[i+1].date*24*60+bill[i+1].hour*60+bill[i+1].minute;
                   allminute=minuteb-minutea;
                   money=(bill[i+1].date-bill[i].date)*day;
                   if(bill[i].hour==bill[i+1].hour){
                     money+=clock[bill[i].hour]*allminute;
                   }
                   else{
                     money+=(60-bill[i].minute)*clock[bill[i].hour]+bill[i+1].minute*clock[bill[i+1].hour];
                     for(int j=bill[i].hour+1;j<bill[i+1].hour;j++){
                        money+=clock[j]*60;
                     }
                   }
                   allmoney+=money;
                   printf("%d $%.2f\n",allminute,money*0.01);
                   i++;
                   countt++;
                }
            }
        }else{
              if(countt!=0)
                 printf("Total amount: $%.2f\n",allmoney*0.01);
            strcpy(str1,bill[i].name);
            allmoney=0;
            i--;
            countt=0;
        }
    }if(countt!=0)
     printf("Total amount: $%.2f",allmoney*0.01);

    return 0;
}
