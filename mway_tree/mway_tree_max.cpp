void maximum(MTPTR T, int &m){
    if(T!=NULL){
        int i=0;
        while(T->data[i]!=0&&i!=m){
            i++;
        }
        maximum(T->child[i], m);
        m=T->data[i];
    }
    else{
        return;
    }
}
