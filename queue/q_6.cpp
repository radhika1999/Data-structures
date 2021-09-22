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
        return 0;
    }

        int ans=s1.elements[s1.top];
        s1.top=s1.top-1;
        //cout<<ans;
        return ans;

}
char Top(struct stack<int> &s1){
    if(s1.top==-1){
        cout<<"stack empty"<<endl;
        return 0;
    }
    else{
      return s1.elements[s1.top];
    }
}

using namespace std;
union u{
    int a;
    char c;
};
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
int postfix(union u str[],int tag[], int n){
    stack<int> s;
    s.top=-1;
    s.size=50;
    for(int i=0;i<n;i++){
        if(tag[i]==2){
            int ans=evaluate(pop(s),pop(s),str[i].c);
            push(s,ans);
        }
        else
            push(s,str[i].a);
    }
    return pop(s);
}

int main(){
    union u str[100];
    int n;
    cin>>n;
    int *tag=new int[n];
    for(int i=0;i<n;i++){
        cin>>tag[i];
        cout<<endl;
        if(tag[i]==1){
            int x;
            cin>>x;
            str[i].a=x;
        }
        else{
            char x;
            cin>>x;
            str[i].c=x;
        }
    }
    cout<<postfix(str,tag,n);
}
