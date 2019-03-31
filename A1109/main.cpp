#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxK 15
#define maxN 10010

struct person{
    char name[15];
    int height;
    int rankk;
};
vector<person>all;
vector<person> rows[maxK];
bool cmp3(person a,person b){
     if(a.height!=b.height)return a.height>b.height;
     return strcmp(a.name,b.name)<0;
}
bool cmp(person a,person b){
    if(a.height!=b.height)return a.height>b.height;
    return strcmp(a.name,b.name)<0;
}
bool cmp2(person a,person b){
    return a.rankk<b.rankk;
}
int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    person p;
    for(int i=0;i<N;i++){
        scanf("%s %d",p.name,&p.height);
        all.push_back(p);
    }
    sort(all.begin(),all.end(),cmp);
    int temp1=N/K;
    int group=0;
    int temp3=N-1;
    for(int i=0;i<all.size();i++){
        group=temp3/temp1;
        temp3--;
        if(group>K-1){
            rows[K-1].push_back(all[i]);
        }else {
            rows[group].push_back(all[i]);
        }
    }
    int fu,temp2;
    for(int i=0;i<K;i++){
        temp1=N;
        fu=1;
        temp2=N;
        for(int j=0;j<rows[i].size();j++){
            rows[i][j].rankk=temp1+fu*j;
            fu=-fu;
        }
        if(rows[i].size()>0)
           sort(rows[i].begin(),rows[i].end(),cmp2);
    }
    for(int i=K-1;i>=0;i--){
        for(int j=0;j<rows[i].size();j++){
            if(j==0){
                printf("%s",rows[i][j].name);
            }else
             printf(" %s",rows[i][j].name);
        }
        printf("\n");
    }
    return 0;
}
