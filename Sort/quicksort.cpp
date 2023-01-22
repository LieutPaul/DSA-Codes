#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int a[],int l,int r){
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
void quicksort(int a[],int l, int r){
    if(l<r){
        int p=partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}
int main(){
    int a[]={10,4,1,-7,3,5};
    quicksort(a,0,5);
    for(int i=0;i<=5;i++){
        cout <<a[i]<<" ";
    }
    cout <<endl;
}
