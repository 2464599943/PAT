#include <iostream>
#include<map>
#include<stdio.h>
using namespace std;
map<char,int> m1;
map<char,int>::iterator it;
pair<char,int> p;
map<char,int> m2;
map<char,bool> m3;
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    for(int i=0;i<str1.size();i++){
        it=m1.find(str1[i]);
        if(it==m1.end()){
            m1[str1[i]]=1;
            m3[str1[i]]=true;
        }else{
            m1[str1[i]]++;
        }
    }
    bool result=true;
    int que=0;
    int duo=0;
    for(int i=0;i<str2.size();i++){
        it=m1.find(str2[i]);
        if(it==m1.end()){
            que++;
            result=false;
        }else{
            if(m1[str2[i]]==0){
                que++;
                result=false;
                m3[str2[i]]=false;
            }else{
                m1[str2[i]]--;
                if(m1[str2[i]]==0){
                    m3[str2[i]]=false;
                }
            }
        }
    }
    if(!result){
        printf("No %d",que);
    }else{
        for(it=m1.begin();it!=m1.end();it++){
            p=*it;
            char c=p.first;
            if(m3[c]){
                duo+=m1[c];
            }
        }
        printf("Yes %d",duo);
    }
    return 0;
}
