#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
//finding level of X in graph with vertices 0 to V and with adjacency list adj
int nodeLevel(int V, vector<int> adj[], int X) { 
    int level[V];
    int visited[V];
    for(int i=0;i<V;i++){
        level[i]=0;
        visited[i]=0;
    }
    visited[0]=1;
    int curr_lev,node;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        node=q.front();
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
    if(X>=V){
        return -1;
    }else{
        return level[X];
    }
}
void DFS(int s, vector<vector<int> > adj){
    vector<bool> visited(adj.size(),false);
    stack<int> stack;
    stack.push(s);
    while(!stack.empty()){
        int s = stack.top();
        stack.pop();
        if(!visited[s]){
            cout << s << " ";
            visited[s] = true;
        }
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if(!visited[*i]){
                stack.push(*i);
            }
    }
}
void BFS(int s, vector<vector<int> > adj){
    int x;
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        x=q.front();
        q.pop();
        cout << x << " ";
        for(int i=0;i<adj[x].size();i++){
            if(!visited[adj[x][i]]){
                q.push(adj[x][i]);
                visited[adj[x][i]]=true;
            }
        }
    }
    cout<<endl;
}
int main(){
    int n,m,s;
    cin>>n>>m;
    int x,y;
    vector<vector<int> > adj(n);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"Source:"<<endl;
    cin>>s;
    BFS(s,adj);
	return 0;
}