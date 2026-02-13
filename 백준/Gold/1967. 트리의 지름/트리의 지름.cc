#include <bits/stdc++.h>
#define SZ 10001
using namespace std;
vector<pair<int, int>> tree[SZ];
bool chk[SZ];
int V, maxLen, maxNode;
void init() {
	maxLen = 0;
	memset(chk, 0, sizeof(chk));
}
void dfs(int s, int len) {
	if (chk[s]) return;
	chk[s] = true;
	if (maxLen < len) {
		maxLen = len; maxNode = s;
	}
	for (auto& u : tree[s]) {
		int v = u.first, w = u.second;
		dfs(v, len + w);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V; V--;
	while (V--) {
		int u, v, w; cin >> u >> v >> w;
		tree[u].push_back({ v, w });
		tree[v].push_back({ u, w });
	}
	dfs(1, 0);
	init();
	dfs(maxNode, 0);
	cout << maxLen;
	return 0;
}