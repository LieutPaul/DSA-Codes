#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int inf = 1e9;
pair<int,int> makepair(int a,int b){
    pair<int,int> ans;
    ans.first=a;
    ans.second=b;
    return ans;
}
void primsMST(int src, vector<vector<pair<int,int> > > graph){
    int cost=0;
    int N=graph.size();
    vector<int> parent(N),dist(N);
    vector<bool> vis(N,false);
    for(int i=0;i<N;i++){
        dist[i]=(inf);
        parent[i]=-1;
    }
    dist[src]=0;
    set<pair<int,int> >s;
    s.insert(makepair(0,src));
    while(!s.empty()){
        pair<int,int> temp=*(s.begin());
        vis[temp.second]=true;
        int u=temp.second;
        int v=parent[temp.second];
        int w=temp.first;
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost+=w;
        for(pair<int,int> it: graph[u]){
            if(!vis[it.first]){
                if(dist[it.first]>it.second){
                    s.erase(makepair(dist[it.first],it.first));
                    dist[it.first]=it.second;
                    s.insert(makepair(dist[it.first],it.first));
                    parent[it.second]=it.first;
                }
            }
        }
    }

}
int main(){
    int n,m;
    cin>>n>>m; //Graph vertices are from 1 to n
    vector<int> dist(n+1,inf);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(makepair(v,w));
        graph[v].push_back(makepair(u,w)); // Undirected Graph
    }
    
    int source;
    cin>>source;
}