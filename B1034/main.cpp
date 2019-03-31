#include <iostream>
#include<stdio.h>
using namespace std;
long long  a1=0,b1=0,a2=0,b2=0,k1=0,k2=0;
long long  aa1=0,bb1=0,aa2=0,bb2=0;
long long temp1=0,temp2=0,temp3=0,temp4=0;
long long gcd(long long a,long long b){
    if(b==0)return a;
    return gcd(b,a%b);
}
void yue(long long &k,long long &a,long long &b){
    long long help=gcd(a,b);
    a=a/help;
    b=b/help;
    k=a/b;
    a=a%b;
    if(k==0&&b<0){
        a=-a;
        b=-b;
    }else if(k!=0){
        if(a<0){
            a=-a;
        }
        if(b<0){
            b=-b;
        }
    }
}
void add(){
    temp1=bb1*bb2;
    temp2=aa1*bb2+aa2*bb1;
    yue(temp3,temp2,temp1);


}
void sub(){
    temp1=bb1*bb2;
    temp2=aa1*bb2-aa2*bb1;
    yue(temp3,temp2,temp1);
}
void mul(){
    temp1=bb1*bb2;
    temp2=aa1*aa2;
    yue(temp3,temp2,temp1);
}
void div(){
    temp1=bb1*aa2;
    temp2=aa1*bb2;
    if(temp1==0)return;
    yue(temp3,temp2,temp1);
}
void output(long long num1,long long num2,long long num3){
    if(num1<0){
        printf("(");
    }else if(num1==0&&num2<0){
        printf("(");
    }
    if(num1!=0&&num2!=0&&num3!=1){
        printf("%lld %lld/%lld",num1,num2,num3);
    }else if(num1==0&&num2!=0&&num3!=1){
        printf("%lld/%lld",num2,num3);
    }else if(num1==0&&num2!=0&&num3==1){
        printf("%lld",num2);
    }else if(num1!=0&&num2!=0&&num3==1){
        printf("%lld %lld",num1,num2);
    }else if(num2==0){
        printf("%lld",num1);
    }
    if(num1<0){
        printf(")");
    }else if(num1==0&&num2<0){
        printf(")");
    }

}
int main()
{
    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    aa1=a1;
    aa2=a2;
    bb1=b1;
    bb2=b2;
    yue(k1,a1,b1);
    yue(k2,a2,b2);
    output(k1,a1,b1);
    printf(" + ");
    output(k2,a2,b2);
    printf(" = ");
    add();
    output(temp3,temp2,temp1);
    printf("\n");

    output(k1,a1,b1);
    printf(" - ");
    output(k2,a2,b2);
    printf(" = ");
    sub();
    output(temp3,temp2,temp1);
    printf("\n");

    output(k1,a1,b1);
    printf(" * ");
    output(k2,a2,b2);
    printf(" = ");
    mul();
    output(temp3,temp2,temp1);
    printf("\n");

    output(k1,a1,b1);
    printf(" / ");
    output(k2,a2,b2);
    printf(" = ");
    div();
    if(temp1==0){
        printf("Inf\n");
    }else{
         output(temp3,temp2,temp1);
         printf("\n");
    }
    return 0;
}
