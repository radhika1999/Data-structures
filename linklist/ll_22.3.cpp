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

int count(LPTR L){
    if(L==NULL){
        return 0;
    }
    return 1+count(L->next);
}
void swap_val(int &a, int &b){
    int t=a;
    a=b;
    b=t;
}
int partition(LPTR L, int low, int high){
    int l,h,p;
    int c=0;
    LPTR T=L;
    LPTR T1=L,T2=L;
    while(c<low&&L!=NULL){
        L=L->next;
        T1=T1->next;
        c++;
    }
    T1=T1->next;
    c=0;
    while(c<high&&T2!=NULL){
        T2=T2->next;
        c++;
    }
    p=L->data;
    l=low+1;
    h=high;
    while(l<h){
        while(T1->data<p){
            T1=T1->next;
            l++;
        }
        while(T2->data>p){
            c=0;
            T2=T;
            while(c<h-1){
                T2=T2->next;
                c++;
            }
            //T2=T2->left;
            h--;
        }
        if(l<h){
            swap_val(T1->data,T2->data);
        }
    }
    swap_val(L->data,T2->data);
    return h;
}
void quicksort(LPTR L, int low, int high){
    int j;
    if(low<high){
        j=partition(L,low,high);
        //cout<<"j="<<endl;
        quicksort(L,low,j-1);
        quicksort(L,j+1,high);
    }
}
int main(){
    LPTR L=create();
    int c=count(L);
    //cout<<"c="<<c<<endl;
    quicksort(L,0,c-1);
    //swap_val(D->data,D->right->data);
    while(L!=NULL){
        cout<<L->data<<" ";
        L=L->next;
    }
}
