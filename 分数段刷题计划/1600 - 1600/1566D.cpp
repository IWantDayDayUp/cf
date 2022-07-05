#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void slove() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> p(n * m);
    for (int i = 0; i < n * m; i++)
    {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end());

    for (int i = 0; i < n * m; i++)
    {
        p[i].second = -p[i].second;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sort(p.begin() + i * m, p.begin() + (i + 1) * m);
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (p[i * m + k].second > p[i * m + j].second)
                {
                    ans += 1;
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        slove();
    }

    return 0;
}