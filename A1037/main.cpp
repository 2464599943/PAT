#include <iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    int NC,NP,azheng=0,afu=0,bzheng=0,bfu=0;
    scanf("%d",&NC);
    long long *a=new long long[NC];
    for(int i=0;i<NC;i++){
        scanf("%lld",&a[i]);
        if(a[i]>0)azheng++;
        else if(a[i]<0)afu++;
    }
    scanf("%d",&NP);
    long long *b=new long long[NP];
    for(int i=0;i<NP;i++){
        scanf("%lld",&b[i]);
        if(b[i]>0)bzheng++;
        else if(b[i]<0)bfu++;
    }
    sort(a,a+NC,cmp);
    sort(b,b+NP,cmp);
    long long result=0;
    for(int i=0;i<azheng&&i<bzheng;i++){
        result+=a[i]*b[i];
    }
    for(int i=0;i<afu&&i<bfu;i++){
        result+=a[NC-1-i]*b[NP-1-i];
    }
    printf("%lld",result);
    return 0;
}
