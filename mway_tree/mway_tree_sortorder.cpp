
void sortprint(MTPTR T){
    if(T!=NULL){
        for(int i=0;i<m-1;i++){
            sortprint(T->child[i]);
            cout<<T->data[i];
            sortprint(T->child[m-1]);
        }
    }
}
