#include <iostream>
#define inf 10000000
using namespace std;

int main()
{
    int N;
    cin>>N;
    string *str=new string[N];
    int *length=new int[N];
    string s;
    getline(cin,s);
    for(int i=0;i<N;i++){
        getline(cin,str[i]);
        length[i]=str[i].size();
    }
    int minn=inf;
    for(int i=0;i<N;i++){
        if(minn>str[i].size()){
            minn=str[i].size();
        }
    }
    char c;
    bool ok=true;
    int i;
    for(i=1;i<=minn;i++){
        c=str[0][length[0]-i];
        for(int j=1;j<N;j++){
            if(str[j][length[j]-i]!=c){
                ok=false;
                break;
            }

        }
        if(ok==false){
                break;
            }
    }
    s=str[0].substr(length[0]-i+1,i);
    if(s.size()==0){
        cout<<"nai";
    }else{
        cout<<s;
    }

    return 0;
}
