#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m), b(m), c(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        a[i] -= 1;
        b[i] -= 1;
    }

    vector<long long> dist(n, 1e18);
    dist[0] = 0;
    while (k--)
    {
        int e;
        cin >> e;
        e--;

        if (dist[b[e]] > dist[a[e]] + c[e])
        {
            dist[b[e]] = dist[a[e]] + c[e];
        }
    }

    if (dist[n - 1] == 1e18)
    {
        cout << -1 << endl;
    } else {
        cout << dist[n - 1] << endl;
    }

    return 0;
}