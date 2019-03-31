#include <iostream>
#include<map>
#include<stdio.h>
#include<queue>
#include<string>
#define inf 100000000
using namespace std;
struct intnode{
    int index;
    int left;
    int right;
};
struct node{
    int key;
    node* left;
    node* right;
};
void level_order(node *root,int *countt,int N){
    if(root==NULL)return;
    queue<node *>q;
    q.push(root);
    node *current;
    while(!q.empty()){
        current=q.front();
        q.pop();
        if(current!=NULL){
           if(current->left!=NULL);
             q.push(current->left);
           if(current->right!=NULL)
             q.push(current->right);
            countt[0]++;
            if(countt[0]==N){
                printf("%d",current->key);
            }else{
                printf("%d ",current->key);
            }
        }
    }
}
void inorder(node *root,int *countt,int N){
    if(root==NULL)return;
     inorder(root->left,countt,N);
     countt[0]++;
    if(countt[0]==N){
        printf("%d",root->key);
    }else{
        printf("%d ",root->key);
    }
    inorder(root->right,countt,N);
}
int main()
{
    int N;
    scanf("%d",&N);
    intnode *a=new intnode[N];
    int *help=new int[N];
    map<int,int> mm;
    for(int i=0;i<N;i++){
        help[i]=0;
    }
    char c1,c2;
    getchar();
    for(int i=0;i<N;i++){
        scanf("%c %c",&c1,&c2);
        getchar();
        if(c1<='9'&&c1>='0'){
            a[i].right=c1-'0';
            help[a[i].right]++;
            mm[a[i].right]=i;
        }else{
            a[i].right=-1;
        }
        if(c2<='9'&&c2>='0'){
            a[i].left=c2-'0';
            help[a[i].left]++;
            mm[a[i].left]=i;
        }else{
            a[i].left=-1;
        }
        a[i].index=i;

    }
    queue<intnode> q1;
    for(int i=0;i<N;i++){
       if(help[i]==0){
           q1.push(a[i]);
           help[i]=inf;
           break;
       }
    }
    node *root=NULL;
    node *current;
    node *newnode;
    intnode in;
    map<int,node *> m;
    while(!q1.empty()){
        in=q1.front();
        q1.pop();
        newnode=new node();
        newnode->key=in.index;
        newnode->left=NULL;
        newnode->right=NULL;
        if(in.left!=-1){
            help[in.left]--;
            if(help[in.left]==0){
               q1.push(a[in.left]);
               help[in.left]=inf;
            }
        }
        if(in.right!=-1){
            help[in.right]--;
            if(help[in.right]==0){
               q1.push(a[in.right]);
               help[in.right]=inf;
             }
        }
        if(root==NULL){
            root=newnode;
            m[root->key]=root;
        }else{
            int parent=mm[in.index];
            current=m[parent];
            if(a[current->key].left==in.index){
                current->left=newnode;
            }else if(a[current->key].right==in.index){
                current->right=newnode;
            }
            m[newnode->key]=newnode;
        }
    }

    int *countt=new int[1];
    countt[0]=0;
    level_order(root,countt,N);
    printf("\n");
    countt[0]=0;
    inorder(root,countt,N);
    printf("\n");
    return 0;
}
