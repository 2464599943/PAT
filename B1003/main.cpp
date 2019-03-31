#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
bool handle(string str){
    bool result=true;
    for(int i=0;i<str.size();i++){
        if(str[i]=='P')continue;
        else if(str[i]=='A')continue;
        else if(str[i]=='T')continue;
        else{
            result=false;
            return false;
        }
    }
    int help;
    int index=str.find("PAT");
    while(index==-1){
        string temp=str;
        int index2=temp.find("P");
        if(index2==-1)return false;
        string s1=temp.substr(0,index2);
        int index3=temp.find("T");
        if(index3==-1||index3==0)return false;
        if(temp[index3-1]!='A')return false;
        temp.erase(temp.begin()+index3-1);
        int index4=temp.find(s1,index3-1);
        if(index4==-1&&s1.size()!=0)return false;
        string s2=temp.replace(temp.size()-s1.size(),s1.size(),"");
        str=s2;
         index=str.find("PAT");
    }
        string str1,str2;
        if(str.size()>3){
           str1=str.substr(0,index);
            str2=str.substr(index+3,str.size()-index-3);
        }else{
            str1="";
            str2="";
        }
        if(str1.size()!=str2.size())return false;
        for(int i=0;i<str1.size();i++){
            if(str1[i]!='A'){
                result=false;
                return false;
            }
        }
        for(int i=0;i<str2.size();i++){
            if(str2[i]!='A'){
                result=false;
                return false;
            }
        }

    return true;
}
int main()
{
    int N;
    scanf("%d",&N);
    string str;
    for(int i=0;i<N;i++){
        cin>>str;
        bool result=handle(str);
        if(result){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
