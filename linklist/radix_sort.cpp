#include<iostream>
#include<cmath>
using namespace std;
void radix(int a[], int n){
    for(double k=0.0;k<3.0;k=k+1.0){
    for(int i=0;i<n-1;i++){
        for (int j=0; j<n-i-1; j++){
           if (a[j]%int((pow(10.0,k))) > a[j+1]%int((pow(10.0,k)))){
              int t=a[j];
              a[j]=a[j+1];
              a[j+1]=t;
           }
        }
    }
    }
}
int main(){
    int b[100],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    radix(b,n);
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
}
