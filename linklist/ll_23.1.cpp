#include "LL_queue.cpp"
void radixsort(int a[], int n){
    struct queue q[10];
    for(int i=0;i<10;i++){
        q[i].L=NULL;
        q[i].R=NULL;
    }
    for(int k=0;k<3;k=k+1){
        for(int i=0;i<n;i++){
            int x;
            if(k==0){
                x=a[i]%10;
            }
            if(k==1){
                x=a[i]/10;
                x=x%10;
            }
            if(k==2){
                x=a[i]/100;
            }
            enqueue(q[x], a[i]);
        }
        int x=0;
        for(int i=0;i<n;i++){
            if(isEmpty(q[x])){
                x++;
                i--;
                continue;
            }
            else{
                a[i]=dequeue(q[x]);
            }
        }
    }
}
int main(){
    int a[20];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    radixsort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

