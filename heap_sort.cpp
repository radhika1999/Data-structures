#include "heap_create.cpp"
void circulatedown(int H[], int i){
    if(H[i]>H[2*i+1]){
        swap(H[i], H[2*i+1]);
        circulatedown(H, 2*i+1);
    }
    else if(H[i]>H[2*i+2]){
        swap(H[i], H[2*i+2]);
        circulatedown(H, 2*i+2);
    }
    else
        return;
}
void heapsort(int H[], int n){
    if(n!=0){
        cout<<H[0]<<" ";
        H[0]=H[n-1];
        circulatedown(H, 0);
        heapsort(H, n-1);
    }
}
