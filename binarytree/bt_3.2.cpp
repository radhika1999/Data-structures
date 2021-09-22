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
bool check(char a[], int l, int h, char x){
    bool flag=false;
    for(int i=l;i<=h;i++){
        if(a[i]==x){
            flag=true;
            break;
        }
    }
    return flag;
}
int left_right(char a[], int n, char b[], int l, int h, char x[]){
    int c=0;
    for(int i=0;i<n;i++){
        if(check(b, l, h, a[i])){
            x[c++]=a[i];
        }
    }
    return c;
}
void create(BTPTR &T, char a[], int n, char b[], int l, int h){
    if(l<=h){
        T=new btnode;
        T->data=a[0];
        T->lchild=NULL;
        T->rchild=NULL;
        int p=find(b, a[0]);
        char left[20];
        char right[20];
        int x=left_right(a+1, n-1, b, l, p-1, left);
        int y=left_right(a+1, n-1, b, p+1, h, right);
        create(T->lchild, left, x, b, l, p-1);
        create(T->rchild, right, y, b, p+1, h);
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
    create(T, a, h1, b, 0, h2-1);
    print(T);
}
