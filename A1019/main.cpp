#include <iostream>
#include<stack>
using namespace std;

int main()
{
    int N,b;
    cin>>N>>b;
    stack<int> s;
    int shang=N/b;
    int yu=N%b;
    s.push(yu);
    while(shang!=0){
        yu=shang%b;
        shang=shang/b;
        s.push(yu);
    }
    int sizee=s.size();
    int *a=new int[sizee];
    int i=0;
    while(!s.empty()){
        yu=s.top();
        s.pop();
        a[i]=yu;
        i++;
    }
    int ok=1;
    for(int i=0;i<=sizee/2;i++){
        if(a[i]!=a[sizee-1-i]){
            ok=0;
            break;
        }
    }
    if(ok==1){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    cout<<endl;
    for(int i=0;i<sizee-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[sizee-1];
    return 0;
}
