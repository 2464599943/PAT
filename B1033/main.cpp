#include <iostream>
#include<stdio.h>
#include<map>
using namespace std;
map<char,bool> m;
map<char,bool>::iterator it;
int jia=0;
int main()
{
    char c;
    string str;
    c=getchar();
    while(c!='\n'){
        if(c=='+')jia=1;
        if(c<='Z'&&c>='A'){
            m[c-'A'+'a']=false;
        }
        m[c]=false;
        c=getchar();
    }
    cin>>str;
    for(int i=0;i<str.size();i++){
        it=m.find(str[i]);
        if(it==m.end()){
            if(str[i]<='Z'&&str[i]>='A'&&jia==1){
                continue;
            }
            cout<<str[i];
        }
    }
    return 0;
}
