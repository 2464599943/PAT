#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{
    string A;
    cin>>A;
    if(A[0]=='-'){
        cout<<"-";
        A.erase(A.begin());
    }else{
        A.erase(A.begin());
    }
    int index=A.find("E");
    string str=A.substr(index+1,A.size()-1-index);
    string  now=A.substr(0,index);
    now.erase(now.begin()+1,now.begin()+2);
    int Ex=atoi(str.c_str());
    if(Ex<=0){
        Ex=-Ex;
        now.insert(0,Ex,'0');
        now.insert(1,1,'.');
    }else if(Ex>0){
        if(Ex>now.size()-1){
            now.insert(now.size(),Ex-(now.size()-1),'0');
        }else if(Ex<now.size()-1){
            now.insert(Ex+1,1,'.');
        }
    }
    cout<<now;
    return 0;
}
