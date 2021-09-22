#include<iostream>
#include<cstring>
using namespace std;
//chem phy math eng comp lang x 68 chem comp math x 49 chem math eng lang x 0
union u{
    struct reg *x;
    struct s *y;
};
struct reg{
    int dtag;
    int ntag;
    union u next;
    union u down;
};
struct s{
    char data[20];
    struct s *snext;
    struct reg *sdown;
};
typedef struct s * SPTR;
typedef struct reg * RPTR;
void print_course(SPTR S){
    while(S!=NULL){
        cout<<S->data<<" ";
        RPTR R=S->sdown;
        while(R->dtag!=1){
            RPTR R1=R;
            while(R1->ntag!=1){
                R1=R1->next.x;
            }
            cout<<R1->next.y->data<<" ";
            R=R->down.x;
        }
        RPTR R1=R;
        while(R1->ntag!=1){
            R1=R1->next.x;
        }
        cout<<R1->next.y->data;
        S=S->snext;
        cout<<endl;
    }
}
SPTR create_course(){
    SPTR C=NULL;
    char n[20];
    cout<<"Enter course name"<<endl;
    cin>>n;
    while(n[0]!='x'){
        SPTR T=new s;
        T->sdown=NULL;
        int i;
        for(i=0;n[i]!='\0';i++){
            T->data[i]=n[i];
        }
        T->data[i]='\0';
        if(C==NULL){
            C=T;
            C->snext=NULL;
        }
        else{
            SPTR temp=C;
            while(temp->snext!=NULL){
                temp=temp->snext;
            }
            temp->snext=T;
            T->snext=NULL;
        }
        cout<<"Enter course name"<<endl;
        cin>>n;
    }
    return C;
}
SPTR create_student(SPTR C){
    SPTR S=NULL;
    SPTR T;
    char n[20];
    cout<<"Enter student roll numbers"<<endl;
    cin>>n;
    while(n[0]!='0'){
        T=new s;
        T->snext=NULL;
        T->sdown=NULL;
        int i;
        for(i=0;n[i]!='\0';i++){
            T->data[i]=n[i];
        }
        T->data[i]='\0';
        if(S==NULL){
            S=T;
            S->snext=NULL;
        }
        else{
            SPTR temp=S;
            while(temp->snext!=NULL){
                temp=temp->snext;
            }
            temp->snext=T;
            T->snext=NULL;
        }
        char x[20];
        cout<<"Enter course taken by student"<<endl;
        cin>>x;
        while(x[0]!='x'){
            SPTR C1=C;
            RPTR T1=new reg;
            bool flag=1;
            while(flag){
                if(strcmp(x,C1->data)==0){
                    flag =0;
                }
                else{
                    C1=C1->snext;
                }
            }
            if(T->sdown==NULL){
                T->sdown=T1;
                T1->dtag=1;
                T1->down.y=S;
            }
            else{
                RPTR R=T->sdown;
                while(R->dtag!=1){
                    R=R->down.x;
                }
                R->dtag=0;
                R->down.x=T1;
                T1->dtag=1;
                T1->down.y=S;
            }
            if(C1->sdown==NULL){
                C1->sdown=T1;
                T1->ntag=1;
                T1->next.y=C1;
            }
            else{
                RPTR R=C1->sdown;
                while(R->ntag!=1){
                    R=R->next.x;
                }
                R->ntag=0;
                R->next.x=T1;
                T1->ntag=1;
                T1->next.y=C1;
            }
            cout<<"Enter course taken by student"<<endl;
            cin>>x;
        }
        cout<<"Enter student roll numbers"<<endl;
        cin>>n;
    }
    return S;
}
int main(){
    SPTR C=create_course();
    SPTR S=create_student(C);
    print_course(S);
}
