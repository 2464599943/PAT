#include <iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct node{
    int key;
    node *left;
    node *right;
};
node* findnode(node *root,int num){
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
int main()
{
    int N,num;
    scanf("%d",&N);
    node *root=NULL;
    node *newnode;
    node *current;
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        newnode=new node();
        newnode->key=num;
        newnode->left=NULL;
        newnode->right=NULL;
        if(root==NULL){
            root=newnode;
        }else{
            current=findnode(root,num);
            if(current!=NULL){
                if(num<current->key){
                    current->left=newnode;
                }else{
                    current->right=newnode;
                }
            }
        }
    }
    queue<node *> q;
    q.push(root);
    int countt=0;
    while(!q.empty()){
        current=q.front();
        q.pop();
        if(current!=NULL){
            if(current->left!=NULL){
                q.push(current->left);
            }
            if(current->right!=NULL){
                q.push(current->right);
            }
            countt++;
            if(countt==N){
                printf("%d",current->key);
            }else{
                printf("%d ",current->key);
            }
        }
    }
    return 0;
}
