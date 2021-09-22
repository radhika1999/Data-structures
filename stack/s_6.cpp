#include<iostream>
using namespace std;

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
int Top(struct stack &s1){
    if(s1.top==-1){
        cout<<"stack empty"<<endl;
        return 0;
    }
    else{
      return s1.elements[s1.top];
    }
}

void bubblesort(struct stack &s1, struct stack &s2, int n){
	for(int i=0;i<(n/2)-1;i++){
	int j=0;
	int e;
	if(i!=0)
		e=pop(s1);
	while((j<n-i*2-1)&&s1.top==-1){
		int x=pop(s1);
		if(x>Top(s1)){
			push(s2, pop(s1));
			push(s1, x);
		}
		else{
			push(s2, x);
		}
		j++;
	}
	if(i!=0)
		push(s1,e);
	push(s1, pop(s2));
	while(s2.top!=-1){
		int x=pop(s2);
		if(x>Top(s2)){
			push(s1, pop(s2));
			push(s2, x);
		}
		else{
			push(s1, x);
		}
	}
}
}
int main(){
	struct stack s1;
	struct stack s2;
	int n;
	cin>>n;
	push(s1,2);
	push(s1,8);
	push(s1,3);
	push(s1,9);
	push(s1,11);
	push(s1,4);
	push(s1,1);
	/*for(int i=0;i<n;i++){
        int t;
		cin>>t;
		push(s1,t);
	}*/
	bubblesort(s1,s2,n);
	while(s1.top!=-1){
		cout<<pop(s1)<<" ";
	}
}

