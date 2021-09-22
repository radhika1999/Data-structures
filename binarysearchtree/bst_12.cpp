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
int main(){
    int a[20];
    int n;
    int i=0;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    while(n!=-1){
        a[i++]=n;
        cout<<"Enter numbers"<<endl;
        cin>>n;
    }
    BSTPTR T=NULL;
    create(T, a, 0, i-1);
    levelprint(T);
}
