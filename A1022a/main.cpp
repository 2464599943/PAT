#include <iostream>
#include<stdio.h>
#include<string>
#include<set>
#include<map>
using namespace std;
map<string,set<int> >title,author,keywords,publisher,years;
map<string,set<int> >::iterator it;

bool findtitle(string s){
    it=title.find(s);
    if(it==title.end()){
        return false;
    }
    set<int>::iterator sit;
    for(sit=title[s].begin();sit!=title[s].end();sit++){
        printf("%07d\n",*sit);
    }
    return true;
}
bool findauthor(string s){
    it=author.find(s);
    if(it==author.end()){
        return false;
    }
    set<int>::iterator sit;
    for(sit=author[s].begin();sit!=author[s].end();sit++){
        printf("%07d\n",*sit);
    }
    return true;
}
bool findkeywords(string s){
    it=keywords.find(s);
    if(it==keywords.end()){
        return false;
    }
    set<int>::iterator sit;
    for(sit=keywords[s].begin();sit!=keywords[s].end();sit++){
        printf("%07d\n",*sit);
    }
    return true;
}
bool findpublisher(string s){
    it=publisher.find(s);
    if(it==publisher.end()){
        return false;
    }
    set<int>::iterator sit;
    for(sit=publisher[s].begin();sit!=publisher[s].end();sit++){
        printf("%07d\n",*sit);
    }
    return true;
}
bool findyear(string s){
    it=years.find(s);
    if(it==years.end()){
        return false;
    }
    set<int>::iterator sit;
    for(sit=years[s].begin();sit!=years[s].end();sit++){
        printf("%07d\n",*sit);
    }
    return true;
}

int main()
{

    int N;
    scanf("%d",&N);
   ;
    string stitle,sauthor,skeywords,spublisher,syear;
    int id;
    for(int i=0;i<N;i++){
        scanf("%d",&id);
        getchar();
        getline(cin,stitle);
        getline(cin,sauthor);
        getline(cin,skeywords);
        getline(cin,spublisher);
        getline(cin,syear);
        title[stitle].insert(id);
        author[sauthor].insert(id);
        publisher[spublisher].insert(id);
        years[syear].insert(id);
        int index1=0;
        int index2;
        string str;
        while(index1<skeywords.size()){
            index2=skeywords.find(" ",index1);
            if(index2==-1){
                str=skeywords.substr(index1,skeywords.size()-index1);
                keywords[str].insert(id);
                break;
            }
            str=skeywords.substr(index1,index2-index1);
            index1=index2+1;
            keywords[str].insert(id);
        }

    }
    int M;
    scanf("%d",&M);
    int type;
    string s;
    for(int i=0;i<M;i++){
        scanf("%d: ",&type);
        getline(cin,s);
        bool result;
        printf("%d: %s\n",type,s.c_str());
        if(type==1){
            result=findtitle(s);
        }else if(type==2){
            result=findauthor(s);
        }else if(type==3){
            result=findkeywords(s);
        }else if(type==4){
            result=findpublisher(s);
        }else{
            result=findyear(s);
        }
        if(!result)printf("Not Found\n");
    }
    return 0;
}
