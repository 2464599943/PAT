#include <iostream>
#include<set>
#include<stdio.h>
#define maxN 51
using namespace std;
double calculate(set<int> a,set<int> b){
    int total=a.size();
    int num=0;
    set<int>::iterator it;
    for(it=a.begin();it!=a.end();it++){
        if(b.find(*it)!=b.end())num++;
    }
    total=a.size()+b.size()-num;
    return (double)num/total*100;
}
int main()
{
    int N,M,K,num;
    scanf("%d",&N);
    set<int> s[maxN];
    set<int>::iterator it;

    for(int i=1;i<=N;i++){
        scanf("%d",&M);
        for(int j=0;j<M;j++){
            scanf("%d",&num);
            s[i].insert(num);
        }
    }
    int set1,set2;
    double result;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d%d%%",&set1,&set2);
        result=calculate(s[set1],s[set2]);
        printf("%.1f%%\n",result);
    }
    return 0;
}
