#include <iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
#define maxN 10010
using namespace std;
struct person{
    int id;
    int estate;
    int area;
};
struct all{
    int id;
    double allestate;
    double allarea;
    int allnum;
};
vector<all> v2;
int bing[maxN];
bool fuzhu[maxN];
vector<person> v[maxN];
map<int,person> m1;
map<int,int> m2;
map<int,person>::iterator it1;
map<int,int>::iterator it2;

bool cmp(all a,all b){
    if(a.allarea!=b.allarea)return a.allarea>b.allarea;
    return a.id<b.id;
}
void Merge(int num,int root){
    int a=num;
    while(num!=bing[num]){
        a=bing[num];
        bing[num]=root;
        num=a;
    }
}

int findroot(int num){
    while(num!=bing[num]){
        num=bing[num];
    }
    return num;
}
void update(int num){
    int a=findroot(num);
    Merge(num,a);
}

int main()
{
    int N,temp1,father,mother,K,root1,root2,root3;
    scanf("%d",&N);
    for(int i=0;i<maxN;i++){
        bing[i]=i;
    }
    int cnt=0;
    person p1;
    p1.estate=0;
    p1.area=0;
    int temp2,temp3,temp4;
    for(int i=0;i<N;i++){
        scanf("%d%d%d%d",&temp1,&father,&mother,&K);
        it2=m2.find(temp1);
        if(it2==m2.end()){
            m2[temp1]=cnt;
            p1.id=temp1;
            p1.area=0;
            p1.estate=0;
            m1[m2[temp1]]=p1;
            cnt++;
        }
        root1=findroot(m2[temp1]);
        if(father!=-1){
           it2=m2.find(father);
           if(it2==m2.end()){
               m2[father]=cnt;
               p1.id=father;
               p1.area=0;
               p1.estate=0;
               m1[m2[father]]=p1;
               cnt++;
           }
            root2=findroot(m2[father]);
            bing[root2]=root1;
            Merge(m2[temp1],root1);
            Merge(m2[father],root1);

        }

         if(mother!=-1){
           it2=m2.find(mother);
           if(it2==m2.end()){
               m2[mother]=cnt;
                p1.id=mother;
                p1.area=0;
                p1.estate=0;
                m1[m2[mother]]=p1;
               cnt++;
           }
            root3=findroot(m2[mother]);
            bing[root3]=root1;
            Merge(m2[temp1],root1);
            Merge(m2[mother],root1);
        }
        for(int j=0;j<K;j++){
            scanf("%d",&temp2);
            it2=m2.find(temp2);
           if(it2==m2.end()){
               m2[temp2]=cnt;
               p1.id=temp2;
               p1.estate=0;
               p1.area=0;
               m1[m2[temp2]]=p1;
               cnt++;
           }
            root3=findroot(m2[temp2]);
            bing[root3]=root1;
            Merge(m2[temp1],root1);
            Merge(m2[temp2],root1);
        }
         scanf("%d%d",&temp3,&temp4);
         m1[m2[temp1]].estate=temp3;
         m1[m2[temp1]].area=temp4;

    }
    for(int i=0;i<cnt;i++){
        update(i);
    }
    fill(fuzhu,fuzhu+maxN,false);
    for(int i=0;i<cnt;i++){
        v[bing[i]].push_back(m1[i]);
    }
    all a;
    for(int i=0;i<cnt;i++){
        if(v[i].size()!=0){
            a.id=v[i][0].id;
            a.allnum=v[i].size();
            a.allarea=0.0;
            a.allestate=0.0;
            for(int j=0;j<v[i].size();j++){
                if(v[i][j].id<a.id){
                    a.id=v[i][j].id;
                }
                a.allarea+=v[i][j].area;
                a.allestate+=v[i][j].estate;
            }
            a.allarea=a.allarea/v[i].size();
            a.allestate=a.allestate/v[i].size();
            v2.push_back(a);
        }
    }
    sort(v2.begin(),v2.end(),cmp);
    printf("%d\n",v2.size());
    for(int i=0;i<v2.size();i++){
        printf("%04d %d %.3lf %.3lf\n",v2[i].id,v2[i].allnum,v2[i].allestate,v2[i].allarea);
    }
    return 0;
}
