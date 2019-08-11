#include<iostream>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
union u{
    char str[10];
    struct trienode *ptr[4];
};
struct trienode{
    int tag;
    union u data;
};
typedef struct trienode * TPTR;
void insert(TPTR &T, char a[], int i, int n){
    if(T==NULL){
        T=new trienode;
        T->tag=0;
        strcpy(T->data.str, a);
    }
    else{
        int x=a[i]-'a';
        if(T->tag==1){
            insert(T->data.ptr[x], a, i+1, n);
        }
        else{
            char b[10];
            strcpy(b, T->data.str);
            T->tag=1;
            for(int i=0;i<4;i++){
                T->data.ptr[i]=NULL;
            }
            int y=b[i]-'a';
            int s=strlen(b);
            if(i!=n&&i!=s){
                insert(T->data.ptr[x], a, i+1, n);
                insert(T->data.ptr[y], b, i+1, s);
            }
            else if(i==n){
                /*TPTR X=new trienode;
                X->tag=1;
                T->data.ptr[x]=X;
                for(int i=0;i<4;i++){
                    X->data.ptr[i]=NULL;
                }
                */
                TPTR Y=new trienode;
                Y->tag=0;
                strcpy(Y->data.str, a);
                T->data.ptr[3]=Y;
                insert(T->data.ptr[y], b, i+1, s);
            }
            else if(i==s){
                /*TPTR X=new trienode;
                X->tag=1;
                T->data.ptr[x]=X;
                for(int i=0;i<4;i++){
                    X->data.ptr[i]=NULL;
                }
                */
                TPTR Y=new trienode;
                Y->tag=0;
                strcpy(Y->data.str, b);
                T->data.ptr[3]=Y;
                insert(T->data.ptr[x], a, i+1, n);
            }
        }
    }
}
void levelprint(TPTR T){
    queue<TPTR> q;
    if(T!=NULL){
        q.push(T);
        TPTR X=new trienode;
        X->tag=0;
        X->data.str[0]='-';
        q.push(X);
    }
    while(!q.empty()&&q.size()!=1){
        TPTR A=q.front();
        q.pop();
        if(A->tag==0){
        if(A->data.str[0]=='-'){
            cout<<endl;
            q.push(A);
        }
        else{
            cout<<A->data.str<<"\t";
        }
    }
    else{
        cout<<"*"<<"\t";
        for(int i=0;i<4;i++){
            if(A->data.ptr[i]!=NULL){
                q.push(A->data.ptr[i]);
            }
        }
    }
    }
}
/*int main(){
    char b[10];
    TPTR T=NULL;
    T=new trienode;
    T->tag=1;
    for(int i=0;i<4;i++){
        T->data.ptr[i]=NULL;
    }
    cin>>b;
    while(b[0]!='-'){
        int n=strlen(b);
        insert(T, b, 0, n);
        //levelprint(T);
        cin>>b;
    }
    levelprint(T);
}
*/
