#include <iostream>
#include<stdio.h>
using namespace std;
struct node{
    int key;
    node *left;
    node *right;
};
node* insertnode(node *root,int num){
    node *current=root;
    node *p=NULL;
    while(current!=NULL){
         p=current;
        if(num<current->key){
            current=current->left;
        }else{
            current=current->right;
        }
    }
   return p;
}
int i=0;
int j=0;
bool ifi=true;
bool ifj=true;
void preorderi(node *root,int *a,int N){
    if(root==NULL)return;
    if(i<N&&root->key==a[i]){
        i++;
    }else{
        ifi=false;
        return;
    }
    preorderi(root->left,a,N);
    preorderi(root->right,a,N);
}
void preorderj(node *root,int *a,int N){
    if(root==NULL)return;
    if(j<N&&root->key==a[j]){
        j++;
    }else{
        ifj=false;
        return;
    }
    preorderj(root->right,a,N);
    preorderj(root->left,a,N);
}
void postorderi(node *root,node *realnode){
    if(root==NULL)return;
    postorderi(root->left,realnode);
    postorderi(root->right,realnode);
    if(root==realnode){
        printf("%d",root->key);
    }else{
        printf("%d ",root->key);
    }
}
void postorderj(node *root,node *realnode){
    if(root==NULL)return;
    postorderj(root->right,realnode);
    postorderj(root->left,realnode);
    if(root==realnode){
        printf("%d",root->key);
    }else{
        printf("%d ",root->key);
    }
}
int main()
{
    int N,num;
    scanf("%d",&N);
    node *root=NULL;
    node *current;
    int *a=new int[N];
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        a[i]=num;
        if(root==NULL){
            root=new node();
            root->key=num;
            root->left=NULL;
            root->right=NULL;
        }else{
            current=insertnode(root,num);
            node *newnode=new node();
            newnode->key=num;
            newnode->left=NULL;
            newnode->right=NULL;
            if(current!=NULL){
                if(num<current->key){
                    current->left=newnode;
                }else{
                    current->right=newnode;
                }
            }
        }
    }
    preorderi(root,a,N);
     preorderj(root,a,N);
    if(ifi){
        printf("YES\n");
        postorderi(root,root);
    }
    else{
        if(ifj){
            printf("YES\n");
            postorderj(root,root);
        }else{
              printf("NO\n");
        }
    }
    return 0;
}
