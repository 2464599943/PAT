#include <iostream>
#include<stdlib.h>
#include<string>
using namespace std;
#define inf 100000000
int handletime(string str){
    string hour,minute,second;
    hour=str.substr(0,2);
    minute=str.substr(3,2);
    second=str.substr(6,2);
    int inthour=atoi(hour.c_str());
    int intminute=atoi(minute.c_str());
    int intsecond=atoi(second.c_str());
    return inthour*3600+intminute*60+intsecond;
}
int main()
{
    int M;
    cin>>M;
    string first;
    string last;
    int time1=inf,time2=0;
    string str1,str2,str3;
    int num1,num2;
    for(int i=0;i<M;i++){
        cin>>str1;
        cin>>str2;
        cin>>str3;
        num1=handletime(str2);
        num2=handletime(str3);
        if(num1<time1){
            time1=num1;
            first=str1;
        }
        if(num2>time2){
            time2=num2;
            last=str1;
        }
    }
    cout<<first<<" "<<last;
    return 0;
}
