#include<iostream>
using namespace std;
struct mtnode{
    int m;
    struct mtnode **child;
    int *data;
};
typedef struct mtnode * MTPTR;
bool search(MTPTR T, int k){
    if(T==NULL){
        return false;
    }
    else{
       if(k==T->data[0]){
            return true;
       }
       else if(T->data[0]>k){
            return search(T->child[0], k);
       }
       else{
            int i=0;
            while(T->data[i]<=k&&T->data[i]!=0){
                i++;
            }
            if(T->data[i]==k)
                return true;
            return search(T->child[i], k);
       }
    }
}
