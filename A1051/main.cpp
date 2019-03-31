#include <iostream>
#include<stdio.h>
using namespace std;
#include<stack>
int main()
{
    int M,N,K;
    scanf("%d%d%d",&M,&N,&K);
    int *a=new int[N+1];
    stack<int> s;
    for(int i=0;i<K;i++){
        for(int j=1;j<=N;j++){
            scanf("%d",&a[j]);
        }
        int where1=1;
        int where2=1;
        int countt=0,num;
        bool result=true;
        while(where2<=N){
            if(where1<=a[where2]&&countt<M){
                s.push(where1);
                countt++;
                where1++;
            }else{
                num=s.top();
                s.pop();
                countt--;
                if(num!=a[where2]){
                    result=false;
                    break;
                }else{
                    where2++;
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
