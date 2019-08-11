#include<iostream>
using namespace std;
void swap(int &a, int &b){
    int t=a;
    a=b;
    b=t;
}
void insert(int H[], int n, int k){
    H[n]=k;
    while(H[(n-1)/2>H[n]){
        swap(H[(n-1)/2], H[n]);
        n=(n-1)/2;
    }
}
void insert_rec(int H[], int n, int k){
    H[n]=k;
    if(H[(n-1)/2>H[n]){
        swap(H[(n-1)/2], H[n]);
        insert_rec(H, (n-1)/2, k);
    }
}
