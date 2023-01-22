#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void merge(int arr[],int l,int mid, int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1]; //left half of sub-array
    int b[n2]; //right half of subarray
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i]; //putting value of left half of subarray in a
    }
    for(int j=0;j<n2;j++){
        b[j]=arr[mid+1+j]; //putting value of right half of subarray in b
    }
    int i=0;int j=0;int k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;k++;
        }else{
            arr[k]=b[j];
            j++;k++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;i++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;k++;
    }
}
void mergesort(int a[], int l, int r){
    int mid=0;
    if(l<r){
        mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main(){
    int a[50]={11,4,1,8,6,2,10,3};
    mergesort(a,0,7);
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}