#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
bool cmp(string a,string b){
    return a+b<b+a;
}
int main()
{
    int N;
    cin>>N;
    string *a=new string[N];
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    sort(a,a+N,cmp);
    bool ok=true;
    if(a[0][0]=='0')ok=false;
    for(int i=0;i<N;i++){
        if(ok){
            cout<<a[i];
        }else{
            while(a[i].size()!=0&&a[i][0]=='0'){
                a[i].erase(a[i].begin());
            }
            cout<<a[i];
            if(a[i].size()!=0)ok=true;
        }
    }
    if(!ok)cout<<0;
    return 0;
}
