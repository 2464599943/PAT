#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
long long Map[256];
void mapmap(){
    for(char c='0';c<='9';c++){
        Map[c]=c-'0';
    }
    for(char c='a';c<='z';c++){
        Map[c]=c-'a'+10;
    }
}
int findmax(string str){
    long long  maxx=-1;
    for(int i=0;i<str.size();i++){
        if(maxx<Map[str[i]]){
            maxx=Map[str[i]];
        }
    }
    return maxx;
}
long long transforms(string str,int radix){
    long long result=0;
    long long jie=1;
    for(int i=str.size()-1;i>=0;i--){
        result+=jie*Map[str[i]];
        jie*=radix;
    }
    return result;
}
int main()
{
    string a,b;
    int flag,radix;
    cin>>a>>b;
    cin>>flag>>radix;
    if(flag==2){
        swap(a,b);
        flag=1;
    }
    mapmap();
    long long num1=transforms(a,radix);
    long long left=findmax(b)+1;
    long long right=max(left,num1);
    long long mid,num2;
    bool ok=false;
    while(left<=right){
        mid=(left+right)/2;
        num2=transforms(b,mid);
        if(num2<0){
            right=mid-1;
            continue;
        }
        if(num1==num2){
            cout<<mid;
            ok=true;
            break;
        }else if(num1<num2){
            right=mid-1;
        }else {
            left=mid+1;
        }
    }
    if(!ok)cout<<"Impossible";

    return 0;
}
