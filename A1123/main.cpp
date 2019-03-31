#include <iostream>
#include<stdio.h>
#include<queue>
#define maxN 30
int maxlevel=0;
using namespace std;
struct node{
    int key;
    int height;
    node *left;
    node *right;
    int level;
};
int getHeight(node *&root){
    if(root==NULL){
        return 0;
    }
    return max(getHeight(root->left),getHeight(root->right))+1;
}
void update(node *&root){
    if(root==NULL)return ;
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
}
int getBalanceFactor(node *&root){
    if(root==NULL)return 0;
    return getHeight(root->left)-getHeight(root->right);
}
void rotateL(node *&root){
    if(root==NULL)return ;
    if(root->right==NULL)return ;
    node *temp=root->right;
    root->right=temp->left;
    temp->left=root;
    update(root);
    update(temp);
    root=temp;
}
void rotateR(node *&root){
    if(root==NULL)return ;
    if(root->left==NULL)return;
    node *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    update(root);
    update(temp);
    root=temp;

}
void insertAVL(int num,node* &root){
    if(root==NULL){
        root=new node();
        root->key=num;
        root->height=1;
        root->left=NULL;
        root->right=NULL;
        return ;

    }
    if(num<root->key){
        insertAVL(num,root->left);
        update(root);
        if(getBalanceFactor(root)==2){
            if(getBalanceFactor(root->left)==1){
                rotateR(root);
            }else if(getBalanceFactor(root->left)==-1){
                rotateL(root->left);
                rotateR(root);
            }
        }

    }else{
        insertAVL(num,root->right);
        update(root);
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
    int N,temp;
    scanf("%d",&N);
    node *root=NULL;
    for(int i=0;i<N;i++){
        scanf("%d",&temp);
        insertAVL(temp,root);
    }
    queue<node *>q;
    bool result=true;
    root->level=0;
    q.push(root);
    node *current;
    int cnt=0;
    int after=0;
    while(!q.empty()){
        current=q.front();
        q.pop();
        if(current!=NULL){
            if(current->left!=NULL){
                if(after)result=false;
                q.push(current->left);
            }else{
                after=1;
            }
            if(current->right!=NULL){
                if(after)result=false;
                q.push(current->right);
            }else{
                after=1;
            }
            cnt++;
           if(cnt==1){
                printf("%d",current->key);
            }else{
                printf(" %d",current->key);
            }

        }
    }
    printf("\n");
    if(result){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
