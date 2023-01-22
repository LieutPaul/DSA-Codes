#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> nodeLevel(int V, vector<vector<int> >adj) { 
    int level[V];
    int visited[V];
    for(int i=0;i<V;i++){
        level[i]=-1;
        visited[i]=0;
    }
    for(int i=0;i<V;i++){
        if(level[i]==-1){
            visited[i]=1;
            level[i]=0;
            int curr_lev;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                curr_lev=level[node];
                for(int i=0;i<adj[node].size();i++){
                    if(!visited[adj[node][i]]){
                        level[adj[node][i]]=curr_lev+1;
                        q.push(adj[node][i]);
                        visited[adj[node][i]]=1;
                    }
                }
            }
        }
        
    }
    vector<int>levels;
    for(int i=0;i<V;i++){
        levels.push_back(level[i]);
    }
    return levels;
}
void colourable(vector<vector<int> > adj){
    vector<int> red,blue;
    vector<int> levels=nodeLevel(adj.size(),adj);
    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();j++){
            if(levels[adj[i][j]]%2 == levels[i]%2){
                cout<<"Not Colourable"<<endl;
                return;
            }
        }
    }
    for(int i=0;i<adj.size();i++){
        if(levels[i]%2==0){
            red.push_back(i);
        }else{
            blue.push_back(i);
        }
    }
    cout<<"Red: ";
    for(int i=0;i<red.size();i++){
        cout<<red[i]<<" ";
    }
    cout<<endl<<"Blue: ";
    for(int i=0;i<blue.size();i++){
        cout<<blue[i]<<" ";
    }
    cout<<endl;
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
    colourable(adj);
}