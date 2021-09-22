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

LPTR merge(LPTR L1, LPTR L2){
    LPTR A=L1;
    LPTR P=NULL;
    while(L1!=NULL&&L2!=NULL){
        if(L1->data<L2->data){
            P=L1;
            L1=L1->next;
        }
        else{
            if(P==NULL){
                A=L2;
                P=L2;
                L2=L2->next;
                P->next=L1;
            }
            else{
            LPTR T=L2;
            P->next=L2;
            L2=L2->next;
            T->next=L1;
            P=T;
            }
        }
    }
    while(L2!=NULL){
            LPTR T=L2;
            P->next=L2;
            L2=L2->next;
            T->next=L1;
            P=T;
    }
    return A;
}
int main(){
    LPTR L1=create();
    LPTR L2=create();
    LPTR T=merge(L1,L2);
    while(T!=NULL){
        cout<<T->data<<" ";
        T=T->next;
    }
}
