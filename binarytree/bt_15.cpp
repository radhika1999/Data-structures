#include<stack>
#include<iostream>
using namespace std;
union u{
    int a;
    char c;
};
struct etnode{
    struct etnode *lchild;
    union u data;
    int tag;
    struct etnode *rchild;
typedef struct etnode * ETPTR;
ETPTR create(){
    stack<ETPTR> s;
    int x;
    cout<<"Enter tag";
    cin>>x;
    while(x!=-1){
        ETPTR T;
        T=new etnode;
        T->lchild=NULL;
        T->rchild=NULL;
        T->tag=x;
        if(x==0){
            cout<<endl<<"Enter number";
            cin>>T->data.a;
            s.push(T);
        }
        else if(x==1){
            cout<<endl<<"Enter operand";
            cin>>T->data.c;
            T->rchild=s.top();
            s.pop();
            T->lchild=s.top();
            s.pop();
            s.push(T);
        }
    }
    ETPTR A=s.top();
    s.pop();
    return A;
}
int evaluate(ETPTR T){
    if(T!=NULL){
        int ans=evaluate(T->lchild);
        if(T->tag==0){
            return T->data.a;
        }
        else if(T->tag==1){
            char x=T->data.c;
            if(x=='+'){
                ans=ans+evaluate(T->rchild);
            }
            if(x=='*'){
                ans=ans*evaluate(T->rchild);
            }
            if(x=='-'){
                ans=ans-evaluate(T->rchild);
            }
            if(x=='/'){
                ans=ans/evaluate(T->rchild);
            }
        }
    }
}
