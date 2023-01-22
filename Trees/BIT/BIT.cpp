#include<iostream>
using namespace std;
int PrefixSum(int BIT[], int i){
	int sum = 0; 
	while (i>0){
		sum += BIT[i];
		i -= i & (-i);
	}
	return sum;
}
void updateBIT(int BIT[], int n, int i, int X){
	while (i <= n){
        BIT[i] += X;
        i += i & (-i);
	}
}
void constructBIT(int BIT[], int A[], int n){
	for(int i=1; i<=n; i++){
		BIT[i] = 0;
    }
    for(int i=1; i<=n; i++){
		updateBIT(BIT, n, i, A[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<BIT[i]<<" ";
    }
    cout << endl;
}
int main(){
    int n,r;
    cin>>n; // Input size of BIT
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int BIT[n+1];
    constructBIT(BIT,a,n);
    cin >> r; // Input position to calculate prefix sum till
    cout<<PrefixSum(BIT,r);
    cout<<endl;
}