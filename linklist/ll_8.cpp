#include<iostream>
using namespace std;
struct lnode{
    int data;
    struct lnode *next;
};
typedef struct lnode * LPTR;
LPTR create(){
    LPTR L=NULL;
    int n;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    while(n!=-1){
        LPTR T=new lnode;
        T->data=n;
        if(L==NULL){
            L=T;
            L->next=NULL;
        }
        else{
            LPTR temp=L;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=T;
            T->next=NULL;
        }
        cout<<"Enter numbers"<<endl;
        cin>>n;
    }
    return L;
}

LPTR even(LPTR L){
    LPTR T=L;
    LPTR P=NULL;
    LPTR A=L;
    int c=0;
    while(T->next!=NULL){
        c++;
        T=T->next;
    }
    for(int i=0;i<c;i++){
        if(L->data%2==0){
            if(P==NULL){
                T->next=L;
                L=L->next;
                A=L;
                T=T->next;
                T->next=NULL;
            }
            else{
                T->next=L;
                L=L->next;
                P->next=L;
                T=T->next;
                T->next=NULL;
            }
        }
        else{
                P=L;
                L=L->next;
        }
    }
    return A;
}
int main(){
    LPTR L=create();
    LPTR A=even(L);
    while(A!=NULL){
        cout<<A->data<<" ";
        A=A->next;
    }
}
