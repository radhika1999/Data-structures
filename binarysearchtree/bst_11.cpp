#include<stack>
#include "bst_levelprint.cpp"
void create(BSTPTR &T, int a[], int l, int h){
    if(l<=h){
        int mid=(l+h)/2;
        T=new bstnode;
        T->data=a[mid];
        T->lchild=NULL;
        T->rchild=NULL;
        create(T->lchild, a, l, mid-1);
        create(T->rchild, a, mid+1, h);
    }
    else{
        return;
    }
}
void merge(BSTPTR T1, BSTPTR T2){
    BSTPTR X=T1, Y=T2;
    stack<BSTPTR> s1,s2;
    int a[20], i=0;
    while(X!=NULL&&Y!=NULL){
        s1.push(X);
        s2.push(Y);
        X=X->lchild;
        Y=Y->lchild;
    }
    while(X!=NULL){
        s1.push(X);
        X=X->lchild;
    }
    while(Y!=NULL){
        s2.push(Y);
        Y=Y->lchild;
    }
    while(!s1.empty()&&!s2.empty()){
        X=s1.top();
        Y=s2.top();
        if(X->data<Y->data){
            a[i++]=X->data;
            s1.pop();
            X=X->rchild;
            while(X!=NULL){
                s1.push(X);
                X=X->lchild;
            }
        }
        else if(X->data>Y->data){
            a[i++]=Y->data;
            s2.pop();
            Y=Y->rchild;
            while(Y!=NULL){
                s2.push(Y);
                Y=Y->lchild;
            }
        }
        else{
            a[i++]=X->data;
            s1.pop();
            s2.pop();
            X=X->rchild;
            while(X!=NULL){
                s1.push(X);
                X=X->lchild;
            }
            Y=Y->rchild;
            while(Y!=NULL){
                s2.push(Y);
                Y=Y->lchild;
            }
        }
    }
    BSTPTR T=NULL;
    create(T, a, 0, i-1);
    levelprint(T);
}
int main(){
    BSTPTR T1=NULL;
    int n;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    while(n!=-1){
        insert(T1, n);
        cout<<"Enter numbers"<<endl;
        cin>>n;
    }
    BSTPTR T2=NULL;
    //int n;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    while(n!=-1){
        insert(T2, n);
        cout<<"Enter numbers"<<endl;
        cin>>n;
    }
    merge(T1, T2);
}
