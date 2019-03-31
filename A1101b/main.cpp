#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<set>
#define maxN 100010
using namespace std;
int a[maxN];
int b[maxN];
set<int> s;
set<int>::iterator it;
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(a,a+N);
    for(int i=0;i<N;i++){
        if(a[i]==b[i]){
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
