#include <iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int strsize=str.size();
    int N=strsize+2;
    int n2;
    if(N%3==0){
        n2=N/3;
    }else{
        n2=N/3+1;
    }
    while((N-n2)%2!=0){
        n2++;
    }
    int n1=(N-n2)/2;
    for(int i=0;i<n1-1;i++){
        cout<<str[i];
        for(int j=0;j<n2-2;j++){
            cout<<" ";
        }
        cout<<str[strsize-1-i];
        cout<<endl;
    }
    for(int i=0;i<n2;i++){
        cout<<str[n1+i-1];
    }
    return 0;
}
