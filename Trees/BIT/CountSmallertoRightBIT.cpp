#include<iostream>
#include<vector>
using namespace std;
int PrefixSum(int BIT[], int i){
	int sum = 0; 
	while (i>0){
		sum += BIT[i];
		i -= i & (-i);
	}
	return sum;
}
void updateBIT(int BIT[],int i){
	while (i <= 1000){
        BIT[i] += 1;
        i += i & (-i);
	}
}
vector <int> countSmallerBIT(vector<int> &nums){
    int a[20000];
    for(int i=1;i<=1000;i++){
        a[i]=0;
    }
    vector<int> ans;
    for(int i=nums.size()-1;i>=0;i--){
        ans.push_back(PrefixSum(a,nums[i] - 1));
        updateBIT(a,nums[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n,a;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>a;
        a+=100;
        v.push_back(a);
    }
    vector<int>ans2=countSmallerBIT(v);
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i]<<" ";
    }
    cout<<endl;
}