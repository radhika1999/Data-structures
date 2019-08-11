#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
struct bstnode{
    struct bstnode *lchild;
    int data;
    struct bstnode *rchild;
};
typedef struct bstnode * BSTPTR;
stack<BSTPTR> s;
void insert(BSTPTR &T, int k){
    if(T==NULL){
        T=new bstnode;
        T->data=k;
        T->lchild=NULL;
        T->rchild=NULL;
        s.push(T);
    }
    else{
        if(k>T->data){
            s.push(T);
            insert(T->rchild, k);
        }
        else if(k<T->data){
            s.push(T);
            insert(T->lchild, k);
        }
        else{
            cout<<"Duplicate"<<endl;
        }
    }
}
void preorder(BSTPTR T){
    if(T!=NULL){
        cout<<T->data<<" ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}
void levelprint(BSTPTR T){
    queue<BSTPTR> q;
    if(T!=NULL){
        q.push(T);
        BSTPTR X=new bstnode;
        X->data=-1;
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
            cout<<A->data<<" ";
            if(A->lchild!=NULL){
                q.push(A->lchild);
            }
            if(A->rchild!=NULL){
                q.push(A->rchild);
            }
        }
    }
}
BSTPTR mini(BSTPTR T){
    if(T->lchild==NULL){
        return T;
    }
    else{
        return mini(T->lchild);
    }
}
int height(BSTPTR T){
    if(T==NULL){
        return -1;
    }
    else{
        return (height(T->lchild)>height(T->rchild)?height(T->lchild):height(T->rchild))+1;
    }
}
void rotateleft(BSTPTR &K1, BSTPTR &K2){
    K1->rchild=K2->lchild;
    K2->lchild=K1;
}
void rotateright(BSTPTR &K1, BSTPTR &K2){
    K1->lchild=K2->rchild;
    K2->rchild=K1;
}
void doublerotateleft(BSTPTR &K1, BSTPTR &K2, BSTPTR &K3){
    K3->rchild=K2->lchild;
    K1->lchild=K2->rchild;
    K2->lchild=K3;
    K2->rchild=K1;
}
void doublerotateright(BSTPTR &K1, BSTPTR &K2, BSTPTR &K3){
    K3->lchild=K2->rchild;
    K1->rchild=K2->lchild;
    K2->rchild=K3;
    K2->lchild=K1;
}
void check_height(BSTPTR &T, int n){
    //cout<<"a"<<endl;
    BSTPTR K1=NULL, K2=NULL, K3=NULL;
    bool flag=false;
    while(!s.empty()){
        K2=K1;
        K1=K3;
        K3=s.top();
        s.pop();
        int h1=height(K3->lchild);
        int h2=height(K3->rchild);
        if((h1-h2)>1||(h1-h2)<-1){
                //cout<<"a"<<endl;
            flag=true;
            break;
        }
    }
    if(flag){
        if(n>K3->data&&n<K1->data){
            doublerotateleft(K1, K2, K3);
            if(!s.empty()){
                BSTPTR P=s.top();
                if(P->lchild==K3)
                    P->lchild=K2;
                else if(P->rchild==K3)
                    P->rchild=K2;
            }
            else{
                T=K2;
            }
        }
        else if(n>K1->data&&n<K3->data){
            doublerotateright(K1, K2, K3);
            if(!s.empty()){
                BSTPTR P=s.top();
                if(P->lchild==K3)
                    P->lchild=K2;
                else if(P->rchild==K3)
                    P->rchild=K2;
            }
            else{
                T=K2;
            }
        }
        else if(n>K1->data&&n>K3->data){
            rotateleft(K3, K1);
            if(!s.empty()){
                BSTPTR P=s.top();
                if(P->lchild==K3)
                    P->lchild=K1;
                else if(P->rchild==K3)
                    P->rchild=K1;
            }
            else{
                T=K1;
            }
        }
        else if(n<K1->data&&n<K3->data){
            rotateright(K3, K1);
            if(!s.empty()){
                BSTPTR P=s.top();
                if(P->lchild==K3)
                    P->lchild=K1;
                else if(P->rchild==K3)
                    P->rchild=K1;
            }
            else{
                T=K1;
            }
        }
    }
        while(!s.empty()){
            s.pop();
        }
}
BSTPTR create(){
    BSTPTR T=NULL;
    int n;
    cout<<"Enter number ";
    cin>>n;
    while(n!=-1){
        insert(T, n);
        check_height(T, n);
        cout<<endl<<"Enter number ";
        cin>>n;
    }
    return T;
}
BSTPTR delnode(BSTPTR T, int k){
    if(T==NULL){
        return NULL;
    }
    if(k<T->data){
        s.push(T);
        T->lchild=delnode(T->lchild, k);
    }
    else if(k>T->data){
        s.push(T);
        T->rchild=delnode(T->rchild, k);
    }
    else if(k==T->data){
        if(!(T->lchild)&&!(T->rchild)){
            //delete T;
            return NULL;
        }
        else if((T->lchild)&&!(T->rchild)){
            BSTPTR X=T->lchild;
            s.push(X);
            //delete T;
            return X;
        }
        else if((T->rchild)&&!(T->lchild)){
            BSTPTR X=T->rchild;
            s.push(X);
            //delete T;
            return X;
        }
        else {
            BSTPTR M=mini(T->rchild);
            T->data=M->data;
            s.push(T);
            T->rchild=delnode(T->rchild, M->data);
        }
    }
    return T;
}
void helper(){

}
int main(){
    BSTPTR T=create();
    levelprint(T);

}
