#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int cnt[30];
int main()
{
    fill(cnt,cnt+30,0);
    string str;
    char c;
    do{
        cin>>str;
        transform(str.begin(),str.end(),str.begin(),::tolower);
        for(int i=0;i<str.size();i++){
            if(str[i]<='z'&&str[i]>='a'){
                cnt[str[i]-'a']++;
            }
        }
        c=getchar();
    }while(c!='\n');
    int maxx=0;
    for(int i=1;i<26;i++){
        if(cnt[maxx]<cnt[i]){
            maxx=i;
        }
    }
    printf("%c %d",'a'+maxx,cnt[maxx]);
    return 0;
}
