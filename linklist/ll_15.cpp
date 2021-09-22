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

LPTR swap(LPTR L){
    LPTR A=L;
    LPTR P=NULL;
    while(L->next!=NULL&&L->next->next!=NULL){
        LPTR N=L->next;
        if(P==NULL){
            A=N;
            L->next=N->next;
        }
        else{
            P->next=N;
            L->next=N->next;
        }
        N->next=L;
        P=L;
        L=L->next;
    }
    return A;
}
int main(){
    LPTR L=create();
    LPTR T=swap(L);
    while(T!=NULL){
        cout<<T->data<<" ";
        T=T->next;
    }
}
