#include <iostream>
#include<map>
#include<stdio.h>
using namespace std;
map<int,int> m;
map<int,int>::iterator it;
int main()
{
     int N,temp1,temp2;
     scanf("%d",&N);
     int maxx=-1;
     for(int i=0;i<N;i++){
        scanf("%d%d",&temp1,&temp2);
        it=m.find(temp1);
        if(it==m.end()){
            m[temp1]=temp2;
        }else{
            m[temp1]+=temp2;
        }
        if(i==0)maxx=temp1;
        else if(m[maxx]<m[temp1]){
            maxx=temp1;
        }
     }
     printf("%d %d",maxx,m[maxx]);
    return 0;
}
