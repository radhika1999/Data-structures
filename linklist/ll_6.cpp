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

LPTR reverse(LPTR L){
    LPTR C=L;
    LPTR P=NULL;
    int c=0;
    while(C!=NULL){
        LPTR N=C->next;
        C->next=P;
        P=C;
        C=N;
        c++;
    }
    L=P;
    return L;
}
int main(){
    LPTR L=create();
    LPTR T=reverse(L);
    while(T!=NULL){
        cout<<T->data<<" ";
        T=T->next;
    }
}
