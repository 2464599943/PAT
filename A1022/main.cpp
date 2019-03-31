#include <iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;
#define maxv 1001
int main()
{
    int N;
    multimap<string,int> record[5];
    string book,aut,words,publish,year,str1,str2;
    int id;
    pair<string,int> p;
    getline(cin,str1);
    N=atoi(str1.c_str());
    for(int i=0;i<N;i++){
       getline(cin,str1);
       getline(cin,book);

       getline(cin,aut);

       getline(cin,words);

       getline(cin,publish);
       getline(cin,year);
       id=atoi(str1.c_str());
       record[0].insert(make_pair(book,id));
       record[1].insert(make_pair(aut,id));
       record[2].insert(make_pair(publish,id));
       record[3].insert(make_pair(year,id));
       int index1=0;
       int index2=0;
       string keys;
       while(index1<words.size()){
           index2=words.find(" ",index1);
           keys=words.substr(index1,index2-index1);
           cout<<keys<<endl;
           index1=index2+1;
           p=make_pair(keys,id);
           record[4].insert(p);
           if(index2==-1)break;
       }

    }

    for(int i=0;i<5;i++){
        cout<<record[i].size()<<endl;
    }
    int M;
    getline(cin,str1);
    M=atoi(str1.c_str());
    string str;
    int type;
    multimap<string,int>::iterator it;
    pair< multimap<string,int>::iterator,multimap<string,int>::iterator > p2;
    for(int i=1;i<=M;i++){
        bool result=false;
        cin>>type;
        if(type==1){
            getline(cin,str1);
            cout<<str<<endl;
        }else if(type==2){
        }else if(type==3){
        }else if(type==4){
        }else{
        }

        for(int j=0;j<5;j++){
            if(record[j].count(str)==0){
                continue;
            }else{
                result=true;
                p2=record[i].equal_range(str);
                it=p2.first;
                while(it!=p2.second){
                    p=*it;
                    cout<<p.second<<endl;
                    it++;
                }
                break;
            }
        }
        if(!result){
            cout<<"Not Found"<<endl;
        }
    }
    return 0;
}
