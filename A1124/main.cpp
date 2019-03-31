#include <iostream>
#include<stdio.h>
#include<map>
using namespace std;

int main()
{
    map<string,int> m;
    map<string,int>::iterator it;
    int M,N,S,win;
    scanf("%d%d%d",&M,&N,&S);
    win=S;
    string str;
    for(int i=1;i<=M;i++){
        cin>>str;
       if(i==win){
          it=m.find(str);
          if(it==m.end()){
             m[str]=1;
              win+=N;
             cout<<str<<endl;
          }else{
              m[str]++;
              win++;
          }

       }
    }
    if(m.size()==0){
        printf("Keep going...\n");
    }
    return 0;
}
