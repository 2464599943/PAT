#include <iostream>
#include<stdio.h>
using namespace std;
struct node{
    int key;
    node *left;
    node *right;
};
void insernode(node *&root,int num){
    if(root==NULL){
        root=new node();
        root->key=num;
        root->left=NULL;
        root->right=NULL;
        return ;
    }
    if(num<root->key){
        insernode(root->left,num);
    }else{
        insernode(root->right,num);
    }
}
int key1;
int key2;
int type=-10;
int ancestor;
bool flag1=false;
bool flag2=false;
void postorder(node *root){
    if(root==NULL)return;
    bool f11,f12,f21,f22,f01,f02;
    f01=flag1;
    f02=flag2;
    postorder(root->left);
    f11=flag1;
    f12=flag2;
    postorder(root->right);
     f21=flag1;
     f22=flag2;
     bool find1=false;
     bool find2=false;

        if((!f01&&f11)||(!f11&&f21)){
            find1=true;
        }
       if((!f02&&f12)||(!f12&&f22)){
            find2=true;
       }
       if(type==-10){
           if(find1&&find2){
              type=0;
              ancestor=root->key;
           }else if(find1&&!find2&&root->key==key2){
               type=-1;
               ancestor=root->key;
           }else if(!find1&&find2&&root->key==key1){
               type=1;
               ancestor=root->key;
           }
       }
       if(root->key==key1){
          flag1=true;
       }
       if(root->key==key2){
          flag2=true;
       }

}
int main()
{
    int N,M,num,v1,v2;
    scanf("%d%d",&M,&N);
    node *root=NULL;
    for(int i=0;i<N;i++){
        scanf("%d",&num);
        insernode(root,num);
    }
    for(int i=0;i<M;i++){
        flag1=false;
        flag2=false;
        type=-10;
        scanf("%d%d",&v1,&v2);
        key1=v1;
        key2=v2;
        postorder(root);
        if(flag1&&flag2){
            if(type==0){
                if(v1!=v2){
                    printf("LCA of %d and %d is %d.\n",v1,v2,ancestor);
                }else{
                    printf("LCA of %d and %d is %d.\n",v1,v2,v1);
                }
            }else if(type==1){
                printf("%d is an ancestor of %d.\n",ancestor,v2);
            }else if(type==-1){
                 printf("%d is an ancestor of %d.\n",ancestor,v1);
            }
        }else if(flag1&&!flag2){
            printf("ERROR: %d is not found.\n",v2);
        }else if(!flag1&&flag2){
            printf("ERROR: %d is not found.\n",v1);
        }else{
            printf("ERROR: %d and %d are not found.\n",v1,v2);
        }
    }
    return 0;
}
