#include<stack>
#include<queue>
#include "bt_numbering_view.cpp"

void boundary(BTPTR T){
    BTPTR X=T->lchild;
    cout<<T->data<<" ";
    stack<BTPTR> s;
    while(X!=NULL){
            s.push(X);
            cout<<X->data<<" ";
            X=X->lchild;
    }
    int i=0;
    while(!s.empty()){
        BTPTR A=s.top();
        s.pop();
        if(A->lchild==NULL&&A->rchild==NULL&&i!=0){
            cout<<A->data<<" ";
        }
        i=1;
        A=A->rchild;
        while(A!=NULL){
            s.push(A);
            A=A->lchild;
        }
    }
    stack<BTPTR> s1;
    X=T->rchild;
    while(X!=NULL){
        s.push(X);
        s1.push(X);
        X=X->rchild;
    }
    i=0;
    while(!s.empty()){
        BTPTR A=s.top();
        s.pop();
        if(A->rchild==NULL&&A->lchild==NULL&&i!=0){
            s1.push(A);
        }
        i=1;
        A=A->lchild;
        while(A!=NULL){
            s.push(A);
            A=A->rchild;
        }
    }
    while(!s1.empty()){
        cout<<s1.top()->data<<" ";
        s1.pop();
    }
}
int main(){
    BTPTR T;
    create(T, 'A');
    number(T, 0);
    boundary(T);
}
