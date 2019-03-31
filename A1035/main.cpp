#include <iostream>

using namespace std;
int main()
{
    int N,M=0;
    cin>>N;
    string *name=new string[N];
    string *password=new string[N];
    string *str1;
    string *str2;
    string str;
    for(int i=0;i<N;i++){
        str1=new string();
        str2=new string();
        cin>>*str1;
        cin>>*str2;
         bool m=false;
         str=*str2;
    for(int j=0;j<str.size();j++){
        if(str[j]=='1'){
            str[j]='@';
            m=true;
        }
        else if(str[j]=='0'){
            str[j]='%';
            m=true;
        }else if(str[j]=='l'){
            str[j]='L';
            m=true;
        }else if(str[j]=='O'){
            str[j]='o';
            m=true;
        }
    }
        if(m==true){
            name[M]=*str1;
            password[M]=str;
            M++;
        }
    }
    if(M==0&&N==1){
        cout<<"There is "<<N<<" account and no account is modified";
    }
    else if(M==0&&N>1){
       cout<<"There are "<<N<<" accounts and no account is modified";
    }
    else{
        cout<<M;
        cout<<endl;
        for(int i=0;i<M;i++){
            cout<<name[i]<<" "<<password[i]<<endl;
        }
    }
    return 0;
}
