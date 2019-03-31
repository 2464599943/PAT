#include <iostream>
#include<stdio.h>
#include<queue>
#define maxN 35
using namespace std;

struct node{
    int key;
    node *left;
    node *right;
    int level;

};
int inorder[maxN];
int postorder[maxN];
void insertnode(int left1,int right1,int left2,int right2,node* &root,int level){
    if(left1>right1||left2>right2)return;
    root=new node();
    root->key=postorder[right2];
    root->left=NULL;
    root->right=NULL;
    root->level=level;
    int index;
    if(left1==right1&&left2==right2)return;
    for(int i=left1;i<=right1;i++){
        if(inorder[i]==root->key){
            index=i;
            break;
        }
    }
    int leftnum=index-left1;
    int rightnum=right1-index;
    insertnode(left1,left1+leftnum-1,left2,left2+leftnum-1,root->left,level+1);
    insertnode(right1-rightnum+1,right1,right2-1-rightnum+1,right2-1,root->right,level+1);

}
int main()
{
    int N;
    scanf("%d",&N);
    node* root=NULL;
    for(int i=0;i<N;i++){
        scanf("%d",&inorder[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&postorder[i]);
    }
    insertnode(0,N-1,0,N-1,root,1);
    queue<node*> q1;
    queue<node* >q2;
    if(root!=NULL){
        q1.push(root);
        q2.push(root);
    }
    node *current1;
    node *current2;
    int cnt=0;
    while(!q1.empty()&&!q2.empty()){
          current1=q1.front();
          q1.pop();
          current2=q2.front();
          q2.pop();
          if(current1!=NULL&&current2!=NULL){
                if(current1->left!=NULL){
                    q1.push(current1->left);
                }
                if(current1->right!=NULL){
                    q1.push(current1->right);

                }
                if(current2->right!=NULL){
                    q2.push(current2->right);
                }
                if(current2->left!=NULL){
                    q2.push(current2->left);
                }
                cnt++;
                if(current1->level%2==1){
                    if(cnt==1){
                        printf("%d",current2->key);
                    }
                    else{
                        printf(" %d",current2->key);
                    }
                }else{
                    if(cnt==1){
                        printf("%d",current1->key);
                    }else{
                        printf(" %d",current1->key);
                    }
                }
          }


    }

    return 0;
}
