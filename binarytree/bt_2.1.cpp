#include<stack>
#include "bt_create.cpp"
void print(BTPTR T){
    stack<BTPTR> s;
    while(T!=NULL){
        s.push(T);
        T=T->lchild;
    }
    while(!s.empty()){
        BTPTR A=s.top();
        s.pop();
        cout<<A->data<<" ";
        A=A->rchild;
        while(A!=NULL){
            s.push(A);
            A=A->lchild;
        }
    }
}
int main(){
    BTPTR T;
    create(T, 'A');
    print(T);
}
