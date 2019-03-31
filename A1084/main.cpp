#include <iostream>
#include<stdio.h>
#include<map>
using namespace std;
map<char,bool> m;
map<char,bool> m2;
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int index1=0,index2=0;
    while(index1<str1.size()){
        if(str1[index1]==str2[index2]){
            m[str1[index1]]=true;
            m2[str1[index1]]=false;
            index2++;
        }else{
            m[str1[index1]]=false;
            m2[str1[index1]]=false;

        }
        if(str1[index1]<='z'&&str1[index1]>='a'){
            m2[str1[index1]-'a'+'A']=false;
        }
        index1++;
    }
    for(int i=0;i<str1.size();i++){
        if(!m[str1[i]]&&!m2[str1[i]]){
            m2[str1[i]]=true;
            if(str1[i]<='9'&&str1[i]>='0'){
                printf("%c",str1[i]);
            }else if(str1[i]>='a'&&str1[i]<='z'&&!m2[str1[i]-'a'+'A']){
                m2[str1[i]-'a'+'A']=true;
                printf("%c",str1[i]-'a'+'A');
            }else if(str1[i]>='A'&&str1[i]<='Z'){
                printf("%c",str1[i]);
            }else if(str1[i]=='_'){
                printf("%c",str1[i]);
            }
        }
    }
    return 0;
}
