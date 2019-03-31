#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
bool iflegal(string str,double &ans){
    int fu=1;
    if(str[0]=='-'){
        fu=-1;
        str.erase(str.begin());
    }
    if(str[0]=='+'){
        fu=1;
        str.erase(str.begin());
    }
    for(int i=0;i<str.size();i++){
        if(str[i]<='9'&&str[i]>='0')continue;
        else if(str[i]=='.')continue;
        else return false;
    }
    int qian;
    int hou;
    double num=0.0;
    int index=str.find(".");
    int index2=str.find(".",index+1);
    if(index2!=-1&&index2!=str.size()-1)return false;
    if(index2==str.size()-1)str.erase(str.begin()+str.size()-1);
    if(index==-1){
        qian=atoi(str.c_str());
        hou=0;
        num=qian*1.0;
    }else if(index==str.size()-1){
        string str1=str.substr(0,str.size()-1);
        qian=atoi(str1.c_str());
        hou=0;
        num=qian*1.0;
    }
    else{
        string str1=str.substr(0,index);
        string str2=str.substr(index+1,str.size()-index-1);
        qian=atoi(str1.c_str());
        hou=atoi(str2.c_str());
        if(str2.size()>2)return false;
        if(str2.size()==2){
            num=qian*1.0+hou*0.01;
        }else if(str2.size()==1){
            num=qian*1.0+hou*0.1;
        }
    }
    if(num>1000)return false;
    ans=fu*num;
    return true;
}
int main()
{
    int N;
    scanf("%d",&N);
    string str;
    bool result;
    double ans=0.0;
    double all=0.0;
    int countt1=0;
    int countt2=0;
    for(int i=0;i<N;i++){
        cin>>str;
        result=iflegal(str,ans);
        if(result){
            countt1++;
            all+=ans;
        }else{
            countt2++;
            printf("ERROR: %s is not a legal number\n",str.c_str());
        }
    }
    if(countt1==0){
        printf("The average of 0 numbers is Undefined\n");
    }else if(countt1==1){
        printf("The average of 1 number is %.2f\n",all);
    }else{
        double temp=all/countt1;
        printf("The average of %d numbers is %.2f\n",countt1,temp);
    }

    return 0;
}
