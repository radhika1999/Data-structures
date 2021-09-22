#include<iostream>
using namespace std;
struct btnode{
    struct btnode *lchild;
    int data;
    struct btnode *rchild;
};
typedef struct btnode * BTPTR;
void create(BTPTR a[], int n){
    if(n>1){
        BTPTR T=new btnode;
        T->lchild=a[0];
        T->rchild=a[1];
        T->data=max(a[0]->data, a[1]->data);
        a[n]=T;
        create(a+2, n-1);
    }
}
BTPTR maximum(BTPTR T){
    if(T!=NULL){
        if(T->lchild!=NULL&&T->rchild!=NULL){
            if(T->lchild->data==T->data)
                return maximum(T->lchild);
            else
                return maximum(T->rchild);
        }
        else{
            return T;
        }
    }
}
int main(){
    BTPTR a[30];
    int x;
    int n=0;
    cout<<"Enter numbers ";
    cin>>x;
    while(x!=-1){
        a[n]=new btnode;
        a[n]->data=x;
        a[n]->lchild=NULL;
        a[n]->rchild=NULL;
        n++;
        cout<<"Enter numbers ";
        cin>>x;
    }
    create(a, n);
    //cout<<n<<endl;
    int t=0;
    while(n!=0){
        t=t+n;
        n=n/2;
    }
    //cout<<t<<endl;
    BTPTR T=a[t-1];
    T=maximum(T);
    cout<<T->data;
}
