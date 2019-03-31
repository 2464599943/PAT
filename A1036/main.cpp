#include <iostream>
#define inf 100000000
using namespace std;

int main()
{
    int N;
    string name1,name2,id1,id2;
    int highest=-1,lowest=inf;
    cin>>N;
    string str1,str2,str3;
    int num;
    for(int i=0;i<N;i++){
        cin>>str1>>str2>>str3;
        cin>>num;
        if(str2=="M"){
              if(num<lowest){
                lowest=num;
                name2=str1;
                id2=str3;
              }

        }else if(str2=="F"){
              if(num>highest){
                 highest=num;
                 name1=str1;
                 id1=str3;
              }
        }
    }
    int ok=1;
    if(highest==-1||lowest==inf)ok=0;
    if(highest==-1){
        cout<<"Absent";
    }else{
        cout<<name1<<" "<<id1;
    }
    cout<<endl;
    if(lowest==inf){
        cout<<"Absent";
    }else{
        cout<<name2<<" "<<id2;
    }
    cout<<endl;
    if(ok==0){
        cout<<"NA";
    }else{
        cout<<highest-lowest;
    }
    return 0;
}
