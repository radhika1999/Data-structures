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

void common(LPTR L1, LPTR L2){
    int c1=0,c2=0;
    LPTR T1=L1, T2=L2;
    while(T1!=NULL){
        c1++;
        T1=T1->next;
    }
    while(T2!=NULL){
        c2++;
        T2=T2->next;
    }
    int x=c1-c2;
    //cout<<x;
    if(x<0){
        while(x!=0){
            L2=L2->next;
            x++;
        }
    }
    else if(x>0){
        while(x!=0){
            L1=L1->next;
            x--;
        }
    }
    while(L1!=L2){
        L1=L1->next;
        L2=L2->next;
    }
    cout<<L2->data;


}
int main(){
    LPTR L1=create();
    LPTR L2=create();
    LPTR T2=L2;
    while(T2->next!=NULL){
        T2=T2->next;
    }
    T2->next=L1->next->next->next->next;
    common(L1, L2);
}
