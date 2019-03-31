#include <iostream>
#include<string.h>
#include<stdio.h>
#include<map>
using namespace std;
map<char,int> m;
int cnt=0;
string pat="PATest";
int main()
{
    string str;
    cin>>str;
    for(int i=0;i<pat.size();i++){
        m[pat[i]]=0;
    }
    for(int i=0;i<str.size();i++){
        if(str[i]=='P'||str[i]=='A'||str[i]=='T'||str[i]=='e'||str[i]=='s'||str[i]=='t'){
               m[str[i]]++;
               cnt++;
        }
    }
    while(cnt){
        for(int i=0;i<pat.size()&&cnt;i++){
            if(m[pat[i]]!=0){
                    printf("%c",pat[i]);
                    m[pat[i]]--;
                    cnt--;
            }



        }
    }
    return 0;
}
