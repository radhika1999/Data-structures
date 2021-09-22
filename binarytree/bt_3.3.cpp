#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct btnode{
    struct btnode *lchild;
    char data;
    struct btnode *rchild;
};
typedef struct btnode * BTPTR;
int find(char b[], char c){
    int i=0;
    while(b[i]!=c){
        i++;
    }
    return i;
}
void create(BTPTR &T, char a[], int l1, int h1, char b[], int l2, int h2){
    if(l1<=l2){
        T=new btnode;
        T->data=a[h1];
        T->lchild=NULL;
        T->rchild=NULL;
        int p=find(b, a[h1]);
        int len=p-l2;
        create(T->lchild, a, l1, len+l1, b, l2, p-1);
        create(T->rchild, a, len+l1+1, h1-1, b, p+1, h2);
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
    char a[20];
    char b[20];
    cin>>a>>b;
    int h1=strlen(a);
    int h2=strlen(b);
    BTPTR T;
    create(T, a, 0, h1-1, b, 0, h2-1);
    print(T);
}
