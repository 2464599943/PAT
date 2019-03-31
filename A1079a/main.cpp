#include <iostream>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<cstring>
#define maxN 100010
using namespace std;
double ans=0.0;
struct node{
    int sale;
    vector<int> v;
};
node a[maxN];
void dfs(int depth,int index,double P,double r){
    if(a[index].v.size()==0){
        ans+=P*pow(1+0.01*r,depth)*a[index].sale;
        return;
    }
    for(int i=0;i<a[index].v.size();i++){
        dfs(depth+1,a[index].v[i],P,r);
    }
}
int main()
{
    int N,num,temp;
    double P,r;
    scanf("%d %lf %lf",&N,&P,&r);
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        if(num==0){
            scanf("%d",&a[i].sale);
        }else{
            for(int j=0;j<num;j++){
                scanf("%d",&temp);
                a[i].v.push_back(temp);
            }
        }
    }
    dfs(0,0,P,r);
    printf("%.1f\n",ans);
    return 0;
}
