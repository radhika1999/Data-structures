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

struct rnode{
    LPTR P;
    struct rnode *right;
    struct rnode *left;
};
typedef struct rnode * RPTR;
RPTR R;

LPTR addnode(LPTR R, int n){
    LPTR A=R;
    LPTR T=new lnode;
    T->data=n;
    if(R==NULL){
        A=T;
        T->next=NULL;
    }
    else{
        while(R->next!=NULL){
            R=R->next;
        }
        R->next=T;
        T->next=NULL;
    }
    return A;
}
void radixsort(int a[], int n){
    RPTR P=NULL;
    for(int j=0;j<10;j++){
    RPTR T=new rnode;
    T->P=NULL;
    if(R==NULL){
        R=T;
        T->left=P;
        P=T;
    }
    else{
        P->right=T;
        T->left=P;
        P=T;
    }
    T->right=NULL;
}
    for(int k=0;k<3;k=k+1){
        int c=0;
        RPTR T=R;
        for(int i=0;i<n;i++){
            int x;
            if(k==0){
                x=a[i]%10;
            }
            if(k==1){
                x=a[i]/10;
                x=x%10;
            }
            if(k==2){
                x=a[i]/100;
            }
            if(x>c){
                while(c!=x){
                    T=T->right;
                    c++;
                }
            }
            else if(x<c){
                while(c!=x){
                    T=T->left;
                    c--;
                }
            }
            T->P=addnode(T->P,a[i]);
        }
        RPTR T1=R;
        for(int i=0;i<n;i++){
            if(T1->P==NULL){
                T1=T1->right;
                i--;
                continue;
            }
            if(T1->P!=NULL){
                //cout<<"a";
                a[i]=T1->P->data;
                T1->P=T1->P->next;
            }
        }
}
}
int main(){
    int a[20];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    radixsort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
