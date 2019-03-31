#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
struct node{
    int key;
    int height;
    node *left;
    node *right;
};
int getHeight(node *root){
    if(root==NULL)return 0;
    return root->height;
}
void updateHeight(node *root){

   root->height=max(getHeight(root->left),getHeight(root->right))+1;

}
void rotateR(node* &root){
    if(root==NULL||root->left==NULL)return;
    node *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;

}
void rotateL(node* &root){
    if(root==NULL||root->right==NULL)return;
    node *temp=root->right;
    root->right=temp->left;
    temp->left=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
int getBalanceFactor(node *root){
    return getHeight(root->left)-getHeight(root->right);
}
void insertnode(node* &root,int num){
    if(root==NULL){
        root=new node();
        root->key=num;
        root->left=NULL;
        root->right=NULL;
        root->height=1;
        return;
    }
    if(num<root->key){
        insertnode(root->left,num);
        updateHeight(root);
            if(getBalanceFactor(root)==2){
                   if(getBalanceFactor(root->left)==1){
                         rotateR(root);
                   } else if(getBalanceFactor(root->left)==-1){
                         rotateL(root->left);
                         rotateR(root);
                   }
            }



    }else{
        insertnode(root->right,num);
        updateHeight(root);
            if(getBalanceFactor(root)==-2){
                if(getBalanceFactor(root->right)==-1){
                         rotateL(root);
                }else if(getBalanceFactor(root->right)==1){
                         rotateR(root->right);
                         rotateL(root);
                }
            }


    }
}
int main()
{
    int N,num;
    scanf("%d",&N);
    node *root=NULL;
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        insertnode(root,num);
    }
    printf("%d\n",root->key);
    return 0;
}
