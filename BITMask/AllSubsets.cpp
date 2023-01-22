#include<iostream>
using namespace std;
void gen_subsets(int a[], int n){
    for(int i=0;i<(1<<n) ;i++){
        for(int j=0;j<n;j++){
            if((i & (1<<j)) != 0){
                cout<<a[j]<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    gen_subsets(a,n);
}