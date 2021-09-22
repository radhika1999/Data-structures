#include<stack>
#include "bst_operations.cpp"
void common(BSTPTR T1, BSTPTR T2){
    BSTPTR X=T1, Y=T2;
    stack<BSTPTR> s1,s2;
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
            s1.pop();
            X=X->rchild;
            while(X!=NULL){
                s1.push(X);
                X=X->lchild;
            }
        }
        else if(X->data>Y->data){
            s2.pop();
            Y=Y->rchild;
            while(Y!=NULL){
                s2.push(Y);
                Y=Y->lchild;
            }
        }
        else{
            cout<<X->data<<" ";
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
}
/*18 12 36 5 16 20 45 2 9 -1
20 16 40 12 36 90 9 13 -1
*/
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
    common(T1, T2);
}
