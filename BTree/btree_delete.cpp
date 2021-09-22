#include "btree.cpp"
void maximum(BDPTR T, int &m){
    if(T!=NULL){
        int i=0;
        while(T->key[i+1]!=0&&i!=2*d-1){
            i++;
        }
        maximum(T->ptr[i], m);
        m=T->key[i];
    }
    else{
        return;
    }
}
void delnode(BDPTR &T, int k);
void nodecombinig(BDPTR &T, BDPTR &P){
    cout<<"check"<<endl;
    int i=0;
    while(P->ptr[i]!=T){
        i++;
    }
    cout<<"cnt"<<P->cnt<<endl;
    if(i!=P->cnt){
        cout<<"y"<<endl;
        T->key[T->cnt++]=P->key[i];
        BDPTR X=P->ptr[i+1];
        for(int j=0;j<X->cnt;j++){
            T->key[T->cnt++]=X->key[j];
        }
        //delete X;
    }
    else{
        cout<<"x"<<endl;
        BDPTR X=P->ptr[i-1];
        X->key[X->cnt++]=P->key[i];
        for(int j=0;j<T->cnt;j++){
            X->key[X->cnt++]=T->key[j];
        }
        //delete T;
    }
}
bool redistribute(BDPTR &T, BDPTR &P){
    if(P!=NULL){
        int i=0;
        while(P->ptr[i]!=T){
            i++;
        }
        if(i!=2*d&&P->ptr[i+1]!=NULL&&P->ptr[i+1]->cnt>d){
        T->key[T->cnt++]=P->key[i];
        P->key[i]=P->ptr[i+1]->key[0];
        for(int j=0;j<2*d;j++){
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
        cout<<"cnt"<<T->cnt<<endl;
        if(T->cnt<d){
            if(s.empty())
                return;
            if(!s.empty()){
                P=s.top();
            }
            bool ans=redistribute(T, P);
            if(!ans){
                nodecombinig(T, P);
            }
        }
    }
    while(!s.empty())
        s.pop();
}
void delnode(BDPTR &T, int k){
    if(T==NULL){
        return ;
    }
    else{
        s.push(T);
        if(T->ptr[0]!=NULL){
            if(T->key[0]>k)
                delnode(T->ptr[0], k);
            else if(T->key[0]<k){
                int i=0;
                while(T->key[i]<k&&T->key[i]!=0&&i!=2*d){
                    i++;
                }
                if(T->key[i]==k){
                    int m=0;
                    maximum(T->ptr[i], m);
                    T->key[i]=m;
                    delnode(T->ptr[i], m);
                }
                else{
                    delnode(T->ptr[i], k);
                }
            }
            else{
                int m=0;
                maximum(T->ptr[0], m);
                T->key[0]=m;
                delnode(T->ptr[0], m);
            }
        }
        else{
            int i=0;
            while(T->key[i]!=k){
                i++;
            }
            cout<<"i"<<i<<endl;
            for(int j=i;j<2*d;j++){
                T->key[j]=T->key[j+1];
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
    cout<<endl;
    levelprint(H);
    cout<<endl<<"*********"<<endl;
    delnode(H, 8);
    delnode(H, 9);
    levelprint(H);
}
