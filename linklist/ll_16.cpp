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

int carry(LPTR L1,LPTR L2){
    if(L2==NULL){
        return 0;
    }
    int ans=L1->data+L2->data+carry(L1->next,L2->next);
    L1->data=ans%10;
    return ans/10;
}
LPTR add(LPTR L1,LPTR L2){
    int x=carry(L1,L2);
    if(x>0){
        LPTR T=new lnode;
        T->data=x;
        T->next=L1;
        L1=T;
    }
    return L1;
}
int main(){
    LPTR L1=create();
    LPTR L2=create();
    LPTR T=add(L1,L2);
    while(T!=NULL){
        cout<<T->data<<" ";
        T=T->next;
    }
}
