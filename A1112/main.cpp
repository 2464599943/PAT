#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#define maxnum 37
int help[maxnum];
int fuzhu[maxnum];
int fuzhu2[maxnum];
using namespace std;
int main()
{
    map <char,int> m1;
    map <int,char> m2;
    int cnt=0;
    for(char c='a';c<='z';c++){
        m1[c]=cnt;
        m2[cnt]=c;
        cnt++;
    }
    for(char c='0';c<='9';c++){
        m1[c]=cnt;
        m2[cnt]=c;
        cnt++;
    }
    m1['_']=cnt;
    m2[cnt]='_';
    fill(help,help+maxnum,0);
    fill(fuzhu,fuzhu+maxnum,0);
    fill(fuzhu2,fuzhu2+maxnum,0);
    int K;
    scanf("%d",&K);
    string str;
    cin>>str;
    help[m1[str[0]]]++;
    int last=0;
    set<char> s;
    vector<char> v;
    for(int i=1;i<str.size();i++){
        help[m1[str[i]]]++;
        if(str[i]!=str[last]){
            if(help[m1[str[last]]]%K==0&&fuzhu[m1[str[last]]]!=2){
                s.insert(str[last]);
                if(fuzhu[m1[str[last]]]==0){
                    v.push_back(str[last]);
                }
                fuzhu[m1[str[last]]]=1;
                fuzhu2[m1[str[last]]]+=help[m1[str[last]]]/K;
            }else if(help[m1[str[last]]]%K!=0&&fuzhu[m1[str[last]]]==1){
               fuzhu[m1[str[last]]]=2;
               s.erase(str[last]);
               fuzhu2[m1[str[last]]]=0;
            }
            help[m1[str[last]]]=0;
            last=i;
        }
    }
    if(help[m1[str[last]]]%K==0&&fuzhu[m1[str[last]]]!=2){
        s.insert(str[last]);
        if(fuzhu[m1[str[last]]]==0){
            v.push_back(str[last]);
        }
        fuzhu[m1[str[last]]]=1;
        fuzhu2[m1[str[last]]]+=help[m1[str[last]]]/K;
    }else if(help[m1[str[last]]]%K!=0&&fuzhu[m1[str[last]]]==1){
        fuzhu[m1[str[last]]]=2;
        s.erase(str[last]);
        fuzhu2[m1[str[last]]]=0;
    }
    help[m1[str[last]]]=0;

    set<char> ::iterator it;
    char c;
     for(int i=0;i<v.size();i++){
        if(fuzhu[m1[v[i]]]==1)
             printf("%c",v[i]);
    }
    printf("\n");
    for(it=s.begin();it!=s.end();it++){
        c=*it;
        string str1(1,c);
        string str2(K,c);
        while(fuzhu2[m1[c]]--){
            str.replace(str.find(str2),K,str1);
        }
    }
    cout<<str;
    return 0;
}
