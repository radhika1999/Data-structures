
bool deadend(MTPTR T, int a[], int &n){
    if(T!=NULL){
        for(int i=0;i<m-1;i++){
            sortprint(T->child[i], a, n);
            a[n++]=T->data[i];
            sortprint(T->child[m-1], a, n);
        }
    }
}
int main(){
    int a[20];
    int n=0;
    MTPTR T=NULL;
    deadend(T, a, n);
    int i;
    for(i=0;i<n-2;i++){
        if(a[i]==1){
            cout<<"yes"<<endl;
            break;
        }
        if(a[i]+1==a[i+1]&&a[i+1]-1==a[i+2]){
            cout<<"yes"<<endl;
            break;
        }
    }
    if(i==n-2)
        cout<<"no"<<endl;
}
