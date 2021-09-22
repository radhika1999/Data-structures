#include<iostream>
using namespace std;
struct lnode{
    int data;
    struct lnode *next;
};
typedef struct lnode * LPTR;
struct queue{
    LPTR L;
    LPTR R;
};
void enqueue(queue &q, int n){
    LPTR NewNode=new lnode;
    NewNode->data=n;
    if(q.L==NULL){
        q.L=NewNode;
        q.R=NewNode;
    }
    else{
        q.R->next=NewNode;
        q.R=NewNode;
    }
    q.R->next=NULL;
}
int dequeue(queue &q){
    if(q.L==NULL){
        cout<<"queue empty"<<endl;
        return -1;
    }
    int ans=q.L->data;
    q.L=q.L->next;
    return ans;
}
bool isEmpty(queue &q){
    if(q.L==NULL){
        return true;
    }
    return false;
}
/*int main(){
    queue q;
    q.L=NULL;
    q.R=NULL;
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    cout<<dequeue(q)<<endl;
    cout<<dequeue(q)<<endl;
}*/
