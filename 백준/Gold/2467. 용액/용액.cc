#include <bits/stdc++.h>
using namespace std;
int res, N;
long long int m, M, li[100'001];
int main(void) {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> li[i];

	int l = 0, r = N - 1;
	res = abs(li[l] + li[r]);
	m = li[l], M = li[r];

	while (l < r) {
		int tmp = li[l] + li[r];
		if (abs(tmp) < res) {
			res = abs(tmp);
			m = li[l], M = li[r];
		}
		if (tmp < 0) ++l;
		else --r;
	}
	cout << m << ' ' << M;
	return 0;
}