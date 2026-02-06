#include <bits/stdc++.h>
#define SZ 100'001
using namespace std;
int N, S, li[SZ];
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> S;
    for(int i=1;i<=N;++i) {
        cin >> li[i];
        li[i] += li[i-1];
    }
    int l=0, r=0, sum=0, res=INT_MAX;
    while (l<=r && r<N) {
        int sum = li[r+1]-li[l];
        if (sum >= S) {
            res = min(res, r-l+1);
            l++;
        }
        else r++;
    }
    cout << (res == INT_MAX ? 0 : res);
    return 0;
}