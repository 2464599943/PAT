#include <iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#define maxlength 10000
using namespace std;
bool ifis(string str){
    for(int i=0;i<str.size()/2;i++){
        if(str[i]!=str[str.size()-1-i])return false;
    }
    return true;
}
string add(string str1,string str2){
    char c[maxlength];
    int cnt=0;
    int jin=0;
    for(int i=str1.size()-1;i>=0;i--){
        if((str1[i]-'0')+(str2[i]-'0')+jin>9){
            c[cnt]=(str1[i]-'0')+(str2[i]-'0')+jin-10+'0';
            jin=1;
        }else{
            c[cnt]=(str1[i]-'0')+(str2[i]-'0')+jin+'0';
            jin=0;
        }
        cnt++;
    }
    if(jin==1){
        c[cnt]='1';
        cnt++;
    }
    c[cnt]='\0';
    string str(c);
    reverse(str.begin(),str.end());
    return str;
}
int main()
{
    string orgin,after,finally;
    cin>>orgin;
    after=orgin;
    reverse(after.begin(),after.end());
    finally=orgin;
    int cnt=0;
    if(ifis(orgin)){
         cout<<orgin<<" + "<<after<<" = "<<finally<<endl;
         cout<<finally<<" is a palindromic number."<<endl;
    }
    else{
        bool result=false;
        while(!result&&cnt<10){
           cnt++;
           orgin=finally;
           after=orgin;
           reverse(after.begin(),after.end());
           finally=add(orgin,after);
           cout<<orgin<<" + "<<after<<" = "<<finally<<endl;
           result=ifis(finally);
        }
        if(result){
            cout<<finally<<" is a palindromic number."<<endl;
        }else{
            cout<<"Not found in 10 iterations."<<endl;
        }

    }

    return 0;
}
