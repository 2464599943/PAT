#include <iostream>
#include<set>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#define maxN 100010
using namespace std;
set<int> s;
set<int>::iterator it;
int a[maxN];
int help[maxN];
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    help[N-1]=a[N-1];
    for(int i=N-2;i>=0;i--){
        help[i]=min(a[i],help[i+1]);
    }
    int maxx=-1;
    for(int i=0;i<N;i++){
        bool left=true;
        bool right=true;
        if(a[i]>maxx){
            maxx=a[i];
        }else{
            left=false;
        }
        if(help[i]<a[i]){
            right=false;
        }
        if(left&&right){
            s.insert(a[i]);
        }
    }
    printf("%d\n",s.size());
    for(it=s.begin();it!=s.end();it++){
        if(it==s.begin()){
            printf("%d",*it);
        }else{
            printf(" %d",*it);
        }
    }
    printf("\n");
    return 0;
}
