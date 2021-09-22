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

void n_node(LPTR L, int n){
    LPTR T1=L;
    LPTR T2=L;
    for(int i=0;i<n;i++){
        T2=T2->next;
    }
    while(T2!=NULL){
        T1=T1->next;
        T2=T2->next;
    }
    cout<<T1->data;
}
int main(){
    LPTR L=create();
    n_node(L,4);
}
