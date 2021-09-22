#include<iostream>
using namespace std;
template <typename T>
struct stack{
    int top;
    T elements[50];
    int size;
};
void push(struct stack<int> &s1, int n){
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
int pop(struct stack<int> &s1){
    if(s1.top==-1){
        cout<<"stack empty"<<endl;
        return -1;
    }

        int ans=s1.elements[s1.top];
        s1.top=s1.top-1;
        //cout<<ans;
        return ans;

}
int Top(struct stack<int> &s1){
    if(s1.top==-1){
        cout<<"stack empty"<<endl;
        return -1;
    }
    else{
      return s1.elements[s1.top];
    }
}
void printdigit(struct stack<int> s, int n){
    while(n!=0){
        push(s, n%10);
        //cout<<s.top;
        n=n/10;
    }
    while(s.top!=-1){
        int x=pop(s);
        //cout<<s.top;
        cout<<x<<endl;
    }
}
int main(){
    struct stack<int> s;
    int n;
    cin>>n;
    s.top=-1;
    s.size=50;
    printdigit(s, n);
}
