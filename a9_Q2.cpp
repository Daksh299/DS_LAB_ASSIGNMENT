#include <iostream>
using namespace std;

void dfs(int x, vector<vector<int>> &g, vector<int> &vis){
    vis[x]=1;
    cout<<x<<" ";
    for(int y:g[x]) if(!vis[y]) dfs(y,g,vis);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<int> vis(n,0);
    while(m--){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,g,vis);
}