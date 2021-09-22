#include<stack>
#include<queue>
#include "bst_operations.cpp"
void print(BSTPTR T){
    queue<BSTPTR> q;
    stack<BSTPTR> s;
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
            BSTPTR X=A;
            q.push(X);
        }
        else{
            //cout<<A->data<<" ";
            if(A->rchild!=NULL){
                q.push(A->rchild);
            }
            if(A->lchild!=NULL){
                q.push(A->lchild);
            }
        }
        s.push(A);
    }
    while(!s.empty()){
        BSTPTR A=s.top();
        if(A->data==-1){
            cout<<endl;
        }
        else{
            cout<<A->data<<" ";
        }
        s.pop();
        //delete A;
    }
}
int main(){
    BSTPTR T=NULL;
    int n;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    while(n!=-1){
        insert(T, n);
        cout<<"Enter numbers"<<endl;
        cin>>n;
    }
    print(T);
}
