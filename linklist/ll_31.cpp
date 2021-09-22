#include<iostream>
using namespace std;
struct mdnode{
    int data;
    struct mdnode *left;
    struct mdnode *right;
    struct mdnode *down;
};
typedef struct mdnode * MPTR;
void print(MPTR M){
    while(M!=NULL){
        cout<<M->data<<" ";
        print(M->down);
        M=M->right;
    }
}
MPTR create(){
    MPTR M=NULL;
    MPTR P=NULL;
    int n;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    while(n!=-1){
        MPTR T=new mdnode;
        T->data=n;
        if(M==NULL){
            M=T;
            M->right=NULL;
            M->left=NULL;
            P=T;
        }
        else{
            T->left=P;
            P->right=T;
            T->right=NULL;
            P=T;
        }
        int ch;
        cout<<"Enter 1 for down list\nEnter 0 for no\n";
        cin>>ch;
        if(ch==0){
            T->down=NULL;
        }
        else{
            T->down=create();
        }
        cout<<"Enter numbers"<<endl;
        cin>>n;
    }
    return M;
}
int main(){
    MPTR M=create();
    print(M);
}
