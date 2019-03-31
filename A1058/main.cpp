#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
    string A,B;
    cin>>A;
    cin>>B;
    string str1;
    long long AA=0,BB=0;
    int num1,num2,num3,afirst,asecond,athird,bfirst,bsecond,bthird;
    num1=A.find(".");
    str1=A.substr(0,num1);
    afirst=atoi(str1.c_str());
    num2=A.find(".",num1+1);
    str1=A.substr(num1+1,num2-num1-1);
    asecond=atoi(str1.c_str());
    str1=A.substr(num2+1,A.size()-num2);
    athird=atoi(str1.c_str());
    num1=B.find(".");
    str1=B.substr(0,num1);
    bfirst=atoi(str1.c_str());
    num2=B.find(".",num1+1);
    str1=B.substr(num1+1,num2-num1-1);
    bsecond=atoi(str1.c_str());
    str1=B.substr(num2+1,B.size()-num2);
    bthird=atoi(str1.c_str());
    int cfirst,csecond,cthird;
    cthird=athird+bthird;
    int c=0,b=0;
    if(cthird>=29){
        cthird=cthird-29;
        c=1;
    }
    csecond=asecond+bsecond+c;
    if(csecond>=17){
        csecond=csecond-17;
        b=1;
    }
    cfirst=afirst+bfirst+b;
    cout<<cfirst<<"."<<csecond<<"."<<cthird;
    return 0;
}
