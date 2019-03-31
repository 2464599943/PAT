#include <iostream>
#include<map>
#include<set>
#include<stdio.h>
using namespace std;
#define maxN 50010
set<int> s[maxN];
map<int,int> m;
map<int,int>::iterator it;
set<int>::iterator sit;
int main()
{
    int N,K,query;
    int maxx=1,cnt;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%d",&query);
        if(i==0){
            m[query]=1;
            s[1].insert(query);
            maxx=1;
            continue;
        }
        printf("%d:",query);
        cnt=0;
        for(int j=maxx;j>=1;j--){
            for(sit=s[j].begin();sit!=s[j].end()&&cnt<K;sit++){
                cnt++;
                printf(" %d",*sit);
            }
        }
        printf("\n");
        it=m.find(query);
        if(it!=m.end()){
            int tt=m[query];
            s[tt].erase(query);
            s[tt+1].insert(query);
            m[query]=tt+1;
            if(tt+1>maxx){
                maxx=tt+1;
            }
        }else{
            m[query]=1;
            s[1].insert(query);
        }
    }
    return 0;
}
