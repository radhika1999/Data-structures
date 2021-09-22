#include<iostream>
#include<stack>
using namespace std;
struct lnode{
    int data;
    struct lnode *next;
};
typedef struct lnode * LPTR;
LPTR create(){
    LPTR L=NULL;
    int n;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    while(n!=-1){
        LPTR T=new lnode;
        T->data=n;
        if(L==NULL){
            L=T;
            L->next=NULL;
        }
        else{
            LPTR temp=L;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=T;
            T->next=NULL;
        }
        cout<<"Enter numbers"<<endl;
        cin>>n;
    }
    return L;
}

bool palindrome(LPTR L){
    stack<int> s;
    LPTR S=L;
    LPTR F=L;
    int c=0;
    while(F!=NULL){
        c++;
        F=F->next;
    }
    for(int i=0;i<c/2;i++){
        s.push(S->data);
        S=S->next;
    }
    if(c%2!=0){
        //pop(s);
        S=S->next;
    }
    //cout<<S->data<<endl;
    while(S!=NULL){
        if(s.top()!=S->data){
            return false;
        }
        s.pop();
        S=S->next;
    }
    return true;
}
int main(){
    LPTR L=create();
    cout<<palindrome(L);
}
