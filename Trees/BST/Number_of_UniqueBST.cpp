#include <iostream>
#define ll unsigned long long int
using namespace std;
int numUniqueStructureTrees(int n) {
	int dp[n+1];
	fill_n(dp,n+1,0);
	dp[0]=1; dp[1]=1;
	for(int i=2;i<=n;i++){
		int a=i-1,b=0;
		while(a>=0){
			dp[i] += (dp[a]*dp[b]);
			a--; b++;
		}
	}
	return dp[n];
}
int numTrees(int n) {
	int mod = 1e9 + 7;
	long long int dp[n + 1];
	fill_n(dp, n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < i; j++){
			dp[i] += ((dp[j] % mod) * (dp[i - 1 - j] % mod))%mod;
			dp[i] %= mod;
		}
	}
	return dp[n];
}
int main(){
	ll n;
    cin>>n;
	cout<<numUniqueStructureTrees(n)<<endl;
}

