#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define maxN 40001
char name[maxN][5];
using namespace std;
bool cmp(int a,int b){
    return strcmp(name[a],name[b])<0;
}
int main()
{
    int N,K,num,courseid;
    scanf("%d%d",&N,&K);
    vector<int> v[K+1];

    for(int i=0;i<N;i++){
        scanf("%s%d",name[i],&num);
        for(int j=0;j<num;j++){
            scanf("%d",&courseid);
            v[courseid].push_back(i);


        }
    }


    for(int i=1;i<=K;i++){
        printf("%d %d\n",i,v[i].size());
        sort(v[i].begin(),v[i].end(),cmp);
        for(int j=0;j<v[i].size();j++){
            printf("%s\n",name[v[i][j]]);
        }
    }
    return 0;
}
