#include<iostream>
using namespace std;
struct htnode{
    struct htnode *lchild;
    char c;
    int f;
    struct htnode *rchild;
};
typedef struct htnode * HTPTR;
void input(HTPTR a[], int n){
    for(int i=0;i<n;i++){
        cout<<"Enter character ";
        cin>>a[i]->c;
        cout<<"Enter frequency ";
        cin>>a[i]->f;
    }
}
void merge(HTPTR arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    HTPTR L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i]->f <= R[j]->f)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(HTPTR arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
HTPTR create(HTPTR T1, HTPTR T2){
    HTPTR T=new htnode;
    T->c='-';
    T->f=T1->f+T2->f;
    T->lchild=T1;
    T->rchild=T2;
    return T;
}
HTPTR create_full(HTPTR a[], int n){
    if(n!=1){
        HTPTR X=create(a[0], a[1]);
        int i;
        for(i=2;i<n;i++){
            if(X->f<a[i]->f)
                break;
        }
        for(int j=n-1;j>=i;j--){
            a[j+1]=a[j];
        }
        a[i]=X;
        create_full(a+2, n-1);
    }
    else
        return a[0];
}
void print(HTPTR T, int x){
    if(T!=NULL){
        if(T->f>x){
            cout<<0;
            print(T->lchild, x);
        }
        else if(T->f<x){
            cout<<1;
            print(T->rchild, x);
        }
        else
            return;
    }
}
int main(){
    char x, c=0;;
    HTPTR a[100];
    cout<<"Enter a character ";
    cin>>x;
    while(x!='-'){
        int y;
        cout<<"Enter frequency ";
        cin>>y;
        HTPTR T=new htnode;
        T->c=x;
        T->f=y;
        T->lchild=NULL;
        T->rchild=NULL;
        a[c++]=T;
        cout<<"Enter a character ";
        cin>>x;
    }
    //t 16 a 3 m 30 j 10 k 40 p 2 s 20 -
    mergeSort(a, 0, c-1);
    HTPTR X=create_full(a, c);
    cout<<endl;
    print(X, 3);
}
