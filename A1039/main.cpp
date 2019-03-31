#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
struct student{
    char name[10];
    int course;
    int num;
    int left;
    int right;
};
struct record{
    int index;
    char name[10];
    int  number;
    int left;
    int right;
};
bool cmp(student a,student b){
    if(strcmp(a.name,b.name)!=0)return strcmp(a.name,b.name)<0;
    return a.course<b.course;
}
bool cmp2(record a,record b){
    return strcmp(a.name,b.name)<0;

}
bool cmp3(record a,record b){
    return a.index<b.index;
}
int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    int coursei,Ni;
    vector<student> v;
    student stu;
    for(int i=0;i<K;i++){
        scanf("%d%d",&coursei,&Ni);
        for(int j=0;j<Ni;j++){
            scanf("%s",stu.name);
            stu.course=coursei;
            stu.num=1;
            v.push_back(stu);
        }
    }
    sort(v.begin(),v.end(),cmp);
    int first=0;
    int countt=1;
    for(int i=1;i<v.size();i++){
        if(strcmp(v[first].name,v[i].name)==0){
            countt++;
        }else{
            v[first].num=countt;
            v[first].left=first;
            v[first].right=i-1;
            first=i;
            i--;
            countt=0;
        }
    }
    v[first].num=countt;
    v[first].left=first;
    v[first].right=v.size()-1;
    vector<record> vv;
    record r;
    for(int i=0;i<N;i++){
       scanf("%s",r.name);
       r.index=i;
       vv.push_back(r);
    }
    sort(vv.begin(),vv.end(),cmp2);
    int where=0;
    int i=0;
   while(i<vv.size()&&where<v.size()){
        if(vv[i].name[0]==v[where].name[0]){
            bool ok=false;
            for(int j=where;j<v.size()&&v[j].name[0]==vv[i].name[0];j++){
                if(strcmp(vv[i].name,v[j].name)==0){
                    vv[i].number=v[j].num;
                    vv[i].left=v[j].left;
                    vv[i].right=v[j].right;
                    ok=true;
                    break;
                }
            }
            if(!ok){
                vv[i].number=0;
            }
            i++;
        }else if(vv[i].name[0]>v[where].name[0]){
            where++;
        }else{
            vv[i].number=0;
            i++;
        }
    }
    sort(vv.begin(),vv.end(),cmp3);
    for(int i=0;i<vv.size();i++){
        printf("%s %d",vv[i].name,vv[i].number);
        if(vv[i].number!=0){
            for(int j=vv[i].left;j<=vv[i].right;j++){
                printf(" %d",v[j].course);
            }
        }
        printf("\n");
    }
    return 0;
}
