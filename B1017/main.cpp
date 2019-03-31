#include <iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
char s2[1010];
char s3[1010];
int main()
{
    string str;
    cin>>str;
    int B;
    cin>>B;
    string shang="";
    long long yu;
    long long temp,temp1,temp2;
    string s1="";
    int length,sizee;
    int cnt=0;
    if(str.size()>1){
    while(str.size()>1){
        sizee=str.size();
        length=min(17,sizee);
        s1=str.substr(0,length);
        str.erase(str.begin(),str.begin()+s1.size());
        sscanf(s1.c_str(),"%lld",&temp);
        if(temp==0){
            shang=shang+s1;
        }else{
             temp1=temp/B;
             temp2=temp%B;
             sprintf(s2,"%lld",temp1);
             sprintf(s3,"%lld",temp2);
             string s4(s2);
             string s5(s3);
             if(cnt!=0)
               s4.insert(0,length-s4.size()-1,'0');
              cnt++;
             shang=shang+s4;
             str=s5+str;
             if(str[0]=='0'&&str.size()>1){
                str.erase(str.begin());
             }
        }

    }
    if(shang.size()==0){
        shang="0";
    }
    if(str.size()==0){
        str="0";
    }
       cout<<shang<<" "<<str<<endl;
    }else{
        cout<<atoi(str.c_str())/B<<" "<<atoi(str.c_str())%B<<endl;
    }

    return 0;
}
