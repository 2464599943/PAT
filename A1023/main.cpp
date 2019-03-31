#include <iostream>
#include<stdio.h>
using namespace std;
bool doublenum(int *num,int sizee){
    int jin=0;
    for(int i=sizee-1;i>=0;i--){
        if(2*num[i]+jin>9){
            num[i]=2*num[i]+jin-10;
            jin=1;
        }else{
            num[i]=2*num[i]+jin;
            jin=0;
        }
    }
    if(jin==1)return false;
    return true;
}
int main()
{
    string a;
    cin>>a;
    int num[25];
    int num2[10];
    int num3[10];
    for(int i=0;i<10;i++){
        num2[i]=0;
        num3[i]=0;
    }
    int sizee=a.size();
    for(int i=0;i<a.size();i++){
        num[i]=a[i]-'0';
        num2[num[i]]++;
    }
    bool result=doublenum(num,sizee);
    if(result){

        for(int i=0;i<sizee;i++){
            num3[num[i]]++;
        }
        for(int i=0;i<10;i++){
            if(num2[i]!=num3[i]){
                result=false;
                break;
            }
        }
        if(result){
           cout<<"Yes"<<endl;
        }
        else{
             cout<<"No"<<endl;
        }
    }else{
        cout<<"No"<<endl;
        cout<<1;
    }
     for(int i=0;i<sizee;i++){
           cout<<num[i];
        }
    return 0;
}
