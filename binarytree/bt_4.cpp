#include<stack>
#include "mergesort.cpp"
struct btnode{
    struct btnode *lchild;
    int data;
    struct btnode *rchild;
};
typedef struct btnode * BTPTR;
void create(BTPTR &T, int c){
    if(c==-1)
        return;
    T=new btnode;
    T->data=c;
    T->lchild=NULL;
    T->rchild=NULL;
    int cl,cr;
    cout<<"Enter left of "<<c;
    cin>>cl;
    create(T->lchild, cl);
    cout<<"Enter right of "<<c;
    cin>>cr;
    create(T->rchild, cr);
}

void scan(BTPTR T, int a[], int &n){
    if(T!=NULL){
        a[n++]=T->data;
        scan(T->lchild, a, n);
        scan(T->rchild, a, n);
    }
}
void createbst(BTPTR &T, int a[], int n){
    stack<BTPTR> s;
    while(T!=NULL){
        s.push(T);
        T=T->rchild;
    }
    while(!s.empty()){
        BTPTR A=s.top();
        s.pop();
        A->data=a[n--];
        A=A->lchild;
        while(A!=NULL){
            s.push(A);
            A=A->rchild;
        }
    }
}
void print(BTPTR T){
    if(T!=NULL){
        print(T->lchild);
        cout<<T->data<<" ";
        print(T->rchild);
    }
}
int main(){
    BTPTR T;
    create(T, 30);
    int a[30];
    int n=0;
    scan(T, a, n);
    merges(a, n);
    createbst(T, a, n);
    print(T);
}
