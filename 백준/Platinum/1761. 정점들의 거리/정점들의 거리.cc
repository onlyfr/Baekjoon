#include <bits/stdc++.h>
using namespace std;
constexpr int SZ = 40'001;
constexpr int LOG = 16;
int N, M, parent[SZ][LOG], depth[SZ], dist[SZ];
vector<pair<int,int>> adj[SZ];
void dfs(int s, int ps, int dep, int dis) {
    depth[s] = dep, dist[s] = dis;
    for(auto& [u,w]: adj[s]){
        if (u!=ps) {
            parent[u][0] = s;
            dfs(u, s, dep+1, dis+w);
        }
    }
}
void setParent() {
    for(int k=1; k<LOG; ++k)
        for(int i=1; i<=N; ++i)
            if(parent[i][k-1] != 0) parent[i][k] = parent[parent[i][k-1]][k-1];
}
int lca(int u, int v) {
    if(depth[v] > depth[u]) swap(u,v);
    for(int k=LOG-1; k>=0; --k)
        if(depth[u]-depth[v] >= (1<<k)) u = parent[u][k];
    if (u==v) return u;
    for(int k=LOG-1; k>=0; --k)
        if(parent[u][k] != parent[v][k]) u = parent[u][k], v = parent[v][k];
    return parent[u][0];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    int u, v, w;
    cin >> N; 
    for(int i=0; i<N-1; ++i){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1, 1, 0, 0);
    setParent();
    cin >> M;
    while(M--) {
        cin >> u >> v;
        cout << dist[u]+dist[v]-2*dist[lca(u, v)] << '\n';
    }
    return 0;
}
