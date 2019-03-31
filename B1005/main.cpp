#include <iostream>
#include<map>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define maxK 110
using namespace std;
int num[maxK];
map<int,bool> m[maxK];
map<int,bool>::iterator it;
vector<int> v;
int main()
{
    int K,temp;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d",&num[i]);
        temp=num[i];
        m[i][temp]=true;
        while(temp!=1){
            if(temp%2==0){
                temp=temp/2;
            }else{
                temp=(3*temp+1)/2;
            }
            m[i][temp]=true;
        }
    }
    for(int i=0;i<K;i++){
        bool result=true;
        for(int j=0;j<K;j++){
            if(i!=j){
                it=m[j].find(num[i]);
                if(it!=m[j].end()){
                    result=false;
                     break;
                }
            }
        }
        if(result){
            v.push_back(num[i]);
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++){
       if(i==0){
        printf("%d",v[i]);
       }else{
           printf(" %d",v[i]);
       }
    }
    return 0;
}
