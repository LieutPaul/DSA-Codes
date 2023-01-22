#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int inf=1e7;

int main(){
    int n,m;
    cin>>n>>m; //Graph vertices are from 1 to n
    vector<int> dist(n+1,inf);
    vector<vector<pair<int,int> > > graph(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w)); // Undirected Graph
    }
    
    int source;
    cin>>source;
    dist[source]=0;
    set <pair<int,int> > s;
    s.insert(make_pair(0,source));
    
    while(!s.empty()){
        pair<int,int> x = *(s.begin());
        s.erase(x);
        for(int i=0;i<graph[x.second].size();i++){
            pair<int,int> it=graph[x.second][i];
            if(dist[it.first]>dist[x.second]+it.second){
                s.erase(make_pair(dist[it.first],it.first));
                dist[it.first]=dist[x.second]+it.second;
                s.insert(make_pair(dist[it.first],it.first));
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(dist[i]!=inf){
            cout<<dist[i]<<" ";
        }else{
            cout<<-1<<" ";
        }
    }
    cout<<endl;
}
