#include "btree.cpp"
void maximum(BDPTR T, int &m){
    if(T!=NULL){
        int i=0;
        while(T->key[i]!=0&&i!=2*d-1){
            i++;
        }
        maximum(T->ptr[i], m);
        m=T->key[i];
    }
    else{
        return;
    }
}
BDPTR delnode(BDPTR T, int k);
void nodecombinig(BDPTR &T, BDPTR &P){
    int i=0;
    while(P->ptr[i]!=T){
        i++;
    }
    if(i!=2*d-1){
        T->key[T->cnt++]=P->key[i];
        BDPTR X=P->ptr[i+1];
        for(int j=0;j<X->cnt;j++){
            T->key[T->cnt++]=X->key[j];
        }
        delete X;
        H=delnode(H, P->key[i]);
    }
    else{
        BDPTR X=P->ptr[i-1];
        X->key[X->cnt++]=P->key[i];
        for(int j=0;j<T->cnt;j++){
            X->key[X->cnt++]=T->key[j];
        }
        delete T;
        H=delnode(H, P->key[i]);
    }
}
bool redistribute(BDPTR &T, BDPTR &P){
    if(P!=NULL){
        //BDPTR P=s.top();
        int i=0;
        while(P->ptr[i]!=T){
            i++;
        }
        if(i!=2*d&&P->ptr[i+1]!=NULL&&P->ptr[i+1]->cnt>d){
        T->key[T->cnt]=P->key[i];
        P->key[i]=P->ptr[i+1]->key[0];
        for(int j=0;j<2*d-1;j++){
            P->ptr[i+1]->key[j]=P->ptr[i+1]->key[j+1];
        }
        while(!s.empty())
            s.pop();
        return true;
        }
        else if(i!=0&&P->ptr[i-1]->cnt>d){
            BDPTR X=P->ptr[i-1];
            for(int j=2*d-1;j>0;j--){
                T->key[j]=T->key[j-1];
            }
            T->key[0]=P->key[i];
            P->key[i]=X->key[X->cnt--];
        while(!s.empty())
            s.pop();
            return true;
        }
    }
    s.push(T);
    return false;
}
void checkunderflow(){
    if(!s.empty()){
        BDPTR T=s.top();
        s.pop();
        BDPTR P=NULL;
        if(T->cnt<d){
            if(s.empty())
                return;
            if(!s.empty()){
                P=s.top();
            }
            bool ans=redistribute(T, P);
            if(!ans)
                nodecombinig(T, P);
        }
    }
    while(!s.empty())
        s.pop();
}
BDPTR delnode(BDPTR T, int k){
    if(T==NULL){
        return NULL;
    }
    else{
        s.push(T);
        if(T->cntptr>0){
            if(T->key[0]>k)
                T->ptr[0]=delnode(T->ptr[0], k);
            else if(T->key[0]<k){
                int i=0;
                while(T->key[i]<k&&T->key[i]!=0&&i!=2*d){
                    i++;
                }
                if(T->key[i]==k){
                    int m=0;
                    maximum(T->ptr[i], m);
                    T->key[i]=m;
                    T->ptr[i]=delnode(T->ptr[i], m);
                }
                else{
                    T->ptr[i]=delnode(T->ptr[i], k);
                }
            }
            else{
                int m=0;
                maximum(T->ptr[0], m);
                T->key[0]=m;
                T->ptr[0]=delnode(T->ptr[0], m);
            }
        }
        else{
            int i=0;
            while(T->key[i]!=k){
                i++;
            }
            for(int j=i;j<2*d;j++){
                T->key[i]=T->key[i+1];
            }
            T->cnt--;
            checkunderflow();
        }
    }
}
//1 3 7 9 1 6 4 8 2 5 -1
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
    delnode(H, 7);
    levelprint(H);
}
