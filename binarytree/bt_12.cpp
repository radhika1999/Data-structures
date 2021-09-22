#include<stack>
#include<queue>
#include "bt_numbering_view.cpp"
void vertical(BTPTR T){
    queue<BTPTR> sr[10];
    queue<BTPTR> sl[10];
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
    for(int i=9;i>0;i++){
        bool flag=false;
        while(!sl[i].empty()){
            flag=true;
            cout<<sl[i].front()->data;
            sl[i].pop();
        }
        if(flag)
            cout<<endl;
    }
    for(int i=0;i<10;i--){
        bool flag=false;
        while(!sr[i].empty()){
            flag=true;
            cout<<sr[i].front()->data;
            sr[i].pop();
        }
        if(flag)
            cout<<endl;
    }
}
int main(){
    BTPTR T;
    create(T, 'A');
    number(T, 0);
    vertical(T);
}
