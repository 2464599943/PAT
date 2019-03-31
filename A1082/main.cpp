#include <iostream>
#include<stack>
#include<queue>
using namespace std;
string digits[15]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","Shi","Bai","Qian","Wan","Yi"};
int main()
{
   int N;
   cin>>N;
   string str;
   if(N<0){
     cout<<"Fu ";
     N=-N;
   }
   stack<int> s;
   int num1=N,num2;
   num2=num1%10;
   num1=num1/10;
   s.push(num2);
   int round=2,all=2;
   while(num1!=0){
       num2=num1%10;
       num1=num1/10;
       if(round==2){
         s.push(10);
       }else if(round==3){
         s.push(11);
       }else if(round==4){
         s.push(12);
         round=0;
       }
       if(all==5){
         s.push(13);
       }else if(all==9){
         s.push(14);
       }
       s.push(num2);
       round++;
       all++;
   }
   int sizee=s.size();
   int *a=new int[sizee];
   int countt=0;
    while(!s.empty()){
        num1=s.top();
        s.pop();
        a[countt]=num1;
        countt++;
    }
    bool ok=true;
    queue<int> help;
    for(int i=0;i<sizee;i++){
        if(a[i]!=0){
           help.push(a[i]);
        }
        else{
            if(i==sizee-15&&a[i+2]==0){
                i=i+1;
            }
            else if(i==sizee-15&&a[i+2]!=0){
                help.push(a[i]);
                i=i+1;
            }else if(i==sizee-13&&a[i+2]==0){
                i=i+1;
            }else if(i==sizee-13&&a[i+2]!=0){
                help.push(a[i]);
                i=i+1;
            }else if(i==sizee-11&&a[i+2]==0){
                i=i+1;
            }else if(i==sizee-11&&a[i+2]!=0){
                help.push(i);
                i=i+1;
            }else if(i==sizee-9){

            }else if(i==sizee-7&&a[i+2]!=0){
                 help.push(a[i]);
                 i=i+1;
            }else if(i==sizee-7&&a[i+2]==0){
                 i=i+1;
            }else if(i==sizee-5&&a[i+2]==0){
                i=i+1;
            }else if(i==sizee-5&&a[i+2]!=0){
                help.push(a[i]);
                i=i+1;
            }else if(i==sizee-3&&a[i+2]==0){
                i=i+1;
                break;
            }else if(i==sizee-3&&a[i+2]!=0){
                help.push(a[i]);
                i=i+1;

            }
        }

    }
    while(!help.empty()){
        num1=help.front();
        help.pop();
        cout<<digits[num1];
        if(!help.empty()){
            cout<<" ";
        }
    }
    if(N==0){
        cout<<digits[0];
    }
    return 0;
}
