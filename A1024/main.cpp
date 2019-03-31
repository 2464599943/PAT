#include <iostream>
#define maxsize 10000
#include<string.h>
using namespace std;
bool ifpalindromic(int *orgin,int size1){
     bool result=true;
     for(int i=0;i<size1/2;i++){

         int num1=orgin[maxsize-size1+i];
         int num2=orgin[maxsize-1-i];
         if(num1!=num2){
              result=false;
              break;
         }
     }
     return result;
}
int add(int* orgin,int size1){
    int result[maxsize];
    int jinwei=0,num1,num2;
    for(int i=0;i<size1;i++){
        num1=orgin[maxsize-1-i];
        num2=orgin[maxsize-size1+i];
        if(num1+num2+jinwei>9){
            result[maxsize-1-i]=num1+num2+jinwei-10;
            jinwei=1;
        }else{
             result[maxsize-1-i]=num1+num2+jinwei;
             jinwei=0;
        }
    }
    if(jinwei==1){
        size1++;
        result[maxsize-size1]=1;
    }
    for(int i=0;i<size1;i++){
        orgin[maxsize-size1+i]=result[maxsize-size1+i];
    }
    return size1;
}
int main()
{
    string str="";
    int K=0;
    cin>>str;
    cin>>K;
    int num[maxsize];
    int size2=str.size();
    bool yuan=true;
    for(int i=0;i<str.size();i++){
        num[maxsize-1-i]=str[str.size()-1-i]-'0';
    }

    yuan=ifpalindromic(num,str.size());
    int countt=0;
   while(!yuan&&countt<K){
      size2=add(num,size2);
      yuan=ifpalindromic(num,size2);
      countt++;
   }

   for(int i=0;i<size2;i++){
      cout<<num[maxsize-size2+i];
   }
   cout<<endl<<countt;

    return 0;
}
