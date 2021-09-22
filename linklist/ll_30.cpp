#include<iostream>
using namespace std;
struct dnode{
    int data;
    struct dnode *right;
    struct dnode *left;
};
typedef struct dnode * DPTR;
DPTR create_dll(){
    DPTR D=NULL;
    int n;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    while(n!=-1){
        DPTR T=new dnode;
        T->data=n;
        if(D==NULL){
            D=T;
            D->right=NULL;
            D->left=NULL;
        }
        else{
            DPTR temp=D;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            T->left=temp;
            temp->right=T;
            T->right=NULL;
        }
        cout<<"Enter numbers"<<endl;
        cin>>n;
    }
    return D;
}

void swap_val(int &a, int &b){
    int t=a;
    a=b;
    b=t;
}
DPTR biotonic(DPTR D){
    DPTR T=D;
    while(T->right->data<T->data){
        T=T->right;
    }
    DPTR T1=T->left;
    DPTR T2=T->right;
    while(T1!=NULL&&T2!=NULL){
        if(T2->data<T1->data){
            T2=T2->right;
        }
        else{
            DPTR X=T2->left;
            DPTR Y=T1->left;
            T2->left=T1;
            if(Y!=NULL)
                T1->left->right=T1->right;
            T1->right=T2;
            T1->left=X;
            X->right=T1;
            T->left=Y;
            T1=Y;
        }
    }
    DPTR P=T;
    while(P->right!=NULL){
        P=P->right;
    }
    if(T1!=NULL){
            DPTR Y=T1->left;
            //T2->left=T1;
            if(Y!=NULL)
                T1->left->right=T1->right;
            T->left=Y;
            T1->right=NULL;
            T1->left=P;
            P->right=T1;
            T1=Y;
    }
    return T;
}

int main(){
    DPTR D=create_dll();
    DPTR T=biotonic(D);
    while(T!=NULL){
        cout<<T->data<<" ";
        T=T->right;
    }
}
