#include <bits/stdc++.h>
#define SZ 20'001
using namespace std;
enum { FALSE, RED, BLUE };
vector<int> adj[SZ];
queue<int> q;
int V, E, chk[SZ];
void bfs(int s) {
	int color = RED;
	chk[s] = color;
	q.push(s);
	while (!q.empty()) {
		int n = q.front(); q.pop();
		if (chk[n] == RED) color = BLUE;
		else if (chk[n] == BLUE) color = RED;
		for (auto& v : adj[n]) {
			if (chk[v] == FALSE) {
				chk[v] = color;
				q.push(v);
			}
		}
	}
}
bool isBipartiteGraph() {
	for (int u = 1; u <= V; ++u)
		for (auto& v : adj[u])
			if (chk[u] == chk[v]) return false;
	return true;
}
void init() {
	for (int i = 0; i < SZ; ++i) adj[i].clear();
	memset(chk, 0, sizeof(chk));
	q = {};
}
int main(void) {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int K; cin >> K;
	while (K--) {
		init();
		cin >> V >> E;
		for (int i = 0; i < E; ++i) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int u = 1; u <= V; ++u)
			if (chk[u] == FALSE) bfs(u);
		cout << (isBipartiteGraph() ? "YES" : "NO") << '\n';
	}
	return 0;
}