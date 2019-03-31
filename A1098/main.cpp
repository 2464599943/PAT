#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool compare(int *a,int *b,int N){
    for(int i=0;i<N;i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}
void initheap(int *origin2,int N){
    for(int i=N/2;i>=1;i--){
        int k=i;
        int j=i*2;
        while(j<=N){
            if(j+1<N&&origin2[j]<origin2[j+1]){
                j=j+1;
            }
            if(origin2[j]>origin2[k]){
                swap(origin2[k],origin2[j]);
                k=j;
                j=j*2;
            }
           else break;
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int *origin1=new int[N+1];
    int *origin2=new int[N+1];
    int *after=new int[N];
    int *after2=new int[N+1];
    for(int i=0;i<N;i++){
        scanf("%d",&origin1[i]);
        origin2[i+1]=origin1[i];
    }
    for(int i=0;i<N;i++){
        scanf("%d",&after[i]);
        after2[i+1]=after[i];
    }
    bool first=false;
    bool second=false;
    int temp;
    for(int i=1;i<N;i++){
        if(i!=1)
            first=compare(origin1,after,N);
          sort(origin1,origin1+i+1);
        if(first){
            printf("Insertion Sort\n");
            for(int i=0;i<N;i++){
                if(i==0)
                    printf("%d",origin1[i]);
                else
                    printf(" %d",origin1[i]);
            }
            break;
        }
    }
    if(!first){
        initheap(origin2,N);
        int length=N;
        for(int i=2;i<=N;i++){
             if(i!=2)
               second=compare(after2,origin2,N);
            swap(origin2[1],origin2[length]);
            length--;
            int k=1;
            int j=2*k;
            while(j<=length){
                if(j+1<length&&origin2[j]<origin2[j+1]){
                    j=j+1;
                }
                if(origin2[k]<origin2[j]){
                    swap(origin2[k],origin2[j]);
                    k=j;
                    j=j*2;
                }
               else break;
            }
            if(second){
                printf("Heap Sort\n");
                for(int i=1;i<=N;i++){
                if(i==1)
                    printf("%d",origin2[i]);
                else
                    printf(" %d",origin2[i]);
                }
                break;
            }

        }
    }
    return 0;
}
