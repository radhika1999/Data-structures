#include<stack>
#include<queue>
#include "bt_numbering_view.cpp"
void leftview(BTPTR T){
   stack<BTPTR> s1, s2;
   int x=0;
   s2.push(T);
   T=T->lchild;
   while(T!=NULL){
        s1.push(T);
        if(T->n < x){
            s2.push(T);
            x=T->n;
        }
        T=T->lchild;
   }
   while(!s1.empty()){
        BTPTR A=s1.top();
        s1.pop();
        A=A->rchild;
        while(A!=NULL){
            s1.push(A);
            if(A->n < x){
                s2.push(A);
                x=A->n;
            }
            A=A->lchild;
        }
   }
   while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
   }
}
int main(){
    BTPTR T;
    create(T, 'A');
    number(T, 0);
    leftview(T);
}
