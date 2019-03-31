#include <iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct school{
    string code;
    int A;
    int B;
    int T;
    int tws;
    int ns;
    int r;
};
map<string,school> m;
map<string,school>::iterator it;
pair<string,school> p;
vector<school> v;
bool cmp(school a,school b){
    if(a.tws!=b.tws)return a.tws>b.tws;
    else if(a.ns!=b.ns)return a.ns<b.ns;
    return a.code<b.code;
}
int main()
{
    int N,score;
    scanf("%d",&N);
    char id[10];
    string str;
    for(int i=0;i<N;i++){
        scanf("%s %d",id,&score);
        cin>>str;
        transform(str.begin(),str.end(),str.begin(),::tolower);
        it=m.find(str);
        if(it==m.end()){
            m[str].code=str;
            m[str].A=0;
            m[str].B=0;
            m[str].T=0;
            m[str].ns=1;
        }else{
            m[str].ns++;
        }
        if(id[0]=='A'){
            m[str].A+=score;
        }else if(id[0]=='B'){
            m[str].B+=score;
        }else if(id[0]=='T'){
            m[str].T+=score;
        }
    }
    double all=0.0;
    school sch;
    for(it=m.begin();it!=m.end();it++){
        p=*it;
        sch=p.second;
        all=sch.A+sch.T*1.5+sch.B/(1.5);
        sch.tws=(int)all;
        v.push_back(sch);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        if(i==0){
            v[i].r=1;
        }else{
            if(v[i].tws==v[i-1].tws){
                v[i].r=v[i-1].r;
            }else{
                v[i].r=i+1;
            }
        }
    }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++){
        printf("%d %s %d %d\n",v[i].r,v[i].code.c_str(),v[i].tws,v[i].ns);
    }
    return 0;
}
