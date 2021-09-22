#include<iostream>
using namespace std;
struct queue{
    int f;
    int r;
    int elements[50];
    int size;
};
void enqueue(struct queue &Q, int n){
    if((Q.r+1)%Q.size==Q.f)
        cout<<"queue is full"<<endl;
    else{
        if(Q.r==-1){
            Q.f=0;
        }
        Q.r=(Q.r+1)%Q.size;
        Q.elements[Q.r]=n;
    }
}
int dequeue(struct queue &Q){
    if(Q.f==-1){
        cout<<"queue is empty"<<endl;
        return -1;
    }
    else{
        int t=Q.elements[Q.f];
        if(Q.f==Q.r){
            Q.f=-1;
            Q.r=-1;
        }
        else
            Q.f=(Q.f+1)%Q.size;
        return t;
    }
}
bool isEmpty(struct queue &Q){
    if(Q.f==-1){
            return true;
    }
    return false;
}
struct stack{
    int top;
    int elements[50];
    int size;
};
void push(struct stack &s1, int n){
    if(s1.top==s1.size-1){
        cout<<"stack full"<<endl;
    }
    else{
        s1.top=s1.top+1;
        s1.elements[s1.top]=n;
        //cout<<"a"<<s1.top;
        //cout<<s.elements[s.top]<<endl;
    }

}
int pop(struct stack &s1){
    if(s1.top==-1){
        cout<<"stack empty"<<endl;
        return 0;
    }

        int ans=s1.elements[s1.top];
        s1.top=s1.top-1;
        //cout<<ans;
        return ans;

}
char Top(struct stack &s1){
    if(s1.top==-1){
        cout<<"stack empty"<<endl;
        return 0;
    }
    else{
      return s1.elements[s1.top];
    }
}


bool palindrome(struct stack &s, struct queue &q){
    int k=s.top+1;
    for(int j=0;j<k/2;j++){
        int n=s.top;
        int i;
        for(i=0;i<n;i++){
            enqueue(q, pop(s));
        }
        if(i!=0){
            int x=dequeue(q);
            if(x!=Top(s))
                return false;
            pop(s);
            while(!isEmpty(q)){
                push(s, dequeue(q));
            }
        }
    }
    return true;
}

int main(){
    struct stack s;
    struct queue q;
    q.f=-1;
    q.r=-1;
    q.size=50;
    s.top=-1;
    s.size=50;
    int n,t;
    cin>>n;
    while(n!=0){
        cin>>t;
        push(s,t);
        n--;
    }

    /*push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 2);
    push(s, 1);
    */
    bool ans=palindrome(s,q);
    cout<<ans;
}
