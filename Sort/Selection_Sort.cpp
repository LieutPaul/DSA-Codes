#include<iostream>
using namespace std;
void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void selectionsort(int a[],int n){
    int max=0;
    for(int i=0;i<n-1;i++){
        max=0;
        for(int j=0;j<n-i;j++){
            if(a[j]>a[max]){
                max=j;
            }
        }
        swap(&a[max],&a[n-i-1]);

    }
}
int main(){
    int a[50]={4,1,8,6,2,10,3};
    selectionsort(a,7);
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}