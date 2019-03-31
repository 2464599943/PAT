#include <iostream>
#include<stdio.h>
using namespace std;
int cnt1C=0;
int cnt1J=0;
int cnt1B=0;
int cnt2C=0;
int cnt2J=0;
int cnt2B=0;
int ping1=0;
int sheng1=0;
int fu1=0;
int handle(char a,char b){
    if(a==b){ping1++;return 0;}
    if(a=='C'&&b=='J'){
         cnt1C++;
         sheng1++;
         return -1;
    }else if(a=='J'&&b=='C'){
         cnt2C++;
         fu1++;
        return 1;

    }else if(a=='C'&&b=='B'){
        cnt2B++;
        fu1++;
        return 1;
    }else if(b=='C'&&a=='B'){
        cnt1B++;
        sheng1++;
        return -1;
    }else if(a=='J'&&b=='B'){
        cnt1J++;
        sheng1++;
        return -1;
    }else if(b=='J'&&a=='B'){
        cnt2J++;
        fu1++;
        return 1;
    }
    return 0;

}
int main()
{
    int N;
    char temp1,temp2;
    cin>>N;

    for(int i=0;i<N;i++){
       cin>>temp1>>temp2;

       handle(temp1,temp2);
    }
    int time=max(cnt1B,max(cnt1C,cnt1J));
    if(time==cnt1B){
        temp1='B';
    }else if(time==cnt1C){
        temp1='C';
    }else{
        temp1='J';
    }
    int time1=max(cnt2B,max(cnt2C,cnt2J));
    if(time1==cnt2B){
        temp2='B';
    }else if(time1==cnt2C){
        temp2='C';
    }else{
        temp2='J';
    }
    printf("%d %d %d\n",sheng1,ping1,fu1);
    printf("%d %d %d\n",fu1,ping1,sheng1);
       printf("%c %c\n",temp1,temp2);
    return 0;
}
