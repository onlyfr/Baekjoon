#include <bits/stdc++.h>
#define SZ 10'001
using namespace std;
constexpr int INF = 1e9;
vector<pair<int, int>> adj[SZ];
int V, maxLen, maxNode;
void init() {
    maxLen = 0;
}
void dfs(int s, int ps, int len) {
    if (maxLen < len) maxLen = len, maxNode = s;
    for(auto& [v,w]: adj[s])
        if (v != ps) dfs(v, s, len+w);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> V; V--;
    while(V--) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1,1,1);
    init();
    dfs(maxNode, maxNode, 0);
    cout << maxLen;
    return 0;
}
