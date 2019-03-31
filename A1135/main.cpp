#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct node{
    int key;
    node *left;
    node *right;
    int rb;
};
void insertnode(node *&root,int num){
    if(root==NULL){
        root=new node();
        root->key=abs(num);
        if(num<0){
            root->rb=0;
        }else{
            root->rb=1;
        }
        root->left=NULL;
        root->right=NULL;
        return;
    }
    if(abs(num)<root->key){
        insertnode(root->left,num);
    }else{
        insertnode(root->right,num);
    }
}
bool result;
int postorder(node *&root){
    if(root==NULL)return 0;
    if(root->rb==0){
       if(root->left!=NULL&&root->left->rb==0){
           result=false;
       }
       if(root->right!=NULL&&root->right->rb==0){
           result=false;
       }
    }
    int leftnum=postorder(root->left);
    int rightnum=postorder(root->right);
    if(leftnum!=rightnum){
        result=false;
    }
    return leftnum+root->rb;

}
int main()
{
    int K,N,temp1;
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        scanf("%d",&N);
        node *root=NULL;
        for(int j=0;j<N;j++){
            scanf("%d",&temp1);
            insertnode(root,temp1);
        }
        result=true;
        if(root->rb==0){
            result=false;
        }else{
            postorder(root);
        }
        if(result){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
