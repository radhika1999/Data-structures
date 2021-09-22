#include<iostream>
#include<cmath>
using namespace std;

struct convert{
    int n;
    char r;
};

void binary(int n){
    if(n==0)
        return;
    binary(n/2);
    cout<<n%2;
}
void hexadecimal(int n){
    char a[]={'A','B','C','D','E','F'};
    if(n==0)
        return;
    hexadecimal(n/16);
    int x=n%16;
    if(x<10)
        cout<<x;
    else
        cout<<a[x-10];
}
void octal(int n){
    if(n==0)
        return;
    octal(n/8);
    cout<<n%8;
}
void print(int n){
    string s[]={"zero","one","two","three","four","five","six","seven","eight","nime"};
    if(n==0)
        return;
    print(n/10);
    cout<<s[n%10];
}

int main(){
    struct convert s;
    cin>>s.n;
    cin>>s.r;

    switch(s.r){
        case'b':
        binary(s.n);
        break;
        case'h':
        hexadecimal(s.n);
        break;
        case'o':
        octal(s.n);
        break;
        case'p':
        print(s.n);
        break;
    }
}
