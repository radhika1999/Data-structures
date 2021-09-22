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
int main(){
    DPTR D=create_dll();
    while(D!=NULL){
        cout<<D->data<<" ";
        D=D->right;
    }
}
