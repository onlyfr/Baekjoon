#include <bits/stdc++.h>
#define SZ 5'000'001
using namespace std;
int N, L, li[SZ];
deque<pair<int,int>> d;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> L;
    for(int i=0;i<N;++i) cin >> li[i];
    for(int i=0;i<N;++i) {
        if (!d.empty() && i==d.front().second + L) d.pop_front();
        while (!d.empty() && d.back().first > li[i]) d.pop_back();
        d.push_back({li[i],i});
        cout << d.front().first << ' ';
    }
    return 0;
}