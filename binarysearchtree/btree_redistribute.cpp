#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct bdnode{
    int cnt;
    int cntptr;
    int key[20];
    struct bdnode *ptr[20];
};
typedef struct bdnode * BDPTR;
BDPTR H=NULL;
int d;
stack<BDPTR> s;
BDPTR createnewnode(){
    BDPTR T=new bdnode;
    T->cntptr=0;
    T->cnt=0;
    for(int j=0;j<2*d+1;j++){
        T->key[j]=0;
        T->ptr[j]=NULL;
    }
    T->ptr[2*d+1]=NULL;
    return T;
}
void overflow(BDPTR &T, BDPTR &P){
    int m=d;
    BDPTR X=createnewnode();
    int i=0;
    for(int j=m+1;j<2*d+1;j++){
        X->key[i]=T->key[j];
        T->key[j]=0;
        X->ptr[i]=T->ptr[j];
        T->ptr[j]=NULL;
        i++;
    }
    X->ptr[d]=T->ptr[2*d+1];
    T->ptr[2*d+1]=NULL;
    X->cnt=d;
    T->cnt=d;
    if(P==NULL){
        P=createnewnode();
        P->cnt=0;
        P->cntptr=1;
    }
    int k=T->key[m];
    T->key[m]=0;
    i=0;
    while(P->key[i]<k&&P->key[i]!=0&&i!=2*d){
        i++;
    }
    for(int j=2*d;j>i;j--){
        P->key[j]=P->key[j-1];
        P->ptr[j+1]=P->ptr[j];
    }
    P->key[i]=k;
    P->ptr[i]=T;
    P->ptr[i+1]=X;
    P->cnt++;
    P->cntptr++;
    if(P->cnt==(2*d+1)){
        BDPTR A=NULL;
        if(!s.empty()){
            A=s.top();
            s.pop();
        }
        overflow(P, A);
    }
    else{
        if(!s.empty()){
            s.top()=P;
        }
        else
        H=P;
    }
}
void checkoverflow(){
    if(!s.empty()){
        BDPTR T=s.top();
        s.pop();
        if(T->cnt==(2*d+1)){
            BDPTR P=NULL;
            if(!s.empty()){
                P=s.top();
                s.pop();
            }
            overflow(T, P);
        }
    }
    while(!s.empty())
        s.pop();
}
bool redistribute(BDPTR T){
    if(!s.empty()){
        BDPTR P=s.top();
        int i=0;
        while(P->ptr[i]!=T){
            i++;
        }
        if(i!=0&&P->ptr[i-1]->cnt!=2*d){
            BDPTR X=P->ptr[i-1];
            X->key[X->cnt]=P->key[i-1];
            P->key[i-1]=T->key[0];
            for(int j=0;j<2*d;j++){
                T->key[j]=T->key[j+1];
            }
            T->cnt--;
            X->cnt++;
            return true;
        }
        else if(i!=2*d&&P->ptr[i+1]!=NULL&&P->ptr[i+1]->cnt!=2*d){
            BDPTR X=P->ptr[i+1];
            for(int j=2*d;j>0;j--){
                X->key[j]=X->key[j-1];
            }
            X->key[0]=P->key[i];
            P->key[i]=T->key[T->cnt-1];
            T->key[T->cnt]=0;
            T->cnt--;
            X->cnt++;
            return true;
        }
    }
    return false;
}
void insert(BDPTR &T, int k){
    if(T==NULL){
        T=createnewnode();
        T->cnt=1;
        T->key[0]=k;
    }
    else{
        s.push(T);
        if(T->cntptr>0){
            if(T->key[0]>k)
                insert(T->ptr[0], k);
            else if(T->key[0]<k){
                int i=0;
                while(T->key[i]<k&&T->key[i]!=0&&i!=2*d){
                    i++;
                }
                if(T->key[i]==k){
                    cout<<"Duplicate"<<endl;
                }
                else{
                    insert(T->ptr[i], k);
                }
            }
            else{
                cout<<"Duplicate"<<endl;
            }
        }
        else{
            int i=0;
            while(T->key[i]<k&&T->key[i]!=0&&i!=2*d){
                i++;
            }
            for(int j=2*d;j>i;j--){
                T->key[j]=T->key[j-1];
            }
            T->key[i]=k;
            T->cnt++;
            BDPTR T=s.top();
            s.pop();
            if(T->cnt>2*d){
            bool ans=redistribute(T);
            cout<<"ans="<<ans<<endl;
            if(!ans){
                s.push(T);
                checkoverflow();
            }
            while(!s.empty()){
                s.pop();
            }
        }
        while(!s.empty()){
                s.pop();
            }
        }
    }
}
void levelprint(BDPTR T){
    queue<BDPTR> q;
    if(T!=NULL){
        q.push(T);
        BDPTR X=createnewnode();
        X->key[0]=-1;
        q.push(X);
    }
    while(!q.empty()&&q.size()!=1){
        BDPTR A=q.front();
        q.pop();
        if(A->key[0]==-1){
            cout<<endl;
            q.push(A);
        }
        else{
            int i=0;
            while(A->key[i]!=0&&i!=2*d){
                cout<<A->key[i]<<"-";
                if(A->ptr[i]!=NULL){
                    q.push(A->ptr[i]);
                }
                i++;
            }
            cout<<"\t";
            if(A->ptr[i]!=NULL){
                q.push(A->ptr[i]);
            }
        }
    }
}

//1 3 7 9 1 6 4 8 2 5 -1
//2 4 7 22 21 35 12 23 39 16 32 29 46 28 43 64 9 49 53 40 42 24 60 -1
int main(){
    cout<<"Enter d ";
    cin>>d;
    int n;
    cout<<"Enter numbers ";
    cin>>n;
    while(n!=-1){
        insert(H, n);
        //levelprint(H);
        cout<<"Enter numbers ";
        cin>>n;
    }
    levelprint(H);
}
