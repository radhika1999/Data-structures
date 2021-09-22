#include<iostream>
#include<queue>
using namespace std;
struct bstnode{
    struct bstnode *lchild;
    int data;
    struct bstnode *rchild;
};
typedef struct bstnode * BSTPTR;
void insert(BSTPTR &T, int k){
    if(T==NULL){
        T=new bstnode;
        T->data=k;
        T->lchild=NULL;
        T->rchild=NULL;
    }
    else{
        if(k>T->data){
            insert(T->rchild, k);
        }
        else if(k<T->data){
            insert(T->lchild, k);
        }
        else{
            cout<<"Duplicate"<<endl;
        }
    }
}

int max(BSTPTR T){
    if(T==NULL){
        return -1;
    }
    if(T->rchild==NULL){
        return T->data;
    }
    else{
        return max(T->rchild);
    }
}

int min(BSTPTR T){
    if(T==NULL){
        return 1000;
    }
    if(T->lchild==NULL){
        return T->data;
    }
    else{
        return min(T->lchild);
    }
}

void sortprint(BSTPTR T){
    if(T!=NULL){
        sortprint(T->lchild);
        cout<<T->data<<" ";
        sortprint(T->rchild);
    }
}

void preorder(BSTPTR T){
    if(T!=NULL){
        cout<<T->data<<" ";
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

void postorder(BSTPTR T){
    if(T!=NULL){
        postorder(T->lchild);
        postorder(T->rchild);
        cout<<T->data<<" ";
    }
}

int find(BSTPTR T, int k){
    if(T!=NULL){
        if(T->data==k)
            return 1;
        find(T->lchild, k);
        find(T->rchild, k);
    }
    else{
        return 0;
    }
}

int height(BSTPTR T){
    if(T==NULL){
        return -1;
    }
    else{
        return (height(T->lchild)>height(T->rchild)?height(T->lchild):height(T->rchild))+1;
    }
}

int countleaves(BSTPTR T){
    if(T!=NULL){
        if(T->lchild==NULL&&T->rchild==NULL){
            return 1;
        }
        else{
            return countleaves(T->lchild)+countleaves(T->rchild);
        }
    }
    else{
        return 0;
    }
}

int nonleaves(BSTPTR T){
    int c1=0,c2=0;
    if(T!=NULL){
        if(T->lchild!=NULL)
            c1=nonleaves(T->lchild);
        if(T->rchild!=NULL)
            c2=nonleaves(T->rchild);
    }
    if(T->rchild!=NULL||T->lchild!=NULL)
        return c1+c2+1;
    else
        return c1+c2;
    /*if(T!=NULL){
        if(T->lchild!=NULL||T->rchild!=NULL){
            return nonleaves(T->lchild)+nonleaves(T->rchild);
            return 1;
        }
    }
    else{
        return 1;
    }*/
}
bool bst_check(BSTPTR T){
    if(T==NULL){
        return true;
    }
    int x=max(T->lchild);
    int y=min(T->rchild);
    //cout<<x<<" "<<y;
    return (T->data>x)&&(T->data<y)&&bst_check(T->lchild)&&bst_check(T->rchild);
}
//18 10 5 6 27 20 45 36 54 -1
/*int main(){
    BSTPTR T=NULL;
    int n;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    while(n!=-1){
        insert(T, n);
        cout<<"Enter numbers"<<endl;
        cin>>n;
    }
    cout<<"Max="<<max(T)<<endl;
    cout<<"Min="<<min(T)<<endl;
    cout<<"Sort print:"<<endl;
    sortprint(T);
    cout<<endl<<"Pre order:"<<endl;
    preorder(T);
    cout<<endl<<"Postoder:"<<endl;
    postorder(T);
    cout<<"Find:"<<find(T,45)<<endl;
    cout<<"Height="<<height(T)<<endl;
    cout<<"Leaves="<<countleaves(T)<<endl;
    cout<<"Non-leaves="<<nonleaves(T)<<endl;
    cout<<"Check "<<bst_check(T);
}

*/
