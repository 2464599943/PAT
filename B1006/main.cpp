#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    string N;
    cin>>N;
    char a2,a3;
    if(N.size()==3){
        for(char c='1';c<=N[0];c++){
            cout<<"B";
        }
        N.erase(N.begin());
    }
    if(N.size()==2){
        for(char c='1';c<=N[0];c++){
            cout<<"S";
        }
        N.erase(N.begin());
    }
    if(N.size()==1){
        for(char c='1';c<=N[0];c++){
            cout<<c;
        }
    }
    return 0;
}
