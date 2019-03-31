#include <iostream>
#include<stdio.h>
#include<string.h>
#include<set>
#include<algorithm>
using namespace std;
set<int> P;
set<int> A;
set<int> T;
set<int>::iterator pit;
set<int>::iterator ait;
set<int>::iterator tit;
int main()
{
    string str;
    cin>>str;
    for(long long i=0;i<str.size();i++){
        if(str[i]=='P'){
          P.insert(i);
        }else if(str[i]=='A'){
             A.insert(i);
        }else if(str[i]=='T'){
            T.insert(i);
        }
    }
    long long index1=0,index2=0,index3=0;
    long long cnt=0;
    long long all=0;
    long long mode=1000000007LL;
    while(cnt<str.size()&&index1<P.size()&&index2<A.size()&&index3<T.size()){
        if(str[cnt]=='P'){
            index1++;
            upper_bound()
            all+=(A.size()-index2)*(T.size()-index3);
            all=all%mode;
        }else if(str[cnt]=='A'){
            index2++;
        }else{
            index3++;
        }
        cnt++;
    }
    all=all%mode;
    cout<<all<<endl;
    return 0;
}
