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

void insert(LPTR *L, LPTR T){
    LPTR A=*L;
    if(T->data<A->data||A==nullptr){
        T->next=*L;
        *L=T;
    }
    else{
        while(A->next->data<T->data){
            A=A->next;
        }
        T->next=A->next;
        A->next=T;
    }
    //return A;
}
void sorting(LPTR *L1){
    LPTR T=*L1;
    LPTR P=NULL;
    while(T!=NULL){
        LPTR N=T->next;
        insert(&P,T);
        T=N;
    }
    *L1=P;
    /*if(L2==NULL){
        return;
    }
    LPTR T=L2;
    LPTR N=L2->next;
    insert(L1,T);
    helper(L1,N);
    */
}
int main(){
    LPTR L=create();
    LPTR T=L;
    T->next=NULL;
    L=L->next;
    sorting(&L);
    while(L!=NULL){
        cout<<L->data<<" "<<endl;
        L=L->next;
    }
}
