#include <iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    N++;
    int *distance=new int[N];
    int all=0,num;
    for(int i=2;i<N;i++){
        cin>>num;
        all+=num;
        distance[i]=all;
    }
    cin>>num;
    all+=num;
    distance[1]=all;
    int M;
    cin>>M;
    int num1,num2;
    for(int i=0;i<M;i++){
        cin>>num1>>num2;
       cout<<min(abs(distance[num1]-distance[num2]),all-abs(distance[num1]-distance[num2]));
       cout<<endl;
    }
    return 0;
}
