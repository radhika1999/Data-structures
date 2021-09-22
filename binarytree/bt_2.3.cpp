#include<stack>
#include "bt_create.cpp"
void preorder(BTPTR T){
    stack<BTPTR> s;
    if(T!=NULL){
        s.push(T);
    }
    while(!s.empty()){
        BTPTR A=s.top();
        s.pop();
        cout<<A->data<<" ";
        if(A->rchild!=NULL)
            s.push(A->rchild);
        if(A->lchild!=NULL)
            s.push(A->lchild);
    }
}
int main(){
    BTPTR T;
    create(T, 'A');
    preorder(T);
}
