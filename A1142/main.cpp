#include <iostream>
#include<set>
#include<stdio.h>
#define maxN 210
using namespace std;
set<int> s[maxN];
set<int>::iterator it;
set<int>::iterator sit;
int num[maxN];
int main()
{
    int Nv,Ne,v1,v2;
    scanf("%d%d",&Nv,&Ne);
    for(int i=0;i<Ne;i++){
        scanf("%d%d",&v1,&v2);
        s[v1].insert(v2);
        s[v2].insert(v1);
    }
    int M,K;
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        scanf("%d",&K);
        bool result=true;
        for(int j=0;j<K;j++){
            scanf("%d",&num[j]);
        }
        for(int j=0;j<K;j++){
            for(int k=0;k<K;k++){
                if(j!=k){
                it=s[num[j]].find(num[k]);
                if(it==s[num[j]].end()){
                    result=false;
                    break;
                }
                }
            }
            if(!result){
                break;
            }

        }
        if(!result){
            printf("Not a Clique\n");
        }else{
            bool flag=false;
            bool flag2=true;
            if(K==1)flag=false;
            for(sit=s[num[0]].begin();sit!=s[num[0]].end();sit++){
                v1=*sit;
                flag2=true;
                for(int j=1;j<K;j++){
                    it=s[num[j]].find(v1);
                    if(it==s[num[j]].end()){
                        flag2=false;
                        break;
                    }
                }
                if(flag2){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                printf("Yes\n");
            }else{
                printf("Not Maximal\n");
            }
        }
    }
    return 0;
}
