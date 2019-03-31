#include <iostream>
#include<map>
#include<vector>
#include<math.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct student{
    string id;
    int Gp;
    int Gm;
    int Gf;
    int G;
};
vector<student> v;
map<string,student> m;
pair<string,student> p;
map<string,student>::iterator it;
bool cmp(student a,student b){
    if(a.G!=b.G)return a.G>b.G;
    return a.id<b.id;
}
int main()
{
    int P,M,N,temp;
    string str;
    scanf("%d%d%d",&P,&M,&N);
    student stu;
    for(int i=0;i<P;i++){
        cin>>str;
        scanf("%d",&temp);
        stu.id=str;
        stu.Gp=temp;
        stu.Gf=-1;
        stu.Gm=-1;
        stu.G=-1;
        m[str]=stu;
    }
    for(int i=0;i<M;i++){
         cin>>str;
         scanf("%d",&temp);
        it=m.find(str);
        if(it==m.end()){
            stu.id=str;
            stu.Gm=temp;
            stu.Gp=-1;
            stu.Gf=-1;
            stu.G=-1;
        }else{
            m[str].Gm=temp;
        }
    }
    for(int i=0;i<N;i++){
        cin>>str;
        scanf("%d",&temp);
        it=m.find(str);
        if(it==m.end()){
            stu.id=str;
            stu.Gf=temp;
            stu.Gm=-1;
            stu.Gp=-1;
            stu.G=-1;
        }else{
            m[str].Gf=temp;
        }
    }
    double ttemp;
    for(it=m.begin();it!=m.end();it++){
        p=*it;
        stu=p.second;
        if(stu.Gp<200)continue;
        if(stu.Gm>stu.Gf){
            if(stu.Gf==-1){
                ttemp=0.4*stu.Gm;
            }else{
                ttemp=0.4*stu.Gm+0.6*stu.Gf;
            }
        }else{
            ttemp=stu.Gf;
        }
        stu.G=(int)round(ttemp);
        if(stu.G<60)continue;
        v.push_back(stu);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
       printf("%s %d %d %d %d\n",v[i].id.c_str(),v[i].Gp,v[i].Gm,v[i].Gf,v[i].G);
    }
    return 0;
}
