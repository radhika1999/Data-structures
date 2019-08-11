#include<iostream>
#include<queue>
using namespace std;
struct tstnode{
    char data;
    struct tstnode *lchild;
    struct tstnode *echild;
    struct tstnode *rchild;
    int check;
};
typedef struct tstnode * TSTPTR;
void create(TSTPTR &T, char a[], int n){
    if(n>0){
        if(T==NULL){
            T=new tstnode;
            T->data=a[0];
            T->echild=NULL;
            T->lchild=NULL;
            T->rchild=NULL;
            T->check=0;
            if(n==1){
                T->check=1;
            }
            else{
                create(T->echild, a+1, n-1);
            }
        }
        else{
            if(T->data>a[0]){
                create(T->lchild, a, n);
            }
            else if(T->data<a[0]){
                create(T->rchild, a, n);
            }
            else{
                create(T->echild, a+1, n-1);
            }
        }
    }
}
int search(TSTPTR T, char a[], int n){
    if(n==0){
        return 1;
    }
    if(T==NULL){
        return 0;
    }
    if(T->data==a[0]){
        return search(T->echild, a+1, n-1);
    }
    else if(T->data>a[0]){
        return search(T->lchild, a, n);
    }
    else{
        return search(T->rchild, a, n);
    }
}
void levelprint(TSTPTR T){
    queue<TSTPTR> q;
    if(T!=NULL){
        q.push(T);
        TSTPTR X=new tstnode;
        X->data='-';
        X->lchild=NULL;
        X->rchild=NULL;
        X->echild=NULL;
        q.push(X);
    }
    while(!q.empty()&&q.size()!=1){
        TSTPTR A=q.front();
        q.pop();
        if(A->data=='-'){
            cout<<endl;
            q.push(A);
        }
        else{
            cout<<A->data<<" ";
            if(A->lchild!=NULL){
                q.push(A->lchild);
            }
            if(A->echild!=NULL){
                q.push(A->echild);
            }
            if(A->rchild!=NULL){
                q.push(A->rchild);
            }
        }
    }
}
int main(){
    TSTPTR T=NULL;
    create(T, "shell", 5);
    create(T, "she", 3);
    create(T, "it", 2);
    levelprint(T);
}
