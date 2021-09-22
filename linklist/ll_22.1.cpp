
#include<iostream>
using namespace std;
int partition(int a[],int si,int ei){
  int count=0;
  for(int i=si+1;i<=ei;i++){
    if(a[si]>a[i])
        count++;
  }
  int temp;
  int pi=si+count;
  temp=a[si];
  a[si]=a[pi];
  a[si+count]=temp;
  int i=si;
  int j=ei;
  while(i<pi&&j>pi){
    if(a[i]<a[pi]){
        i++;
    }
    else if(a[j]>=a[pi])
        j--;
    else{
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
  }
  return pi;

}
void helper(int a[] , int si , int ei){
  if(si>=ei){
    return;
  }
  int pi=partition(a,si,ei);
  helper(a,si,pi-1);
  helper(a,pi+1,ei);
}
void qs(int a[],int size){
  helper(a,0,size-1);

}
int main(){
  int a[10],n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  qs(a,n);
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
}
