#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
#define maxN 100010
#define inf 1000000000
int num[maxN];
int help[maxN];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    int N;
    scanf("%d",&N);
    int zeros=0;
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
        if(num[i]!=0){
            zeros++;
        }
    }
    sort(num,num+N,cmp);
    map<int,int> m;
    int result=0;
    m[num[0]]=0;
    if(num[N-1]==0){
        num[N]=zeros-1;
        sort(num,num+N+1,cmp);
    }
    else{
        num[N]=min(num[N-1]-1,N);
    }
    int last=0;
    for(int i=1;i<N+1;i++){
        if(num[last]!=num[i]){
            m[num[i]]=i;
            last=i;
        }else{
            m[num[i]]=m[num[last]];
        }
    }
    bool ok=false;
    for(int i=1;i<N+1;i++){
        if(m[num[i]]>=num[i]){
            for(int j=num[i-1]-1;j>=num[i];j--){
                if(m[num[i]]>=j){
                   result=j;
                   ok=true;
                   break;
                }
            }
            if(ok)break;
        }
    }

    printf("%d\n",result);
    return 0;
}
