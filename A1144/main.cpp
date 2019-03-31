#include <iostream>
#include<algorithm>
#include<stdio.h>
#define maxN 100010
#define inf 100000000
using namespace std;
int a[maxN];
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+N);
    int index;
    for(index=0;index<N;index++){
        if(a[index]>0){
            break;
        }
    }
    if(index==N)
        printf("%d\n",1);
    else{
        if(a[index]==1){
            int cnt=1;
            a[N]=inf;
            while(a[index]==cnt){
                if(a[index]==a[index+1]){
                    index++;
                }
                else{
                    index++;
                    cnt++;
                }

            }

            printf("%d\n",cnt);
        }else{
            printf("%d\n",1);
        }
    }
    return 0;
}
