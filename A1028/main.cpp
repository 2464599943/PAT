#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct student{
    char id[10];
    char name[10];
    int grade;
};
bool cmp1(student a,student b){
    return strcmp(a.id,b.id)<0;
}
bool cmp2(student a,student b){
    if(strcmp(a.name,b.name)!=0)return strcmp(a.name,b.name)<0;
    return strcmp(a.id,b.id)<0;
}
bool cmp3(student a,student b){
    if(a.grade!=b.grade)return a.grade<b.grade;
    return strcmp(a.id,b.id)<0;
}
int main()
{
    int N,C;
    scanf("%d%d",&N,&C);
    student *record=new student[N];
    for(int i=0;i<N;i++){
        scanf("%s%s%d",record[i].id,record[i].name,&record[i].grade);
    }
    switch(C){
    case 1:
        sort(record,record+N,cmp1);
        break;
    case 2:
        sort(record,record+N,cmp2);
        break;
    case 3:
        sort(record,record+N,cmp3);
        break;
    default:
        break;
    }
    for(int i=0;i<N;i++){
        printf("%s %s %d\n",record[i].id,record[i].name,record[i].grade);
    }
    return 0;
}
