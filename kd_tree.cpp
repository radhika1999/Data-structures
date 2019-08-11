#include<iostream>
using namespace std;
struct kdnode{
    struct kdnode *lchild;
    int data[20];
    int d;
    struct kdnode *rchild;
};
typedef struct kdnode * KDPTR;
void insert(KDPTR T, int k[], int i, int c){
    if(T==NULL){
        T=new kdnode;
        for(int j=0;j<c;j++){
            T->data[j]=k[j];
        }
        T->d=c;
        T->lchild=NULL;
        T->rchild=NULL;
    }
    else{
        if(k[i-1]>T->data[i-1]){
            insert(T->rchild, k, (i+1)%c, c);
        }
        else{
            insert(T->lchild, k, (i+1)%c, c);
        }
    }
}
bool find(KDPTR T, int k[], int i, int c){
    static int x=0;
    if(T!=NULL){
        if(x==c){
            return true;
        }
        if(k[i-1]>T->data[i-1]){
            x=0;
            return find(T->rchild, k, (i+1)%c, c);
        }
        else if(k[i-1]<T->data[i-1]){
            x=0;
            return find(T->lchild, k, (i+1)%c, c);
        }
        else{
            x++;
            return find(T, k, (i+1)%c, c);
        }
    }
    else{
        return false;
    }
}
int min_x(KDPTR T, int i){
    if(T!=NULL){
        int min1, min2, min3;
        if(i==0){
            if(T->lchild==NULL){
                return T->data[0];
            }
            min3=min_x(T->lchild, i+1);
        }
        else{
            min1=min_x(T->lchild, 0);
            min2=min_x(T->rchild, 0);
        }
        return min((min1, min2), min3);
    }
}
