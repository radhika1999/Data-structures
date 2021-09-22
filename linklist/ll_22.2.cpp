#include<iostream>
using namespace std;
struct dnode{
    int data;
    struct dnode *right;
    struct dnode *left;
};
typedef struct dnode * DPTR;
DPTR create_dll(){
    DPTR D=NULL;
    int n;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    while(n!=-1){
        DPTR T=new dnode;
        T->data=n;
        if(D==NULL){
            D=T;
            D->right=NULL;
            D->left=NULL;
        }
        else{
            DPTR temp=D;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            T->left=temp;
            temp->right=T;
            T->right=NULL;
        }
        cout<<"Enter numbers"<<endl;
        cin>>n;
    }
    return D;
}
int count(DPTR D){
    if(D==NULL){
        return 0;
    }
    return 1+count(D->right);
}
void swap_val(int &a, int &b){
    int t=a;
    a=b;
    b=t;
}
/*void swap(DPTR D1, DPTR D2){
    if(D1==D2){
        return;
    }
    if(D1->right==D2){
        DPTR T1=D2->right;
        D1->left->right=D2;
        D2->left=D1->left;
        D1->right=T1;
        T1->left=D1;
        D2->right=D1;
        D1->left=D2;
        return;
    }
    DPTR T1=D2->right;
    DPTR T2=D2->left;
    D1->right->left=D2;
    D1->left->right=D2;
    D2->right=D1->right;
    D2->left=D1->left;
    T1->left=D1;
    T2->right=D1;
    D1->right=T1;
    D1->left=T2;
}*/
int partition(DPTR D, int low, int high){
    int l,h,p;
    int c=0;
    DPTR T1=D,T2=D;
    while(c<low&&D!=NULL){
        D=D->right;
        T1=T1->right;
        c++;
    }
    T1=T1->right;
    c=0;
    while(c<high&&T2!=NULL){
        T2=T2->right;
        c++;
    }
    p=D->data;
    l=low+1;
    h=high;
    while(l<h){
        while(T1->data<p){
            T1=T1->right;
            l++;
        }
        while(T2->data>p){
            T2=T2->left;
            h--;
        }
        if(l<h){
            swap_val(T1->data,T2->data);
        }
    }
    swap_val(D->data,T2->data);
    return h;
}
void quicksort(DPTR D, int low, int high){
    int j;
    if(low<high){
        j=partition(D,low,high);
        //cout<<"j="<<endl;
        quicksort(D,low,j-1);
        quicksort(D,j+1,high);
    }
}
int main(){
    DPTR D=create_dll();
    int c=count(D);
    //cout<<"c="<<c<<endl;
    quicksort(D,0,c-1);
    //swap_val(D->data,D->right->data);
    while(D!=NULL){
        cout<<D->data<<" ";
        D=D->right;
    }
}
