#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    int  c[256];
    for(int i=0;i<256;i++)c[i]=0;
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<a.size();i++){
        int num=(int)a[i];
        if(c[num]==0){
            c[num]++;
        }
    }
    for(int i=0;i<b.size();i++){
         int num=(int)b[i];
        c[num]++;
    }
    for(int i=0;i<a.size();i++){
        int num=(int)a[i];
        if(c[num]==1)cout<<a[i];
    }
    return 0;
}
