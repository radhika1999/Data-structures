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

void loop(LPTR L){
    LPTR S=L;
    LPTR F=L;
    while(S!=F&&F!=NULL&&F->next!=NULL){
        S=S->next;
        F=F->next;
    }
    bool ans;
    if(S==F){
        ans=true;
        cout<<ans;
    }
    else{
        ans=false;
        cout<<ans;
    }
    if(ans){
        int x=0;
        cout<<endl<<S->data;
        while(S->next!=F){
            S=S->next;
            x++;
        }
        cout<<"Length="<<x<<endl;
    }
}
int main(){
    LPTR L=create();
    LPTR T=L;
    while(T->next!=NULL){
        T=T->next;
    }
    T->next=L->next->next->next;
    loop(L);
}
