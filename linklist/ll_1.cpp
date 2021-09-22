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

void union_ll(LPTR L1, LPTR L2){
    LPTR A=L1;
    LPTR P=NULL;
    while(L1!=NULL&&L2!=NULL){
        if(L1->data<L2->data){
            cout<<L1->data<<" ";
            L1=L1->next;
        }
        else if(L1->data>L2->data){
            cout<<L2->data<<" ";
            L2=L2->next;
        }
        else{
            cout<<L1->data<<" ";
            L1=L1->next;
            L2=L2->next;
        }
    }
    while(L2!=NULL){
            cout<<L2->data<<" ";
            L2=L2->next;
    }
     while(L1!=NULL){
            cout<<L1->data<<" ";
            L1=L1->next;

}
}
void intersection(LPTR L1, LPTR L2){
    LPTR A=L1;
    LPTR P=NULL;
    while(L1!=NULL&&L2!=NULL){
        if(L1->data>L2->data){
            L2=L2->next;
        }
        else if(L1->data<L2->data){
            L1=L1->next;
        }
        else{
            cout<<L1->data<<" ";
            L1=L1->next;
            L2=L2->next;
        }
    }
}
int main(){
    LPTR L1=create();
    LPTR L2=create();
    cout<<"union\n";
    union_ll(L1,L2);
    cout<<"intersection\n";
    intersection(L1, L2);
}
