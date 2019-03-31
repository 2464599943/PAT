#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    char a[50];
    char b[50];
    double temp;
    int N;
    scanf("%d",&N);
    int countt=0;
    double all=0.0;
    for(int i=0;i<N;i++){
        scanf("%s",a);
        sscanf(a,"%lf",&temp);
        sprintf(b,"%.2lf",temp);
        bool result=true;
        for(int j=0;j<strlen(a);j++){
            if(a[j]!=b[j]){
                result=false;
            }
        }

        if(!result||temp>1000||temp<-1000){
            printf("ERROR: %s is not a legal number\n",a);
        }else{
            countt++;
            all+=temp;
        }
    }
    if(countt==0){
        printf("The average of 0 numbers is Undefined\n");
    }else if(countt==1){
        printf("The average of 1 number is %.2lf\n",all);
    }else{
        printf("The average of %d numbers is %.2lf\n",countt,all/countt);
    }
    return 0;
}
