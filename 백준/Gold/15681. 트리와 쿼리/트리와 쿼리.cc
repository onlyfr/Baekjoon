#include <bits/stdc++.h>
#define SZ 100'001
using namespace std;
vector<int> adj[SZ];
int N, R, Q, f[SZ];
int dfs(int s, int ps) {
    if(f[s]) return f[s];
    int len = 1;
    for(auto& n: adj[s])
        if(n!=ps) len += dfs(n,s);
    return f[s]=len;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> R >> Q; --N;
	while(N--) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(R,R);
	while(Q--) {
		int n; cin >> n;
		cout << f[n] << '\n';
	}
    return 0;
}
