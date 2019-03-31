#include <iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int N,num;
    scanf("%d",&N);
    vector<int> v;
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int all1=0;
    int all2=0;
    for(int i=1;i<=v.size();i++){
        if(i<=v.size()/2){
            all1+=v[i-1];
        }
        else{
            all2+=v[i-1];
        }
    }
    if(N%2==0){
        printf("0 %d",all2-all1);
    }else{
        printf("1 %d",all2-all1);
    }
    return 0;
}
