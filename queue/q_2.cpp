#include<iostream>
using namespace std;
union u{
    int a;
    char c;
};
struct queue{
    int f;
    int r;
    u elements[50];
    int tag[50];
    int size;
};
void enqueue(struct queue &Q, u n,int t){
    if((Q.r+1)%Q.size==Q.f)
        cout<<"queue is full"<<endl;
    else{
        if(Q.r==-1){
            Q.f=0;
        }
        Q.r=(Q.r+1)%Q.size;
        if(t==1){
            Q.elements[Q.r].a=n.a;
            Q.tag[Q.r]=1;
        }
        else{
            Q.elements[Q.r].c=n.c;
            Q.tag[Q.r]=2;
        }
    }
}
u dequeue(struct queue &Q, int t){
    if(Q.f==-1){
        cout<<"queue is empty"<<endl;
        u t;
        return t;
    }
    else{
        union u temp;
        if(t==1)
            temp.a=Q.elements[Q.f].a;
        else
            temp.c=Q.elements[Q.f].c;
        if(Q.f==Q.r){
            Q.f=-1;
            Q.r=-1;
        }
        else
            Q.f=(Q.f+1)%Q.size;
        return temp;
    }
}
/*bool isEmpty(struct queue &Q){
    if(Q.f==-1){
            return true;
    }
    return false;
}
*/
int evaluate(int op1,int op2,char ch){
    switch(ch){
    case '+':
        return op1+op2;
    case '-':
        return op1-op2;
    case '*':
        return op1*op2;
    case '/':
        return op1/op2;
    }
}
void prefix_queue(queue &q){
    while(q.r!=q.f){
        if(q.tag[q.f]==2){
            u op;
            op=dequeue(q,2);
            char x=op.c;
            if(q.tag[q.f]==1){
                u op1=dequeue(q,1);
                if(q.tag[q.f]==1){
                    u op2=dequeue(q,1);
                    int t1=op1.a;
                    int t2=op2.a;
                    int ans=evaluate(t1,t2,x);
                    u op3;
                    op3.a=ans;
                    enqueue(q,op3,1);
                }
            }
        }
    }
    union u ans=dequeue(q,1);
    cout<<ans.a;
}
void prefix(union u str[],int tag[], int n){
    queue q;
    q.f=-1;
    q.r=-1;
    q.size=50;
    for(int i=0;i<n;i++){
        if(tag[i]==2){
            if(tag[i+1]==1&&tag[i+2]==1){
                int ans=evaluate(str[i+1].a,str[i+2].a,str[i].c);
                union u ans1;
                ans1.a=ans;
                enqueue(q,ans1,1);
            }
        }
        else
            enqueue(q,str[i],tag[i]);
    }
    prefix_queue(q);
    //int ans=prefix_queue(q);
    //cout<<ans;
}

int main(){
    u str[50];
    int tag[50];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tag[i];
        if(tag[i]==1)
            cin>>str[i].a;
        else
            cin>>str[i].c;
    }
    prefix(str,tag,n);
}
