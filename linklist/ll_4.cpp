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

void mid(LPTR L){
    LPTR S=L;
    LPTR F=L;
    while(F!=NULL&&F->next!=NULL){
        S=S->next;
        F=F->next->next;
    }
    cout<<S->data;
}
int main(){
    LPTR L=create();
    mid(L);
}
