#include <iostream>
#include<stdio.h>
#include<map>
#include<queue>
#include<algorithm>
#define maxN 110
using namespace std;
struct intnode{
    int left;
    int right;
};
struct node{
    int index;
    int key;
    node *left;
    node *right;
};
int a[maxN];
int k=0;
void inorder(node *root,int N){
    if(root==NULL)return;
    inorder(root->left,N);
    if(k<N){
        root->key=a[k];
        k++;
    }
    inorder(root->right,N);
}
int main()
{
    map<int,intnode> m;
    int N,l,r;
    scanf("%d",&N);
    intnode in;
    for(int i=0;i<N;i++){
        scanf("%d%d",&l,&r);
        in.left=l;
        in.right=r;
        m[i]=in;
    }
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    queue<node *> q;
    node *root=new node();
    root->index=0;
    root->left=NULL;
    root->right=NULL;
    q.push(root);
    node *current;
    node *newnode;
    while(!q.empty()){
      current=q.front();
      q.pop();
      in=m[current->index];
      if(in.left!=-1){
        newnode=new node();
        newnode->index=in.left;
        newnode->left=NULL;
        newnode->right=NULL;
        current->left=newnode;
        q.push(newnode);
      }
      if(in.right!=-1){
        newnode=new node();
        newnode->index=in.right;
        newnode->left=NULL;
        newnode->right=NULL;
        current->right=newnode;
        q.push(newnode);
      }

    }
    sort(a,a+N);
    inorder(root,N);
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
