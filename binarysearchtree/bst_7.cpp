#include<iostream>
using namespace std;
struct bstnode{
    struct bstnode *lchild;
    int data;
    struct bstnode *rchild;
};
typedef struct bstnode * BSTPTR;
void insert(BSTPTR &T, int k){
    if(T==NULL){
        T=new bstnode;
        T->data=k;
        T->lchild=NULL;
        T->rchild=NULL;
    }
    else{
        if(k>T->data){
            insert(T->rchild, k);
        }
        else if(k<T->data){
            insert(T->lchild, k);
        }
        else{
            cout<<"Duplicate"<<endl;
        }
    }
}

int countleaves(BSTPTR T){
    if(T!=NULL){
        if(T->lchild==NULL&&T->rchild==NULL){
            return 1;
        }
        else{
            return countleaves(T->lchild)+countleaves(T->rchild);
        }
    }
    else{
        return 0;
    }
}

int nonleaves(BSTPTR T){
    int c1=0,c2=0;
    if(T!=NULL){
        if(T->lchild!=NULL)
            c1=nonleaves(T->lchild);
        if(T->rchild!=NULL)
            c2=nonleaves(T->rchild);
    }
    if(T->rchild!=NULL||T->lchild!=NULL)
        return c1+c2+1;
    else
        return c1+c2;
    /*if(T!=NULL){
        if(T->lchild!=NULL||T->rchild!=NULL){
            return nonleaves(T->lchild)+nonleaves(T->rchild);
            return 1;
        }
    }
    else{
        return 1;
    }*/
}
int main(){
    BSTPTR T=NULL;
    int n;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    while(n!=-1){
        insert(T, n);
        cout<<"Enter numbers"<<endl;
        cin>>n;
    }
    cout<<"leaf"<<countleaves(T)<<endl;
    cout<<"nonleaves"<<nonleaves(T)<<endl;
