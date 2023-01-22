#include <iostream>
#define ll long long int
using namespace std;
ll power(ll x, ll n){
    ll y=1;
    while(n>0){
        if(n%2==1){
            y*=x;
        }
        x=x*x;
        n=n/2;
    }
    return y;
}
int main(){
    cout<<power(5,10)<<endl;
}
