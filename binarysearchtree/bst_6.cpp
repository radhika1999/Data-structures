#include<iostream>
#include<queue>
using namespace std;
struct bstnode{
    struct bstnode *lchild;
    int data;
    int order;
    struct bstnode *rchild;
};
typedef struct bstnode * BSTPTR;
void insert(BSTPTR &T, int k){
    if(T==NULL){
        T=new bstnode;
        T->data=k;
        T->order=0;
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

int sorting(BSTPTR &T){
    if(T!=NULL){
        int ans= 1+sorting(T->lchild);
        T->order=ans;
        ans= 1+sorting(T->rchild);
    }
    if(T==NULL){
        return 0;
    }
}
void sorting2(BSTPTR &T, int ans){

    if(T!=NULL){
        sorting2(T->lchild, ans);
        T->order=1+ans;
        ans++;
        sorting2(T->rchild, ans);
    }

}
void sorting3(BSTPTR &T){
    int x=1;
    BSTPTR X=T;
    while(X->lchild!=NULL){
        X=X->lchild;
    }
    X->data=x;
    x++;
    if(X->rchild!=NULL){
        X=X->rchild;
    }
}
int x=0;
void sorting4(BSTPTR &T){
    if(T!=NULL){
        sorting4(T->lchild);
        T->order=1+x;
        x=T->order;
        sorting4(T->rchild);
    }
}
//18 10 5 6 27 20 45 36 54 -1
void sorting1(BSTPTR &T){
    if(T!=NULL){
        sorting1(T->lchild);
        cout<<T->order<<" ";
        sorting1(T->rchild);
    }

}
void levelprint(BSTPTR T){
    cout<<endl;
    queue<BSTPTR> q;
    if(T!=NULL){
        q.push(T);
        BSTPTR X=new bstnode;
        X->data=-1;
        X->order=0;
        X->lchild=NULL;
        X->rchild=NULL;
        q.push(X);
    }
    while(!q.empty()&&q.size()!=1){
        BSTPTR A=q.front();
        q.pop();
        if(A->data==-1){
            cout<<endl;
            q.push(A);
        }
        else{
            //cout<<A->order<<endl;
            for(int i=0;i<A->order;i++){
                cout<<" ";
            }
            cout<<A->data;
            if(A->lchild!=NULL){
                q.push(A->lchild);
            }
            if(A->rchild!=NULL){
                q.push(A->rchild);
            }
        }
    }
}
//18 10 5 6 27 20 45 36 54 -1
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
    sorting4(T);
    //sorting1(T);
    levelprint(T);
}

