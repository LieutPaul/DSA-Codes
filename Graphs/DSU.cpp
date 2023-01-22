#include<iostream>
#include<vector>
using namespace std;
void make_set(int v, vector<int>&parent, vector<int>&sz){
    for(int i=1;i<=v;i++){
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
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> parent(edges.size()+1);
    vector<int> sz(edges.size()+1);
    make_set(edges.size(),parent,sz);
    for(auto e:edges){
        if(find_set(e[0],parent,sz) != find_set(e[1],parent,sz)){
            union_sets(e[0],e[1],parent,sz);
        }else{
            return e;
        }
    }
    return {};
}