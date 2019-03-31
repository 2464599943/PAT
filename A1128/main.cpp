#include <iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define maxN 1010
bool help[maxN];
int a[maxN];
using namespace std;

int main()
{
    int K,N,Q,temp,first;
    scanf("%d",&K);

    for(int i=0;i<K;i++){
        scanf("%d",&N);
        fill(help,help+maxN,false);
        bool result=true;
        for(int j=1;j<=N;j++){
            scanf("%d",&a[j]);
            if(help[a[j]]){
                result=false;
            }
            help[a[j]]=true;
            for(int k=1;k<j;k++){
                if(abs(a[j]-a[k])==abs(j-k)){
                    result=false;
                    break;
                }
            }
        }
        if(result){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
