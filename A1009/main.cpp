#include <iostream>
#include<iomanip>
using namespace std;
#define maxN 1001
int main()
{
    double a[maxN];
    double b[maxN];
    double c[2*maxN];
    for(int i=0;i<maxN;i++){
        a[i]=0.0;
        b[i]=0.0;
    }
    for(int i=0;i<2*maxN;i++){
        c[i]=0.0;
    }
    int K1,K2,index;
    cin>>K1;
    for(int i=0;i<K1;i++){
        cin>>index;
        cin>>a[index];
    }
    cin>>K2;
    for(int i=0;i<K2;i++){
        cin>>index;
        cin>>b[index];
    }
    for(int i=0;i<maxN;i++){
        for(int j=0;j<maxN;j++){
            c[i+j]+=a[i]*b[j];
        }
    }
    int result=0;
     for(int i=0;i<2*maxN;i++){
         if(c[i]>0.1||c[i]<-0.1){
            result++;
         }
    }
    cout<<result;
    for(int i=2*maxN-1;i>=0;i--){
         if(c[i]>0.1||c[i]<-0.1){
            cout<<" "<<i<<" ";
            cout<<setiosflags(ios::fixed)<<setprecision(1)<<c[i];
         }
    }
    return 0;
}
