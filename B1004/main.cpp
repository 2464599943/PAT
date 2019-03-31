#include <iostream>
#include<stdio.h>
#include<string.h>
#define inf 100000000
using namespace std;
struct student{
    string name;
    string id;
    int score;
};
int main()
{
    int N;
    scanf("%d",&N);
    student s,smax,smin;
    int maxx=-1,minn=inf;
    for(int i=0;i<N;i++){
        cin>>s.name;
        cin>>s.id;
        cin>>s.score;
        if(s.score>maxx){
            maxx=s.score;
            smax.id=s.id;
            smax.name=s.name;
            smax.score=s.score;
        }
        if(s.score<minn){
            minn=s.score;
            smin.id=s.id;
            smin.name=s.name;
            smin.score=s.score;
        }
    }
    printf("%s %s\n",smax.name.c_str(),smax.id.c_str(),smax.score);
    printf("%s %s\n",smin.name.c_str(),smin.id.c_str(),smin.score);
    return 0;
}
