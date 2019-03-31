#include <iostream>
#include<stdio.h>
#define maxN 35
using namespace std;
int preorder[maxN];
int postorder[maxN];
struct node{
    int key;
    node* left;
    node* right;
};
bool result=true;
void insertnode(int left1,int right1,int left2,int right2,node* &root){
    if(left1>right1||left2>right2)return;
    root=new node();
    root->key=preorder[left1];
    root->left=NULL;
    root->right=NULL;
    if(left1==right1&&left2==right2)return;
    int index=-1;
    for(int i=left1+1;i<=right1;i++){
        if(preorder[i]==postorder[right2-1]){
            index=i;
            break;
        }
    }
    if(index==-1)return;
    if(index==left1+1){
        result=false;
        insertnode(left1+1,right1,left2,right2-1,root->left);
    }else{
        int leftnum=index-left1-1;
        int rightnum=right1-index;
        insertnode(left1+1,left1+1+leftnum-1,left2,left2+leftnum-1,root->left);
        insertnode(right1-rightnum,right1,right2-1-rightnum,right2-1,root->right);
    }
}
int cnt=0;
void inorder(node* &root,int N){
    if(root!=NULL){
        inorder(root->left,N);
        cnt++;
        if(cnt==1){
            printf("%d",root->key);
        }else{
            printf(" %d",root->key);
        }
        inorder(root->right,N);
    }
}
int main()
{
    int N,temp;
    scanf("%d",&N);
    node* root=NULL;
    for(int i=0;i<N;i++){
        scanf("%d",&preorder[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&postorder[i]);
    }
    insertnode(0,N-1,0,N-1,root);
    if(result){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    inorder(root,N);
    printf("\n");
    return 0;
}
