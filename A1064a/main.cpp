#include <iostream>
#include<stdio.h>
#include<algorithm>
#define maxN 1010
using namespace std;
int a[maxN];
int b[maxN];
int k=0;
void inorder(int root,int N){
    if(root<=0||root>N)return;
    inorder(2*root,N);
    if(k<N){
        b[root]=a[k];
        k++;
    }
    inorder(2*root+1,N);
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+N);
    inorder(1,N);
    for(int i=1;i<N;i++){
        printf("%d ",b[i]);
    }
    printf("%d",b[N]);
    return 0;
}
