#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int celebrity(vector<vector<int> >& a, int n) {
        vector <int> zerorows;
        for(int i=0;i<n;i++){
            bool bol = true;
            for(int j=0;j<n;j++){
                if(a[i][j]==1){
                    bol=false;
                    break;
                }
            }
            if(bol){
                zerorows.push_back(i);
            }
        }
        if(zerorows.size()==0){
            return -1;
        }
        bool bol;
        for(int i=0;i<zerorows.size();i++){
            bol=true;
            for(int j=0;j<n;j++){
                if(a[j][zerorows[i]] == 0 && zerorows[i]!=j){
                    bol=false;
                    break;
                }
            }
            if(bol){
                return zerorows[i];
            }
        }
        return -1;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;
    }
}
