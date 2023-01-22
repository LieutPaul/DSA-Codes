#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void make_set(int v, vector<int>&parent, vector<int>&sz){
    for(int i=0;i<v;i++){
        parent[i]=i;
        sz[i]=1;
    }
}
int find_set(int v, vector<int>&parent, vector<int>&sz){
    if(v==parent[v]){
        return v;
    }
    return parent[v]=find_set(parent[v],parent,sz);
}
void union_sets(int a, int b, vector<int>&parent, vector<int>&sz){
    a=find_set(a,parent,sz);
    b=find_set(b,parent,sz);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b]=a;
        sz[a]+=sz[b];
    }
}
vector<vector<int> > generate_CCs(int n, vector<pair<int,int> >edges){
    vector<int> parent(n);
    vector<int> sz(n);
    make_set(n,parent,sz);
    for(auto e:edges){
        union_sets(e.first,e.second,parent,sz);
    }
    unordered_map<int,vector<int>>m;
    for(int i=0;i<n;i++){
        m[find_set(i,parent,sz)].push_back(i);
    }
    int id=0;
    vector<vector<int>> ccs(m.size());
    for(auto itr:m){
        for(int i=0;i<itr.second.size();i++){
            ccs[id].push_back(itr.second[i]);
        }
        id++;
    }
    return ccs;
}
int main(){
    //We require Edge List
    int n,m;
    cin>>n>>m; 
    vector<pair<int,int> > edges(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back(make_pair(u,v)); 
    }
    vector<vector<int > > ccs=generate_CCs(n,edges);
    for(int i=0;i<ccs.size();i++){
        cout<<"CC #"<<(i+1)<<": ";
        for(int j=0;j<ccs[i].size();j++){
            cout<<ccs[i][j]<<" ";
        }
        cout<<endl;
    }
}