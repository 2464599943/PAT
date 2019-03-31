#include <iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
struct student{
    char id[6];
    int problem[6];
    int submit;
    int valid;
    int total;
    int never;
};
bool cmp1(student a,student b){
    return strcmp(a.id,b.id)<0;
}
bool cmp2(student a,student b){
    if(a.total!=b.total)return a.total>b.total;
    else if(a.submit!=b.submit)return a.submit>b.submit;
    return strcmp(a.id,b.id)<0;
}
int main()
{
    int N,K,M;
    scanf("%d%d%d",&N,&K,&M);
    student *people=new student[M];
    int score[6];
    for(int i=1;i<=K;i++){
        scanf("%d",&score[i]);
    }
    char user[6];
    int problem,pscore;
    int countt=0;
    for(int i=0;i<M;i++){
        scanf("%s %d %d",user,&problem,&pscore);
        if(pscore==-1){
            pscore=0;
            people[countt].never=0;
        }
        else people[countt].never=1;
        for(int j=1;j<=K;j++){
            people[countt].problem[j]=-1;
        }
        strcpy(people[countt].id,user);
        people[countt].problem[problem]=pscore;
        people[countt].valid=0;
        people[countt].submit=0;
        people[countt].total=0;
        countt++;
    }
    sort(people,people+countt,cmp1);
    for(int i=1;i<countt;i++){
        if(strcmp(people[i].id,people[i-1].id)==0){
            people[i].total+=people[i-1].total;
            people[i].never+=people[i-1].never;
            for(int j=1;j<=K;j++){
                people[i].problem[j]=max(people[i].problem[j],people[i-1].problem[j]);
            }
        }else{
            people[i-1].valid=1;
            for(int j=1;j<=K;j++){
                if(people[i-1].problem[j]!=-1){
                    people[i-1].total+=people[i-1].problem[j];
                    if(people[i-1].problem[j]==score[j]){
                        people[i-1].submit++;
                    }
                }
            }
        }
    }
    people[countt-1].valid=1;
    for(int j=1;j<=K;j++){
        if(people[countt-1].problem[j]!=-1){
            people[countt-1].total+=people[countt-1].problem[j];
            if(people[countt-1].problem[j]==score[j]){
                    people[countt-1].submit++;
            }
        }
    }
    sort(people,people+countt,cmp2);
    int r=1,num=1;
    int last=-1;
    for(int i=0;i<countt;i++){
        if(last==-1&&people[i].valid==1&&people[i].never!=0){
            last=i;
            printf("%d %s %d",r,people[i].id,people[i].total);
            for(int j=1;j<=K;j++){
                if(people[i].problem[j]!=-1){
                    printf(" %d",people[i].problem[j]);
                }
                else{
                    printf(" -");
                }
            }
            printf("\n");
            num++;
            continue;
        }
        if(people[i].valid==1&&people[i].never!=0){
            if(people[last].total!=people[i].total)r=num;
            printf("%d %s %d",r,people[i].id,people[i].total);
            for(int j=1;j<=K;j++){
                if(people[i].problem[j]!=-1){
                    printf(" %d",people[i].problem[j]);
                }
                else{
                    printf(" -");
                }
            }
            printf("\n");
            num++;
            last=i;

        }
    }

    return 0;
}
