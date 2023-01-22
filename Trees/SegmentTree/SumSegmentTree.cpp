#include<iostream>
using namespace std;
int *constructST(int A[], int n) {
    int i;
    int *ST = new int[2 * n - 1];
    for (i = n - 1; i < 2 * n - 1; ++i){
        ST[i] = A[i - n + 1];
    }
    i = n - 2;
    while (i >= 0){
        ST[i]=ST[2*i + 1] + ST[2*i + 2];
        i--;
    }
    return ST;
}
void Update(int *ST, int i,int X,int n) {
    i = i + n - 1;
    ST[i]+=X;
    int p = (i - 1) / 2;
    while(true){
        if(p==0){
            ST[p]+=X;
            break;
        }
        ST[p]+=X;
        p = (p - 1) / 2;
    }
}
int sum(int *ST, int ss, int se, int l, int r, int i){
    if(se<l || ss>r){
        return 0;
    }
    if (ss >= l && se <= r){ 
        return ST[i];
    }
    int mid = (ss + se) / 2;
    return sum(ST,ss,mid,l,r,2*i + 1)+sum(ST,mid+1,se,l,r, 2*i +2);
}
int main(){
    int n,l,r;
    cin>>n;
    int size=1;
    while(size<n){
        size*=2;
    }
    int arr[10000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n;i<size;i++){
        arr[i]=0;
    }
    int *ST=constructST(arr,size);
    //Update(ST,2,5,size);
    for(int i=0;i<2*size - 1;i++){
        cout<<ST[i]<<" ";
    }
    cout<<endl;
    cin>>l>>r;
    cout<<sum(ST,0,size -1,l,r,0)<<endl;
}
    