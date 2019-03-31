#include <iostream>
#include<stdio.h>
#include<map>

using namespace std;
map<char,int> m;
map<char,int>::iterator it;
int main()
{
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        it=m.find(str[i]);
        if(it==m.end()){
            m[str[i]]=1;

        }else{
            m[str[i]]++;
        }
    }
    for(char c='0';c<='9';c++){
        it=m.find(c);
        if(it!=m.end())
        printf("%c:%d\n",c,m[c]);
    }
    return 0;
}
