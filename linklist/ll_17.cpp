#include<iostream>
#include <cstdlib>
using namespace std;
struct rlnode{
    int data;
    struct rlnode *next1;
    struct rlnode *next2;
};
typedef struct rlnode * LPTR;
LPTR create(){
    LPTR L=NULL;
    int n;
    cout<<"Enter numbers"<<endl;
    cin>>n;
    int c=1;
    while(n!=-1){
        c++;
        LPTR T=new rlnode;
        T->data=n;
        if(L==NULL){
            L=T;
            L->next1=NULL;
        }
        else{
            LPTR temp=L;
            while(temp->next1!=NULL){
                temp=temp->next1;
            }
            temp->next1=T;
            T->next1=NULL;
        }
        cout<<"Enter numbers"<<endl;
        cin>>n;
    }
    LPTR T=L;
    while(T!=NULL){
        int x=rand()%c;
        LPTR A=L;
        int cnt=0;
        while(cnt!=x){
            A=A->next1;
        }
        T->next2=A;
    }
    return L;
}
