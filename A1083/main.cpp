#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct student{
    char name[11];
    char id[11];
    int grade;
};
bool cmp(student a,student b){
    if(a.grade!=b.grade)return a.grade>b.grade;
    return strcmp(a.id,b.id)<0;
}

int main()
{
    int N;
    scanf("%d",&N);
    student *record=new student[N];
    for(int i=0;i<N;i++){
        scanf("%s%s%d",record[i].name,record[i].id,&record[i].grade);
    }
    sort(record,record+N,cmp);
    int small,big;
    scanf("%d%d",&small,&big);
    int countt=0;
    for(int i=0;i<N;i++){
        if(record[i].grade>=small&&record[i].grade<=big){
            countt++;
            printf("%s %s\n",record[i].name,record[i].id);
        }
    }
    if(countt==0){
        printf("NONE");
    }
    return 0;
}
