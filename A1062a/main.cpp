#include <iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct student{
    int flag;
    int id;
    int virtue;
    int talent;
    int sum;
};
bool cmp(student a,student b){
    if(a.flag!=b.flag)return a.flag<b.flag;
    else if(a.sum!=b.sum)return a.sum>b.sum;
    else if(a.virtue!=b.virtue)return a.virtue>b.virtue;
    return a.id<b.id;

}
int main()
{
    int N,L,H;
    scanf("%d%d%d",&N,&L,&H);
    int M=0;
    student *grade=new student[N];
    int id,virtue,talent;
    for(int i=0;i<N;i++){
        scanf("%d%d%d",&id,&virtue,&talent);
        if(virtue>=L&&talent>=L){
            grade[M].id=id;
            grade[M].talent=talent;
            grade[M].virtue=virtue;
            grade[M].sum=talent+virtue;
            if(virtue>=H&&talent>=H){
                grade[M].flag=1;
            }else if(virtue>=H&&talent<H){
                grade[M].flag=2;
            }else if(virtue>=talent&&virtue<H){
                grade[M].flag=3;
            }else{
                grade[M].flag=4;
            }
            M++;
        }

    }
    printf("%d\n",M);
    sort(grade,grade+M,cmp);
    for(int i=0;i<M;i++){
        printf("%d %d %d\n",grade[i].id,grade[i].virtue,grade[i].talent);
    }
    return 0;
}
