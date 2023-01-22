#include<iostream>
using namespace std;
#define ll unsigned long long int
void mult(ll a[2][2], ll b[2][2]){
    int x,y,z,w;
    x=a[0][0]*b[0][0] + a[0][1]*b[1][0];
    y=a[0][0]*b[0][1] + a[0][1]*b[1][1];
    z=a[1][0]*b[0][0] + a[1][1]*b[1][0];
    w=a[1][0]*b[0][1] + a[1][1]*b[1][1];
    a[0][0]=x;
    a[0][1]=y;
    a[1][0]=z;
    a[1][1]=w;
}
ll fast_fib(ll n){
    ll a[2][2]={{1,1},{1,0}};
    ll y[2][2]={{1,0},{0,1}};
    while(n>0){
        if(n%2==1){
            mult(y,a);
        }
        mult(a,a);
        n=n/2;
    }
    return y[1][0];
}
int main(){
    cout << fast_fib(21) << endl;
    return 0;
}