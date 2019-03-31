#include <iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;
vector<int> v;
bool ifprime(int num){
    if(num==1)return false;
    int half=(int)pow(num*1.0,0.5);
    for(int i=2;i<=half;i++){
        if(num%i==0)return false;
    }
    return true;
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        if(ifprime(i)){
            v.push_back(i);
        }
    }
    int cnt=0;
    for(int i=1;i<v.size();i++){
        if(v[i]-v[i-1]==2){
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
