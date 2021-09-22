#include<iostream>
#include<cstring>
using namespace std;
struct btnode{
    struct btnode *lchild;
    char data;
    struct btnode *rchild;
};
typedef struct btnode * BTPTR;
void create(BTPTR &T, char a[], int n){
    if(n!=0){
        if(a[0]!='.'){
            T=new btnode;
            T->data=a[0];
            T->lchild=NULL;
            T->rchild=NULL;
            create(T->lchild, a+1, n-1);
            create(T->rchild, a+1, n-1);
        }
        else{
            return;
        }
    }
}
/*int main(){
    char a[20];
    cin>>a;
    int n=strlen(a);
    BTPTR T;
    create(T, a, n);
}
*/
