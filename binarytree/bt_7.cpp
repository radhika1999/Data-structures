#include "bt_create.cpp"
bool mirror(BTPTR T1, BTPTR T2){
    if(T1==NULL&&T2==NULL){
        return true;
    }
    if(T1!=NULL&&T2!=NULL){
        if(T1->data!=T2->data){
            return false;
        }
        else{
            bool ans1= mirror(T1->rchild, T2->lchild);
            bool ans2= mirror(T1->lchild, T2->rchild);
            return (ans1&&ans2);
        }
    }
}
int main(){
    BTPTR T1,T2;
    create(T1, 'A');
    create(T2, 'A');
    bool ans=mirror(T1, T2);
    cout<<ans;
}
