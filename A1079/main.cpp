#include <iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;
struct retailer{
    int index;
    int sale;
};
int main()
{
    int N;
    double p,r;
    scanf("%d %lf %lf",&N,&p,&r);
    int *supplier=new int[N];
    memset(supplier,-1,sizeof(supplier));
    vector<retailer> v;
    int num,people;
    retailer retail;
    for(int i=0;i<N;i++){
       scanf("%d",&num);
       if(num==0){
          retail.index=i;
          scanf("%d",&retail.sale);
          v.push_back(retail);
       }else{
           for(int j=0;j<num;j++){
               scanf("%d",&people);
               supplier[people]=i;
           }
       }
    }
    double result=0.0;
    for(int i=0;i<v.size();i++){
         num=v[i].index;
         double temp=p;
         while(supplier[num]!=-1){
            temp=temp*(1+r*0.01);
            num=supplier[num];
         }
         result+=temp*v[i].sale;
    }
    printf("%.1f\n",result);
    return 0;
}
