#include "bst_operations.cpp"
#include<queue>
#include<stack>
void spiralprint(BSTPTR T){
    queue<BSTPTR> q;
    stack<BSTPTR> s;
    //cout<<T->data;
    if(T!=NULL){
        q.push(T);
        BSTPTR X=new bstnode;
        X->data=-1;
        X->lchild=NULL;
        X->rchild=NULL;
        q.push(X);
    }
    bool flag =false;
    while(!q.empty()&&q.size()!=1){
            //cout<<"x";
        BSTPTR A=q.front();
        q.pop();
        if(A->data==-1){
            while(!s.empty()){
                cout<<(s.top())->data<<" ";
                s.pop();
            }
            //cout<<"x";
            if(flag)
                flag=false;
            else
                flag=true;
            cout<<endl;
            q.push(A);
        }
        else{
            if(flag)
                s.push(A);
            else
                cout<<A->data<<" ";
            if(A->lchild!=NULL){
                q.push(A->lchild);
            }
            if(A->rchild!=NULL){
                q.push(A->rchild);
            }
        }
    }
}
//18 10 27 5 6 45 36 54 -1
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
    spiralprint(T);
}
