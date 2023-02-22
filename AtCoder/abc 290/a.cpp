#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        int cur;
        cin >> cur;
        cur--;

        ans += a[cur];
    }

    cout << ans << endl;

    return 0;
}