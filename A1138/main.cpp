#include <iostream>
#include<stdio.h>
#define maxN 50010
using namespace std;
int preorder[maxN];
int inorder[maxN];
struct node{
    int key;
    node *left;
    node *right;
};
void insertnode(int left1,int right1,int left2,int right2,node *&root){
    if(left1>right1||left2>right2)return ;
    root=new node();
    root->key=preorder[left1];
    root->left=NULL;
    root->right=NULL;
    if(left1==right1&&left2==right2){
        return ;
    }
    int index;
    for(int i=left2;i<=right2;i++){
        if(inorder[i]==root->key){
            index=i;
            break;
        }
    }
    int leftnum=index-left2;
    int rightnum=right2-index;
    insertnode(left1+1,left1+1+leftnum-1,left2,left2+leftnum-1,root->left);
    insertnode(right1-rightnum+1,right1,right2-rightnum+1,right2,root->right);
}
int cnt=0;
void postorder(node *root){
    if(root==NULL)return ;
    postorder(root->left);
    postorder(root->right);
    cnt++;
    if(cnt==1){
        printf("%d\n",root->key);
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    node* root=NULL;
    for(int i=0;i<N;i++){
        scanf("%d",&preorder[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&inorder[i]);
    }
    insertnode(0,N-1,0,N-1,root);
    postorder(root);
    return 0;
}
