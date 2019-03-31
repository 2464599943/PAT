#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int getid(char id[5]){
    int result=0;
    for(int i=0;i<3;i++){
        result=result*26+(id[i]-'A');
    }
    result=result*10+(id[3]-'0');
    return result;
}
int main()
{
    int N,K,coursei,Ni,id;
    scanf("%d%d",&N,&K);
    char name[5];
    int M=26*26*26*10+1;
    vector<int> v[M];
    for(int i=0;i<K;i++){
        scanf("%d%d",coursei,Ni);
        for(int j=0;j<Ni;j++){
            scanf("%s",name);
            id=getid(name);
            v[id].push_back(coursei);
        }
    }
    for(int i=0;i<N;i++){
        scanf("%s",name);
        id=getid(name);
        printf("%s %d",name,v[id].size());
        if(v[id].size()!=0){
            sort(v[id].begin(),v[id].end());
            for(int j=0;j<v[id].size();j++){
                printf(" %d",v[id][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
