#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    a.push_back(1e9 + 7);
    b.push_back(1e9 + 8);

    vector<int> ans_a(n), ans_b(m);

    int l = 0, r = 0;
    int cnt = 1;
    while (l < n || r < m)
    {
        if (a[l] < b[r])
        {
            ans_a[l++] = cnt++;
        } else {
            ans_b[r++] = cnt++;
        }

        // l = min(l, n - 1);
        // r = min(r, m - 1);
        // cout << l << ' ' << r << endl;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans_a[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < m; i++)
    {
        cout << ans_b[i] << " \n"[i == m - 1];
    }

    return 0;
}