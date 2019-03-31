#include <iostream>
#include<stdio.h>
#include<vector>
#include<math.h>
#define maxN 100010
using namespace std;
vector<int> v[maxN];
double minn=10000000001.0;
int in=0;
void dfs(int depth,int index,double P,double r){
    double price;
    if(v[index].size()==0){
        price=P*pow(1+0.01*r,depth);
        if(minn>price){
            minn=price;
            in=1;
        }else if(minn==price){
            in++;
        }
        return;
    }
    for(int i=0;i<v[index].size();i++){
        dfs(depth+1,v[index][i],P,r);
    }
}
int main()
{
    int N,num,who;
    double P,r;
    scanf("%d %lf %lf",&N,&P,&r);
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            scanf("%d",&who);
            v[i].push_back(who);
        }
    }
    dfs(0,0,P,r);
    printf("%.4f %d\n",minn,in);
    return 0;
}
