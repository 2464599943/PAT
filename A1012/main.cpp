#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct courseC{
    int id;
    int grade;
};
struct courseM{
    int id;
    int grade;
};
struct courseE{
    int id;
    int grade;
};
struct courseA{
    int id;
    double grade;
};
bool cmp1(courseC a,courseC b){
    return a.grade>b.grade;
}
bool cmp2(courseM a,courseM b){
    return a.grade>b.grade;
}
bool cmp3(courseE a,courseE b){
    return a.grade>b.grade;
}
bool cmp4(courseA a,courseA b){
    return a.grade>b.grade;
}
int bestC(courseC* CC,int c){
    for(int i=c-1;i>=0;i--){
        if(CC[i].grade!=CC[c].grade){
            return i+1;
        }
    }
    return 0;
}
int bestM(courseM* MM,int m){
    for(int i=m-1;i>=0;i--){
        if(MM[i].grade!=MM[m].grade){
            return i+1;
        }
    }
    return 0;
}
int bestE(courseE* EE,int e){
    for(int i=e-1;i>=0;i--){
        if(EE[i].grade!=EE[e].grade){
            return i+1;
        }
    }
    return 0;
}
int bestA(courseA* AA,int a){
    for(int i=a-1;i>=0;i--){
        if(AA[i].grade!=AA[a].grade){
            return i+1;
        }
    }
    return 0;
}
int findidC(courseC *CC,int N,int id){
    for(int i=0;i<N;i++){
        if(CC[i].id==id){
            return i;
        }
    }
    return -1;
}
int findidM(courseM *MM,int N,int id){
    for(int i=0;i<N;i++){
        if(MM[i].id==id){
            return i;
        }
    }
    return -1;
}
int findidE(courseE *EE,int N,int id){
    for(int i=0;i<N;i++){
        if(EE[i].id==id){
            return i;
        }
    }
    return -1;
}
int findidA(courseA *AA,int N,int id){
    for(int i=0;i<N;i++){
        if(AA[i].id==id){
            return i;
        }
    }
    return -1;
}
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    courseC *CC=new courseC[N];
    courseM *MM=new courseM[N];
    courseE *EE=new courseE[N];
    courseA *AA=new courseA[N];
    int id;
    for(int i=0;i<N;i++){
        scanf("%d%d%d%d",&id,&CC[i].grade,&MM[i].grade,&EE[i].grade);
        CC[i].id=MM[i].id=EE[i].id=AA[i].id=id;
        AA[i].grade=round((CC[i].grade+MM[i].grade+EE[i].grade)/3);
    }
    sort(CC,CC+N,cmp1);
    sort(MM,MM+N,cmp2);
    sort(EE,EE+N,cmp3);
    sort(AA,AA+N,cmp4);
    int c,m,e,a,minn1,minn2,minn;
    char first='C',second='M',third='E',fourth='A';
    for(int i=0;i<M;i++){
        scanf("%d",&id);
        c=findidC(CC,N,id);
        if(c==-1){
            printf("N/A\n");
            continue;
        }
        m=findidM(MM,N,id);
        e=findidE(EE,N,id);
        a=findidA(AA,N,id);
        c=bestC(CC,c);
        m=bestM(MM,m);
        e=bestE(EE,e);
        a=bestA(AA,a);
        minn1=min(c,m);
        minn2=min(e,a);
        minn=min(minn1,minn2);
        printf("%d ",minn+1);
        if(minn==a){
            printf("%c\n",fourth);
        }else if(minn==c){
            printf("%c\n",first);
        }else if(minn==m){
            printf("%c\n",second);
        }else{
            printf("%c\n",third);
        }

    }

    return 0;
}
