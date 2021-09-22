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

struct lnode{
    char* data=new char[10];
    struct lnode *next;
};
typedef struct lnode * LPTR;
LPTR create(){
    LPTR L=NULL;
    char n[10];
    cout<<"Enter string"<<endl;
    cin>>n;
    while(n[0]!='x'){
        LPTR T=new lnode;
        int i;
        for( i=0;n[i]!='\0';i++){
            T->data[i]=n[i];
        }
        T->data[i]='\0';
        if(L==NULL){
            L=T;
            L->next=NULL;
        }
        else{
            LPTR temp=L;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=T;
            T->next=NULL;
        }
        cout<<"Enter string"<<endl;
        cin>>n;
    }
    return L;
}

int count(LPTR L){
    int c=0;
    while(L!=NULL){
        for(int i=0;L->data[i]!='\0';i++){
            c++;
        }
        L=L->next;
    }
    return c;
}
bool palindrome(LPTR L){
    struct stack<char> s;
    s.top=-1;
    s.size=50;
    bool ans;
    int c=count(L);
    int x=0;
    while(x<c/2){
        if(L->data[0]=='\0'){
            L=L->next;
        }
        else{
            push(s,L->data[0]);
            L->data=L->data+1;
            x++;
        }
    }
    while(x!=c){
        if(L->data[0]=='\0'){
            L=L->next;
        }
        else{
            if(pop(s)!=L->data[0]){
                return false;
            }
            x++;
            L->data=L->data+1;
        }
    }
    return true;
}

int main(){
    LPTR L=create();
    bool ans=palindrome(L);
    cout<<ans;
}
