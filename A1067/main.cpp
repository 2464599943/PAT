#include <iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int *b=new int[N];
    int num=0,left=0;
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        b[num]=i;
        if(num!=i&&num!=0){
            left++;
        }
    }
    int result=0;
    int k=1;
    while(left>0){
       if(b[0]==0){
          while(k<N){
            if(b[k]!=k){
                swap(b[0],b[k]);
                result++;
                break;
            }
            k++;
          }
       }
       else{
         swap(b[0],b[b[0]]);
         result++;
         left--;
       }

    }
    printf("%d",result);
    return 0;
}
