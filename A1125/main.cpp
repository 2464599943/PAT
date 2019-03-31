#include <iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
bool cmp(double a,double b){
    return a<b;
}
int main()
{
    int N;
    double temp;
    scanf("%d",&N);
    priority_queue<double,vector<double>,greater<double> > q;
    for(int i=0;i<N;i++){
        scanf("%lf",&temp);
        q.push(temp);
    }
    double num1,num2,num3;
    while(q.size()!=1){
        num1=q.top();
        q.pop();
        num2=q.top();
        q.pop();
        num3=(num1+num2)/2;
        q.push(num3);
    }
    num1=q.top();
    q.pop();
    int result=(int)num1;
    printf("%d\n",result);
    return 0;
}
