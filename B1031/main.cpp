#include <iostream>
#include<stdio.h>
using namespace std;
char m[11]={'1','0', 'X','9' ,'8', '7' ,'6' ,'5', '4' ,'3', '2'};
int w[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
string str;
int result;
bool handle(){
    result=0;
    for(int i=0;i<str.size()-1;i++){
        if(str[i]<='9'&&str[i]>='0'){
            result+=w[i]*(str[i]-'0');
            continue;
        }else{
            return false;
        }
    }
    result=result%11;
    if(m[result]!=str[str.size()-1])return false;
    return true;

}
int main()
{
    int N;
    scanf("%d",&N);
    int cnt=0;
    for(int i=0;i<N;i++){
        cin>>str;
        if(handle()){
           cnt++;
        }else{
        cout<<str<<endl;
        }

    }
    if(cnt==N){
        cout<<"All passed"<<endl;
    }
    return 0;
}
