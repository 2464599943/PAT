#include <iostream>
#include<stdio.h>
#include<map>
#include<queue>
#include<string.h>
#define maxN 25
using namespace std;
struct node {
    string key;
    node *left;
    node *right;
    int intleft;
    int intright;
};
map<int,node* > m;
map<int,node* >::iterator it;
queue<node* >q;
int help[maxN];
void inorder(node *root,node *realroot){
    if(root==NULL)return ;
    if(root->left!=NULL||root->right!=NULL){
        if(root!=realroot)
         printf("(");
    }
    inorder(root->left,realroot);
    cout<<root->key;
    inorder(root->right,realroot);
     if(root->left!=NULL||root->right!=NULL){
        if(root!=realroot)
        printf(")");
    }
}
int main()
{

    int N,child1,child2;
    scanf("%d",&N);
    fill(help,help+maxN,0);
    string str;
    node *newnode;
    for(int i=1;i<=N;i++){
        cin>>str;
        scanf("%d%d",&child1,&child2);
        newnode=new node();
        newnode->key=str;
        newnode->intleft=child1;
        newnode->intright=child2;
        newnode->left=NULL;
        newnode->right=NULL;
        m[i]=newnode;
        if(child1!=-1){
            help[child1]++;
        }
        if(child2!=-1){
            help[child2]++;
        }
    }
    int roott;
    for(int i=1;i<=N;i++){
        if(help[i]==0){
            roott=i;
            break;
        }
    }
    node *current=m[roott];
    q.push(current);
    node *root=current;
    while(!q.empty()){
        current=q.front();
        q.pop();
        if(current!=NULL){
            if(current->intleft!=-1){
                current->left=m[current->intleft];
                q.push(current->left);
            }
            if(current->intright!=-1){
                current->right=m[current->intright];
                q.push(current->right);
            }
        }
    }
    inorder(root,root);
    return 0;
}
