#include <bits/stdc++.h>
#define SZ 1'001
using namespace std;
queue<pair<int,int>> q;
vector<int> adj[SZ];
int a, b, N, M;
bool chk[SZ];
int bfs(int s){
    q.push({s,0});
    chk[s]=true;
    while(!q.empty()){
        int u,w; tie(u,w)=q.front(); q.pop();
        if (u==b) return w;
        for(auto& v:adj[u]){
            if (chk[v]) continue;
            chk[v]=true;
            q.push({v,w+1});
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> b >> N >> M;
    while(M--){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << bfs(a);
    return 0;
}