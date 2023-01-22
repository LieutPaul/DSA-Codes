#include<iostream>
#include<vector>
using namespace std;
const int N=1e6;
vector<int> parent(N);
vector<int>sz(N);

vector<int> make_vector(int a, int b, int c){
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);
    ans.push_back(c);
    return ans;
}
// All disjoint union functions
void make_set(int v){
    parent[v]=v;
    sz[v]=1;
}

int find_set(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a, int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b]=a;
        sz[a]+=sz[b];
    }
}

//-------------------------------------
int main(){
    //initialising the parents
    for(int i=0;i<N;i++){
        make_set(i);
    }
    int n,m,u,v,w,cost=0;
    cin>>n>>m;
    vector<vector<int> >edges;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edges.push_back(make_vector(w,u,v));
    }
    sort(edges.begin(),edges.end()); //sorting the edge lengths
    cout<<"MST: "<<endl<<endl;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][1],w=edges[i][0],v=edges[i][2];
        if(find_set(u)!=find_set(v)){ //If they are not of the same set(connected component)
            cout<<u<<" "<<v<<endl;
            union_sets(u,v); //Merging the two sets (CCs)
            cost+=w;
        }
    }
    cout<<cost<<endl;
}