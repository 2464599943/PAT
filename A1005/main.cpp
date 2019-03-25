#include <iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<stack>
using namespace std;
void output(int num1){
   switch(num1){
   case 0:
       cout<<"zero";
       break;
   case 1:
       cout<<"one";
       break;
   case 2:
       cout<<"two";
       break;
   case 3:
       cout<<"three";
       break;
   case 4:
       cout<<"four";
       break;
   case 5:
       cout<<"five";
       break;
   case 6:
       cout<<"six";
       break;
   case 7:
       cout<<"seven";
       break;
   case 8:
       cout<<"eight";
       break;
   case 9:
       cout<<"nine";
       break;

   }
}
int main()
{
    string num,str;
    cin>>num;
    int all=0,digits;
    for(int i=0;i<num.size();i++){
        str=num.substr(i,1);
        digits=atoi(str.c_str());
        all+=digits;
    }
    stack<int> s;
    int num1,num2;
    num1=all;
    if(num1==0){
        cout<<"zero";
    }
    else{
    while(num1!=0){
        num2=num1%10;
        num1=num1/10;
        s.push(num2);
    }
    while(!s.empty()){
        num1=s.top();
        s.pop();
        output(num1);
        if(!s.empty()){
            cout<<" ";
        }
    }
    }
    return 0;
}
