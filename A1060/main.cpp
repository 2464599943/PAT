#include <iostream>
#include<string.h>
using namespace std;
struct number{
    string digits;
    int ex;
};
number findnumber(string a,int N){
    string a1,a2,a3;
    number c;
    while(a.size()>0&&a[0]=='0'){
        a.erase(a.begin());
    }
    if(a.size()==0){
        a3="";
        c.ex=0;
    }
    int index=a.find(".");
    if(index==-1){
        a3=a;
        c.ex=a.size();
    }else{
        if(index==0){
            a2=a.substr(index+1,a.size()-index-1);
            int zero=0;
            while(a2.size()>0&&a2[0]=='0'){
                a2.erase(a2.begin());
                zero++;
            }
            if(a2.size()==0){c.ex=0;}
            else{
                c.ex=-zero;
            }
            a3=a2;
        }else{
            a1=a.substr(0,index);
            a2=a.substr(index+1,a.size()-index-1);
            a3=a1+a2;
            c.ex=index;
        }
    }
    if(N<=a3.size()){
        c.digits=a3.substr(0,N);
    }
    else{
         while(N>a3.size()){
            a3=a3+"0";
         }
            c.digits=a3;
         }

    return c;
}
int main()
{
    int N;
    cin>>N;
    string A,B;
    cin>>A;
    cin>>B;
       number a=findnumber(A,N);
       number b=findnumber(B,N);

    if(a.digits==b.digits&&a.ex==b.ex){
        cout<<"YES 0."<<a.digits<<"*10^"<<a.ex;
    }
    else{
        cout<<"NO 0.";
        cout<<a.digits<<"*10^"<<a.ex;
        cout<<" 0."<<b.digits<<"*10^"<<b.ex;
    }
    return 0;
}
