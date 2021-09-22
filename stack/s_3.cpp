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
int postfix_operation(char str[]){
    struct stack<int> s;
    s.top=-1;
    s.size=50;
    for(int i=0;str[i]!='\0';i++){
        int ans;
        if(str[i]=='+'){
            ans=evaluate(pop(s),pop(s),str[i]);
            push(s,ans);
        }
        else if(str[i]=='-'){
            ans=evaluate(pop(s),pop(s),str[i]);
            push(s, ans);
        }
        else if(str[i]=='*'){
            ans=evaluate(pop(s),pop(s),str[i]);
            push(s, ans);
        }
        else if(str[i]=='/'){
            ans=evaluate(pop(s),pop(s),str[i]);
            push(s, ans);
        }
        else{
            push(s, str[i]-'0');
        }
    }
    return pop(s);
}
int main(){
    char st[100];
    cin>>st;
    cout<<postfix_operation(st);

}
