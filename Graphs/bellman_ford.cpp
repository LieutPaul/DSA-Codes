#include<iostream>
#include<vector>
#define ll long long int
#define INF 1e9
using namespace std;
int main(){
    ll n,m;
    ll u,v,w,src;
    cin>>n>>m;
    vector <vector<ll> > edges;
    vector <ll> temp;
    for(ll i=0;i<m;i++){
        temp.clear();
        cin>>u>>v>>w;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(w);
        edges.push_back(temp);
    }
    cin>>src;
    vector<ll> distances(n,INF);
    distances[src]=0;
    for(int i=0;i<n;i++){
        for(auto e : edges){
            u=e[0];
            v=e[1];
            w=e[2];
            distances[v]=min(distances[v], distances[u]+w);
        }
    }
    for(int i=0;i<distances.size();i++){
        cout<<distances[i]<<" ";
    }
    cout<<endl;
    
}