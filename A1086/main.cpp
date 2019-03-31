#include <iostream>
#include<stdio.h>
#include<stack>
#include<cstring>
using namespace std;
struct node{
    int key;
    node *left;
    node *right;
};
void traverse(node *root,node *realroot){
    if(root==NULL)return;
    traverse(root->left,realroot);
    traverse(root->right,realroot);
    if(root->key==realroot->key){
        printf("%d",root->key);
    }else{
        printf("%d ",root->key);
    }

}
int main()
{
    int N,num;
    scanf("%d",&N);
    stack<node *> s;
    char operation[10];
    node *root=NULL;
    node *current;
    node *newnode;
    for(int i=0;i<2*N;i++){
        scanf("%s",operation);
        if(strcmp(operation,"Push")==0){
             scanf("%d",&num);
             if(root==NULL){
                root=new node();
                root->key=num;
                root->left=NULL;
                root->right=NULL;
                current=root;
             }else{
                 newnode=new node();
                 newnode->key=num;
                 newnode->left=NULL;
                 newnode->right=NULL;
                 if(current->left==NULL){
                    current->left=newnode;
                 }
                 else if(current->right==NULL){
                    current->right=newnode;
                 }
                 current=newnode;
             }
             s.push(current);

        }else if(strcmp(operation,"Pop")==0){
            current=s.top();
            s.pop();
        }
    }
    traverse(root,root);
    return 0;
}
