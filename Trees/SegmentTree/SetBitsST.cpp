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
int main(){
    int N,q,l,r,x;
    int k=1;
    cin>>N;
    while(k<N){
        k*=2;
    }
    int ST[2*k - 1];
    for(int i=0;i<2*k - 1;i++){
        ST[i]=0;
    }
    while(true){
        cin>>q;
        if(q==1){
            cin>>x;
            Update(ST,x,1,k);
        }else if(q==2){
            cin>>x;
            Update(ST,x,-1,k);
        }else if(q==3){
            cin>>l>>r;
            cout<<sum(ST,0,k-1,l,r,0)<<endl;
        }else{
            break;
        }
    }

}