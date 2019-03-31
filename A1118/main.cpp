#include <iostream>
#include<stdio.h>
#include<math.h>
#define maxbird 10010
using namespace std;
int bird[maxbird];
bool help[maxbird];
int findroot(int num){
    int a=num,temp;
    while(num!=bird[num]){
        num=bird[num];
    }
    int root=num;
    while(a!=bird[a]){
        temp=bird[a];
        bird[a]=root;
        a=bird[a];
    }
    return root;
}
int main()
{
    for(int i=0;i<maxbird;i++){
        bird[i]=i;
    }
    int N,num,temp,first,root1,root2;
    scanf("%d",&N);
    int maxxnum=0;
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            scanf("%d",&temp);
            if(temp>maxxnum){
                maxxnum=temp;
            }
            if(j==0){
                first=temp;
            }else{
                root1=findroot(first);
                root2=findroot(temp);
                bird[root1]=min(root1,root2);
                bird[root2]=min(root1,root2);
            }

        }
    }
    fill(help,help+maxxnum,false);
    for(int i=1;i<=maxxnum;i++){
        root1=findroot(i);
        help[root1]=true;
    }
    int cnt=0;
    for(int i=1;i<=maxxnum;i++){
        if(help[i]){
            cnt++;
        }
    }
    printf("%d %d\n",cnt,maxxnum);
    int K,temp1,temp2;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d%d",&temp1,&temp2);
        root1=findroot(temp1);
        root2=findroot(temp2);
        if(root1==root2){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
