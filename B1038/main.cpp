#include <iostream>
#include<stdio.h>
#include<map>
using namespace std;
map<int,int> m;
map<int,int>::iterator it;
int main()
{
    int N,K,temp;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
       scanf("%d",&temp);
       it=m.find(temp);
       if(it==m.end()){
          m[temp]=1;
       }else{
           m[temp]++;
       }
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d",&temp);
        it=m.find(temp);
        if(it==m.end()){
            m[temp]=0;
        }
        if(i==0){
            printf("%d",m[temp]);
        }else{
            printf(" %d",m[temp]);
        }
    }
    return 0;
}
