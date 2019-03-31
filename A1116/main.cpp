#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
struct person{
    int rankk;
    int countt=0;
};
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
    int N,temp,K;
    map<int,person> m;
    map<int,person>::iterator it;
    scanf("%d",&N);
    person p;
    for(int i=1;i<=N;i++){
        scanf("%d",&temp);
        p.rankk=i;
        p.countt=0;
        m[temp]=p;
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d",&temp);
        it=m.find(temp);
        if(it==m.end()){
            printf("%04d: Are you kidding?\n",temp);
            continue;
        }
        p=m[temp];
        if(p.countt>=1){
            printf("%04d: Checked\n",temp);
            m[temp].countt++;
            continue;
        }
        if(p.rankk==1){
            printf("%04d: Mystery Award\n",temp);
        }else{
            bool result=ifprime(p.rankk);
            if(result){
                printf("%04d: Minion\n",temp);
            }else{
                printf("%04d: Chocolate\n",temp);
            }
        }
        m[temp].countt++;
    }
    return 0;
}
