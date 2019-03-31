#include <iostream>
#include<stdio.h>
#include<algorithm>
#define maxN 100010
using namespace std;
long long a[maxN];
int main()
{
    int N;
    int p;
    scanf("%d%ld",&N,&p);
    for(int i=0;i<N;i++){
        scanf("%ld",&a[i]);
    }
    sort(a,a+N);
    int maxx=1,index;
    long long result;
    for(int i=0;i<N;i++){
            result=a[i]*p;
        index=upper_bound(a,a+N,(long long)result)-(a+i);
        if(maxx<index){
            maxx=index;
        }
    }
    printf("%d",maxx);
    return 0;
}
