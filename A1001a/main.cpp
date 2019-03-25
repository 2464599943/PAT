#include <iostream>

using namespace std;

int main()
{
    int A,B,C;
    cin>>A>>B;
    C=A+B;
    if(C<0){
        cout<<"-";
        C=-C;
    }
    if(C<10000){
        cout<<C;
    }
    else{
        int *c=new int[10];
        int num1,num2;
        num1=C;
        int countt=9;
        while(num1!=0){
            num2=num1%10;
            num1=num1/10;
            c[countt]=num2;
            countt--;
        }
        int j=1;
        for(int i=countt+1;i<10;i++){
           cout<<c[i];
           if(j==3&&i!=9){
            cout<<",";
            j=0;
           }
            j++;
        }
    }
    return 0;
}
