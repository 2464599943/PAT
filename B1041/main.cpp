#include <iostream>
#include<map>
#include<stdio.h>
using namespace std;
struct num{
    string str;
    int num1;
    int num2;
};
map<int,num> m;
int main()
{
    int N,M,temp1,temp2;
    scanf("%d",&N);
    string str;
    num n;
    for(int i=0;i<N;i++){
        cin>>str;
        cin>>temp1;
        cin>>temp2;
        n.str=str;
        n.num1=temp1;
        n.num2=temp2;
        m[temp1]=n;
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d",&temp1);
        printf("%s %d\n",m[temp1].str.c_str(),m[temp1].num2);
    }
    return 0;
}
