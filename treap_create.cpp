#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct treap{
    struct treap *lchild;
    char k1;
    int k2;
    struct treap *rchild;
};
typedef struct treap * TPTR;
stack<TPTR> s;
void insert(TPTR &T, char a, int p){
    if(T==NULL){
        T=new treap;
        T->lchild=NULL;
        T->rchild=NULL;
        T->k1=a;
        T->k2=p;
        s.push(T);
        return;
    }
    else{
        if(a>T->k1){
            s.push(T);
            insert(T->rchild, a, p);
        }
        else if(a<T->k1){
            s.push(T);
            insert(T->lchild, a, p);
        }
        else{
            cout<<"Duplicate"<<endl;
            return;
        }
    }
}
void rotateone(TPTR K2, TPTR K3){
    K2->lchild=K3->rchild;
    K3->rchild=K2;
}
void rotatetwo(TPTR K2, TPTR K3){
    K2->rchild=K3->lchild;
    K3->lchild=K2;
}
rotatethree(TPTR K1, TPTR K2){

}
rotatefour(TPTR K1, TPTR K2){

}
void check(TPTR &T){
    TPTR H=T;
    TPTR K1=NULL, K3=s.top();
    s.pop();
    while(!s.empty()){
        K1=K3;
        K3=s.top();
        s.pop();
        //cout<<K1->k2<<" "<<K3->k2<<endl;
        if(K3->k2>K1->k2){
            //cout<<"check"<<endl;
            if(K3->lchild!=NULL){
                //cout<<"y"<<endl;
            if(K1==K3->lchild){
                //cout<<"check1"<<endl;
                rotateone(K3, K1);
            }
            }
            else if(K3->rchild!=NULL){
                //cout<<"z"<<endl;
                if(K1->k1==K3->rchild->k1){
                //cout<<"check2"<<endl;
                rotatetwo(K3, K1);
                }
            }
            if(!s.empty()){
                TPTR A=s.top();
                if(A->lchild==K3){
                    A->lchild=K1;
                }
                else if(A->rchild==K3){
                    A->rchild=K1;
                }
                s.push(K1);
            }
            else{
                T=K1;
            }
        }
    }
}
TPTR create(){
    TPTR T=NULL;
    char c;
    cout<<"Enter a character ";
    cin>>c;
    TPTR A=NULL;
    while(c!='-'){
        int p;
        cout<<"Enter priority ";
        cin>>p;
        insert(T, c, p);
        check(T);
        cout<<"Enter a character ";
        cin>>c;
    }
    return T;
}
TPTR mini(TPTR T){
    if(T->lchild==NULL){
        return T;
    }
    else{
        return mini(T->lchild);
    }
}
TPTR delnode(TPTR T, char k){
    if(T==NULL){
        return NULL;
    }
    if(k<T->k1){
        s.push(T);
        T->lchild=delnode(T->lchild, k);
    }
    else if(k>T->k1){
        s.push(T);
        T->rchild=delnode(T->rchild, k);
    }
    else if(k==T->k1){
        if(!(T->lchild)&&!(T->rchild)){
            //delete T;
            return NULL;
        }
        else if((T->lchild)&&!(T->rchild)){
            TPTR X=T->lchild;
            s.push(X);
            //delete T;
            return X;
        }
        else if((T->rchild)&&!(T->lchild)){
            TPTR X=T->rchild;
            s.push(X);
            //delete T;
            return X;
        }
        else {
            TPTR M=mini(T->rchild);
            T->k1=M->k1;
            s.push(T);
            T->rchild=delnode(T->rchild, M->k1);
        }
    }
    return T;
}
void sortprint(TPTR T){
    if(T!=NULL){
        sortprint(T->lchild);
        cout<<T->k1<<" ";
        sortprint(T->rchild);
    }
}
void levelprint(TPTR T){
    queue<TPTR> q;
    if(T!=NULL){
        q.push(T);
        TPTR X=new treap;
        X->k1=-1;
        X->lchild=NULL;
        X->rchild=NULL;
        q.push(X);
    }
    while(!q.empty()&&q.size()!=1){
        TPTR A=q.front();
        q.pop();
        if(A->k1==-1){
            cout<<endl;
            q.push(A);
        }
        else{
            cout<<A->k1<<A->k2<<" ";
            if(A->lchild!=NULL){
                q.push(A->lchild);
            }
            if(A->rchild!=NULL){
                q.push(A->rchild);
            }
        }
    }
}
void helper(TPTR &T, char k){
    T=delnode(T, k);
    check(T);
}
//p 45 s 59 h 21 m 37 e 32 f 3
int main(){
    TPTR T=create();
    levelprint(T);
    cout<<endl;
    helper(T, 'h');
    levelprint(T);
}
