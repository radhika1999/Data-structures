#include<stack>
#include "bst_operations.cpp"
stack<BSTPTR> s;
int cousin(BSTPTR T, int k){
    queue<BSTPTR> q;
    int s=0;
    if(T!=NULL){
        q.push(T);
        BSTPTR X=new bstnode;
        X->data=-1;
        X->lchild=NULL;
        X->rchild=NULL;
        q.push(X);
    }
    bool flag=false;
    while(!q.empty()&&q.size()!=1){
        BSTPTR A=q.front();
        q.pop();
        if(A->data==-1){
            if(flag){
                return s;
            }
            s=0;
            q.push(A);
        }
        else{
            s=s+A->data;
            if(A->data==k){
                flag=true;
            }
            if(A->lchild!=NULL){
                q.push(A->lchild);
            }
            if(A->rchild!=NULL){
                q.push(A->rchild);
            }
        }
    }
}
//18 10 5 6 27 20 45 36 54 -1
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
    cout<<cousin(T, 5);
}
