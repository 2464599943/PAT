#include <iostream>
#include<stdio.h>
#include<stack>
using namespace std;
stack<string> s;
int main()
{
    string str;
    char c;
    do{
        cin>>str;
        s.push(str);
        c=getchar();
    }while(c!='\n');
    int cnt=0;
    while(!s.empty()){
        str=s.top();
        s.pop();
        if(cnt==0){
            printf("%s",str.c_str());
        }else{
            printf(" %s",str.c_str());
        }
       cnt++;
    }
    return 0;
}
