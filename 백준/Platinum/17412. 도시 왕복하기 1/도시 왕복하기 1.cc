#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e9;
constexpr int SZ = 401;
int N, P, S=1, E=2;
vector<int> adj[SZ];
queue<int> q;
int flow[SZ][SZ], cap[SZ][SZ], parent[SZ];
void init() {
    q = {};
    fill(parent, parent+SZ, -1);
}
int edmondsKarp() {
    int res = 0;
    while(1) {
        init();
        parent[S]=S;
        q.push(S);
        while(!q.empty() && parent[E] == -1){
            int u=q.front(); q.pop();
            for(auto& v: adj[u]) {
                if(cap[u][v] - flow[u][v] > 0 && parent[v] == -1) {
                    parent[v] = u;
                    q.push(v);
                    if(v==E) break;
                }
            }
        }
        if(parent[E] == -1) break;

        int minFlow = INF;
        for(int i=E; i!=S; i=parent[i]) 
            minFlow = min(minFlow, cap[parent[i]][i] - flow[parent[i]][i]);
        for(int i=E; i!=S; i=parent[i]) {
            flow[parent[i]][i] += minFlow;
            flow[i][parent[i]] -= minFlow;
        }
        res += minFlow;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> P;
	while (P--) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		cap[u][v] += 1; 
	}
	cout << edmondsKarp();
	return 0;
}