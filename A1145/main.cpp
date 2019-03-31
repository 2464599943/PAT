#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#define maxSize 100000
using namespace std;
int hashtable[maxSize];
bool help[maxSize];
bool ifprime(int num){
    if(num==1)return false;
    int half=(int)pow(num*1.0,0.5);
    for(int i=2;i<=half;i++){
        if(num%i==0)return false;
    }
    return true;
}
int findprime(int Msize){
    bool result=false;
    int i;
    for(i=Msize;i<maxSize;i++){
         result=ifprime(i);
         if(result)break;
    }
    return i;
}
int main()
{
    int Msize,N,M,temp,key,cnt,another;
    scanf("%d%d%d",&Msize,&N,&M);
    int sizee=findprime(Msize);
    fill(help,help+maxSize,false);
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        key=temp%sizee;
        cnt=0;
        another=key;
        bool result=false;
        while(cnt<sizee){
            if(!help[another]){
                hashtable[another]=temp;
                help[another]=true;
                result=true;
                break;
            }
            cnt++;
            another=(key+cnt*cnt)%sizee;
        }
        if(!result){
            printf("%d cannot be inserted.\n",temp);
        }
    }
    double all=0.0;
    for(int i=0;i<M;i++){
        scanf("%d",&temp);
        key=temp%sizee;
        cnt=0;
        another=key;
        bool result=false;
        while(cnt<=sizee){
            cnt++;
            if(!help[another]){
                break;
            }
            if(hashtable[another]==temp){
                break;
            }
            another=(key+cnt*cnt)%sizee;
        }
        all+=cnt;
    }
    double finally=all/M;
    printf("%.1f\n",finally);
    return 0;
}
