#include<stack>
#include<queue>
#include "bt_numbering_view.cpp"
void topview(BTPTR T){
   stack<BTPTR> s1, s2;
   int x=0;
   BTPTR X=T->rchild;
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
   x=0;
   queue<BTPTR> q;
   while(X!=NULL){
        s1.push(X);
        if(X->n > x){
            q.push(X);
            x=X->n;
        }
        X=X->rchild;
   }
   while(!s1.empty()){
        BTPTR A=s1.top();
        s1.pop();
        A=A->lchild;
        while(A!=NULL){
            s1.push(A);
            if(A->n > x){
                q.push(A);
                x=A->n;
            }
            A=A->rchild;
        }
   }
   while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
   }
   while(!q.empty()){
        cout<<q.front()->data<<" ";
        q.pop();
   }
}
int main(){
    BTPTR T;
    create(T, 'A');
    number(T, 0);
    topview(T);
}
