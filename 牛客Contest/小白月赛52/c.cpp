#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 2);

    for (int i = 0; i < m; i++)
    {
        int label;
        cin >> label;

        if (label == 1)
        {
            int l, r;
            cin >> l >> r;

            a[l] -= 1;
            a[r + 1] += 1;
        } else if (label == 2)
        {
            int k;
            cin >> k;

            a[k] -= 1;
            a[n + 1] += 1;
        } else {
            int k;
            cin >> k;

            a[1] -= 1;
            a[k + 1] += 1;
        }
    }

    int mx = -1e9;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];

        if (a[i] > mx)
        {
            mx = a[i];
            cnt = 1;
        } else if (a[i] == mx)
        {
            cnt += 1;
        }

        // cout << a[i] << " \n"[i == n];
    }

    cout << mx + m << ' ' << cnt << endl;

    return 0;
}