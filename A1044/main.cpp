#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define inf 100000000
using namespace std;

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    int *a=new int[N+1];
    int *b=new int[N+1];
    b[0]=0;
    for(int i=1;i<=N;i++){
        scanf("%d",&a[i]);
        b[i]=b[i-1]+a[i];
    }
    int j;
    pair<int,int> p;
    vector<pair<int,int> > v;
    int minn=inf;
    bool ok=false;
    for(int i=1;i<=N;i++){
       j=upper_bound(b+i,b+N+1,b[i-1]+M)-(b+1);
       if(b[j]-b[i-1]<M)j=j+1;
       if(j>N)continue;
       if(b[j]-b[i-1]==M){
        if(!ok)v.clear();
        p=make_pair(i,j);
        v.push_back(p);
        ok=true;
       }else {
           if(minn>b[j]-(b[i-1]+M)&&!ok){
              minn=b[j]-(b[i-1]+M);
              p=make_pair(i,j);
              v.clear();
              v.push_back(p);
           }
           else if(minn==b[j]-(b[i-1]+M)&&!ok){
              p=make_pair(i,j);
              v.push_back(p);
           }
       }
    }
    vector<pair<int,int> >::iterator it;
    for(it=v.begin();it!=v.end();it++){
        p=*it;
      printf("%d-%d\n",p.first,p.second);
    }
    return 0;
}
