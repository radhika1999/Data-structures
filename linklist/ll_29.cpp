#include <iostream>
#include<stack>
using namespace std;
//{ibhC{lD}{k{Bf}s} {gh{kC}m} {nop} {qr}
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
LPTR A,B,C,D;
void print(LPTR L){
    cout<<"{";
    while(L!=NULL){
        if(L->tag==0){
            if(L->data.c>='a'&&L->data.c<='z'){
                cout<<L->data.c;
                L=L->next;
                continue;
            }
            else{
                if(L->data.c=='B'){
                    print(B);
                    L=L->next;
                }
                if(L->data.c=='C'){
                    print(C);
                    L=L->next;
                }
                if(L->data.c=='D'){
                    print(D);
                    L=L->next;
                }
            }
        }
        if(L->tag==1){
            print(L->data.dlink);
        }
    }
    cout<<"}";
}
LPTR create(char a[]){
     LPTR P=NULL;
     LPTR L=NULL;
     //cout<<a[1]<<endl;
     for(int i=1;a[i]!='\0';i++){
        LPTR T=new mlnode;
        if(a[i]=='{'){
            /*if(L==NULL){
                L=T;
                P=T;
            }*/
            P->next=T;
            T->tag=1;
            //cout<<"check";
            T->data.dlink=create(a+i);
            //cout<<T->data.dlink->data.c<<endl;
            //cout<<T->tag<<endl;
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
    char b[20];
    char c[20];
    char d[20];
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    A=create(a);
    B=create(b);
    C=create(c);
    D=create(d);
    print(B);
}
