#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
bool check(char c){
    if(c<='9'&&c>='0')return true;
    else if(c<='z'&&c>='a')return true;
    else if(c<='Z'&&c>='A')return true;
    return false;
}
int main()
{
    string text;
    getline(cin,text);
    map<string,int> m;
    map<string,int>::iterator it;
    string str;
        int left=0;
        int i;
        for(i=0;i<text.size();i++){
           if(check(text[i]))continue;
           str=text.substr(left,i-left);
           transform(str.begin(),str.end(),str.begin(),::tolower);
           it=m.find(str);
           if(str.size()>0){
              if(it!=m.end()){
                 m[str]++;
              }else{
                 m[str]=1;
             }
           }
             left=i+1;
        }
        if(left!=i){
             str=text.substr(left,i-left);
             it=m.find(str);
             transform(str.begin(),str.end(),str.begin(),::tolower);
             if(it!=m.end()){
                 m[str]++;
             }else{
                 m[str]=1;
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
    cout<<str<<" "<<maxx<<endl;
    return 0;
}
