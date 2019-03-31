#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define maxpeople 30010
using namespace std;
struct testee{
    char id[15];
    int score;
    int final_rank;
    int location_num;
    int local_rank;
};
bool location_cmp(testee a,testee b){
    if(a.location_num!=b.location_num)return a.location_num<b.location_num;
    else if(a.score!=b.score)return a.score>b.score;
    return strcmp(a.id,b.id)<0;
};
bool cmp(testee a,testee b){
    if(a.score!=b.score)return a.score>b.score;
    return strcmp(a.id,b.id)<0;
}
int main()
{
   int N;
   scanf("%d",&N);
   int *K=new int[N+1];
   K[0]=0;
   testee people[maxpeople];
   int countt=0;
   int num;
   for(int i=1;i<=N;i++){
       scanf("%d",&num);
       K[i]=K[i-1]+num;
       for(int j=0;j<num;j++){
           scanf("%s %d",people[countt].id,&people[countt].score);
           people[countt].location_num=i;
           countt++;
       }
   }

   sort(people,people+countt,location_cmp);

   for(int i=0;i<N;i++){
        people[K[i]].local_rank=1;
        for(int j=K[i]+1;j<K[i+1];j++){
            if(people[j].score==people[j-1].score){
                people[j].local_rank=people[j-1].local_rank;
            }else{
                people[j].local_rank=j-K[i]+1;
            }

        }

   }
   sort(people,people+countt,cmp);
   people[0].final_rank=1;
   for(int i=1;i<countt;i++){
       if(people[i].score==people[i-1].score){
           people[i].final_rank=people[i-1].final_rank;
       }else{
           people[i].final_rank=i+1;
       }
   }
   printf("%d\n",countt);
   for(int i=0;i<countt;i++){
        printf("%s %d %d %d\n",people[i].id,people[i].final_rank,people[i].location_num,people[i].local_rank);
   }
    return 0;
}
