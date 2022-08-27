#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[i] = i;
    }
    sort(p.begin(), p.end(), [&](int i, int j)
    {
        if (a[i] == a[j])
        {
            return i < j;
        }
        return a[i] < a[j];
    });
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[p[i]] << " \n"[i == n - 1];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << p[i] << " \n"[i == n - 1];
    // }
    if (n % 10 == 0)
    {
        vector<vector<int>> ans(n / 10);
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            ans[idx].emplace_back(a[p[i]]);
            idx += 1;

            if (idx == n / 10)
            {
                idx = 0;
            }
        }

        for (int i = 0; i < n / 10; i++)
        {
            for (int j = 1; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << ' ';
            }
            cout << ans[i][0] << ' ';
        }
    } else {
        vector<vector<int>> ans(n / 10 + 1);
        int left = n % 10;

        int idx = 0;
        int cnt = 0;
        for (int i = n / 10; i < n; i++)
        {
            ans[idx].emplace_back(a[p[i]]);
            idx += 1;
            if (idx == n / 10 + 1)
            {
                idx = 0;
            }

            cnt += 1;
            if (cnt == (n / 10 + 1) * left)
            {
                break;
            }
        }

        idx = 0;
        for (int i = n / 10 + (n / 10 + 1) * left; i < n; i++)
        {
            ans[idx].emplace_back(a[p[i]]);
            idx += 1;
            if (idx == n / 10)
            {
                idx = 0;
            }
        }

        for (int i = 0; i < n / 10; i++)
        {
            ans[i].emplace_back(a[p[i]]);
        }

        for (int i = 0; i < n / 10 + 1; i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << ' ';
            }
        }
    }

    return 0;
}