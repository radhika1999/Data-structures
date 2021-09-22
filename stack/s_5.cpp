#include<iostream>
using namespace std;
union u{
	int k;
	char c;
	float f;
	char name[20];
};
struct stack{
	int tag[50];
	union u elements[50];
	int top;
	int size;
};
void push(struct stack &s1, union u n){
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
void pop(struct stack &s1,int tag){
    if(s1.top==-1){
        cout<<"stack empty"<<endl;
    }
    else{
        cout<<s1.elements[s1.top];
        s1.top=s1.top-1;
    }

}
/*u Top(struct stack &s1){
    if(s1.top==-1){
        cout<<"stack empty"<<endl;
    }
    else{
      return s1.elements[s1.top];
    }
}
*/
int main(){
	struct stack s;
	union u var;
	var.k=25;
	push(s, var);
	var.c='a';
	push(s, var);
	var.f=17.5;
	push(s, var);

	var.k=45;
	push(s, var);

	cout<<pop(s);
	cout<<pop(s);
	cout<<pop(s);
	cout<<pop(s);

}
