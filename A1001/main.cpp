#include <iostream>
#include<stack>
using namespace std;
void output(int yu){
    if(yu<10){
        cout<<"00"<<yu;

    }
    else if(yu<100){
        cout<<"0"<<yu;
    }
    else{
        cout<<yu;
    }
}
int main()
{
    int A,B,C,shang,yu;
    cin>>A>>B;
    C=A+B;
    stack<int> s;
    if(C<0){
        cout<<"-";
        C=-C;
    }
    if(C<10000){
        cout<<C;
    }
    else{
    yu=C%1000;
    shang=C/1000;
    s.push(yu);
    while(shang!=0){
        yu=shang%1000;
        shang=shang/1000;
        s.push(yu);
    }

        yu=s.top();
        s.pop();
       cout<<yu;
        if(!s.empty()){

            cout<<",";
        }

        while(!s.empty()){
        yu=s.top();
        s.pop();
       output(yu);
       if(!s.empty()){
            cout<<",";
        }
    }
    }
    return 0;
}
