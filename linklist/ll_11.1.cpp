#include<iostream>
using namespace std;
struct lnode{
    int data;
    struct lnode *next;
};
typedef struct lnode * LPTR;
struct stack{
    LPTR L;
    //int size;
};
void push(stack &s, int n){
    LPTR NewNode=new lnode;
    NewNode->data=n;
    if(s.L==NULL){
        s.L=NewNode;
        s.L->next=NULL;
    }
    else{
        NewNode->next=s.L;
        s.L=NewNode;
    }
    //s.size++;
}
int pop(stack &s){
    if(s.L==NULL){
        cout<<"stack empty"<<endl;
        return -1;
    }
    int ans=s.L->data;
    s.L=s.L->next;
    //s.size--;
    return ans;
}
int Top(stack &s){
    if(s.L==NULL){
        cout<<"stack empty"<<endl;
        return -1;
    }
    int ans=s.L->data;
    return ans;
}
bool isEmpty(stack &s){
    if(s.L==NULL){
        return true;
    }
    return false;
}
int main(){
    stack s;
    s.L=NULL;
    s.size=0;
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<s.size<<endl;
}

