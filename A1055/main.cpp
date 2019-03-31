#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct person{
    char name[10];
    int age;
    int worth;
};
bool cmp(person a,person b){
    if(a.worth!=b.worth) return a.worth>b.worth;
    else if(a.age!=b.age) return a.age<b.age;
    return strcmp(a.name,b.name)<0;
}
int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    person *people=new person[N];
    for(int i=0;i<N;i++){
        scanf("%s%d%d",people[i].name,&people[i].age,&people[i].worth);
    }
    sort(people,people+N,cmp);
    int M,small,big,index,MM;
    for(int i=1;i<=K;i++){
        scanf("%d%d%d",&M,&small,&big);
        printf("Case #%d:\n",i);
        MM=M;
        for(int j=0;j<N&&MM;j++){
            if(people[j].age<=big&&people[j].age>=small){
                printf("%s %d %d\n",people[j].name,people[j].age,people[j].worth);
                MM--;
            }
        }
        if(MM==M){
            printf("None\n");
        }
    }

    return 0;
}
