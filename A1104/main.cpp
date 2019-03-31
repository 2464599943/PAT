#include <iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
    int N;
    double temp;
    double all=0.0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lf",&temp);
        all+=temp*(i+1)*(N-i);
    }
    printf("%.2f",all);
    return 0;
}
