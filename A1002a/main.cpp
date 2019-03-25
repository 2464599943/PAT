#include <iostream>
#include<iomanip>
using namespace std;
#define maxN 1001
int main()
{
    double other[maxN];
    for(int i=0;i<maxN;i++){
        other[i]=0.0;
    }
    int K1,K2,index;
    double num;
    cin>>K1;
    for(int i=0;i<K1;i++){
        cin>>index;
        cin>>other[index];
    }
    cin>>K2;
    int countt=0;
    for(int i=0;i<K2;i++){
        cin>>index;
        cin>>num;
        other[index]+=num;

    }
    for(int i=maxN-1;i>=0;i--){
        if(other[i]>0.1||other[i]<-0.1){
           countt++;
        }
    }
    cout<<countt;
    for(int i=maxN-1;i>=0;i--){
        if(other[i]>0.1||other[i]<-0.1){
            cout<<" "<<i<<" ";
            cout<<setiosflags(ios::fixed)<<setprecision(1)<<other[i];
        }
    }
    return 0;
}
