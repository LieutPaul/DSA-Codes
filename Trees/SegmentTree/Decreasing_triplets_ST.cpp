#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Update(int *ST, int i,int X,int n){
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
vector<int> countSmallerST(vector<int> nums){ //To the right that are smaller
    int n=nums.size();
    vector<int> ans;
    int ST[50000];
    for(int i=0;i<20000;i++){
        ST[i]=0;
    }
    for(int i=n-1;i>=0;i--){
        ans.push_back(sum(ST,0,16383,0,nums[i]-1,0));
        Update(ST,nums[i],1,16384);
    }
    reverse(ans.begin(),ans.end());
    return(ans);
}
vector<int> countLargerST(vector<int> nums){ //To the left that are larger
    int n=nums.size();
    vector<int> ans;
    int ST[50000];
    for(int i=0;i<20000;i++){
        ST[i]=0;
    }
    for(int i=0;i<n;i++){
        ans.push_back(sum(ST,0,16383,nums[i]+1,16383,0));
        Update(ST,nums[i],1,16384);
    }
    return(ans);
}
int main(){
    int n,a;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    vector<int>ans1=countSmallerST(v);
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    vector<int>ans2=countLargerST(v);
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i]<<" ";
    }
    cout<<endl;
}