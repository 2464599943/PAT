#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
vector<int> a;
int main()
{
    int N1,N2,temp;
    scanf("%d",&N1);
    for(int i=0;i<N1;i++){
        scanf("%d",&temp);
        a.push_back(temp);
    }
     scanf("%d",&N2);
     int index1=0;
     int half=(N1+N2+1)/2;
     int cnt=0;
    for(int i=0;i<N2;i++){
        scanf("%d",&temp);
        if(index1<a.size()&&a[index1]<temp&&cnt<half){
            while(index1<a.size()&&a[index1]<temp&&cnt<half){
                cnt++;
               if(cnt==half){
                  cout<<a[index1]<<endl;
                  break;
               }
                index1++;

            }
            cnt++;
            if(cnt==half){
                cout<<temp<<endl;
            }
        }else{
            cnt++;
            if(cnt==half){
                cout<<temp<<endl;
            }
        }
    }
    while(cnt<half){
        cnt++;
        if(cnt==half){
             cout<<a[index1]<<endl;
        }
        index1++;
    }

    return 0;
}
