#include<stack>
#include "bt_create.cpp"
void postorder(BTPTR T){
    stack<BTPTR> s;
    while(T!=NULL){
        s.push(T);
        T=T->lchild;
    }
    while(!s.empty()){
        BTPTR A=s.top();
        s.pop();
        /*while(A->lchild!=NULL){
            s.push(A->lchild);
            A=A->lchild;
        }*/
        if(A->rchild!=NULL){
            s.push(A->rchild);
        }
        else{
            cout<<A->data<<" ";
        }
    }
}
int main(){
    BTPTR T;
    create(T, 'A');
    postorder(T);
}
