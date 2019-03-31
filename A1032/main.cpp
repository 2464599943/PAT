#include <iostream>
#include<map>
#include<stdio.h>
using namespace std;
struct node{
    char c;
    int next;
    int countt;
};
int main()
{
    int address1,address2,N;
    scanf("%d%d%d",&address1,&address2,&N);
    node n;
    int address;
    map<int,node> m;
    for(int i=0;i<N;i++){
        scanf("%d %c %d",&address,&n.c,&n.next);
        n.countt=0;
        m[address]=n;
    }
    int num=address1;
    while(num!=-1){
        m[num].countt++;
        num=m[num].next;
    }
    num=address2;
    while(num!=-1){
        m[num].countt++;
        num=m[num].next;
    }
     num=address1;
    while(num!=-1){
       if(m[num].countt==2){
            printf("%05d\n",num);
            break;
       }
        num=m[num].next;
    }
    if(num==-1)printf("%d\n",-1);
    return 0;
}
