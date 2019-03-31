#include <iostream>
#include<stdio.h>
#include<queue>
#define maxN 10010
using namespace std;
struct node{
    int key;
    node *left;
    node *right;
    int level;
};
void insertnode(node *&root,int key){
    if(root==NULL){
        root=new node();
        root->key=key;
        root->left=NULL;
        root->right=NULL;
        return ;
    }
    if(key<=root->key){
        insertnode(root->left,key);
    }else {
        insertnode(root->right,key);
    }
}
int level[maxN];
int main()
{
    int N,temp;
    scanf("%d",&N);
    node *root=NULL;
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        insertnode(root,temp);
    }
    queue<node *> q;
    if(root!=NULL)
       root->level=1;
    q.push(root);
    node *current;
    fill(level,level+maxN,0);
    int maxx=0;
    while(!q.empty()){
        current=q.front();
        q.pop();
        if(current!=NULL){
            level[current->level]++;
            if(maxx<current->level){
                maxx=current->level;
            }
            if(current->left!=NULL){
                current->left->level=current->level+1;
                q.push(current->left);

            }
            if(current->right!=NULL){
                current->right->level=current->level+1;
                q.push(current->right);
            }
        }
    }
    if(N!=0){
        printf("%d + %d = %d",level[maxx],level[maxx-1],level[maxx]+level[maxx-1]);
    }
    else{
        printf("%d + %d = %d",0,0,0);
    }
    return 0;
}
