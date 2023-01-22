#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int a[],int l,int r,int piv){ //piv is the index that we want to partition wrt
    swap(&a[r],&a[piv]); //a[r] is now a[piv] so we're partitioning wrt r
    int pivot=a[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}
int RFindRank(int a[],int l,int r,int rank){
    if(l<r){
        int p=(rand()%(r-l+1) + l);
        int k = partition(a,l,r,p);
        if(rank==r-k+1){
            return k;
        }else if(rank<r-k+1){
            return RFindRank(a,k+1,r,rank);
        }else{
            return RFindRank(a,l,k-1,rank-(r-k+1));
        }
    }
    return r;
}
int main(){
    int a[100]={1,2,3,4,5,6,7,8,9};
    cout << RFindRank(a,0,9,1)<<endl;
}
