int mini(MTPTR T){
    if(T->child[0]==NULL){
        return T->data[0];
    }
    else{
        return mini(T->child[0]);
    }
}
MTPTR delnode(MTPTR T, int k, int x){
    if(T==NULL){
        return NULL;
    }
    if(k<T->data[0]){
        T->child[0]=delnode(T->child[0], k, 0);
    }
    else if(k>T->data[0]){
        int i=0;
        while(T->data[i]<=k&&T->data[i]!=0&&i!=m){
            i++;
        }
        if(k==T->data[i]){
            T->child[i]=delnode(T, k, x);
        }
        T->child[i]=delnode(T->child[i], k, 0);
    }
    else{
       if(T->child[x]==NULL&&T->child[x+1]==NULL){
           for(int j=x+1;j<m;j++){
                T->data[j-1]=T->data[j];
            }
            T->data[m-1]=0;
            return NULL;
       }
       else if(T->child[x]!=NULL&&T->child[x+1]==NULL){
            return T->child[x];
       }
       else if(T->child[x]==NULL&&T->child[x+1]!=NULL){
            return T->child[x+1];
       }
       else{
            int m=mini(T->child[x+1]);
            T->data[x]=m;
            T->child[x+1]=delnode(T->child[x+1], m, 0);
       }
    }
}
