#include <iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

struct record{
    int key;
    int row;
    int col;
};
vector<record> v;
bool cmp(record a,record b){
    return a.key>b.key;
}
bool cmp2(record a,record b){
    if(a.row!=b.row)return a.row<b.row;
    return a.col<b.col;
}
int main()
{
    int N;
    record r;
    scanf("%d",&N);
    int half=(int)pow(N*1.0,0.5);
    int m=N,n=1;
    for(int i=half;i>=1;i--){
        if(N%i==0){
            n=i;
            m=N/n;
            break;
        }
    }
    for(int i=0;i<N;i++){
       scanf("%d",&r.key);
        v.push_back(r);
    }
    sort(v.begin(),v.end(),cmp);
    int temp1=1,temp2=0;
    int cnt=0;
    for(int i=0;i<v.size();i++){
        if(temp1==cnt+1&&temp2<n-cnt){
            temp2++;
        }else if(temp1<m-cnt&&temp2==n-cnt){
            temp1++;
        }else if(temp1==m-cnt&&temp2>cnt+1){
            temp2--;
        }else if(temp1>cnt+2&&temp2==cnt+1){
            temp1--;
            if(temp1==cnt+2&&temp2==cnt+1){
                cnt=cnt+1;
            }
        }
        v[i].row=temp1;
        v[i].col=temp2;
    }
    sort(v.begin(),v.end(),cmp2);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j==0){
                printf("%d",v[i*n+j].key);
            }else{
                printf(" %d",v[i*n+j].key);
            }
        }
        printf("\n");
    }
    return 0;
}
