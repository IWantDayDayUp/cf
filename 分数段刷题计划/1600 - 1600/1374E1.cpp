#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
	cin >> n >> k;
	vector<int> times[4];
	vector<int> sums[4];
	for (int i = 0; i < n; ++i) {
		int t, a, b;
		cin >> t >> a >> b;
		times[a * 2 + b].push_back(t);
	}
	for (int i = 0; i < 4; ++i) {
		sort(times[i].begin(), times[i].end());
		sums[i].push_back(0);
		for (auto it : times[i]) {
			sums[i].push_back(sums[i].back() + it);
		}
	}
	
	int ans = INF;
	for (int cnt = 0; cnt < min(k + 1, int(sums[3].size())); ++cnt) {
		if (k - cnt < int(sums[1].size()) && k - cnt < int(sums[2].size())) {
			ans = min(ans, sums[3][cnt] + sums[1][k - cnt] + sums[2][k - cnt]);
		}
	}
	
	if (ans == INF) ans = -1;
	cout << ans << endl;
	
	return 0;

    int n, k;
    cin >> n >> k;
    vector<int> t(n), a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> a[i] >> b[i];
    }

    if (count(a.begin(), a.end(), 1) < k || count(b.begin(), b.end(), 1) < k)
    {
        cout << -1 << endl;
    } else {

    }

    return 0;
}