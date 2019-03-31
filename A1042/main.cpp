#include <iostream>
#include<string>
using namespace std;
#define num 55
string inital[num]={"","S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
                       "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
                       "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
                       "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
                       "J1","J2"
 };
string* handle(int *order,string *cards){
    string *solve=new string[num];
    for(int i=1;i<num;i++){
         solve[order[i]]=cards[i];
    }
    return solve;
}
int main()
{
    int N;
    cin>>N;
    int *order=new int[num];
    for(int i=1;i<num;i++){
        cin>>order[i];
    }
    string *solve;
    string *cards=new string[num];
    for(int i=1;i<num;i++){
        cards[i]=inital[i];
    }
    for(int i=0;i<N;i++){
        solve=handle(order,cards);
        swap(cards,solve);
    }
    for(int i=1;i<num-1;i++){
        cout<<cards[i]<<" ";
    }
    cout<<cards[num-1];
    return 0;
}
