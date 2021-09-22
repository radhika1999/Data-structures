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

LPTR delete_dup(LPTR L){
    LPTR A=L;
    while(L->next!=NULL&&L!=NULL){
        LPTR T=L;
        while(T->next!=NULL){
            if(L->data==T->next->data){
                T->next=T->next->next;
                //delete T;
            }
            else{
                T=T->next;
            }
        }
        L=L->next;
    }
    return A;
}
int main(){
    LPTR L=create();
    LPTR T=delete_dup(L);
    while(T!=NULL){
        cout<<T->data<<" ";
        T=T->next;
    }
}
