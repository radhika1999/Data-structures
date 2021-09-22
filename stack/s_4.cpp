#include<iostream>
#include <stack>
using namespace std;
void postfix_operation(char str[]){
    stack<char> s;
    //s.top=-1;
    //s.size=50;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='(')
            s.push(str[i]);
        if(str[i]==')'){
            while(s.top()!='('){
                cout<<s.top();
                s.pop();
            }
            s.pop();
        }
        if(str[i]=='+'){
            if(s.size()==0||s.top()=='(')
                s.push(str[i]);
            else{
                while(s.size()!=0){
                    cout<<s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
        }
        else if(str[i]=='-'){
            if(s.size()==0||s.top()=='(')
                s.push(str[i]);
            else{
                while(s.size()!=0){
                    cout<<s.top();
                    s.pop();
                }
                s.push(str[i]);
            }
        }
        else if(str[i]=='*'){
            if(s.top()=='/'){
                cout<<s.top();
                s.pop();
            }
            else
            s.push( str[i]);
        }
        else if(str[i]=='/'){
            if(s.top()=='/'){
                cout<<s.top();
                s.pop();
            }
            else
            s.push(str[i]);
        }
        else{
            cout<<str[i];
        }
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}
int main(){
    char st[100];
    cin>>st;
    postfix_operation(st);

}
