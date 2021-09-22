#include<iostream>
using namespace std;
template <typename T>
struct stack{
    int top;
    T elements[50];
    int size;
};
void push(struct stack<char> &s1, char n){
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
int pop(struct stack<char> &s1){
    if(s1.top==-1){
        cout<<"stack empty"<<endl;
        return 0;
    }

        char ans=s1.elements[s1.top];
        s1.top=s1.top-1;
        //cout<<ans;
        return ans;

}
char Top(struct stack<char> &s1){
    if(s1.top==-1){
        cout<<"stack empty"<<endl;
        return 0;
    }
    else{
      return s1.elements[s1.top];
    }
}

using namespace std;
bool balance(char str[]){
    struct stack<char> s;
    s.top=-1;
    s.size=50;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='{'||str[i]=='['||str[i]=='('){
            push(s, str[i]);
           }
        if(s.top!=-1){
        if(str[i]=='}'){
            if(pop(s)!='{')
                return false;
        }
        if(str[i]==']'){
            if(pop(s)!='['){
                return false;
            }
        }
        if(str[i]==')'){
            if(pop(s)!='(')
                return false;
        }
        }
    }
    if(s.top==-1)
        return true;
    else
        return false;
}

int main(){
    char st[100];
    cin>>st;
    bool ans=balance(st);
    cout<<ans<<endl;
}
