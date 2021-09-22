#include "bst_operations.cpp"
#include<queue>
typedef struct bstnode * BSTPTR;
void levelprint(BSTPTR T){
    queue<BSTPTR> q;
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
            cout<<endl;
            q.push(A);
        }
        else{
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
    levelprint(T);
}
