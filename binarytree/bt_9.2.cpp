#include<stack>
#include<queue>
#include "bt_numbering_view.cpp"
void rightview(BTPTR T){
   stack<BTPTR> s1, s2;
   int x=0;
   s2.push(T);
   T=T->rchild;
   while(T!=NULL){
        s1.push(T);
        if(T->n > x){
            s2.push(T);
            x=T->n;
        }
        T=T->rchild;
   }
   while(!s1.empty()){
        BTPTR A=s1.top();
        s1.pop();
        A=A->lchild;
        while(A!=NULL){
            s1.push(A);
            if(A->n > x){
                s2.push(A);
                x=A->n;
            }
            A=A->rchild;
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
    rightview(T);
}
