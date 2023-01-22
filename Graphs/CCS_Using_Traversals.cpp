#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void find_comp_bfs(int s, vector<int> &cc, vector<bool> &vis, vector<vector<int> > adj){
    int x;
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        x=q.front();
        q.pop();
        for(int i=0;i<adj[x].size();i++){
            if(!vis[adj[x][i]]){
                cc.push_back(adj[x][i]);
                q.push(adj[x][i]);
                vis[adj[x][i]]=true;
            }
        }
    }
}
void find_comp_dfs(int src, vector<int> &cc, vector<bool> &vis, vector<vector<int> > adj){
    if(vis[src]==1){
        return;
    }
    vis[src]=true;
    for(int i=0;i<adj[src].size();i++){
        if(!vis[adj[src][i]]){
            cc.push_back(adj[src][i]);
            find_comp_dfs(adj[src][i],cc,vis,adj);
            vis[adj[src][i]]=true;
        }
    }
}
vector <vector<int> > generate_CCs(vector<vector<int> >adj, int n){
    vector <bool> vis(n,false);
    vector <vector<int> > ccs;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vector<int> cc;
            cc.push_back(i);
            find_comp_bfs(i,cc,vis,adj);
            ccs.push_back(cc);
        }
    }
    return ccs;
}
int main(){
    int n,m;
    cin>>n>>m; 
    vector<vector<int> > adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    vector<vector<int > > ccs=generate_CCs(adj,n);
    for(int i=0;i<ccs.size();i++){
        cout<<"CC #"<<(i+1)<<": ";
        for(int j=0;j<ccs[i].size();j++){
            cout<<ccs[i][j]<<" ";
        }
        cout<<endl;
    }
}