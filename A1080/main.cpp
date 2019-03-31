#include <iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
struct student{
    int GE;
    int GI;
    int all;
    int id;
    int prefer[6];
    int r;
    int admit;
};
bool cmp1(student a,student b){
    if(a.all!=b.all)return a.all>b.all;
    return a.GE>b.GE;
}
bool cmp2(student a,student b){
    if(a.admit!=b.admit)return a.admit<b.admit;
    return a.id<b.id;
}
int main()
{
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    student *record=new student[N];
    int *want=new int[M+1];
    for(int i=0;i<M;i++){
        scanf("%d",&want[i]);
    }
    want[M]=N;
    for(int i=0;i<N;i++){
        scanf("%d%d",&record[i].GE,&record[i].GI);
        for(int j=0;j<K;j++){
            scanf("%d",&record[i].prefer[j]);
        }
        record[i].prefer[K]=M;
        record[i].all=record[i].GE+record[i].GI;
        record[i].id=i;
    }
    sort(record,record+N,cmp1);
    int r=1;
    record[0].r=r;
    int no=0;
    for(int i=1;i<N;i++){
        if(record[i].all==record[i-1].all&&record[i].GE==record[i-1].GE){
            record[i].r=record[i-1].r;
        }else{
            r=i+1;
            record[i].r=r;
        }
    }
    int *m=new int[M+1];
    for(int i=0;i<M+1;i++){
        m[i]=0;
    }
    for(int i=0;i<N;i++){
        if(i>0&&record[i-1].r!=record[i].r){
            for(int p=0;p<M+1;p++){
                want[p]-=m[p];
                m[p]=0;
            }
        }
        for(int j=0;j<=K;j++){
            if(want[record[i].prefer[j]]>0){
                record[i].admit=record[i].prefer[j];
                m[record[i].admit]++;
                break;
            }
        }
    }
    sort(record,record+N,cmp2);
    for(int i=0;i<M+1;i++){
        m[i]=0;
    }
    for(int i=0;i<N;i++){
        m[record[i].admit]++;
    }
    int num=0;
    for(int i=0;i<M;i++){
       if(m[i]==0)printf("\n");
       else{
          printf("%d",record[num].id);
          num++;
          for(int j=1;j<m[i];j++){
            printf(" %d",record[num].id);
            num++;
          }
          printf("\n");
       }
    }

    return 0;
}
