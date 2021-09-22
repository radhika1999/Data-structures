#include<iostream>
#include<stack>
using namespace std;
bool check(int push[], int pop[], int n){
    stack<int> s;
    int c=0;
    for(int i=0;i<n;i++){
        if(pop[c]==push[i]){
            s.pop();
            i--;
            c++;
        }
        else{
            s.push(push[i]);
        }
    }
    if(c==n)
        cout<<"true";
    else
        cout<<"false";
}
int main(){
    int n;
    cin>>n;
    int a[20], b[20];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    check(a, b, n);
}
