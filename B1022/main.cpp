#include <iostream>
#include<stdio.h>
#include<stack>
using namespace std;
stack<int> s;
int main()
{
    long long a,b,temp,D;
    cin>>a;
    cin>>b;
    cin>>D;
    temp=a+b;
    long long num1=temp,num2;
    while(num1!=0){
        num2=num1%D;
        num1=num1/D;
        s.push(num2);
    }
    if(temp!=0){
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    }else{
        cout<<0;
    }
    return 0;
}
