#include <iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxHobby 1010
#define maxpeople 1010
using namespace std;
int a[maxHobby];
bool b[maxHobby];
struct people_hobby{
    int id;
    int hobby;
};
int findroot(int num){
    int digit=num;
    int temp;
    while(num!=a[num]){
        num=a[num];
    }
    while(digit!=a[digit]){
        temp=a[digit];
        a[digit]=num;
        digit=temp;
    }
    return num;
}
void update(int num,int root){
    int digit=num;
    int temp;
    while(digit!=a[digit]){
        temp=a[digit];
        a[digit]=root;
        digit=temp;
    }
}
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    int N,num1,num2,first;
    int root1,root2;
    scanf("%d",&N);
    vector<people_hobby> v;
    set<int> s[maxpeople];
    people_hobby ph;
    for(int i=0;i<maxHobby;i++){
        a[i]=i;
        b[i]=false;
    }
    for(int i=0;i<N;i++){
        scanf("%d: ",&num1);

        for(int j=0;j<num1;j++){
            scanf("%d",&num2);
            ph.id=i+1;
            ph.hobby=num2;
            v.push_back(ph);
            b[num2]=true;
            if(j>0){
                root1=findroot(first);
                root2=findroot(num2);
                if(root1!=root2){
                    a[root1]=min(root1,root2);
                    a[root2]=min(root1,root2);
                    update(first,a[root1]);
                    update(num2,a[root1]);
                }

            }
            first=num2;
        }
    }
    int help[maxHobby];
    memset(help,0,sizeof(help));
    for(int i=1;i<maxHobby;i++){
        if(b[i]){
             root1=findroot(i);
             help[root1]++;
        }
    }
    for(int i=0;i<v.size();i++){
        s[a[v[i].hobby]].insert(v[i].id);
    }
    vector<int> sortt;
    for(int i=0;i<maxpeople;i++){
        if(s[i].size()!=0){
            sortt.push_back(s[i].size());
        }
    }
    sort(sortt.begin(),sortt.end(),cmp);
    int result1=sortt.size();
    printf("%d\n",result1);
    for(int i=0;i<sortt.size();i++){
        if(i==0)
           printf("%d",sortt[i]);
        else
            printf(" %d",sortt[i]);
    }
    return 0;
}
