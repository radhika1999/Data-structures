#include "bst_operations.cpp"
void replace(BSTPTR T, int k, int &l, int &h){
    if(T->data==k){
        h=min(T->rchild)-1;
        l=max(T->lchild)+1;
        return;
    }
    else{
        if(T->data>k){
            replace(T->lchild, k, l, h);
            return;
        }
        if(T->data<k){
            replace(T->rchild, k, l, h);
            return;
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
    int l=0, h=0;
    replace(T, 27, l, h);
    cout<<l<<" "<<h;
}
