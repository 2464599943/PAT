#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    double first=0.0,second=0.0,third=0.0;
    int flag1,flag2,flag3;
    double num;
    for(int i=1;i<=3;i++){
        cin>>num;
        if(num>first){
            first=num;
            flag1=i;
        }
    }
    for(int i=1;i<=3;i++){
        cin>>num;
        if(num>second){
            second=num;
            flag2=i;
        }
    }
    for(int i=1;i<=3;i++){
        cin>>num;
        if(num>third){
            third=num;
            flag3=i;
        }
    }
    if(flag1==1){
        cout<<'W';
    }else if(flag1==2){
        cout<<'T';
    }else{
        cout<<'L';
    }
    cout<<" ";
    if(flag2==1){
        cout<<'W';
    }else if(flag2==2){
        cout<<'T';
    }else{
        cout<<'L';
    }
    cout<<" ";
    if(flag3==1){
        cout<<'W';
    }else if(flag3==2){
        cout<<'T';
    }else{
        cout<<'L';
    }
    cout<<" ";
    double result=(first*second*third*0.65-1)*2;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<result;
    return 0;
}
