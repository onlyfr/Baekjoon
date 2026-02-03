#include <bits/stdc++.h>
#define SZ 1'001
using namespace std;
constexpr int INF = 1e9;
using P = pair<int, int>;
priority_queue<P> q;
vector<P> adj[SZ];
int N, M, dist[SZ];
bool chk[SZ];
void dijkstra(int s){
    for(int i=1;i<=N;++i) dist[i]=INF;
    dist[s]=0;
    q.push({0,s});
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if (chk[u]) continue;
        chk[u]=true;
        for(auto &[v,w]: adj[u])
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.push({-dist[v],v});
            }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    int u, v, w;
    while(M--){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cin >> u >> w;
    dijkstra(u);
    cout << dist[w];
    return 0;
}