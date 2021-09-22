#include<iostream>
using namespace std;
struct btlnode{
    struct btlnode *lchild;
    char data;
    struct btlnode *rchild;
    struct btlnode *level;
};
typedef struct btlnode * BTLPTR;
void create(BTLPTR &T, char c){
    if(c=='x')
        return;
    T=new btnode;
    T->data=c;
    T->lchild=NULL;
    T->rchild=NULL;
    T->level=NULL;
    char cl,cr;
    cout<<"Enter left of "<<c;
    cin>>cl;
    create(T->lchild, cl);
    cout<<"Enter right of "<<c;
    cin>>cr;
    create(T->rchild, cr);
}
void link(BTLPTR T){
    BTLPTR P=T, X=T->lchild;
    while(X!=NULL){
    T=X;
    if(P->rchild!=NULL){
        T->level=P->rchild;
        T=T->level;
    }
    P=P->level;
    while(P!=NULL){
        if(P->lchild!=NULL){
            T->level=P->lchild;
            T=T->level;
        }
        if(P->rchild!=NULL){
            T->level=P->rchild;
            T=T->level;
        }
        P=P->level;
    }
    P=X;
    X=X->lchild;
    }
}
