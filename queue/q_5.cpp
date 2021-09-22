#include<iostream>
#include<cstring>
using namespace std;
void prefix_postfix(char a[]){
    if(a[0]=='\0')
        return;
    if(a[0]=='+'||a[0]=='-'||a[0]=='*'||a[0]=='/'){
        if(a[1]>='A'&&a[1]<='Z'&&a[2]>='A'&&a[2]<='Z'){
            cout<<a[1]<<a[2]<<a[0];
            a[0]='a';
            for(int i=1;i<strlen(a)-1;i++){
                a[i]=a[i+2];
            }
        }
        if(a[1]=='a'&&a[2]>='A'&&a[2]<='Z'){
            cout<<a[2]<<a[0];
            a[0]='a';
            for(int i=1;i<strlen(a)-1;i++){
                a[i]=a[i+2];
            }
        }
        if(a[1]=='a'&&a[2]=='a'){
            cout<<a[0];
            a[0]='a';
            for(int i=1;i<strlen(a)-1;i++){
                a[i]=a[i+2];
            }
        }
    }
    prefix_postfix(a+1);
}

int main(){
    char a[100];
    cin>>a;
    while(a[0]!='a')
        prefix_postfix(a);
    //cout<<endl<<a;
}
