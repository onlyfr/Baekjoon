#include <bits/stdc++.h>
#define SZ 1'000'001
using namespace std;
int N, li[SZ], res[SZ];
stack<int> s;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i=0;i<N;++i) cin >> li[i];
    for(int i=N-1;i>=0;--i) {
        while(!s.empty() && s.top() <= li[i]) s.pop();
        res[i] = s.empty() ? -1 : s.top();
        s.push(li[i]);
    }
    for(int i=0;i<N;++i) cout << res[i] << ' ';
}