#include <iostream>
#include<stack>
using namespace std;
union u{
    char c;
    struct mlnode *dlink;
};
struct mlnode{
    int tag;
    union u data;
    struct mlnode *next;
};
typedef struct mlnode * LPTR;
void print(LPTR L){
    cout<<"{";
    while(L!=NULL){
        if(L->tag==0){
            cout<<L->data.c;
            L=L->next;
        }
        else{
            cout<<"{";
            print(L->data.dlink);
            cout<<"}";
        }
    }
    cout<<"}";
}
LPTR create(char a[]){
     LPTR P=NULL;
     LPTR L=NULL;
     for(int i=1;a[i]!='\0';i++){
        LPTR T=new mlnode;
        if(a[i]=='{'){
            if(L==NULL){
                L=T;
                P=T;
            }
            P->next=T;
            T->tag=1;
            T->data.dlink=create(a+i);
        }
        else if(a[i]=='}'){
            P->next=NULL;
        }
        else{
            if(L==NULL){
                L=T;
            }
            else
                P->next=T;
            T->tag=0;
            T->data.c=a[i];
            T->next=NULL;
            P=T;
        }
    }
    return L;
}
int main(){
    char a[20];
    cin>>a;
    LPTR L=create(a);
    print(L);
}
