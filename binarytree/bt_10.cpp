#include<stack>
#include<queue>
#include "bt_numbering_view.cpp"
void bottomview(BTPTR T){
    stack<BTPTR> sr[10];
    stack<BTPTR> sl[10];
    stack<BTPTR> x;
    if(T!=NULL){
        x.push(T);
    }
    while(!x.empty()){
        BTPTR A=x.top();
        x.pop();
        int l=A->n;
        if(l>=0){
            sr[l].push(A);
        }
        else{
            l=l*(-1);
            sl[l].push(A);
        }
        if(A->rchild!=NULL)
            x.push(A->rchild);
        if(A->lchild!=NULL)
            x.push(A->lchild);
    }
    for(int i=9;i>=0;i--){
        if(!sl[i].empty()){
            cout<<sl[i].top()->data<<" ";
            sl[i].pop();
        }
    }
    for(int i=0;i<10;i++){
        if(!sr[i].empty()){
            cout<<sr[i].top()->data<<" ";
            sr[i].pop();
        }
    }
}
int main(){
    BTPTR T;
    create(T, 'A');
    number(T, 0);
    bottomview(T);
}
