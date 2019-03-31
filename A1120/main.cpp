#include <iostream>
#include<stdio.h>
#include<string.h>
#include<set>
#define maxdigit 10
using namespace std;

int main()
{
    char a[maxdigit];
    int N;
    scanf("%d",&N);
    set<int> s;
    for(int i=0;i<N;i++){
        scanf("%s",a);
        int all=0;
        for(int j=0;j<strlen(a);j++){
            all+=a[j]-'0';
        }
        s.insert(all);
    }
    printf("%d\n",s.size());
    set<int>::iterator it;
    int cnt=0;
    for(it=s.begin();it!=s.end();it++){
        cnt++;
        if(cnt==1)
            printf("%d",*it);
        else
            printf(" %d",*it);
    }
    printf("\n");
    return 0;
}
