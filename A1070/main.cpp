#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct mooncake{
    double amount;
    double price;
    double bi;
};
vector<mooncake> v;
bool cmp(mooncake a,mooncake b){
   return a.bi>b.bi;

}
int main()
{
    int N,D;
    scanf("%d%d",&N,&D);
    mooncake m;
    for(int i=0;i<N;i++){
        scanf("%lf",&m.amount);
        v.push_back(m);
    }
    for(int i=0;i<N;i++){
        scanf("%lf",&v[i].price);
        v[i].bi=v[i].price/v[i].amount;
    }
    sort(v.begin(),v.end(),cmp);
    double all=0.0;
    int i=0;
    while(D&&i<v.size()){
        if(D>=v[i].amount){
            D-=v[i].amount;
            all+=v[i].price;

        }else{
            all+=D*v[i].bi;
            D=0;
            break;
        }
        i++;
    }
    printf("%.2f\n",all);
    return 0;
}
