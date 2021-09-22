#include<iostream>
using namespace std;
struct mtnode{
    struct mtnode *child[10];
    int *data;
};
typedef struct mtnode * MTPTR;
int m=3;
void insert(MTPTR &T, int k){
    if(T==NULL){
        T=new mtnode;
        T->data=new int[m-1];
        int i;
        for(i=0;i<m-1;i++){
            T->data[i]=0;
            T->child[i]=NULL;
        }
        T->child[i]=NULL;
        T->data[0]=k;
    }
    else{
        if(k==T->data[0]){
            cout<<"Duplicate"<<endl;
        }
        else if(T->data[0]>k){
            insert(T->child[0], k);
        }
        else{
            int i=0;
            while(T->data[i]<k&&T->data[i]!=0&&i!=m){
                i++;
            }
            insert(T->child[i], k);
        }
    }
}
void sortprint(MTPTR T){
    if(T!=NULL){
        for(int i=0;i<m-1;i++){
            sortprint(T->child[i]);
            if(T->data[i]!=0)
                cout<<T->data[i]<<" ";
            sortprint(T->child[m-1]);
        }
    }
}

int main(){
    MTPTR T=NULL;
    insert(T, 10);
    insert(T, 44);
    insert(T, 3);
    insert(T, 7);
    insert(T, 22);
    insert(T, 50);
    insert(T, 70);
    insert(T, 66);
    sortprint(T);
}
