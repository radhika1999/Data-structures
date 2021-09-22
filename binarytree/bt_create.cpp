#include<iostream>
#include<queue>
using namespace std;
struct btnode{
    struct btnode *lchild;
    char data;
    struct btnode *rchild;
};
typedef struct btnode * BTPTR;
void create(BTPTR &T, char c){
    if(c=='x')
        return;
    T=new btnode;
    T->data=c;
    T->lchild=NULL;
    T->rchild=NULL;
    char cl,cr;
    cout<<"Enter left of "<<c;
    cin>>cl;
    create(T->lchild, cl);
    cout<<"Enter right of "<<c;
    cin>>cr;
    create(T->rchild, cr);
}
//
/*int main(){
    BTPTR T;
    create(T, 'A');
}
*/
