#include <iostream>

using namespace std;
struct node{
    int id;
    int virtue;
    int talent;
};
int main()
{
    int N,L,H;
    cin>>N>>L>>H;
    node *grade=new node[N];
    int *help1=new int[N];
    int *help2=new int[N];
    int *help3=new int[N];
    int *help4=new int[N];
    int id,virtue,talent;
    int M=0;
    int sages=0;
    int nobleman=0;
    int foolman=0;
    int small=0;
    for(int i=0;i<N;i++){
        cin>>id;
        cin>>virtue;
        cin>>talent;
        if(virtue>=L&&talent>=L){
            grade[M].id=id;
            grade[M].virtue=virtue;
            grade[M].talent=talent;
            if(virtue>=H&&talent>=H){
                help1[sages]=M;
                sages++;
            }else if(virtue>=H&&talent<H){
                help2[nobleman]=M;
                nobleman++;
            }else if(virtue>=talent&&virtue<H){
                help3[foolman]=M;
                foolman++;
            }else{
                help4[small]=M;
                small++;
            }
            M++;
        }

    }
    cout<<M<<endl;
    int maxx,num1,num2;
    for(int i=0;i<sages-1;i++){
        maxx=i;
        for(int j=i+1;j<sages;j++){
            num1=grade[help1[maxx]].virtue+grade[help1[maxx]].talent;
            num2=grade[help1[j]].virtue+grade[help1[j]].talent;
            if(num1<num2){
                maxx=j;
            }else if(num1==num2){
                if(grade[help1[maxx]].virtue<grade[help1[j]].virtue){
                    maxx=j;
                }else if(grade[help1[maxx]].virtue==grade[help1[j]].virtue&&grade[help1[maxx]].id>grade[help1[j]].id){
                    maxx=j;
                }
            }
        }
        swap(help1[i],help1[maxx]);
        cout<<grade[help1[i]].id<<" "<<grade[help1[i]].virtue<<" "<<grade[help1[i]].talent<<endl;
    }
     cout<<grade[help1[sages-1]].id<<" "<<grade[help1[sages-1]].virtue<<" "<<grade[help1[sages-1]].talent<<endl;

    for(int i=0;i<nobleman-1;i++){
        maxx=i;
        for(int j=i+1;j<nobleman;j++){
            num1=grade[help2[maxx]].virtue+grade[help2[maxx]].talent;
            num2=grade[help2[j]].virtue+grade[help2[j]].talent;
            if(num1<num2){
                maxx=j;
            }else if(num1==num2){
                if(grade[help2[maxx]].virtue<grade[help2[j]].virtue){
                    maxx=j;
                }
                else if(grade[help2[maxx]].virtue==grade[help2[j]].virtue&&grade[help2[maxx]].id>grade[help2[j]].id){
                    maxx=j;
                }
            }
        }
        swap(help2[i],help2[maxx]);
         cout<<grade[help2[i]].id<<" "<<grade[help2[i]].virtue<<" "<<grade[help2[i]].talent<<endl;
    }
     cout<<grade[help2[nobleman-1]].id<<" "<<grade[help2[nobleman-1]].virtue<<" "<<grade[help2[nobleman-1]].talent<<endl;
    for(int i=0;i<foolman-1;i++){
        maxx=i;
        for(int j=i+1;j<foolman;j++){
            num1=grade[help3[maxx]].virtue+grade[help3[maxx]].talent;
            num2=grade[help3[j]].virtue+grade[help3[j]].talent;
            if(num1<num2){
                maxx=j;
            }else if(num1==num2){
                if(grade[help3[maxx]].virtue<grade[help3[j]].virtue){
                     maxx=j;
                }else if(grade[help3[maxx]].virtue==grade[help3[j]].virtue&&grade[help3[maxx]].id>grade[help3[j]].id){
                     maxx=j;
                }
            }
        }
        swap(help3[i],help3[maxx]);
         cout<<grade[help3[i]].id<<" "<<grade[help3[i]].virtue<<" "<<grade[help3[i]].talent<<endl;
    }
    cout<<grade[help3[foolman-1]].id<<" "<<grade[help3[foolman-1]].virtue<<" "<<grade[help3[foolman-1]].talent<<endl;

   for(int i=0;i<small-1;i++){
        maxx=i;
        for(int j=i+1;j<small;j++){
            num1=grade[help4[maxx]].virtue+grade[help4[maxx]].talent;
            num2=grade[help4[j]].virtue+grade[help4[j]].talent;
            if(num1<num2){
                maxx=j;
            }else if(num1==num2){
                if(grade[help4[maxx]].virtue<grade[help4[j]].virtue){
                    maxx=j;
                }
                else if(grade[help4[maxx]].virtue==grade[help4[j]].virtue&&grade[help4[maxx]].id>grade[help4[j]].id){
                    maxx=j;
                }

            }
        }
        swap(help4[i],help4[maxx]);
         cout<<grade[help4[i]].id<<" "<<grade[help4[i]].virtue<<" "<<grade[help4[i]].talent<<endl;
    }
    cout<<grade[help4[small-1]].id<<" "<<grade[help4[small-1]].virtue<<" "<<grade[help4[small]].talent;


    return 0;
}
