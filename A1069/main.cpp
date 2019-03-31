#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
char a[10];
char b[10];
bool cmp2(char a,char b){
    return a>b;
}
int main()
{
    int N,num1,num2,num3;
    string a;
    string b;
    cin>>a;
    do{
        sort(a.begin(),a.end(),cmp2);
        b=a;
        reverse(b.begin(),b.end());
        num1=stoi(a);
        num2=stoi(b);
        num3=num1-num2;
        printf("%04d - %04d = %04d",num1,num2,num3);
        a=to_string(num3);
    }while(num3!=0&&num3!=6174);


    return 0;
}
