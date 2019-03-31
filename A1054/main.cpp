#include <iostream>
#include<stdio.h>
#include<map>
using namespace std;

int main()
{
    int M,N,num;
    scanf("%d%d",&M,&N);
    map<int,int> m;
    map<int,int>::iterator it;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&num);
            it=m.find(num);
            if(it!=m.end()){
                m[num]++;
            }else{
                m[num]=1;
            }
        }
    }
    int half=N*M/2+1;
    int result;
    pair<int,int> p;
    for(it=m.begin();it!=m.end();it++){
        p=*it;
        if(p.second>=half){
            result=p.first;
            break;
        }
    }
    printf("%d\n",result);
    return 0;
}
