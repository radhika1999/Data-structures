#include "bt_create.cpp"
int level(BTPTR T){
    if(T==NULL){
        return -1;
    }
    else{
        return (level(T->lchild)>level(T->rchild)?level(T->lchild):level(T->rchild))+1;
    }
}
int main(){
    BTPTR T;
    create(T, 'A');
    cout<<level(T);
}
