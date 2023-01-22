#include<iostream>
#include<vector>
#include<iterator>
#include<set>
using namespace std;
vector<int> find_ans(int a[], int n){
    set <int> ms;
    vector <int> ans;
    for(int i=n-1;i>=0;i--){
        ms.insert(a[i]);
        auto it = ms.upper_bound(a[i]);
        if(it==ms.end()){
            ans.push_back(-1);
        }else{
            ans.push_back(*it);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ans=find_ans(a,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
