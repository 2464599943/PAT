#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct number{
   long long  numerators;
   long long denominators;
};
number calculate(number a,number b){
    number c;
    long long  xia=a.denominators*b.denominators;
    long long shang=a.numerators*b.denominators+b.numerators*a.denominators;
    if(shang<0){
        shang=-shang;
        xia=-xia;
    }
    if(xia!=0){
    for(int i=2;i<=min(abs(shang),abs(xia));i++){
        if(abs(shang)%i==0&&abs(xia)%i==0){
            shang/=i;
            xia/=i;
        }
    }
    c.numerators=shang;
    c.denominators=xia;
    }else{
        c.numerators=0;
        c.denominators=1;
    }
    return c;
}
int main()
{
    int N;
    scanf("%d",&N);
    number *a=new number[N];
    for(int i=0;i<N;i++){
        scanf("%lld/%lld",&a[i].numerators,&a[i].denominators);
        if(a[i].denominators<0){
            a[i].denominators=-a[i].denominators;
            a[i].numerators=-a[i].numerators;
        }
    }
    number c;
    c.numerators=0;
    c.denominators=1;
    for(int i=0;i<N;i++){
        c=calculate(c,a[i]);
    }
    long long num1=c.numerators/c.denominators;
    long long num2=c.numerators%c.denominators;
    long long num3=c.denominators;
    if(num2!=0&&num1!=0)
      if(num3!=1)
         printf("%lld %lld/%lld\n",num1,num2,num3);
      else
         printf("%lld %lld\n",num1,num2);
    else if(num2==0&&num1!=0){
         printf("%lld\n",num1);
    }else if(num2!=0&&num1==0){
         if(num3!=1)
            printf("%lld/%lld\n",num2,num3);aq  TTTTTTT
         else
            printf("%lld\n",num2);
    }else{
        printf("0\n");
    }

    return 0;
}
