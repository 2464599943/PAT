#include <iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
    string str1,str2,str3,str4;
    cin>>str1>>str2>>str3>>str4;
    int day,hour,minute;
    int cnt=0;
    for(int i=0;i<str1.size()&&i<str2.size();i++){
        if(cnt==0&&str1[i]<='G'&&str1[i]>='A'&&str1[i]==str2[i]){
            day=str1[i]-'A'+1;
            cnt++;
        }else if(cnt==1&&str1[i]==str2[i]){
            if(str1[i]<='9'&&str1[i]>='0'){
                hour=str1[i]-'0';
                cnt++;
                break;
            }else if(str1[i]<='N'&&str1[i]>='A'){
                hour=str1[i]-'A'+10;
                cnt++;
                break;
            }
        }
    }
    int cnt1=0;
    for(int i=0;i<str3.size()&&i<str4.size();i++){
        if(str3[i]==str4[i]&&((str3[i]<='z'&&str3[i]>='a')||(str3[i]<='Z'&&str3[i]>='A'))){
               cnt1=i;
                break;

        }
    }
    switch(day){
     case 1:
         printf("MON");
        break;
     case 2:
         printf("TUE");
        break;
     case 3:
         printf("WED");
        break;
     case 4:
         printf("THU");
        break;
     case 5:
         printf("FRI");
        break;
     case 6:
         printf("SAT");
        break;
     case 7:
         printf("SUN");
        break;
    }
    printf(" %02d:%02d\n",hour,cnt1);
    return 0;
}
