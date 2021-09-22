#include<iostream>
using namespace std;
struct stack{
	int elements[50];
	int size1;
	int size2;
	int top1;
	int top2;
};
void push1(struct stack &s, int n){
	if(s.top1==s.size1){
		cout<<"stack 1 full"<<endl;
	}
	else{
		s.elements[++s.top1]=n;
	}
}
int pop1(struct stack &s1){
    if(s1.top1==-1){
        cout<<"stack 1 empty"<<endl;
        return -1;
    }

        int ans=s1.elements[s1.top1];
        s1.top1=s1.top1-1;
        //cout<<ans;
        return ans;

}
void push2(struct stack &s, int n){
	if(s.top2==s.size2){
		cout<<"stack 1 full"<<endl;
	}
	else{
		s.elements[--s.top2]=n;
	}
}
int pop2(struct stack &s1){
    if(s1.top2==-1){
        cout<<"stack empty"<<endl;
        return -1;
    }

        int ans=s1.elements[s1.top2];
        s1.top2=s1.top2+1;
        //cout<<ans;
        return ans;

}
int main(){
	struct stack s;
	s.size1=30;
	s.size2=20;
	s.top1=-1;
	s.top2=50;
	push1(s,10);
	push1(s,20);
	push1(s,30);
	cout<<pop1(s)<<endl;
	push2(s,40);
	push2(s,50);
	push2(s,60);
	cout<<pop2(s)<<endl;
}
