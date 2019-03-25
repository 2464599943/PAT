#include <iostream>
#include<stdio.h>
#include<iomanip>
#include<math.h>
#include<algorithm>
using namespace std;
struct node{
    int exponent;
    double coeff;
    node *next=NULL;
};

int main()
{
     node *first1=NULL;
     node *first2=NULL;
     node *last1=NULL;
     node *last2=NULL;
     int K1=0,K2=0,num1=0;
     double num2=0.0;
     node *current=new node();
     node *p=new node();
     node *q=new node();
     scanf("%d",&K1);
     for(int i=0;i<K1;i++){
        scanf("%d",&num1);
        scanf("%lf",&num2);
        current=new node();
        current->exponent=num1;;
        current->coeff=num2;
        current->next=NULL;
        if(first1==NULL){
            first1=current;
            last1=current;
        }else {
            last1->next=current;
            last1=current;
        }
     }
     scanf("%d",&K2);
     for(int i=0;i<K2;i++){
         scanf("%d",&num1);
        scanf("%lf",&num2);
        current=new node();
        current->exponent=num1;;
        current->coeff=num2;
        current->next=NULL;
        if(first2==NULL){
            first2=current;
            last2=current;
        }else{
            last2->next=current;
            last2=current;
        }
     }
     p=first1;
     q=first2;
     node *other=NULL;
     node *c=new node();
     int result=0;
     while(p!=NULL&&q!=NULL){
        if(p->exponent>q->exponent){
            result++;
            c=p;
            p=p->next;
            K1--;
             if(c!=NULL){
        if(other==NULL){
            other=c;
            current=c;
        }
        else{
            current->next=c;
            current=c;
        }
        }
        }else if(p->exponent<q->exponent){
            result++;
            c=q;
            q=q->next;
            K2--;
             if(c!=NULL){
        if(other==NULL){
            other=c;
            current=c;
        }
        else{
            current->next=c;
            current=c;
        }
        }
        }else if(p->exponent==q->exponent){
            p->coeff=p->coeff+q->coeff;
            c=p;
            p=p->next;
            q=q->next;
            K1--;
            K2--;
            if(c->coeff<0.1&&c->coeff>-0.1){
                c=NULL;
            }else{
                result++;
                if(c!=NULL){
        if(other==NULL){
            other=c;
            current=c;
        }
        else{
            current->next=c;
            current=c;
        }
            }

        }
        }



       }
       if(p!=NULL&&current!=NULL){
         current->next=p;
          result+=K1;
       }
       else if(q!=NULL&&current!=NULL){
          current->next=q;
          result+=K2;
       }
       printf("%d ",result);
    current=other;
    if(current!=NULL){
    if(current->coeff>0.1||current->coeff<-0.1){
      printf("%d ",current->exponent);
      printf("%.1f",current->coeff);
    }
    }
    current=current->next;
    while(current!=NULL){
        if(current->coeff>0.1||current->coeff<-0.1){
        printf(" %d ",current->exponent);
        printf("%.1f",current->coeff);
        }
        current=current->next;

    }

    return 0;
}
