#include <iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct mice{
    int W;
    int r;
};
int main()
{
    int Np,Ng;
    scanf("%d%d",&Np,&Ng);
    mice *a=new mice[Np];
    queue<int> q;
    for(int i=0;i<Np;i++){
        scanf("%d",&a[i].W);
    }
    int num;
    for(int i=0;i<Np;i++){
        scanf("%d",&num);
        q.push(num);
    }
    int temp=Np;
    int group;
    while(q.size()!=1){
        if(temp%Ng==0){
            group=temp/Ng;
        }else{
            group=temp/Ng+1;
        }
        for(int i=0;i<group;i++){
            int maxx=q.front();
            q.pop();
            a[maxx].r=group+1;
            for(int j=1;j<Ng;j++){
                if(i*Ng+1+j>temp)break;
               int num=q.front();
               q.pop();
               if(a[maxx].W<a[num].W) {
                  maxx=num;
               }
               a[num].r=group+1;
            }
            q.push(maxx);
        }
        temp=group;
    }

    a[q.front()].r=1;
    printf("%d",a[0].r);
    for(int i=1;i<Np;i++){
        printf(" %d",a[i].r);
    }
    return 0;
}
