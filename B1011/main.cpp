#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
      long long a,b,c,d;
      scanf("%lld %lld %lld",&a,&b,&c);
      d=a+b;
      if(d>c){
        printf("Case #%d: true\n",i);
      }else{
          printf("Case #%d: false\n",i);
      }
    }
    return 0;
}
