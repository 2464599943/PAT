#include <iostream>

using namespace std;

int main()
{
    int N;
    long long A,B,C,D;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A;
        cin>>B;
        cin>>C;
        D=A+B;
        if(A>0&&B>0&&D<0){
             cout<<"Case #"<<i<<": true";
        }
        else if(A<0&&B<0&&D>0){
            cout<<"Case #"<<i<<": false";
        }
        else if(D>C){
                cout<<"Case #"<<i<<": true";
        }
        else{
                cout<<"Case #"<<i<<": false";

        }
        cout<<endl;

    }
    return 0;
}
