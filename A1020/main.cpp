#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
    int key;
    node *left;
    node *right;
};
node* tree(int *postorder,int *inorder,int left1,int right1,int left2,int right2,int N){
    if(left1>right1||left2>right2)return NULL;
    if(left1==right1||left2==right2){
        node *root=new node();
        root->key=postorder[right1];
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    node *root=new node();
    root->key=postorder[right1];
    root->left=NULL;
    root->right=NULL;

    int index;
    for(int i=left2;i<=right2;i++){
        if(inorder[i]==root->key){
            index=i;
        }
    }
    int leftnum=index-left2-1;
    int rigtnum=right2-index-1;
    root->left=tree(postorder,inorder,left1,left1+leftnum,left2,left2+leftnum,N);
    root->right=tree(postorder,inorder,right1-1-rigtnum,right1-1,right2-rigtnum,right2,N);

    return root;
}
int main()
{
    int N;
    scanf("%d",&N);
    int *postorder=new int[N];
    int *inorder=new int[N];
    for(int i=0;i<N;i++){
        scanf("%d",&postorder[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&inorder[i]);
    }
    node* root=tree(postorder,inorder,0,N-1,0,N-1,N);
    queue<node *> q;
    node *current;
    if(root!=NULL){
        q.push(root);
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
                 if(q.empty()){
                    printf("%d",current->key);
                }else{
                    printf("%d ",current->key);
                }
            }
        }
    }

    return 0;
}
