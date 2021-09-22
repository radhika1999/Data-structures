#include<iostream>
using namespace std;
struct stack_k{
    int elements[50];
    int size;
    int top[50];
    int k;
};
void push(struct stack_k &s1, int n, int c){
    if(s1.top[c]==(s1.size)+c*s1.size-1){
        cout<<"stack full"<<endl;
    }
    else{
        s1.top[c]=s1.top[c]+1;
        s1.elements[s1.top[c]]=n;
    }

}
int pop(struct stack_k &s1, int c){
    if(s1.top[c]==-1+c*s1.size){
        cout<<"stack empty"<<endl;
        return 0;
    }

        int ans=s1.elements[s1.top[c]];
        s1.top[c]=s1.top[c]-1;
        return ans;

}
int Top(struct stack_k &s1, int c){
    if(s1.top[c]==-1+c*s1.size){
        cout<<"stack empty"<<endl;
        return 0;
    }
    else{
      return s1.elements[s1.top[c]];
    }
}

int main(){
    struct stack_k s;
    cout<<"Enter k"<<endl;
    cin>>s.k;
    s.size=50/s.k;
    for(int i=0;i<s.k;i++){
        s.top[i]=-1+i*s.size;
    }
    int c;
    cout<<"Which part to work on"<<endl;
    cin>>c;
    push(s, 10, c);
    push(s, 20, c);
    cout<<pop(s, c);
    push(s, 30, 3);
    cout<<pop(s, 3);

}
