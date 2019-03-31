#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
#define maxN 1048580
int main()
{
    char text[maxN];
    gets(text);
    map<string,int> m;
    map<string,int>::iterator it;
    char word[100];
    int countt=0;
    int left=0;
    while(text[countt]!='\n'){
       if(text[countt]<='9'&&text[countt]>='0'){
                countt++;
        }else if(text[countt]<='z'&&text[countt]>='a'){
                countt++;
        }else if(text[countt]<='Z'&&text[countt]>='A'){
               countt++;
        }else{
               if(left!=countt){
                for(int i=left;i<countt;i++){
                    word[i-left]=text[i];
                }
                word[countt]='\0';
                strings str(word);
                it=m.find(word);
                if(it!=m.end()){
                    m[word]++;
                }
                else{
                    m[word]=1;
                }
               }
        }
    }
    pair<string,int> p;
    int maxx=0;
    str="";
    for(it=m.begin();it!=m.end();it++){
        p=*it;
       if(p.second>maxx){
         maxx=p.second;
         str=p.first;
       }else if(p.second==maxx){
           if(p.first<str){
            str=p.first;
           }
       }
    }
    printf("%s %d",str.c_str(),maxx);
    return 0;
}
