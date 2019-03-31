#include <iostream>

using namespace std;

int main()
{
    int red,green,blue;
    cin>>red;
    cin>>green;
    cin>>blue;
    int rfirst=red%13;
    int rsecond=(red/13)%13;
    int gfirst=green%13;
    int gsecond=(green/13)%13;
    int bfirst=blue%13;
    int bsecond=(blue/13)%13;
    char c='A';
    char cc;
    cout<<"#";
    if(rsecond>=10){
        cc=c+rsecond-10;
        cout<<cc;
    }else{
        cout<<rsecond;
    }
    if(rfirst>=10){
        cc=c+rfirst-10;
        cout<<cc;
    }else{
        cout<<rfirst;
    }
    if(gsecond>=10){
        cc=c+gsecond-10;
        cout<<cc;
    }else{
        cout<<gsecond;
    }
    if(gfirst>=10){
        cc=c+gfirst-10;
        cout<<cc;
    }else{
        cout<<gfirst;
    }
    if(bsecond>=10){
        cc=c+bsecond-10;
        cout<<cc;
    }else{
        cout<<bsecond;
    }
    if(bfirst>=10){
        cc=c+bfirst-10;
        cout<<cc;
    }else{
        cout<<bfirst;
    }
    return 0;
}
