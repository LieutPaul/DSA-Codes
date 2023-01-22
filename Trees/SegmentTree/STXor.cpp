#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int genTree(vector<int> &nums, int *ST){
        int n=nums.size(),k=1;
        while(k<n){
            k*=2;
        }
        int i;
        for(i=k-1;i<2*k - 1;i++){
            if(i+1-k<n){
                ST[i]=nums[i+1-k];
            }else{
                ST[i]=0;
            }
        }
        i=k-2;
        while(i>-1){
            ST[i]=ST[2*i +1]^ST[2*i +2];
            i--;
        }
        return k;
    }
    int Xor(int *ST, int ss, int se, int l, int r, int i){
        if(se<l || ss>r){
            return 0;
        }
        if (ss >= l && se <= r){ 
            return ST[i];
        }
        int mid = (ss + se) / 2;
        return Xor(ST,ss,mid,l,r,2*i + 1) ^ Xor(ST,mid+1,se,l,r, 2*i +2);
    }
    int getXor(vector<int>&nums, int a, int b){
        int ST[500000]={0};
        int x= genTree(nums,ST);
        return Xor(ST,0,x-1,a,b,0);
    }
};
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, a, b;
        cin >> n >> a >> b;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        if(a > b)swap(a, b);
        Solution obj;
        int ans = obj.getXor(nums, a, b);
        cout << ans << "\n";
    }
    return 0;
} 