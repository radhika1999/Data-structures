#include "trie_create.cpp"
stack<TPTR> s;
void delnode(TPTR T, char k[], int i){
    if(T!=NULL){
        if(T->tag==1){
            int x=k[i]-'a';
            s.push(T);
            delnode(T->data.ptr[x], k, i+1);
        }
        else{
            TPTR P=s.top();
            int c=0;
            for(int i=0;i<4;i++){
                if(P->data.ptr[i]==T){
                    P->data.ptr[i]=NULL;
                    break;
                }
            }
            delete T;
            char b[10];
            b[0]='-';
            b[1]='\0';
            for(int j=0;j<4;j++){
                if(P->data.ptr[j]!=NULL){
                    c++;
                }
            }
            int p;
            while(s.size()!=1&&s.size()!=0&&(c==0||(c==1))){
                s.pop();
                if(c==1){
                    if(b[0]=='-'){
                        int j;
                        for(j=0;j<4;j++){
                            if(P->data.ptr[j]!=NULL){
                                break;
                            }
                        }
                        strcpy(b, P->data.ptr[j]->data.str);
                    }
                    else{
                        break;
                    }
                }
                TPTR X=P;
                P=s.top();
                for(int i=0;i<4;i++){
                    if(P->data.ptr[i]==X){
                        P->data.ptr[i]=NULL;
                        break;
                    }
                }
                delete X;
                c=0;
                for(int j=0;j<4;j++){
                    if(P->data.ptr[j]!=NULL){
                        c++;
                    }
                }
                continue;
            }
            if(b[0]!='-'){
                //cout<<"check"<<endl;
                p=s.size()-1;
                p=b[p]-'a';
                //cout<<p<<endl;
                TPTR Y=new trienode;
                Y->tag=0;
                strcpy(Y->data.str, b);
                P->data.ptr[p]=Y;
            }
            while(!s.empty()){
                s.pop();
            }
            /*int p;
            for(int j=0;j<3;j++){
                if(P->data.ptr[j]==T){
                    p=j;
                }
                if(P->data.ptr[j]!=NULL){
                    c++;
                }
            }
            if(c>1){
                delete T;
                P->data.ptr[p]=NULL;
            }
            else{
                if(P->data.ptr[3]!=NULL){
                    TPTR X=P->data.ptr[3];

                }
                else{
                    delete T;
                    P->data.ptr[p]=NULL;
                    while(s.size()!=1&&c!`)
                }
            }
        }*/
    }
}
}
int main(){
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
    cout<<endl;
    delnode(T, "aab", 0);
    levelprint(T);
}
