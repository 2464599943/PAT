#include <iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
#define maxN 10000
using namespace std;
vector<int> v[maxN];
unordered_map<int,bool> m;
unordered_map<int,bool>::iterator it;
struct node{
    int num1;
    int num2;
};
bool cmp(node a,node b){
    if(a.num1!=b.num1)return a.num1<b.num1;
    return a.num2<b.num2;
}
int main()
{
    int N,M;
    string str1,str2;
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        cin>>str1;
        cin>>str2;
        if(str1.size()==str2.size()){
            v[abs(stoi(str1))].push_back(abs(stoi(str2)));
            v[abs(stoi(str2))].push_back(abs(stoi(str1)));
        }
        m[abs(stoi(str1))*maxN+abs(stoi(str2))]=true;
        m[abs(stoi(str2))*maxN+abs(stoi(str1))]=true;
    }
    int K;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
            cin>>str1>>str2;
            vector<node> vv;
         for(int j=0;j<v[abs(stoi(str1))].size();j++){
            for(int k=0;k<v[abs(stoi(str2))].size();k++){
                if(v[abs(stoi(str1))][j]==abs(stoi(str2))||v[abs(stoi(str2))][k]==abs(stoi(str1)))continue;
                it=m.find(v[abs(stoi(str1))][j]*maxN+v[abs(stoi(str2))][k]);
                if(it!=m.end()){
                    vv.push_back(node{v[abs(stoi(str1))][j],v[abs(stoi(str2))][k]});
                }
            }
         }
         sort(vv.begin(),vv.end(),cmp);
         printf("%d\n",vv.size());
         for(int j=0;j<vv.size();j++){
            printf("%04d %04d\n",vv[j].num1,vv[j].num2);
         }
    }
    return 0;
}
