#include <iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<math.h>
#include<string.h>
#define maxN 100010
using namespace std;
int hashh[maxN];
int maxb=(int)pow(maxN,0.5);
int main()
{
    int N;
    scanf("%d",&N);
    string push="Push";
    string pop="Pop";
    string peek="PeekMedian";
    string operation;
    int num;
    stack<int> s;
    int block[maxb+1];
    fill(hashh,hashh+maxN,0);
    fill(block,block+maxb+1,0);
    int temp1,temp2;
    for(int i=0;i<N;i++){
        cin>>operation;
        if(operation==push){
            scanf("%d",&num);
            s.push(num);
            hashh[num]++;
            temp1=num/maxb;
            block[temp1]++;
        }else if(operation==pop){
            if(s.empty()){
                printf("Invalid\n");
            }else{
                num=s.top();
                s.pop();
                temp1=num/maxb;
                block[temp1]--;
                hashh[num]--;
                printf("%d\n",num);
            }
        }else if(operation==peek){
            if(s.empty()){
               printf("Invalid\n");
            }
            else{
            int where=(s.size()+1)/2;
            int k=0;
            temp2=block[k];
            while(where>temp2&&k<=maxb){
                k++;
                temp2+=block[k];
            }
            temp2-=block[k];
            temp1=k*maxb;
            int i;
            for(i=temp1;i<temp1+maxb;i++){
                temp2+=hashh[i];
                if(temp2>=where){
                    break;
                }
            }
            printf("%d\n",i);
            }
        }
    }
    return 0;
}
