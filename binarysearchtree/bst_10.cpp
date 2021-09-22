#include "bst_operations.cpp"
bool path(BSTPTR T, int a[], int &n, int k){
    if(T==NULL){
        n=0;
        return false;
    }
    if(T->data==k){
        for(int i=n;i>0;i--){
            a[i]=a[i-1];
        }
        n++;
        a[0]=T->data;
        return true;
    }
    else{
       bool ans1=path(T->lchild, a, n, k-T->data);
       if(ans1){
        for(int i=n;i>0;i--){
            a[i]=a[i-1];
        }
        n++;
        a[0]=T->data;
        return true;
       }
       bool ans2=path(T->rchild, a, n, k-T->data);
       if(ans2){
        for(int i=n;i>0;i--){
            a[i]=a[i-1];
        }
        n++;
        a[0]=T->data;
        return true;
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
    int a[20], i=0, k;
    cin>>k;
    bool ans=path(T, a, i, k);
    for(int j=0;j<i;j++){
        cout<<a[j]<<" ";
    }
}
