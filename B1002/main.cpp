#include <iostream>
#include<stdio.h>
#include<string.h>
#define maxN 20
using namespace std;
char a[maxN];
int main()
{
    string str;
    cin>>str;
    int all=0;
    for(int i=0;i<str.size();i++){
        all+=str[i]-'0';
    }
    sprintf(a,"%d",all);
    for(int i=0;i<strlen(a);i++){
        if(i!=0){
            printf(" ");
        }
        switch(a[i]){
        case '0':
            printf("ling");
            break;
        case '1':
            printf("yi");
            break;
        case '2':
            printf("er");
            break;
        case '3':
            printf("san");
            break;
        case '4':
            printf("si");
            break;
        case '5':
            printf("wu");
            break;
        case '6':
            printf("liu");
            break;
        case '7':
            printf("qi");
            break;
        case '8':
            printf("ba");
            break;
        case '9':
            printf("jiu");
            break;
        }
    }
    return 0;
}
