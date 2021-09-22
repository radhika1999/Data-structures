#include "bst_operations.cpp"
#include<queue>
typedef struct bstnode * BSTPTR;
int levelmax(BSTPTR T){
    queue<BSTPTR> q;
    int s=0;
    if(T!=NULL){
        q.push(T);
        s=T->data;
        BSTPTR X=new bstnode;
        X->data=-1;
        X->lchild=NULL;
        X->rchild=NULL;
        q.push(X);
    }
    int c=0;
    while(!q.empty()&&q.size()!=1){
        BSTPTR A=q.front();
        q.pop();
        if(c>s)
            s=c;
        c=0;
        if(A->data==-1){
            //cout<<endl;
            q.push(A);
        }
        else{
            c=c+T->data;
            //cout<<A->data<<" ";
            if(A->lchild!=NULL){
                q.push(A->lchild);
            }
            if(A->rchild!=NULL){
                q.push(A->rchild);
            }
        }
    }
    return s;
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
    cout<<levelmax(T);
}

