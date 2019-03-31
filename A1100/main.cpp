#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<map>
using namespace std;
string first[20]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string second[20]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string,int> m1;
map<string,int> m2;
map<string,int>::iterator it;
int main()
{
    int N;
    cin>>N;
    string line;
    getchar();
    for(int i=0;i<13;i++){
        m1[first[i]]=i;
        m2[second[i]]=i;
    }
    for(int i=0;i<N;i++){
        getline(cin,line);
        if(line.size()==0){
            cout<<first[0]<<endl;
            continue;
        }
        if(line[0]<='9'&&line[0]>='0'){
            int temp1=atoi(line.c_str());
            int temp2=temp1/13;
            int temp3=temp1%13;
            if(temp2==0){
                cout<<first[temp3];
            }else if(temp3!=0){
                cout<<second[temp2]<<" "<<first[temp3];
            }else{
                 cout<<second[temp2];
            }
        }else{
            int index=line.find(" ");
            if(index==-1){
                it=m1.find(line);
                if(it==m1.end()){
                    cout<<m2[line]*13;
                }else{
                    cout<<m1[line];
                }
            }else{
                string str1=line.substr(0,index);
                string str2=line.substr(index+1,line.size()-index-1);
                cout<<m2[str1]*13+m1[str2];
            }
        }
        cout<<endl;
    }

    return 0;
}
