#include <bits/stdc++.h>
using namespace std;
constexpr int SZ = 100'001;
int V, E, cnt;
bool chk[SZ];
vector<int> adj[SZ], rev[SZ], res[SZ];
stack<int> st;
void init() {
    memset(chk, 0, sizeof(chk));
}
void dfs(int s) {
    chk[s] = true;
    for(auto& u: adj[s])
        if(!chk[u]) dfs(u);
    st.push(s);
}
void rev_dfs(int s) {
    chk[s] = true;
    res[cnt].push_back(s);
    for(auto &n: rev[s]) 
        if(!chk[n]) rev_dfs(n);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> V >> E;
    while(E--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    for(int n=1; n<=V; ++n)
        if(!chk[n]) dfs(n);
    init();
    while(!st.empty()) {
        int n = st.top(); st.pop();
        if(!chk[n]) {
            rev_dfs(n);
            ++cnt;
        }
    }

    for(int i=0; i<cnt; ++i)
        sort(res[i].begin(), res[i].end());
    cout << cnt << '\n';
    sort(res, res+cnt, 
    [](vector<int> f, vector<int> s)->bool {
        return f[0] < s[0];
    });
    for(int i=0; i<cnt; ++i) {
        for(auto& n: res[i]) cout << n << ' ';
        cout << "-1\n";
    }
    return 0;
}