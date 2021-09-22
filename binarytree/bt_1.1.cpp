#include<stack>
#include "bt_create.cpp"
void serialise(BTPTR T, char output[], int &n){
    if(T!=NULL){
        output[n++]=T->data;
        serialise(T->lchild, output, n);
        serialise(T->rchild, output, n);
    }
    else{
        output[n++]='.';
        return;
    }

}
int main(){
    BTPTR T;
    create(T, 'A');
    int n=0;
    char a[50];
    serialise(T, a, n);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}
